#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
mt19937 rng(2);
vector<int> v[MAXN];
vector<bool> vi[MAXN];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},br,n,m,seed,q,tx[MAXN],ty[MAXN],ix[MAXN],iy[MAXN],sv;
stack<pair<pair<int,int>,pair<int,int> > > st;
bool valid(int x,int y) {return x>0 && x<=n && y>0 && y<=m;}
void pathgen(int x,int y)
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vi[x][y]=false;
    v[x][y]=1;
    set<int> se;
    int cnt=2, br=2; vi[x][y]=true;
    ix[1]=x; iy[1]=y;
    for(int i=0;i<4;i++) if(valid(x+dx[i],y+dy[i])) {vi[x+dx[i]][y+dy[i]]=true; tx[cnt]=x+dx[i]; ty[cnt]=y+dy[i]; se.insert(cnt++);}
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

}
int main()
{
	scanf("%d%d%d%d%d",&br,&n,&m,&q,&seed);
	rng=mt19937(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	fprintf(fptc,"%d %d %d\n",n,m,q);
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) {v[i].push_back(0); vi[i].push_back(0);}
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
        swap(v[xa][ya],v[xb][yb]);
        st.push({{xa,ya},{xb,yb}});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) {fprintf(fptc,"%d",v[i][j]); if(j!=m) fprintf(fptc," ");}
        fprintf(fptc,"\n");
    }
    while(!st.empty() && sv<q)
    {
        int xa=st.top().first.first,ya=st.top().first.second,xb=st.top().second.first,yb=st.top().second.second;
        sv++;
        fprintf(fptc,"%d %d %d %d",xa,ya,xb,yb);
        if(sv!=q) fprintf(fptc,"\n");
        swap(v[xa][ya],v[xb][yb]);
        st.pop();
    }
    while(sv<q)
    {
        r=uniform_int_distribution<int>(10,15)(rng);
        for(int i=0;i<r && sv<q;i++)
        {
            int xa=uniform_int_distribution<int>(1,n)(rng);
            int ya=uniform_int_distribution<int>(1,m)(rng);
            int zz=uniform_int_distribution<int>(-5,5)(rng);
            int val=v[xa][ya]+zz;
            if(val<=0 || val>n*m) continue;
            int xb=ix[val];
            int yb=iy[val];
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
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t3",br,n,m,q,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t3",br,n,m,q,seed);
	fclose(fp);
}
