#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

long long get_int_from_range(long long l,long long r){
	assert(l<=r);
	return uniform_int_distribution<long long>(l,r)(rng);
}
void save_test_case(int tc,int n,int q,vector<int> p,vector<int> f,vector<int> u){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++) out<<p[i]<<" ";
	out<<"\n";
	for(int i=0;i<n;i++) out<<f[i]<<" ";
	out<<"\n";
	for(int i=0;i<q;i++) out<<u[i]<<"\n";
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(19,20),q=get_int_from_range(40,50);
        vector<int> p,f,u;
        for(int i=1;i<=n;i++) p.push_back(2);
        for(int i=1;i<=n;i++) f.push_back(get_int_from_range(1,i));
        for(int i=1;i<=q;i++) u.push_back(get_int_from_range(1,n));
        save_test_case(tc,n,q,p,f,u);
	}
}
void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(2400,2500),q=get_int_from_range(17,20);
        vector<int> p,f,u;
        for(int i=1;i<=n;i++) p.push_back(get_int_from_range(1,1000000000));
        for(int i=1;i<=n;i++) f.push_back(get_int_from_range(1,i));
        for(int i=1;i<=q;i++) u.push_back(get_int_from_range(1,n));
        save_test_case(tc,n,q,p,f,u);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(299000,300000),q=get_int_from_range(17,20);
        vector<int> p,f,u;
        for(int i=1;i<=n;i++) p.push_back(get_int_from_range(1,1000000000));
        int k=get_int_from_range(1,3);
        if(k==1) for(int i=1;i<=n;i++) f.push_back(get_int_from_range(1,i));
        if(k==2) for(int i=1;i<=n;i++) f.push_back(get_int_from_range(max(1,i-20),i));
        if(k==3) for(int i=1;i<=n;i++)
        {
            if(get_int_from_range(0,1)) f.push_back(get_int_from_range(1,i));
            else f.push_back(get_int_from_range(max(1,i-20),i));
        }
        for(int i=1;i<=q;i++) u.push_back(get_int_from_range(1,n));
        save_test_case(tc,n,q,p,f,u);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(299000,300000),q=get_int_from_range(299000,300000);
        vector<int> p,f,u;
        for(int i=1;i<=n;i++) p.push_back(get_int_from_range(1,1000000000));
        for(int i=1;i<=n;i++) f.push_back(get_int_from_range(max(1,i-10),i));
        for(int i=1;i<=q;i++) u.push_back(get_int_from_range(1,n));
        save_test_case(tc,n,q,p,f,u);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(299000,300000),q=get_int_from_range(299000,300000);
        vector<int> p,f,u;
        for(int i=1;i<=n;i++) p.push_back(get_int_from_range(1,1000000000));
        int k=get_int_from_range(1,3);
        if(k==1) for(int i=1;i<=n;i++) f.push_back(get_int_from_range(1,i));
        if(k==2) for(int i=1;i<=n;i++) f.push_back(get_int_from_range(max(1,i-20),i));
        if(k==3) for(int i=1;i<=n;i++)
        {
            if(get_int_from_range(0,1)) f.push_back(get_int_from_range(1,i));
            else f.push_back(get_int_from_range(max(1,i-20),i));
        }
        for(int i=1;i<=q;i++) u.push_back(get_int_from_range(1,n));
        save_test_case(tc,n,q,p,f,u);
	}
}
int main(){
	generate_subtask_1(2,9);
	generate_subtask_2(10,23);
	generate_subtask_3(24,37);
	generate_subtask_4(38,52);
	generate_subtask_5(53,80);
	return 0;
}
