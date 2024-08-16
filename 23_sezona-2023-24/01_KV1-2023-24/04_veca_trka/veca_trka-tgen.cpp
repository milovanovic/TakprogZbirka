#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

long long get_int_from_range(long long l,long long r){
	assert(l<=r);
	return uniform_int_distribution<long long>(l,r)(rng);
}
void save_test_case(int tc,int n,long long k,vector<int> x,vector<int> v){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<k;
	for(int i=0;i<n;i++) out<<"\n"<<x[i]<<" "<<v[i];
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=2,k=1;
        vector<int> x,v;
        for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,100000000));
        while(true)
        {
            for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
            sort(x.begin(),x.end());
            bool ok=true;
            for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
            if(ok) break;
        }
        while(v[0]<=v[1]) v[1]=get_int_from_range(1,1000000000);
        save_test_case(tc,n,k,x,v);
	}
}
void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(1970,2000),k=get_int_from_range(1,350000);
        vector<int> x,v;
        int tip=get_int_from_range(1,2);
        if(tip==1)
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,100000000));
            while(true)
            {
                for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
                sort(x.begin(),x.end());
                bool ok=true;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
                if(ok) break;
            }
        }
        else
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,10));
            for(int i=0;i<n;i++) x.push_back(get_int_from_range(2*i+1,2*i+2));
            k=get_int_from_range(1,170000);
        }
        save_test_case(tc,n,k,x,v);
	}
}
void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(149500,150000),k=1;
        vector<int> x,v;
        for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,10));
        while(true)
        {
            for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
            sort(x.begin(),x.end());
            bool ok=true;
            for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) x[i]--;
            for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
            if(ok) break;
            x.clear();
        }
        save_test_case(tc,n,k,x,v);
	}
}
void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(149500,150000),k=get_int_from_range(1,300000);
        vector<int> x,v;
        int tip=get_int_from_range(1,2);
        if(tip==1)
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,100000));
            while(true)
            {
                for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
                sort(x.begin(),x.end());
                bool ok=true;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) x[i]--;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
                if(ok) break;
                x.clear();
            }
        }
        else
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,10));
            for(int i=0;i<n;i++) x.push_back(get_int_from_range(2*i+1,2*i+2));
        }
        save_test_case(tc,n,k,x,v);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
        int n=get_int_from_range(149500,150000);
        long long k=get_int_from_range(1,3500000000);
        vector<int> x,v;
        int tip=get_int_from_range(1,3);
        if(tip==1)
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,100000000));
            while(true)
            {
                for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
                sort(x.begin(),x.end());
                bool ok=true;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) x[i]--;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
                if(ok) break;
            }
        }
        if(tip==2)
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,10));
            for(int i=0;i<n;i++) x.push_back(get_int_from_range(2*i+1,2*i+2));
        }
        if(tip==3)
        {
            for(int i=0;i<n;i++) v.push_back(get_int_from_range(1,10));
            while(true)
            {
                for(int i=0;i<n;i++) x.push_back(get_int_from_range(1,1000000000));
                sort(x.begin(),x.end());
                bool ok=true;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) x[i]--;
                for(int i=0;i+1<n;i++) if(x[i]==x[i+1]) ok=false;
                if(ok) break;
            }
            k=get_int_from_range(2000000000,3000000000);
        }
        save_test_case(tc,n,k,x,v);
	}
}

int main(){
	generate_subtask_1(3,4);
	generate_subtask_2(5,8);
	generate_subtask_3(9,11);
	generate_subtask_4(12,16);
	generate_subtask_5(17,22);
	return 0;
}
