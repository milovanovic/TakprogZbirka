#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int n;
long long l[maxn];
long long b[maxn];
int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r"); //Takmicarev output
	FILE* fsol = fopen(argv[2], "r"); //Komisijski output
	FILE* fin = fopen(argv[3], "r"); //Input
	fscanf(fin, "%d", &n);
	for(int i=0;i<n-1;i++) fscanf(fin,"%lld",&b[i]);
	fclose(fin);
	long long o1=0;
	fscanf(fsol,"%lld",&o1);
    if(o1==-1) { //Komisija nije nasla resenje
        long long o2=0;
        if(feof(fout)) return -1; //Takmicar nije nista ispisao
        fscanf(fout,"%lld",&o2); //Prvi broj, treba da bude -1
        fclose(fsol);
        fclose(fout);
        if(o2==-1) return 0; //Ni takmicar nije nasao resenje
        else return -1; //Takmicar tvrdi da postoji resenje
    }
    fclose(fsol);
	for(int i=0;i<n;i++) {
        if(feof(fout)) return -1; //Takmicar nije ispisao dovoljno brojeva
        fscanf(fout,"%lld",&l[i]);
        if(l[i]<0 || l[i]>=1e18) return -1; //Takmicar ispisuje nevalidno resenje, ili tvrdi da resenje ne postoji
	}
    for(int i=0;i<n-1;i++) {
        if(__gcd(l[i],l[i+1])!=b[i]) return -1;
    }
    fclose(fout);
	return 0; //nije uspeo da pronadje dva ista kada se izbrise takmicarev podniz
}
