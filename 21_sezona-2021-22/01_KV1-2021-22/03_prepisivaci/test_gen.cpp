//Prepisivaci generisanje test primera
#include <bits/stdc++.h>
#define INF INT_MAX
#define MOD 100000007
#define MAX_N 3005

using namespace std;


struct tacka{
	int x, y;
	tacka(int a, int b){
		x=a;
		y=b;
	}
	bool operator<(const tacka& a) const {
    	return (a.x<x or (a.x==x and a.y<y));
    }
};
int N;
vector<tacka> p;
FILE *fptc;

void generate_explicit(int tc){
	N=4;
	if(tc==1){
		p.emplace_back(1, 1);
		p.emplace_back(1, -1);
		p.emplace_back(2, 2);
		p.emplace_back(2, -2);
	}
	else if(tc==2){
		N=5;
		p.emplace_back(0, 0);
		p.emplace_back(1, 1);
		p.emplace_back(1, 2);
		p.emplace_back(0, 3);
		p.emplace_back(-2, 1);
	}
	else if(tc==3){
		p.emplace_back(0, 0);
		p.emplace_back(-1, -1);
		p.emplace_back(1, 0);
		p.emplace_back(1, -1);
	}
	else if(tc==4){
		p.emplace_back(0, 0);
		p.emplace_back(1, 1);
		p.emplace_back(1, 0);
		p.emplace_back(0, 1);
	}
	else return;
}

void generate_grid(int tc){
	int size;
	if(tc==3){
		size=10;
	}
	else if(tc==7){
		size=20;
	}
	else if(tc==8){
		size=18;
	}
	else if(tc==13){
		size=54;
	}
	else if(tc==14){
		size=51;
	}
	else if(tc==19){
		size=53;
	}
	else if(tc==20){
		size=50;
	}
	else return;
	N=size*size;
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			p.emplace_back(i, j);
		}
	}
}

void generate_rows(int tc){
	int rows, pts;
	if(tc==4){
		rows=2;
		pts=50;
	}
	else if(tc==11){
		rows=2;
		pts=200;
	}
	else if(tc==12){
		rows=10;
		pts=40;
	}
	else if(tc==17){
		rows=2;
		pts=1500;
	}
	else if(tc==18){
		rows=10;
		pts=300;
	}
	else return;
	N=rows*pts;
	for(int i=0; i<rows; ++i){
		for(int j=0; j<pts; ++j){
			p.emplace_back(i, j*(1<<i));
		}
	}

}

void generate_random(int tc){
	int size, pts;
	if(tc==5){
		size=50;
		pts=100;
	}
	else if(tc==6){
		size=11;
		pts=100;
	}
	else if(tc==9){
		size=100;
		pts=400;
	}
	else if(tc==10){
		size=30;
		pts=400;
	}
	else if(tc==15){
		size=100;
		pts=3000;
	}
	else if(tc==16){
		size=60;
		pts=3000;
	}
	else return;
	
	N=pts;
	set<tacka> S;
	for(int i=0; i<N*tc; ++i){
		rand();
	}
	int limit=100000000;
	while(S.size()<N){
		tacka P(rand()%limit, rand()%limit);
		if(S.count(P)==0){
			S.insert(P);
			p.emplace_back(P);
		}
	}
}

void generate_homothety(int tc){
	cout<<"generating "<<tc<<endl;
	int pts;
	if(5<=tc and tc<=8){
		pts=55-2*tc;
	}
	if(9<=tc and tc<=14){
		pts=410-2*tc;
	}
	if(15<=tc and tc<=22){
		pts=760-tc;
	}
	N=2*pts;
	for(int i=0; i<N*tc; ++i){
		rand();
	}
	
	int k=rand()%(pts*pts)+pts*pts;
	
	for(int i=1; i<=pts; ++i){
		if(rand()%10!=1)
			p.emplace_back(i, i*i);
		if(rand()%10!=1)
			p.emplace_back(2*i+k, 2*i*i);
	}
	
	N=p.size();
}

void print_tc(){

	assert(N==p.size());

	fprintf(fptc, "%d\n", N);
	for(int i=0; i<N; ++i){
		fprintf(fptc, "%d %d\n", p[i].x, p[i].y);
	}
}

int main(){
    for(int tc=1; tc<23; tc++){
    	p.clear();
    	
		char ch[6]={tc/10+'0',tc%10+'0','.','i','n','\0'};
		fptc=fopen(ch,"w");
		if(tc<=4)
			generate_explicit(tc);
		else
			generate_homothety(tc);
	   	print_tc();
	   	fclose(fptc);
	}
}
/*
Primeri:
4
1 1
1 -1
2 2
2 -2

7
0 2
2 0
2 4
6 0
6 4
8 2
10 4
Izlaz: 10
N\leq 4
01.in
4
0 0
-1 -1
1 0
2 -1

02.in
4
0 0
0 1
1 0
1 1

N\leq 100 
03.in
10x10 grid

04.in 
tacke na ivici kvadrata 20x20

05.in 
random tacke u 50x50 kvadratu

06.in 
random tacke u 11x11 kvadratu 

N\leq 400

07.in
20*20 grid

08.in 
tacke na ivici kvadrata 80x80

09.in 
random tacke u 50x50 kvadratu 

10.in 
random tacke u 30x30 kvadratu

11.in 
dva niza jedan duplo siri od drugog

12.in 
10 nizova progresivno duplo

N\leq 3000

13.in
55*54 grid

14.in 
tacke na ivici kvadrata 700x700

15.in 
random tacke u 100x100 kvadratu skalirano

16.in 
random tacke u 100x100 kvadratu skalirano

17.in 
dva niza jedan duplo siri od drugog

18.in 
10 nizova progresivno duplo skalirano

19.in 
grid 53x53

20.in 
grid 50x50



*/
