#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";

mt19937 rng(time(0));
set<int> se;
int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
vector<int> generate_random_array(int l,int r,int a)
{
    assert(a<=r-l+1);
    vector<int> v;
    se.clear();
    while(se.size()<a)
    {
        int x=get_int_from_range(l,r);
        se.insert(x);
    }
    for(auto it:se) v.push_back(it);
    shuffle(v.begin(),v.end(),rng);
    return v;
}
void save_test_case(int tc,int n,vector<int> x, vector<int> y){
	ofstream out(folder+to_string(tc)+".in");
	out<<n;
	for(int i=0;i<n;i++) out<<"\n"<<x[i]<<" "<<y[i];
	out.close();
}
void generate_subtask_1(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int box=10;
        int n=get_int_from_range(6,7);
        vector<int> x=generate_random_array(1,box,n),y=generate_random_array(1,box,n);
        while(true)
        {
            vector<int> xn=generate_random_array(box+22,2*box+21,n),yn=generate_random_array(box+22,2*box+21,n);
            xn.push_back(box+11); yn.push_back(box+11);
            int k=get_int_from_range(0,n-1);
            swap(xn[k],xn[n]); swap(yn[k],yn[n]);
            n=2*n+1;
            if(n>500) n=500;
            for(int i=0;x.size()<n;i++) x.push_back(xn[i]);
            for(int i=0;y.size()<n;i++) y.push_back(yn[i]);
            int np=get_int_from_range(6,7);
            n=n+2*np;
            if(n>500) n=500;
            vector<int> xa=generate_random_array(box+1,box+10,np),ya=generate_random_array(box+12,box+21,np);
            vector<int> xb=generate_random_array(box+12,box+21,np),yb=generate_random_array(box+1,box+10,np);
            vector<pair<int,int>> p;
            for(int i=0;i<np;i++) p.push_back({xa[i],ya[i]});
            for(int i=0;i<np;i++) p.push_back({xb[i],yb[i]});
            shuffle(p.begin(),p.end(),rng);
            for(int i=0;x.size()<n;i++) {x.push_back(p[i].first); y.push_back(p[i].second);}
            box=2*box+21;
            if(n>480) break;
        }
        save_test_case(tc,n,x,y);
    }
}
void generate_subtask_2(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int n=get_int_from_range(190000,200000);
        vector<int> x=generate_random_array(1,1000000000,n);
        save_test_case(tc,n,x,x);
    }
}
void generate_subtask_3(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int box=30;
        int n=get_int_from_range(18,21);
        vector<int> x=generate_random_array(1,box,n),y=generate_random_array(1,box,n);
        while(true)
        {
            vector<int> xn=generate_random_array(box+62,2*box+61,n),yn=generate_random_array(box+62,2*box+61,n);
            xn.push_back(box+31); yn.push_back(box+31);
            int k=get_int_from_range(0,n-1);
            swap(xn[k],xn[n]); swap(yn[k],yn[n]);
            n=2*n+1;
            if(n>4000) n=4000;
            for(int i=0;x.size()<n;i++) x.push_back(xn[i]);
            for(int i=0;y.size()<n;i++) y.push_back(yn[i]);
            int np=get_int_from_range(18,21);
            n=n+2*np;
            if(n>4000) n=4000;
            vector<int> xa=generate_random_array(box+1,box+30,np),ya=generate_random_array(box+32,box+61,np);
            vector<int> xb=generate_random_array(box+32,box+61,np),yb=generate_random_array(box+1,box+30,np);
            vector<pair<int,int>> p;
            for(int i=0;i<np;i++) p.push_back({xa[i],ya[i]});
            for(int i=0;i<np;i++) p.push_back({xb[i],yb[i]});
            shuffle(p.begin(),p.end(),rng);
            for(int i=0;x.size()<n;i++) {x.push_back(p[i].first); y.push_back(p[i].second);}
            box=2*box+61;
            if(n>3800) break;
        }
        save_test_case(tc,n,x,y);
    }
}
void generate_subtask_4(int l,int r){
    for(int tc=l;tc<=r;tc++)
    {
        int box=100;
        int n=get_int_from_range(60,70);
        vector<int> x=generate_random_array(1,box,n),y=generate_random_array(1,box,n);
        while(true)
        {
            vector<int> xn=generate_random_array(box+202,2*box+201,n),yn=generate_random_array(box+202,2*box+201,n);
            xn.push_back(box+101); yn.push_back(box+101);
            int k=get_int_from_range(0,n-1);
            swap(xn[k],xn[n]); swap(yn[k],yn[n]);
            n=2*n+1;
            if(n>200000) n=200000;
            for(int i=0;x.size()<n;i++) x.push_back(xn[i]);
            for(int i=0;y.size()<n;i++) y.push_back(yn[i]);
            int np=get_int_from_range(60,70);
            n=n+2*np;
            if(n>200000) n=200000;
            vector<int> xa=generate_random_array(box+1,box+100,np),ya=generate_random_array(box+102,box+201,np);
            vector<int> xb=generate_random_array(box+102,box+201,np),yb=generate_random_array(box+1,box+100,np);
            vector<pair<int,int>> p;
            for(int i=0;i<np;i++) p.push_back({xa[i],ya[i]});
            for(int i=0;i<np;i++) p.push_back({xb[i],yb[i]});
            shuffle(p.begin(),p.end(),rng);
            for(int i=0;x.size()<n;i++) {x.push_back(p[i].first); y.push_back(p[i].second);}
            box=2*box+201;
            if(n>180000) break;
        }
        save_test_case(tc,n,x,y);
    }
}
int main(){
	generate_subtask_1(3,7);
	generate_subtask_2(8,13);
	generate_subtask_3(14,19);
	generate_subtask_4(20,28);
	return 0;
}
