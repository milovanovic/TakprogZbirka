#include<bits/stdc++.h>
#define MAXN 307
using namespace std;
long long a[MAXN][MAXN];
int l[MAXN][MAXN],u[MAXN][MAXN],t;
char ta[30],nj[30],kraj[30];
int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r"); //Takmicarev output
	FILE* fsol = fopen(argv[2], "r"); //Komisijski output
	FILE* fin = fopen(argv[3], "r"); //Input
	fscanf(fin, "%d", &t);
	while(t--)
    {
        int n,m;
        fscanf(fin,"%d%d",&n,&m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) fscanf(fin,"%d",&l[i][j]);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) fscanf(fin,"%d",&u[i][j]);
        fscanf(fsol,"%s",ta);
        fscanf(fout,"%s",nj);
        if(strlen(nj)!=2) return -1;
        if(nj[0]!=ta[0] || nj[1]!=ta[1]) return -1;
        if(ta[0]=='N') continue;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) fscanf(fout,"%lld",&a[i][j]);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[0][0]+a[i][j]!=a[0][j]+a[i][0]) return -1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]>u[i][j]) return -1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]<l[i][j]) return -1;
    }
    fscanf(fout,"%s",kraj);
    if(strlen(kraj)!=0) return -1;
    return 0;
}
