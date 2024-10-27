#include <bits/stdc++.h>
using namespace std;
int main()
{
	int br,n,m,a,b,lb,ub,seed;
	scanf("%d%d%d%d%d%d%d%d",&br,&n,&m,&a,&b,&lb,&ub,&seed);
	mt19937 rng(seed);
	int resi=uniform_int_distribution<int>(175,min(a,200))(rng),resj=uniform_int_distribution<int>(175,min(b,200))(rng),resk=uniform_int_distribution<int>(max(200,a),225)(rng),resl=uniform_int_distribution<int>(max(200,b),225)(rng);
	int x=uniform_int_distribution<int>(max(ub-50,0),ub)(rng)-2*resi-2*resj,y=uniform_int_distribution<int>(max(ub-50,0),ub)(rng)+2*resk+2*resl;
	printf("%d %d %d %d %d %d %d %d\n",a,b,resi,resj,resk,resl,x,y);
	char c[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(c,"w");
	fprintf(fptc,"%d %d %d %d",n,m,a,b);
	for(int i=1;i<=n;i++) 
	{
		fprintf(fptc,"\n");
		for(int j=1;j<=m;j++) 
		{
			if(i==resi && j==resj) fprintf(fptc,"%d",x+2*i+2*j);
			else if(i==resk && j==resl) fprintf(fptc,"%d",y-2*i-2*j);
			else if(i==a && j==b) fprintf(fptc,"%d",uniform_int_distribution<int>(lb,min(min(x+2*i+2*j,y-2*i-2*j)-1,ub))(rng));
			else if(i<=a && j<=b) fprintf(fptc,"%d",uniform_int_distribution<int>(lb,min(x+2*i+2*j-1,ub))(rng));
			else if(i>=a && j>=b) fprintf(fptc,"%d",uniform_int_distribution<int>(lb,ub)(rng));
			else fprintf(fptc,"%d",uniform_int_distribution<int>(lb,ub)(rng));
			if(j!=m) fprintf(fptc," ");
		}
	}
	fclose(stdout);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t2",br,n,m,a,b,lb,ub,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t2",br,n,m,a,b,lb,ub,seed);
	fclose(fp);
}
