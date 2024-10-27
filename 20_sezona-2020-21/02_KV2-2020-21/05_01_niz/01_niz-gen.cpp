#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

void random_test_case(string tc,int n,int c,int q,bool l_eq_r){
	ofstream out(tc+".in");
	string s="";
	for(int i=1;i<=n;i++){
		if(rng()&1)s+="1";
		else s+="0";
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		if(l_eq_r){
			l=r=rng()%n+1;
		}else{
			l=rng()%n+1;
			r=rng()%n+1;
			if(l>r)swap(l,r);
		}
		out<<l<<" "<<r<<"\n";
	}
	out.close();
}

void random_blocks(string tc,int n,int c,int q,int block,bool l_eq_r,bool random_q){
	ofstream out(tc+".in");
	string s="";
	for(int i=1;i<=n;){
		for(int j=1;j<=block*2;j++)if(i<=n){
			if(rng()%4>0)s+="1";
			else s+="0";
			i++;
		}
		for(int j=1;j<=block;j++)if(i<=n){
			s+="0";
			i++;
		}
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	if(l_eq_r){
		int now=2*block+1;
		for(int i=1;i<=q;i++){
			if(!random_q&&now<=n){
				out<<now<<" "<<now<<"\n";
				now++;
				if(now%(3*block)==1)now+=2*block;
			}else{
				int l,r;
				l=r=rng()%n+1;
				out<<l<<" "<<r<<"\n";
			}
		}
	}else{
		int now=1;
		for(int i=1;i<=q;i++){
			if(!random_q&&now+3*block-1<=n){
				out<<now+2*block<<" "<<now+3*block-1<<"\n";
				now+=3*block;
			}else{
				int l,r;
				l=rng()%n+1;
				r=rng()%n+1;
				if(l>r)swap(l,r);
				out<<l<<" "<<r<<"\n";
			}
		}
	}
	out.close();
}

void inc_blocks(string tc,int n,int c,int q,bool l_eq_r){
	ofstream out(tc+".in");
	string s="";
	for(int i=1,j=1;i<=n;j++){
		for(int k=1;k<=j;k++)if(i<=n){
			if(j&1)s+="1";
			else s+="0";
			i++;
		}
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		if(l_eq_r){
			l=r=rng()%n+1;
		}else{
			l=rng()%n+1;
			r=rng()%n+1;
			if(l>r)swap(l,r);
		}
		out<<l<<" "<<r<<"\n";
	}
	out.close();
}

void parity(string tc,int n,int c,int q,bool l_eq_r){
	ofstream out(tc+".in");
	string s="";
	for(int i=1;i<=n;i++){
		if(__builtin_popcount(i)&1)s+="1";
		else s+="0";
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		if(l_eq_r){
			l=r=rng()%n+1;
		}else{
			l=rng()%n+1;
			r=rng()%n+1;
			if(l>r)swap(l,r);
		}
		out<<l<<" "<<r<<"\n";
	}
	out.close();
}

void big_upd(string tc,int n,int c,int q){
	ofstream out(tc+".in");
	string s="";
	for(int i=1;i<=n;i++){
		if(rng()&1)s+="1";
		else s+="0";
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		l=rng()%(n/10)+1;
		r=n-rng()%(n/10);
		if(l>r)swap(l,r);
		out<<l<<" "<<r<<"\n";
	}
	out.close();
}

void bitmask(string tc,int n,int c,int q,bool l_eq_r){
	ofstream out(tc+".in");
	string s="";
	for(int i=1,j=1;i<=n;j++){
		for(int k=0;k<20;k++)if(i<=n){
			if(j>>k&1)s+="1";
			else s+="0";
			i++;
		}
	}
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		if(l_eq_r){
			l=r=rng()%n+1;
		}else{
			l=rng()%n+1;
			r=rng()%n+1;
			if(l>r)swap(l,r);
		}
		out<<l<<" "<<r<<"\n";
	}
	out.close();
}

//C=N, N, Q <= 4000 : 03
void subtask1(){
	random_test_case("testcases\\03",4000,4000,4000,false);
}

//C=N, L_i=R_i : 04
void subtask2(){
	random_test_case("testcases\\04",200000,200000,200000,true);
}

//C=N : 05, 06, 07, 08, 09, 10
void subtask3(){
	random_test_case("testcases\\05",200000,200000,200000,false);
	parity("testcases\\06",200000,200000,200000,false);
	big_upd("testcases\\07",200000,200000,200000);
	big_upd("testcases\\08",200000,200000,200000);
	inc_blocks("testcases\\09",200000,200000,200000,false);
	bitmask("testcases\\10",200000,200000,200000,false);
}

//C=1, N, Q <= 4000 : 11, 12
void subtask4(){
	random_test_case("testcases\\11",4000,1,4000,false);
	random_test_case("testcases\\12",4000,1,4000,false);
}

//C=1 : 13, 14, 15
void subtask5(){
	random_test_case("testcases\\13",200000,1,200000,false);
	random_test_case("testcases\\14",200000,1,200000,false);
	big_upd("testcases\\15",200000,1,200000);
}

//Q=1, N <= 1000 : 16, 17, 18, 19
void subtask6(){
	random_test_case("testcases\\16",1000,5,1,false);
	random_test_case("testcases\\17",1000,37,1,false);
	random_blocks("testcases\\18",1000,7,1,7,true,false);
	random_blocks("testcases\\19",1000,17,1,17,false,false);
}

