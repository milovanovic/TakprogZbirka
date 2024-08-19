#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
void save_test_case(int tc,int n,int q, vector<int> a,vector<int> l,vector<int> r){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<q<<endl;
	for(int i=0;i<n;i++) out<<a[i]<<" ";
	out<<endl;
    for(int i=0;i<q;i++) out<<l[i]<<" "<<r[i]<<endl;
	out.close();
}
void generate_subtask_1(int l,int r){
    for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(10,10);
        int q=get_int_from_range(90,100);
        vector<int> a,le,ri;
        for(int i=0;i<n;i++) a.push_back(i+1);
        shuffle(a.begin(),a.end(),rng);
        for(int i=0;i<q;i++)
        {
            int poc=get_int_from_range(1,n);
            int kraj=get_int_from_range(1,n);
            if(poc>kraj) swap(poc,kraj);
            le.push_back(poc);
            ri.push_back(kraj);
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}

void generate_subtask_2(int l,int r){
    for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(490,500);
        int q=get_int_from_range(490,500);
        vector<int> a,le,ri;
        for(int i=0;i<n;i++) a.push_back(i+1);
        shuffle(a.begin(),a.end(),rng);
        for(int i=0;i<q;i++)
        {
            int poc=get_int_from_range(1,n);
            int kraj=get_int_from_range(1,n);
            if(poc>kraj) swap(poc,kraj);
            le.push_back(poc);
            ri.push_back(kraj);
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}

void generate_subtask_3(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int n=get_int_from_range(4900,5000);
        int q=get_int_from_range(4900,5000);
        vector<int> a,le,ri;
        if(get_int_from_range(1,2)==1)
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(800,900);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
            for(int i=0;i<q;i++)
            {
                int poc=get_int_from_range(1,n);
                int kraj=get_int_from_range(1,n);
                if(poc>kraj) swap(poc,kraj);
                le.push_back(poc);
                ri.push_back(kraj);
            }
        }
        else
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(80,120);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
            for(int i=0;i<q;i++)
            {
                int poc=get_int_from_range(1,n);
                int kraj=get_int_from_range(1,n);
                if(poc>kraj) swap(poc,kraj);
                le.push_back(poc);
                ri.push_back(kraj);
            }
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}

void generate_subtask_4(int l,int r){
    for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(490000,500000);
        int q=get_int_from_range(490000,500000);
        vector<int> a,le,ri;
        for(int i=0;i<n;i++) a.push_back(i+1);
        shuffle(a.begin(),a.end(),rng);
        int up=0;
        if(get_int_from_range(1,3)==1)
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(7000,8000);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
        }
        else
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(300,400);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
        }
        int x;
        for(int i=0;i<n;i++) if(a[i]==n) x=i+1;
        for(int i=0;i<q;i++)
        {
            int poc=get_int_from_range(1,x);
            int kraj=get_int_from_range(x,n);
            if(poc>kraj) swap(poc,kraj);
            le.push_back(poc);
            ri.push_back(kraj);
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}

void generate_subtask_5(int l,int r){
    for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(490000,500000);
        int q=get_int_from_range(490000,500000);
        vector<int> a,le,ri;
        for(int i=0;i<n;i++) a.push_back(i+1);
        shuffle(a.begin(),a.end(),rng);
        for(int i=0;i<q;i++)
        {
            int poc=get_int_from_range(1,n);
            int kraj=get_int_from_range(1,n);
            if(poc>kraj) swap(poc,kraj);
            le.push_back(poc);
            ri.push_back(kraj);
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}

void generate_subtask_6(int l,int r){
    for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(490000,500000);
        int q=get_int_from_range(490000,500000);
        vector<int> a,le,ri;
        if(get_int_from_range(1,3)==1)
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(7000,8000);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
            for(int i=0;i<q;i++)
            {
                int poc=get_int_from_range(1,n);
                int kraj=get_int_from_range(1,n);
                if(poc>kraj) swap(poc,kraj);
                le.push_back(poc);
                ri.push_back(kraj);
            }
        }
        else
        {
            for(int i=0;i<n;i++) a.push_back(i+1);
            shuffle(a.begin(),a.end(),rng);
            int up=0;
            for(int i=0;i<n;)
            {
                int k=get_int_from_range(300,400);
                if(i+k>n) k=n-i;
                if(up) sort(a.begin()+i,a.begin()+i+k);
                else sort(a.begin()+i,a.begin()+i+k,greater<int>());
                if(up) shuffle(a.begin()+i,a.begin()+i+k/10,rng);
                else shuffle(a.begin()+i+k-k/10,a.begin()+i+k,rng);
                up^=1;
                i+=k;
            }
            for(int i=0;i<q;i++)
            {
                int poc=get_int_from_range(1,n);
                int kraj=get_int_from_range(1,n);
                if(poc>kraj) swap(poc,kraj);
                le.push_back(poc);
                ri.push_back(kraj);
            }
        }
        save_test_case(tc,n,q,a,le,ri);
    }
}
int main(){
	//generate_subtask_1(2,6);
	//generate_subtask_2(7,13);
	//generate_subtask_3(14,20);
	generate_subtask_4(21,27);
	//generate_subtask_5(28,35);
	//generate_subtask_6(36,50);
	return 0;
}
