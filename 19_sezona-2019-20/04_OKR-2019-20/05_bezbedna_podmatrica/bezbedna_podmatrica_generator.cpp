#include <bits/stdc++.h>
using namespace std;
int main()
{
	int br,n,m,a,b,lb,ub,seed;
	scanf("%d%d%d%d%d%d%d%d",&br,&n,&m,&a,&b,&lb,&ub,&seed);
	mt19937 rng(seed);
	char c[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(c,"w");
	fprintf(fptc,"%d %d %d %d",n,m,a,b);
	for(int i=1;i<=n;i++) 
	{
		fprintf(fptc,"\n");
		for(int j=1;j<=m;j++) 
		{
			fprintf(fptc,"%d",uniform_int_distribution<int>(lb,ub)(rng));
			if(j!=m) fprintf(fptc," ");
		}
	}
	fclose(stdout);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d",br,n,m,a,b,lb,ub,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d",br,n,m,a,b,lb,ub,seed);
	fclose(fp);
}
