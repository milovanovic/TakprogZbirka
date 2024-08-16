#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}

void save_test_case(int tc,int t,vector<int> nv,vector<int> mv, vector<vector<vector<int>>> lv, vector<vector<vector<int>>> uv){
	ofstream out(folder+to_string(tc)+".in");
	out<<t<<"\n";
	for(int i=0;i<t;i++)
    {
        out<<nv[i]<<" "<<mv[i]<<"\n";
        for(int k=0;k<nv[i];k++)
        {
            for(int j=0;j<mv[i];j++)
            {
                out<<lv[i][k][j];
                if(j!=mv[i]-1) out<<" ";
            }
            out<<"\n";
        }
        for(int k=0;k<nv[i];k++)
        {
            for(int j=0;j<mv[i];j++)
            {
                out<<uv[i][k][j];
                if(j!=mv[i]-1) out<<" ";
            }
            if(k!=nv[i]-1 || i!=t) out<<"\n";
        }
    }
	out.close();
}

void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<vector<vector<int>>> lv,uv;
		vector<int> nv,mv;
		for(int tt=0;tt<t;tt++)
        {
            int n=get_int_from_range(9,10);
            int m=get_int_from_range(9,10);
            nv.push_back(n);
            mv.push_back(m);
            vector<vector<int>> l,u;
            vector<int> r,c;
            for(int i=0;i<n;i++) r.push_back(get_int_from_range(-500000000,500000000));
            for(int i=0;i<n;i++) c.push_back(get_int_from_range(-500000000,500000000));
            int fail=get_int_from_range(0,3);
            for(int i=0;i<n;i++)
            {
                vector<int> ul,ll;
                for(int j=0;j<m;j++)
                {
                    int v=r[i]-c[j];
                    int cs=get_int_from_range(0,2);
                    if(!fail) v+=get_int_from_range(-10,10);
                    if(cs==0) {ll.push_back(v); ul.push_back(v);}
                    if(cs==1) {ll.push_back(v); ul.push_back(v+1);}
                    if(cs==2) {ll.push_back(v-1); ul.push_back(v);}

                }
                u.push_back(ul);
                l.push_back(ll);
            }
            lv.push_back(l);
            uv.push_back(u);
        }
		save_test_case(tc,t,nv,mv,lv,uv);
	}
}

void generate_subtask_2(int l,int r){
    for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<vector<vector<int>>> lv,uv;
		vector<int> nv,mv;
		for(int tt=0;tt<t;tt++)
        {
            int n=get_int_from_range(295,300);
            int m=get_int_from_range(295,300);
            nv.push_back(n);
            mv.push_back(m);
            vector<vector<int>> l,u;
            vector<int> r,c;
            for(int i=0;i<n;i++) r.push_back(get_int_from_range(-500000000,500000000));
            for(int i=0;i<n;i++) c.push_back(get_int_from_range(-500000000,500000000));
            int fail=get_int_from_range(0,3);
            for(int i=0;i<n;i++)
            {
                vector<int> ul,ll;
                for(int j=0;j<m;j++)
                {
                    int v=r[i]-c[j];
                    if(!fail) v+=get_int_from_range(-10,10);
                    ll.push_back(v); ul.push_back(v);
                }
                u.push_back(ul);
                l.push_back(ll);
            }
            lv.push_back(l);
            uv.push_back(u);
        }
		save_test_case(tc,t,nv,mv,lv,uv);
    }
}

void generate_subtask_3(int l,int r){
    for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<vector<vector<int>>> lv,uv;
		vector<int> nv,mv;
		for(int tt=0;tt<t;tt++)
        {
            int n=get_int_from_range(295,300);
            int m=get_int_from_range(295,300);
            nv.push_back(n);
            mv.push_back(m);
            vector<vector<int>> l,u;
            vector<int> r,c;
            for(int i=0;i<n;i++) r.push_back(get_int_from_range(-500000000,500000000));
            for(int i=0;i<n;i++) c.push_back(get_int_from_range(-500000000,500000000));
            int fail=get_int_from_range(0,3);
            for(int i=0;i<n;i++)
            {
                vector<int> ul,ll;
                for(int j=0;j<m;j++)
                {
                    int v=r[i]-c[j];
                    if(!fail) v+=get_int_from_range(-1000,1000);
                    if(j==0 || i==0) {ll.push_back(v); ul.push_back(v);}
                    else {ll.push_back(v-get_int_from_range(0,25)); ul.push_back(v+get_int_from_range(0,25));}

                }
                u.push_back(ul);
                l.push_back(ll);
            }
            lv.push_back(l);
            uv.push_back(u);
        }
		save_test_case(tc,t,nv,mv,lv,uv);
    }
}
void generate_subtask_4(int l,int r){
    for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<vector<vector<int>>> lv,uv;
		vector<int> nv,mv;
		for(int tt=0;tt<t;tt++)
        {
            int n=get_int_from_range(295,300);
            int m=get_int_from_range(295,300);
            nv.push_back(n);
            mv.push_back(m);
            vector<vector<int>> l,u;
            vector<int> r,c;
            for(int i=0;i<n;i++) r.push_back(get_int_from_range(-500000000,500000000));
            for(int i=0;i<n;i++) c.push_back(get_int_from_range(-500000000,500000000));
            int fail=get_int_from_range(0,3);
            for(int i=0;i<n;i++)
            {
                vector<int> ul,ll;
                for(int j=0;j<m;j++)
                {
                    int v=r[i]-c[j];
                    if(!fail) v+=get_int_from_range(-1000,1000);
                    if(j%2==i%2) {ll.push_back(v); ul.push_back(v);}
                    else {ll.push_back(v-get_int_from_range(0,25)); ul.push_back(v+get_int_from_range(0,25));}

                }
                u.push_back(ul);
                l.push_back(ll);
            }
            lv.push_back(l);
            uv.push_back(u);
        }
		save_test_case(tc,t,nv,mv,lv,uv);
    }
}

void generate_subtask_5(int l,int r){
    for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<vector<vector<int>>> lv,uv;
		vector<int> nv,mv;
		for(int tt=0;tt<t;tt++)
        {
            int n=get_int_from_range(295,300);
            int m=get_int_from_range(295,300);
            nv.push_back(n);
            mv.push_back(m);
            vector<vector<int>> l,u;
            vector<int> r,c;
            for(int i=0;i<n;i++) r.push_back(get_int_from_range(-400000000,400000000));
            for(int i=0;i<n;i++) c.push_back(get_int_from_range(-400000000,400000000));
            int fail=get_int_from_range(0,3);
            int bigdif=get_int_from_range(0,1);
            for(int i=0;i<n;i++)
            {
                vector<int> ul,ll;
                for(int j=0;j<m;j++)
                {
                    int v=r[i]-c[j];
                    if(!fail) v+=get_int_from_range(-1000,1000);
                    ll.push_back(v-(bigdif*1000000+1)*get_int_from_range(0,25)); ul.push_back(v+(bigdif*1000000+1)*get_int_from_range(0,25));

                }
                u.push_back(ul);
                l.push_back(ll);
            }
            lv.push_back(l);
            uv.push_back(u);
        }
		save_test_case(tc,t,nv,mv,lv,uv);
    }
}

int main(){
	generate_subtask_1(2,4);
	generate_subtask_2(5,6);
    generate_subtask_3(7,9);
	generate_subtask_4(10,12);
	generate_subtask_5(13,21);
	return 0;
}
