#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n,seed;
    string s;
    cin>>tc>>n>>s>>seed;
	mt19937 rng(seed);
	char ch[6]={tc/10+'0',tc%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(ch,"w");
	for(int i=0;i<n;i++)
    {
        char c=(char)('a'+uniform_int_distribution<int>(0,25)(rng));
        if(uniform_int_distribution<int>(0,1)(rng)) {fprintf(fptc,"pp"); i++;}
        else fprintf(fptc,"%c",c);
    }
    fprintf(fptc,"\n");
    for(int i=0;i<s.size();i++) fprintf(fptc,"%c",s[i]);
    FILE *fp=fopen("testGen.txt","a");
	if(tc<10) fprintf(fp,"\n0%d.in\t%d\t%d",tc,n,seed);
	else fprintf(fp,"\n%d.in\t%d\t%d",tc,n,seed);
	fclose(fp);
}
