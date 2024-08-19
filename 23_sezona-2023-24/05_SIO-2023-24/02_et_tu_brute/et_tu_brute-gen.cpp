#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

long long get_int_from_range(long long l,long long r){
	assert(l<=r);
	return uniform_int_distribution<long long>(l,r)(rng);
}
void save_test_case(int tc,int n,int k,vector<long long> a){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<k<<"\n";
	for(int i=0;i<n;i++) out<<a[i]<<" ";
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(499000,500000),k=get_int_from_range(20,30);
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,1));
        save_test_case(tc,n,k,a);
	}
}
void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(499000,500000),k=3;
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,(1LL<<k)-1));
        save_test_case(tc,n,k,a);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(499000,500000),k=get_int_from_range(6,8);
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,(1LL<<k)-1));
        save_test_case(tc,n,k,a);
	}
}
void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(900,1000),k=get_int_from_range(27,30);
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,(1LL<<k)-1));
        save_test_case(tc,n,k,a);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(99900,100000),k=get_int_from_range(27,30);
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,(1LL<<k)-1));
        save_test_case(tc,n,k,a);
	}
}

void generate_subtask_6(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(999000,1000000),k=get_int_from_range(27,30);
        vector<long long> a;
        for(int i=1;i<=n;i++) a.push_back(get_int_from_range(0,(1LL<<k)-1));
        save_test_case(tc,n,k,a);
	}
}
int main(){
	generate_subtask_1(2,9);
	generate_subtask_2(10,16);
	generate_subtask_3(17,24);
	generate_subtask_4(25,33);
	generate_subtask_5(34,41);
	generate_subtask_6(42,50);
	return 0;
}
