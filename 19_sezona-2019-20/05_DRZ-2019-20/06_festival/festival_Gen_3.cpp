#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int per[MAXN],a[2*MAXN],t=0,pz,d,n;
void dfs(int s,mt19937 rng)
{
	a[pz++]=s;
	//printf("%d\n",s);
	while(true)
	{
		int x=uniform_int_distribution<int>(1,d)(rng);
		if(t==n) break;
		if(s!=0 && x==1) break;
		t++; dfs(per[t],rng);
	}
	a[pz++]=s;
}
int main()
{
	int br,seed,q;
	scanf("%d%d%d%d%d",&br,&n,&d,&q,&seed);
	mt19937 rng(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	
	
	for(int i=1;i<=n;i++) per[i]=i;
	shuffle(per+1,per+n+1,rng);
	dfs(0,rng);
	fprintf(fptc,"%d %d\n",n,q);
	for(int i=1;i<=2*n;i++) fprintf(fptc,"%d ",a[i]);
	fprintf(fptc,"\n");
	for(int i=1;i<=q;i++)
	{
		int u=uniform_int_distribution<int>(1,n)(rng),v=uniform_int_distribution<int>(1,n)(rng);
		while(u==v) v=uniform_int_distribution<int>(1,n)(rng);
		fprintf(fptc,"%d %d\n",u,v);
	}
	
	
	fclose(fptc);
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t\t3",br,n,d,q,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t\t3",br,n,d,q,seed);
	fclose(fp);
}
