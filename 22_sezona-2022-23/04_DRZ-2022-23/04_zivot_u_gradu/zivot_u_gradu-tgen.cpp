#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";

mt19937 rng(time(0));
set<int> se;
int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
void save_test_case(int tc,int t,int z,vector<int> n, vector<int> m, vector<int> k,vector<vector<vector<int>>> a){
	ofstream out(folder+to_string(tc)+".in");
	out<<t<<" "<<z<<endl;
	for(int tp=0;tp<t;tp++)
    {
        out<<n[tp]<<" "<<m[tp]<<" "<<k[tp];
        for(int i=0;i<n[tp];i++)
        {
            out<<"\n";
            for(int j=0;j<m[tp];j++) out<<a[tp][i][j];
        }
        if(tp+1!=t) out<<"\n";
    }
	out.close();
}
void generate_subtask_1(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=1;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(9,10),mt=get_int_from_range(9,10),kt;
            vector<vector<int>> ta;
            for(int i=0;i<nt;i++)
            {
                vector<int> row;
                for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                ta.push_back(row);
            }
            kt=get_int_from_range(0,20);
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_2(int l,int r){
    int t=10,z=0;
    for(int tc=l;tc<=r;tc++)
    {
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1490,1500),mt=get_int_from_range(1490,1500),kt;
            int cs=get_int_from_range(1,4),mn,mx,l,r,u,d;
            vector<vector<int>> ta;
            for(int i=0;i<nt;i++)
            {
                vector<int> row;
                for(int j=0;j<mt;j++) row.push_back(0);
                ta.push_back(row);
            }
            if(cs==1)
            {
                l=get_int_from_range(1,nt);
                r=get_int_from_range(1,nt);
                u=get_int_from_range(1,mt);
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=0, mx=r-l+d-u-1;
            }
            if(cs==2)
            {

                l=get_int_from_range(1,nt);
                r=get_int_from_range(1,nt);
                u=1;
                d=mt;
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=r-l+1, mx=r-l+d-u+1;
            }
            if(cs==3)
            {

                l=1;
                r=nt;
                u=get_int_from_range(1,mt);
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=d-u+1, mx=r-l+d-u+1;
            }
            if(cs==4)
            {

                l=1;
                r=get_int_from_range(1,nt);
                u=1;
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=min(r,d), mx=r-l+d-u+1;
            }
            for(int i=l-1;i<r;i++) for(int j=u-1;j<d;j++) ta[i][j]=1;
            if(cs==1)
            {
                if(get_int_from_range(0,1)) kt=get_int_from_range(0,mx);
                else kt=get_int_from_range(mx,3000);
            }
            else
            {
                int pom=get_int_from_range(0,2);
                if(pom==0) kt=get_int_from_range(0,mn);
                if(pom==1) kt=get_int_from_range(mn,mx);
                if(pom==2) kt=get_int_from_range(mx,3000);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}

void generate_subtask_3(int l,int r){
    int t=10,z=1;
    for(int tc=l;tc<=r;tc++)
    {
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1490,1500),mt=get_int_from_range(1490,1500),kt;
            int cs=get_int_from_range(1,4),mn,mx,l,r,u,d;
            vector<vector<int>> ta;
            for(int i=0;i<nt;i++)
            {
                vector<int> row;
                for(int j=0;j<mt;j++) row.push_back(0);
                ta.push_back(row);
            }
            if(cs==1)
            {
                l=get_int_from_range(1,nt);
                r=get_int_from_range(1,nt);
                u=get_int_from_range(1,mt);
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=0, mx=r-l+d-u-1;
            }
            if(cs==2)
            {

                l=get_int_from_range(1,nt);
                r=get_int_from_range(1,nt);
                u=1;
                d=mt;
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=r-l+1, mx=r-l+d-u+1;
            }
            if(cs==3)
            {

                l=1;
                r=nt;
                u=get_int_from_range(1,mt);
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=d-u+1, mx=r-l+d-u+1;
            }
            if(cs==4)
            {

                l=1;
                r=get_int_from_range(1,nt);
                u=1;
                d=get_int_from_range(1,mt);
                if(l>r) swap(l,r);
                if(u>d) swap(u,d);
                mn=min(r,d), mx=r-l+d-u+1;
            }
            for(int i=l-1;i<r;i++) for(int j=u-1;j<d;j++) ta[i][j]=1;
            if(cs==1)
            {
                if(get_int_from_range(0,1)) kt=get_int_from_range(0,mx);
                else kt=get_int_from_range(mx,3000);
            }
            else
            {
                int pom=get_int_from_range(0,2);
                if(pom==0) kt=get_int_from_range(0,mn);
                if(pom==1) kt=get_int_from_range(mn,mx);
                if(pom==2) kt=get_int_from_range(mx,3000);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_4(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=0;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(145,150),mt=get_int_from_range(145,150),kt;
            int cs=get_int_from_range(1,3);
            vector<vector<int>> ta;
            if(cs==1)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
                kt=get_int_from_range(0,300);
            }
            if(cs==2)
            {
                int all=get_int_from_range(0,1);
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(all);
                    ta.push_back(row);
                }
                for(int i=0;i<20;i++)
                {
                    int x=get_int_from_range(1,nt);
                    int y=get_int_from_range(1,mt);
                    ta[x-1][y-1]^=1;
                }
                if(all==0) kt=get_int_from_range(0,10);
                if(all==1) kt=get_int_from_range(nt+mt-12,nt+mt-2);
            }
            if(cs==3)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++)
                    {
                        if(i==j) row.push_back(1);
                        else row.push_back((get_int_from_range(0,1)+1)/20);
                    }
                    ta.push_back(row);
                }
                kt=get_int_from_range(120,220);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_5(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=1;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(145,150),mt=get_int_from_range(145,150),kt;
            int cs=get_int_from_range(1,3);
            vector<vector<int>> ta;
            if(cs==1)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
                kt=get_int_from_range(0,300);
            }
            if(cs==2)
            {
                int all=get_int_from_range(0,1);
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(all);
                    ta.push_back(row);
                }
                for(int i=0;i<20;i++)
                {
                    int x=get_int_from_range(1,nt);
                    int y=get_int_from_range(1,mt);
                    ta[x-1][y-1]^=1;
                }
                if(all==0) kt=get_int_from_range(0,10);
                if(all==1) kt=get_int_from_range(nt+mt-12,nt+mt-2);
            }
            if(cs==3)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++)
                    {
                        if(i==j) row.push_back(1);
                        else row.push_back((get_int_from_range(0,1)+1)/20);
                    }
                    ta.push_back(row);
                }
                kt=get_int_from_range(120,220);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_6(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=1;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(990,1000),mt=get_int_from_range(990,1000),kt=0;
            vector<vector<int>> ta;
            int cs=get_int_from_range(0,1);
            if(cs)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
                vector<int> pp;
                for(int i=0;i<nt-1;i++) pp.push_back(0);
                for(int i=0;i<mt-1;i++) pp.push_back(1);
                shuffle(pp.begin(),pp.end(),rng);
                int xtr=0,ytr=0;
                for(int i=0;i<nt+mt-2;i++)
                {
                    ta[xtr][ytr]=0;
                    if(pp[i]==0) xtr++;
                    else ytr++;
                }
                ta[nt-1][mt-1]=0;
            }
            else
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_7(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=0;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1490,1500),mt=get_int_from_range(1490,1500),kt;
            int cs=get_int_from_range(1,3);
            vector<vector<int>> ta;
            if(cs==1)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
                kt=get_int_from_range(0,3000);
            }
            if(cs==2)
            {
                int all=get_int_from_range(0,1);
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(all);
                    ta.push_back(row);
                }
                for(int i=0;i<100;i++)
                {
                    int x=get_int_from_range(1,nt);
                    int y=get_int_from_range(1,mt);
                    ta[x-1][y-1]^=1;
                }
                if(all==0) kt=get_int_from_range(0,30);
                if(all==1) kt=get_int_from_range(nt+mt-32,nt+mt-2);
            }
            if(cs==3)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++)
                    {
                        if(i==j) row.push_back(1);
                        else row.push_back((get_int_from_range(0,19)+1)/20);
                    }
                    ta.push_back(row);
                }
                kt=get_int_from_range(1250,1900);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