//Q=1 : 20, 21, 22, 23, 24, 25, 26, 27, 28
void subtask7(){
	random_test_case("testcases\\20",200000,2,1,false);
	random_blocks("testcases\\21",200000,370,1,370,false,false);
	inc_blocks("testcases\\22",200000,77,1,false);
	random_test_case("testcases\\23",200000,24356,1,false);
	random_blocks("testcases\\24",200000,705,1,350,false,true);
	inc_blocks("testcases\\25",200000,1000,1,false);
	random_blocks("testcases\\26",200000,2,1,2,false,false);
	random_blocks("testcases\\27",200000,5000,1,2700,false,false);
	random_test_case("testcases\\28",200000,5000,1,false);
}

//L_i=R_i : 29, 30, 31, 32, 33, 34, 35, 36, 37, 38
void subtask8(){
	random_test_case("testcases\\29",200000,2,200000,true);
	random_test_case("testcases\\30",200000,37,200000,true);
	random_test_case("testcases\\31",200000,5007,200000,true);
	random_blocks("testcases\\32",200000,7,200000,7,true,false);
	random_blocks("testcases\\33",200000,50,200000,50,true,false);
	random_blocks("testcases\\34",200000,7045,200000,4062,true,false);
	inc_blocks("testcases\\35",200000,207,200000,true);
	parity("testcases\\36",200000,4096,200000,true);
	parity("testcases\\37",200000,96,200000,true);
	bitmask("testcases\\38",200000,53,200000,true);
}

//full : 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52
void subtask9(){
	random_test_case("testcases\\39",200000,3,200000,false);
	random_test_case("testcases\\40",200000,256,200000,false);
	random_test_case("testcases\\41",200000,9067,200000,false);
	random_blocks("testcases\\42",200000,11,200000,11,false,false);
	random_blocks("testcases\\43",200000,77,200000,77,false,true);
	random_blocks("testcases\\44",200000,7000,200000,6000,false,true);
	inc_blocks("testcases\\45",200000,18,200000,false);
	inc_blocks("testcases\\46",200000,705,200000,false);
	parity("testcases\\47",200000,81,200000,false);
	bitmask("testcases\\48",200000,507,200000,false);
	big_upd("testcases\\49",200000,6,200000);
	big_upd("testcases\\50",200000,42,200000);
	big_upd("testcases\\51",200000,306,200000);
	big_upd("testcases\\52",200000,20000,200000);
}

void gen_22(){
	ofstream out("testcases\\22.in");
	int n=200000,c=77,q=1;
	string s="";
	while(s.size()<n)s+="111111111111100";
	s=s.substr(0,n);
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	out<<"1 2\n";
	out.close();
}

void gen_25(){
	ofstream out("testcases\\25.in");
	int n=200000,c=1000,q=1;
	string s="",block="";
	for(int i=0;i<2300;i++)block+="1";
	for(int i=0;i<300;i++)block+="0";
	shuffle(s.begin(),s.end(),rng);
	for(int i=0;i<1100;i++)block+="0";
	while(s.size()<n)s+=block;
	s=s.substr(0,n);
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	out<<n-100<<" "<<n-50<<"\n";
	out.close();
}

void gen_26(){
	ofstream out("testcases\\26.in");
	int n=200000,c=2,q=1;
	string s="";
	while(s.size()<n)s+="111110111110000101010000";
	s=s.substr(0,n);
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	out<<"100000 200000\n";
	out.close();
}

void gen_28(){
	ofstream out("testcases\\28.in");
	int n=200000,c=5000,q=1;
	string s="",block="";
	for(int i=0;i<6000;i++)block+="1";
	for(int i=0;i<10;i++)block+="0";
	shuffle(s.begin(),s.end(),rng);
	for(int i=0;i<5050;i++)block+="0";
	while(s.size()<n)s+=block;
	s=s.substr(0,n);
	out<<n<<" "<<c<<" "<<q<<"\n";
	out<<s<<"\n";
	out<<n-1<<" "<<n<<"\n";
	out.close();
}

//Weak: 22, 23, 24, 25, 26, 28, 31, 36, 41, 52
void fix_weak_testcases(){
	gen_22();
	random_test_case("testcases\\23",200000,1024,1,false);
	random_blocks("testcases\\24",200000,705,1,609,false,true);
	gen_25();
	gen_26();
	gen_28();
	random_test_case("testcases\\31",200000,2020,200000,true);
	parity("testcases\\36",200000,17,200000,true);
	random_test_case("testcases\\41",200000,777,200000,false);
	big_upd("testcases\\52",200000,899,200000);
}

int main(){
	fix_weak_testcases();
	/*subtask1();
	printf("Subtask 1 generated!\n");
	subtask2();
	printf("Subtask 2 generated!\n");
	subtask3();
	printf("Subtask 3 generated!\n");
	subtask4();
	printf("Subtask 4 generated!\n");
	subtask5();
	printf("Subtask 5 generated!\n");
	subtask6();
	printf("Subtask 6 generated!\n");
	subtask7();
	printf("Subtask 7 generated!\n");
	subtask8();
	printf("Subtask 8 generated!\n");
	subtask9();
	printf("Subtask 9 generated!\n");*/
	return 0;
}
