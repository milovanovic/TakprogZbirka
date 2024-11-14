#include <bits/stdc++.h>
#define INF INT_MAX
#define MOD 100000007
#define MAX_N 10000

using namespace std;

int N, K;
int a[MAX_N], b[MAX_N];

int main(){
	ios::sync_with_stdio(false);
	cin>>N>>K;
	for(int i=0; i<N; ++i){
		cin>>a[i];
		b[i]=a[i]/K;
	}
	sort(b, b+N);
	int result=N;
	for(int i=0; i<N-1; ++i){
		if(b[i]==b[i+1]){
			result--;
		}
	}
	cout<<result;
	return 0;
}