void generate_subtask_8(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int t=10,z=1;
        vector<int> n,m,k;
        vector<vector<vector<int>>> a;
        for(int tp=0;tp<t;tp++)
        {
            int nt=get_int_from_range(1490,1500),mt=get_int_from_range(1490,1500),kt;
            int cs=get_int_from_range(1,3);
            vector<vector<int>> ta;
            if(cs==1)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(get_int_from_range(0,1));
                    ta.push_back(row);
                }
                kt=get_int_from_range(0,3000);
            }
            if(cs==2)
            {
                int all=get_int_from_range(0,1);
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++) row.push_back(all);
                    ta.push_back(row);
                }
                for(int i=0;i<100;i++)
                {
                    int x=get_int_from_range(1,nt);
                    int y=get_int_from_range(1,mt);
                    ta[x-1][y-1]^=1;
                }
                if(all==0) kt=get_int_from_range(0,30);
                if(all==1) kt=get_int_from_range(nt+mt-32,nt+mt-2);
            }
            if(cs==3)
            {
                for(int i=0;i<nt;i++)
                {
                    vector<int> row;
                    for(int j=0;j<mt;j++)
                    {
                        if(i==j) row.push_back(1);
                        else row.push_back((get_int_from_range(0,19)+1)/20);
                    }
                    ta.push_back(row);
                }
                kt=get_int_from_range(1250,1900);
            }
            n.push_back(nt);
            m.push_back(mt);
            k.push_back(kt);
            a.push_back(ta);
        }
        save_test_case(tc,t,z,n,m,k,a);
    }
}
int main(){
	generate_subtask_1(2,3);
	generate_subtask_2(4,6);
	generate_subtask_3(7,9);
	generate_subtask_4(10,13);
	generate_subtask_5(14,17);
	generate_subtask_6(18,21);
	generate_subtask_7(22,27);
	generate_subtask_8(28,34);
	return 0;
}
