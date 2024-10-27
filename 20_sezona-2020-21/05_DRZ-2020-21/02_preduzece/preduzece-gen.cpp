#include "testlib.h"
#include <iostream>

using namespace std;

int n, k, x;
int p[1000001],v[1000001];
long long A;
map<int, int> mp;

void ispis(int *p)
{
	printf("%d\n", n);
    for(int i=0;i<n;i++)
        if (i < (n-1)) printf("%d ", v[i]); else printf("%d\n", v[i]);
	for (int i = 2; i <= n; i++)
			if (i < n) printf("%d ", p[i]); else printf("%d\n", p[i]);
}

void chain()
{
	for (int i = 2; i <= n; i++)
		p[i] = i - 1;
}

void bambo()
{
	for (int i = 2; i <= n / 2; i++)
		p[i] = i - 1;

	for (int i = n / 2 + 1; i <= n; i++)
		p[i] = n / 2;
}

void random()
{
	for (int i = 2; i <= n; i++)
		p[i] = rnd.next(1, i - 1);
}


void binary()
{
	for (int i = 2; i <= n; i++)
		p[i] = i / 2;
}


void steps()
{
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0) p[i] = i - 1; else p[i] = i - 2;
	}
}

void generisiv(int x){
    long long s=0;
    for(int i=1;i<n;i++){
        v[i]=rnd.next(max(-A,-s-A),min(A,A-s));
        s+=v[i];
    }
    if(x==0) v[0]=-s;
    else v[0]=rnd.next(max(-A,-s-A),min(A,A-s));
}

int main(int argc, char* argv[])
{

	registerGen(argc, argv, 1);

	int t = atoi(argv[1]);
	n = atoi(argv[2]);
	A=atoi(argv[3]);
	if(t>0) generisiv(0);
	else generisiv(1);
    t=abs(t);
    if (t == 1) chain();
    if (t == 2) binary();
    if (t == 3) bambo();
    if (t == 4) random();
    if (t == 5) steps();
	ispis(p);

	return 0;
}
