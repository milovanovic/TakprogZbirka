#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int per[MAXN],a[2*MAXN];
int main()
{
	int br,n,d,seed,q;
	scanf("%d%d%d%d%d",&br,&n,&d,&q,&seed);
	mt19937 rng(seed);
	char ch[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	
	
	for(int i=1;i<=n;i++) per[i]=i;
	shuffle(per+1,per+n+1,rng);
	int t=1,rnd=0;
	for(int i=1;i<=2*n;i++)
	{
		if(!a[i])
		{
			rnd=1-rnd;
			a[i]=per[t];
			int x=1,p=i,lst=0;
			if(rnd) x=6;
			while(x>0 && p<2*n) {p++; if(!a[p]) {x--; lst=p;} }
			if(a[p]) p=lst;
			a[p]=per[t++];
		}
	}
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
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d\t\t4",br,n,d,q,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d\t\t4",br,n,d,q,seed);
	fclose(fp);
}
