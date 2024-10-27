//Prijatelji testcase generator
#include <bits/stdc++.h>
#include <random>
#define MAXN 100005
#define MAXM 100005
#define MAXA -1000000000

using namespace std;

mt19937 rng(2);
int N, M;
long long A[MAXN];
int X[MAXM], Y[MAXM];
set<int> adj[MAXN];
	
int main()
{
	while(1){
	
	int br, mxa, seed;
	scanf("%d%d%d%d%d", &br, &N, &M, &mxa, &seed);
	rng=mt19937(seed);
	char infile[6]={br/10+'0',br%10+'0','.','i','n','\0'};
	FILE *fptc=fopen(infile,"w");
	fprintf(fptc,"%d %d\n", N, M);
	for(int i=1; i<=N; i++){
		A[i]=uniform_int_distribution<int>(-mxa, mxa)(rng);
		fprintf(fptc,"%lld\n", A[i]);
	}
	for(int i=1; i<=M; i++){
		X[i]=uniform_int_distribution<int>(1, N)(rng);
		Y[i]=uniform_int_distribution<int>(1, N)(rng);
		if(X[i]==Y[i]){
			i--;
			continue;
		}
		if(adj[X[i]].count(Y[i])!=0){
			i--;
			continue;
		}
		if(adj[Y[i]].count(X[i])!=0){
			i--;
			continue;
		}
		adj[X[i]].insert(Y[i]);
		adj[Y[i]].insert(X[i]);
		fprintf(fptc,"%d %d\n", X[i], Y[i]);
	}
	fclose(fptc);
	
	char outfile[7]={br/10+'0',br%10+'0','.','o','u','t', '\0'};
	FILE *fout=fopen(outfile,"w");
	
	long long max_sreca=0;
	for(int i=1; i<=M; i++){
		max_sreca+=abs(A[X[i]]+A[Y[i]]);
	}
	fprintf(fout, "%lld\n", max_sreca);
	fclose(fout);
	
	
	for(int i=1; i<=N; ++i)adj[i].clear();
	
	
	FILE *fp=fopen("testGen.txt","a");
	if(br<10) fprintf(fp,"\n0%d.in\t%d\t%d\t%d\t%d",br,N,M,mxa, seed);
	else fprintf(fp,"\n%d.in\t%d\t%d\t%d\t%d",br,N,M,mxa, seed);
	fclose(fp);
	
	}	
}
/*
3 5 6 0 3 
4 5 7 1 4
5 5 10 10 5
6 5 10 100 6 
7 1000 10000 1 7
8 2000 20000 1 8
9 10000 100000 1 9
10 100000 100000 1 10
11 5000 5000 1000000000 11
12 5000 10000 1000000000 12
13 20000 50000 1000000000 13
14 50000 50000 1000000000 14
15 5000 5000 1000 15
16 5000 10000 1000 16
17 20000 50000 1000 17
18 50000 50000 1000 18
19 100000 100000 1000000000 19
20 100000 100000 1000000000 20
21 100000 100000 1000000000 21
22 100000 100000 1000000000 22

*/
