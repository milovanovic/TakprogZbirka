#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
mt19937 rng(2);
vector<int> v[MAXN],a[MAXN];
vector<bool> vi[MAXN],gaa[MAXN];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},br,n,m,seed,q,tx[MAXN],ty[MAXN],ix[MAXN],iy[MAXN],sx[MAXN],sy[MAXN],p[MAXN],sv;
stack<pair<pair<int,int>,pair<int,int> > > st;
FILE *fptc;
bool valid(int x,int y) {return x>0 && x<=n && y>0 && y<=m;}
void pathgen(int x,int y)
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) gaa[i][j]=vi[i][j]=false;
    v[x][y]=a[x][y]=1;
    set<int> se;
    int cnt=2, br=2; vi[x][y]=gaa[x][y]=true;
    sx[1]=ix[1]=x; sy[1]=iy[1]=y;
    for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i])) {vi[x+dx[i]][y+dy[i]]=gaa[x+dx[i]][y+dy[i]]=true; tx[cnt]=x+dx[i]; ty[cnt]=y+dy[i]; se.insert(cnt++);}
    while(!se.empty() && br<n*m/2)
    {
        set<int>::iterator it=se.end(); it--;
        int low=*se.begin(),high=*it;
        int z=uniform_int_distribution<int>(low,high)(rng);
        int r=*se.lower_bound(z);
        x=tx[r]; y=ty[r]; se.erase(r);
        sx[br]=ix[br]=x; sy[br]=iy[br]=y;
        v[x][y]=a[x][y]=br++;
        for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i]) && !vi[x+dx[i]][y+dy[i]]) {vi[x+dx[i]][y+dy[i]]=gaa[x+dx[i]][y+dy[i]]=true; tx[cnt]=x+dx[i]; ty[cnt]=y+dy[i]; se.insert(cnt++);}
    }
    int prevcnt=cnt,prevbr=br;
    set<int> seet;
    for(set<int>::iterator it=se.begin();it!=se.end();it++) seet.insert(*it);
    while(!se.empty())
    {
        set<int>::iterator it=se.end(); it--;
        int low=*se.begin(),high=*it;
        int z=uniform_int_distribution<int>(low,high)(rng);
        int r=*se.lower_bound(z);
        x=tx[r]; y=ty[r]; se.erase(r);
        ix[br]=x; iy[br]=y;
        v[x][y]=br++;
        for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i]) && !vi[x+dx[i]][y+dy[i]]) {vi[x+dx[i]][y+dy[i]]=true; tx[cnt]=x+dx[i]; ty[cnt]=y+dy[i]; se.insert(cnt++);}
    }
    for(set<int>::iterator it=seet.begin();it!=seet.end();it++) se.insert(*it);
    cnt=prevcnt; br=prevbr;
    while(!se.empty())
    {
        set<int>::iterator it=se.end(); it--;
        int low=*se.begin(),high=*it;
        int z=uniform_int_distribution<int>(low,high)(rng);
        if(uniform_int_distribution<int>(0,5)(rng)==0) z=low;
        int r=*se.lower_bound(z);
        x=tx[r]; y=ty[r]; se.erase(r);
        sx[br]=x; sy[br]=y;
        a[x][y]=br++;
        for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i]) && !gaa[x+dx[i]][y+dy[i]]) {gaa[x+dx[i]][y+dy[i]]=true; tx[cnt]=x+dx[i]; ty[cnt]=y+dy[i]; se.insert(cnt++);}
    }
}
void dodji()
{
    for(int i=1;i<=n*m;i++) p[i]=i;
    shuffle(p+1,p+n*m+1,rng);
    for(int i=1;i<=m*n;i++)
    {
        int c=p[i];
        if(sx[c] == ix[c] && sy[c] == iy[c]) continue;
        int val=a[ix[c]][iy[c]];
        swap(sx[c],sx[val]);
        swap(sy[c],sy[val]);
        swap(a[sx[c]][sy[c]],a[sx[val]][sy[val]]);
        sv++;
        fprintf(fptc,"%d %d %d %d",sx[c],sy[c],sx[val],sy[val]);
        if(sv!=q) fprintf(fptc,"\n");
        if(sv==q) return;
    }
}
int main()
{
	scanf("%d%d%d%d%d",&br,&n,&m,&q,&seed);
	rng=mt19937(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	fptc=fopen(ch,"w");
	fprintf(fptc,"%d %d %d\n",n,m,q);
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) {v[i].push_back(0); a[i].push_back(0); vi[i].push_back(0); gaa[i].push_back(0);}
	pathgen(uniform_int_distribution<int>(1,n)(rng),uniform_int_distribution<int>(1,m)(rng));
	int r=uniform_int_distribution<int>(10,15)(rng);
	for(int i=0;i<r;i++)
    {
        int xa=uniform_int_distribution<int>(1,n)(rng);
        int ya=uniform_int_distribution<int>(1,m)(rng);
        int zz=uniform_int_distribution<int>(0,3)(rng);
        int xb=xa+dx[zz];
        int yb=ya+dy[zz];
        if(!valid(xb,yb)) continue;
        if(xa==xb && ya==yb) continue;
        swap(a[xa][ya],a[xb][yb]);
        st.push({{xa,ya},{xb,yb}});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) {fprintf(fptc,"%d",a[i][j]); if(j!=m) fprintf(fptc," ");}
        fprintf(fptc,"\n");
    }
    while(!st.empty() && sv<q)
    {
        int xa=st.top().first.first,ya=st.top().first.second,xb=st.top().second.first,yb=st.top().second.second;
        sv++;
        fprintf(fptc,"%d %d %d %d",xa,ya,xb,yb);
        if(sv!=q) fprintf(fptc,"\n");
        swap(a[xa][ya],a[xb][yb]);
        st.pop();
    }
    cout<<sv<<endl;
    dodji();
    cout<<sv<<endl;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) assert(a[i][j]==v[i][j]);
    while(sv<q)
    {
        r=uniform_int_distribution<int>(10,15)(rng);
        int tip=uniform_int_distribution<int>(0,2)(rng);
        for(int i=0;i<r && sv<q;i++)
        {
            int xa=uniform_int_distribution<int>(1,n)(rng);
            int ya=uniform_int_distribution<int>(1,m)(rng);
            int xb,yb;
            if(tip==0)
            {
                int zz=uniform_int_distribution<int>(0,3)(rng);
                xb=xa+dx[zz]; yb=ya+dy[zz];
            }
            if(tip==1)
            {
                xb=uniform_int_distribution<int>(1,n)(rng);
                yb=uniform_int_distribution<int>(1,m)(rng);
            }
            if(tip==2)
            {
                int zz=uniform_int_distribution<int>(-5,5)(rng);
                int val=v[xa][ya]+zz;
                if(val<=0 || val>n*m) continue;
                xb=ix[val]; yb=iy[val];
            }
            if(!valid(xb,yb)) continue;
            if(xa==xb && ya==yb) continue;
            sv++;
            fprintf(fptc,"%d %d %d %d",xa,ya,xb,yb);
            if(sv!=q) fprintf(fptc,"\n");
            st.push({{xa,ya},{xb,yb}});
        }
        while(!st.empty() && sv<q)
        {
            int xa=st.top().first.first,ya=st.top().first.second,xb=st.top().second.first,yb=st.top().second.second;
            sv++;
            fprintf(fptc,"%d %d %d %d",xa,ya,xb,yb);
            if(sv!=q) fprintf(fptc,"\n");
            st.pop();
        }
    }
	fclose(fptc);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t5",br,n,m,q,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t5",br,n,m,q,seed);
	fclose(fp);
}
