#include <bits/stdc++.h>
using namespace std;

const string folder="testcases\\";

typedef vector<int> vi;

mt19937 rng(time(0));

const int maxx = 1e9;

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}

void save_test_case(int tc,int t,vector<int> n,vector<vector<int>> a){
	ofstream out(folder+to_string(tc)+".in");
	out << t << endl;
	for(int tp = 0; tp < t; tp++){
        out << n[tp] << endl;
        for(int i=0;i<n[tp];i++){
        	out << a[tp][i] << ' ';

        }
        if(tp+1!=t) out<<"\n";
    }
	out.close();
}
void generate_subtask_1(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=1;
        vi n;
        vector<vi> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(5,20);
            vi ta;
            for(int i=0;i<nt;i++){
            	ta.push_back(get_int_from_range(1,maxx));
            }
            n.push_back(nt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,a);
    }
}

void generate_subtask_2(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n;
        vector<vi> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(998,1000);
            vi ta;
            for(int i=0;i<nt;i++){
            	ta.push_back(get_int_from_range(1, maxx));
            }
            n.push_back(nt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,a);
    }
}

void generate_subtask_3(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n;
        vector<vi> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1e5-10,1e5);
            vi ta;
            for(int i=0;i<nt;i++){
            	ta.push_back(1);
            }
            n.push_back(nt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,a);
    }
}

void generate_subtask_4(int l,int r,int ok=0){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n;
        vector<vi> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1e5-10,1e5);
            vi ta;
            for(int i=0;i<nt;i++){
            	if (!ok)
            		ta.push_back(get_int_from_range(1, maxx));
            	else
            		ta.push_back(maxx - get_int_from_range(0,5));
            }
            n.push_back(nt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,a);
    }
}

int main(){
	generate_subtask_1(3,6);
	generate_subtask_2(7,11);
	generate_subtask_3(12,15);
	generate_subtask_4(16,20,0);
	generate_subtask_4(21,21,1);

	return 0;
}