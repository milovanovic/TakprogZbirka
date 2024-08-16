#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";

mt19937 rng(time(0));

long long get_int_from_range(long long l,long long r){
	assert(l<=r);
	return uniform_int_distribution<long long>(l,r)(rng);
}
void save_test_case(int tc,int n,int m,int k,int l,vector<int> a){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<m<<" "<<k<<" "<<l<<"\n";
	for(int i=0;i<n*m;i++)
    {
        out<<a[i];
        if(i!=n*m-1) out<<" ";
        else out<<"\n";
    }
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(900,1000),m=get_int_from_range(900,1000);
        int k=1,l=1;
        vector<int> a;
        for(int i=0;i<n*m;i++) a.push_back(get_int_from_range(0,1000));
        save_test_case(tc,n,m,k,l,a);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=3,m=3;
        int k=2,l=2;
        vector<int> a;
        for(int i=0;i<n*m;i++) a.push_back(get_int_from_range(0,1000000));
        save_test_case(tc,n,m,k,l,a);
	}
}
void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(900,1000),m=get_int_from_range(900,1000);
        int k=get_int_from_range(n/4,(3*n)/4),l=get_int_from_range(m/4,(3*m)/4);
        vector<int> a;
        for(int i=0;i<n*m;i++) a.push_back(get_int_from_range(0,1));
        save_test_case(tc,n,m,k,l,a);
	}
}
void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(900,1000),m=get_int_from_range(900,1000);
        int k=get_int_from_range(2,5),l=get_int_from_range(2,5);
        vector<int> a;
        for(int i=0;i<n*m;i++) a.push_back(get_int_from_range(0,1000000));
        save_test_case(tc,n,m,k,l,a);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(900,1000),m=get_int_from_range(900,1000);
        int k=get_int_from_range(n/4,(3*n)/4),l=get_int_from_range(m/4,(3*m)/4);
        vector<int> a;
        for(int i=0;i<n*m;i++) a.push_back(get_int_from_range(0,1000000));
        save_test_case(tc,n,m,k,l,a);
	}
}
int main(){
	generate_subtask_1(3,6);
	generate_subtask_2(7,10);
	generate_subtask_3(11,14);
	generate_subtask_4(15,18);
	generate_subtask_5(19,22);
}
