//Generisanje test primera za zadatak monopol
#include <bits/stdc++.h>
#define INF INT_MAX


using namespace std;

int N, K;
vector<int> X, A;
FILE *fptc;

int main(){
	int Ns[23]={0,
			5, 4, 
			10, 10, 
			50000, 50000, 500000, 500000, 
			1000, 1000, 3000, 3000,
			500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000};
	int Ks[23]={0,
			2, 2, 
			5, 6, 
			10000, 20000, 30000, 30000,
			200, 500, 600, 1000,
			50000, 100000, 150000, 150000, 250000, 260010, 200000, 200000, 200000, 200000};
			
	int seed=123456;
	for(int i=0; i<seed; ++i){
		rand();
	}
	for(int tc=1; tc<23; tc++){
		cout<<tc<<endl;
    	X.clear();
    	A.clear();
		char ch[6]={tc/10+'0',tc%10+'0','.','i','n','\0'};
		fptc=fopen(ch,"w");
		
		N=Ns[tc];
		K=Ks[tc];
		
		if(tc==1){
			A.push_back(2); 
			A.push_back(5);
			X=vector<int> (5, 2); 
		}
		if(tc==2){
			A.push_back(1); 
			A.push_back(4);
			X.push_back(2);
			X.push_back(2);
			X.push_back(8);
			X.push_back(4);
		}
		
		if(tc>2){
			
			for(int j=1; j<6; j+=2){
	   			for(int i=N*(j-1)/5; i<N*j/5; ++i){
					A.push_back(i+1);
				}
			}
			shuffle(A.begin(), A.end(), default_random_engine(seed+tc));
			assert(A.size()>=K);
			A.resize(K);
		}
		
		for(int i=0; i<N; ++i){
			X.push_back( ((rand()%500000000)+1)*2 );
		}
		
		if(5<=tc and tc<=6){
			X.clear();
			for(int i=0; i<N; ++i)
				X.push_back( 2 );
		}
		
		if(7<=tc and tc<=8){
			X.clear();
			for(int i=0; i<N; ++i)
				X.push_back( 2000000 );
		}
				
	   	fprintf(fptc, "%d %d\n", N, K);
		for(int i=0; i<K; ++i){
			fprintf(fptc, "%d", A[i]);
			if(i!=K-1)
				fprintf(fptc, " ");
		}
		fprintf(fptc, "\n");
	   	
		for(int i=0; i<N; ++i){
			fprintf(fptc, "%d", X[i]);
			if(i!=N-1)
				fprintf(fptc, " ");
		}
		fprintf(fptc, "\n");
	   	
	   	fclose(fptc);
	}
	return 0;
}

/*
Samplovi:

5 2
2 5
2 2 2 2 2

4 2
1 4
2 2 8 4

*/
