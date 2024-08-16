#include <bits/stdc++.h>
#define MAX_N 500000
#define MAX_K 500000

using namespace std;

int N, K;
int A[MAX_K];

long long X[2*MAX_N];
long long gain[MAX_K+1][3];
long long psum[2*MAX_N];
int ind[2*MAX_K];


long long compute_gain(int a){
	if(a<K)
		return gain[a][1];
	else
		return gain[a-K][2]-gain[a-K][1];
}

bool compare(int a, int b){
    return compute_gain(a)>compute_gain(b);
}


int main(){
	ios::sync_with_stdio(false);
	cin>>N>>K;
	
	for(int i=0; i<K; i++){
		cin>>A[i];
		A[i]-=1;
	}
	sort(A, A+K);
	A[K]=A[0]+N;
	
	for(int i=0; i<N; i++){
		cin>>X[i];
		X[i+N]=X[i];
	}
	
	psum[0]=X[0];
	for(int i=1; i<2*N; i++){
		psum[i]+=psum[i-1]+X[i];
	}
	
	
	for(int i=0; i<K; i++){
		if(A[i+1]==A[i]+2){
			gain[i][2]=0;
			continue;
		
		}
		gain[i][2]=psum[A[i+1]-1]-psum[A[i]];
	}
	
	for(int i=0; i<K; i++){
		if(A[i+1]==A[i]+1){
			gain[i][1]=0;
			continue;
		}
		long long max=0, imax=-1;
		for(int t=A[i]+1; t<A[i+1]; t++){
			long long gaint=psum[ (t+A[i+1]+1)/2 -1] - psum[ (t+A[i])/2 ];
			if(t%2==A[i]%2){
				gaint+=X[ (t+A[i])/2 ]/2;
			}
			if(t%2==A[i+1]%2){
				gaint+=X[ (t+A[i+1])/2 ]/2;
			}
			
			if(gaint>max){
				max=gaint;
				imax=t;
			}
		}
		gain[i][1]=max;
	}
	
	for(int i=0; i<K; i++){
		ind[i]=i;
		ind[K+i]=K+i;
	}
	
	sort(ind, ind+2*K, compare);
	
	long long sum=0, m=0;
	for(int i=0; i<2*K; i++){
		sum+=compute_gain(ind[i]);
		m++;
		if(sum>psum[N-1]/2){
			break;
		}
	}
	
	if(sum>psum[N-1]/2)
		cout<<m;
	else
		cout<<-1;
	return 0;
}
