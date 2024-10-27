#include <bits/stdc++.h>
using namespace std;

mt19937 rng(7);

const int N=1000050;
int n;
int a[N];

string make(int t){
	t++;
	if(t>9)return to_string(t);
	else return "0"+to_string(t);
}

void Save(int t){
	ofstream in("testcases\\"+make(t)+".in");
	in<<n<<"\n";
	for(int i=1;i<=n;i++)in<<a[i]<<" ";
	in<<"\n";
}

void Subtask1(){
	for(int t=2;t<=4;t++){
		n=10;
		for(int i=1;i<=n;i++){
			if(t==2)a[i]=rng()%20+1;
			else a[i]=rng()%1000000+1;
		}
		Save(t);
	}
}

void Subtask2(){
	for(int t=5;t<=8;t++){
		n=1000;
		for(int i=1;i<=n;i++){
			if(t==5)a[i]=rng()%50+1;
			else if(t==6)a[i]=rng()%1000+1;
			else a[i]=rng()%1000000+1;
		}
		Save(t);
	}
}

void Subtask3(){
	for(int t=9;t<=12;t++){
		n=100000;
		if(t<=10)n-=rng()%10000;
		for(int i=1;i<=n;i++){
			a[i]=rng()%1000+1;
		}
		Save(t);
	}
}

void Subtask4(){
	for(int t=13;t<=16;t++){
		n=100000;
		if(t<=14)n-=rng()%10000;
		int A=rng()%1000000+1;
		int B=rng()%1000000+1;
		for(int i=1;i<=n;i++){
			a[i]=rng()%2==1?B:A;
		}
		Save(t);
	}
}

void Subtask5(){
	for(int t=17;t<=24;t++){
		n=100000;
		if(t<=20)n-=rng()%10000;
		for(int i=1;i<=n;i++){
			a[i]=rng()%1000000+1;
		}
		Save(t);
	}
}
int main(){
	Subtask1();
	Subtask2();
	Subtask3();
	Subtask4();
	Subtask5();
	return 0;
}
