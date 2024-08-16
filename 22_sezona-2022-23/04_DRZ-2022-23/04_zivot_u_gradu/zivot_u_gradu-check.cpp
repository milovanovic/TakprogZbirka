#include<bits/stdc++.h>
#define MAXN 3007
using namespace std;
long long a[MAXN][MAXN];
char ta[30],nj[30],kraj[30],c[2*MAXN],r[MAXN];
int main(int argc, char *argv[])
{
    int t,z;
    FILE* fout = fopen(argv[1], "r"); //Takmicarev output
	FILE* fsol = fopen(argv[2], "r"); //Komisijski output
	FILE* fin = fopen(argv[3], "r"); //Input
	fscanf(fin, "%d%d", &t,&z);
	while(t--)
    {
        int n,m,k;
        fscanf(fin,"%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            fscanf(fin,"%s",r);
            for(int j=0;j<m;j++) a[i][j]=r[j]-'0';
        }
        fscanf(fsol,"%s",ta);
        fscanf(fout,"%s",nj);
        if(strlen(nj)!=2) return -1;
        if(nj[0]!=ta[0] || nj[1]!=ta[1]) return -1;
        if(ta[0]=='N') continue;
        if(z==0) continue;
        fscanf(fout,"%s",c);
        int total=a[0][0],x=0,y=0;
        if(strlen(c)!=n+m-2) return -1;
        for(int i=0;i<n+m-2;i++)
        {
            if(c[i]!='S' && c[i]!='D') return -1;
            if(c[i]=='S') x++;
            else y++;
            if(x>=n || y>=m) return -1;
            total+=a[x][y];
        }
        if(total!=k) return -1;
        fscanf(fsol,"%s",c);
    }
    fscanf(fout,"%s",kraj);
    if(strlen(kraj)!=0) return -1;
    return 0;
}
