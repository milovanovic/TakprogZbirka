#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
vector<int> generate_id_perm(int n){
	vector<int> perm;
	for(int i=0;i<n;i++) perm.push_back(i+1);
	return perm;
}
vector<int> generate_perm(int n){
	vector<int> perm;
	for(int i=0;i<n;i++) perm.push_back(i+1);
	shuffle(perm.begin(),perm.end(),rng);
	return perm;
}
void save_test_case(int tc,int n,int k,vector<int> perm){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<k<<"\n";
	assert(perm.size()==n);
	for(int i=0;i<n;i++) {out<<perm[i]; if(i+1!=n) out<<" ";}
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=2;
		vector<int> perm=generate_perm(n);
		int k=(tc==r)?perm[n-1]:perm[get_int_from_range(1,n-1)-1];
		save_test_case(tc,n,k,perm);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(17000,20000);
		vector<int> perm=generate_id_perm(n);
		int k=(tc==r)?perm[n-1]:perm[get_int_from_range(1,n-1)-1];
		save_test_case(tc,n,k,perm);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=5;
		vector<int> perm=generate_perm(n);
		int k=(tc==r)?perm[n-1]:perm[get_int_from_range(1,n-1)-1];
		save_test_case(tc,n,k,perm);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(17000,20000);
		vector<int> perm=generate_perm(n);
		int k=(tc==r)?perm[n-1]:perm[get_int_from_range(1,n-1)-1];
		save_test_case(tc,n,k,perm);
	}
}
int main(){
	//generate_subtask_1(3,5);
	generate_subtask_2(6,9);
	generate_subtask_3(10,13);
	generate_subtask_4(14,22);
	return 0;
}
