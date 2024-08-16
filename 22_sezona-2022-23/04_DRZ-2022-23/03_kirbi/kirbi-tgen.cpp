#include <bits/stdc++.h>
using namespace std;

#define int ll
typedef long long ll;
const string folder="testcases1\\";

typedef pair<int, int> pi;
typedef vector<int> vi;

mt19937 rng(time(0));

const int maxx = 1e9;

int get_int_from_range(int l,int r){
    assert(l<=r);
    return l+rng()%(r-l+1);
}

void save_test_case(int tc,int t,vector<int> n, vector<int> m, vector<int> p, vector<vector<pair<int, int>>> a){
    ofstream out(folder+to_string(tc)+".in");
    out << t << endl;
    for(int tp = 0; tp < t; tp++){
        out << n[tp] << ' ' << m[tp] << ' ' << p[tp] << endl;
        for(int i=0;i<p[tp];i++){
            out << a[tp][i].first << ' ' << a[tp][i].second << endl;
        }
    }
    out.close();
}
void generate_subtask_1(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n, m, p;
        vector<vector<pair<int, int>>> a;
        
        for(int tp=0;tp<t;tp++)
        {
            set<pi> ss;
            int nt = get_int_from_range(5,5);
            int mt = get_int_from_range(4,5);
            int pt = get_int_from_range(1,nt*mt); 
            vector<pair<int, int>> ta;
            for(int i=0;i<pt;i++){
                pi tmp = {get_int_from_range(1,nt), get_int_from_range(1,mt)};
                if (ss.count(tmp)){--i; continue;}
                ss.insert(tmp);
                ta.push_back(tmp);
            }
            n.push_back(nt);
            m.push_back(mt);
            p.push_back(pt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,m,p,a);
    }
}

void generate_subtask_2(int l,int r,int g){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n, m, p;
        vector<vector<pair<int, int>>> a;
        
        for(int tp=0;tp<t;tp++)
        {
            set<pi> ss;
            int nt = 1e9 - get_int_from_range(0,10);
            int mt = 1e9 - get_int_from_range(0,10);
            int pt = get_int_from_range(g, 200000);

            if (tp % 2)
                nt = 2;
            else
                mt = 2;

            vector<pair<int, int>> ta;
            for(int i=0;i<pt;i++){
                pi tmp = {get_int_from_range(1,nt), get_int_from_range(1,mt)};
                if (ss.count(tmp)) {--i; continue;}
                ta.push_back(tmp);
                ss.insert(tmp);
            }
            n.push_back(nt);
            m.push_back(mt);
            p.push_back(pt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,m,p,a);
    }
}

void generate_subtask_3(int l,int r,int g){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n, m, p;
        vector<vector<pair<int, int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            set<pi> ss;
            int nt = get_int_from_range(90,100);
            int mt = get_int_from_range(90,100);
            int pt = get_int_from_range(1, min((nt*mt)/g, 100ll));

            vector<pair<int, int>> ta;
            for(int i=0;i<pt;i++){
                pi tmp = {get_int_from_range(1,nt), get_int_from_range(1,mt)};
                if (ss.count(tmp)) {--i; continue;}
                ss.insert(tmp);
                ta.push_back(tmp);
            }
            n.push_back(nt);
            m.push_back(mt);
            p.push_back(pt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,m,p,a);
    }
}


void generate_subtask_4(int l,int r,int g){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10;
        vi n, m, p;
        vector<vector<pair<int, int>>> a;
        
        for(int tp=0;tp<t;tp++)
        {
            set<pi> ss;
            int nt = 1e9-get_int_from_range(0,100);
            int mt = 1e9-get_int_from_range(0,100);
            int pt = get_int_from_range(g, 200000);

            vector<pair<int, int>> ta;
            for(int i=0;i<pt;i++){
                pi tmp = {get_int_from_range(1,nt), get_int_from_range(1,mt)};
                if (ss.count(tmp)){--i; continue;}
                ss.insert(tmp);
                ta.push_back(tmp);
            }
            n.push_back(nt);
            m.push_back(mt);
            p.push_back(pt);
            a.push_back(ta);
        }
        save_test_case(tc,t,n,m,p,a);
    }
}

signed main(){
    generate_subtask_1(3,4);
    generate_subtask_2(5,8,1);
    generate_subtask_2(9,11,190000);
    generate_subtask_3(12,14,1);
    generate_subtask_3(15,17,2);
    generate_subtask_4(18,19,1);
    generate_subtask_4(20,21,190000);

    return 0;
}