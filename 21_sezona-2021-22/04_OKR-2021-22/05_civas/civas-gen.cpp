#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
vector<int> generate_array(int n)
{
    vector<int> v(n);
    for(int i=0;i<=n/2;i++) v[i]=get_int_from_range(0,(1<<30)-1);
    for(int i=1;i<n/2;i++) v[i+n/2]=v[i-1+n/2]^v[i]^v[i-1];
    return v;
}
vector<int> generate_const_array(int n)
{
    vector<int> v(n);
    for(int i=0;i<=n/2;i++) v[i]=get_int_from_range(0,(1<<30)-1);
    for(int i=1;i<n/2;i++) v[i]=v[i-1];
    for(int i=1;i<n/2;i++) v[i+n/2]=v[i-1+n/2]^v[i]^v[i-1];
    assert(v[0]!=v[n/2]);
    return v;
}
void save_test_case(int tc,int n,int q,vector<int> a, vector<pair<int,int>> queries){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++) out<<a[i]<<" ";
    for(int i=0;i<q;i++) out<<"\n"<<queries[i].first<<" "<<queries[i].second;
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(240,250)*2;
		int maxq=500,q=0;
		vector<int> a=generate_array(n);
		vector<int> b=a;
		vector<pair<int,int> > queries;
		while(q+20<maxq)
        {
            int k=get_int_from_range(8,10);
            vector<pair<int,int>> tq;
            for(int i=0;i<k;i++)
            {
                int r=get_int_from_range(0,n/2-1);
                int x=get_int_from_range(0,(1<<30)-1);
                tq.push_back({r,x});
                tq.push_back({r+n/2,x});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            q+=2*k;
        }
		save_test_case(tc,n,q,a,queries);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(99980,100000)*2;
		int maxq=25,q=0;
		vector<int> a=generate_array(n);
		vector<int> b=a;
		vector<pair<int,int> > queries;
		while(q+6<maxq)
        {
            int k=get_int_from_range(2,3);
            vector<pair<int,int>> tq;
            for(int i=0;i<k;i++)
            {
                int r=get_int_from_range(0,n/2-1);
                int x=get_int_from_range(0,(1<<30)-1);
                tq.push_back({r,x});
                tq.push_back({r+n/2,x});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            q+=2*k;
        }
		save_test_case(tc,n,q,a,queries);
	}
}
void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(38,43)*4620;
		int maxq=3000,q=0;
		vector<int> a=generate_const_array(n);
		vector<int> b=a;
		vector<pair<int,int> > queries;
		while(q+20<maxq/2)
        {
            int k=get_int_from_range(8,10);
            vector<pair<int,int>> tq;
            for(int i=0;i<k;i++)
            {
                int r=get_int_from_range(0,n/2-1);
                int x=get_int_from_range(0,(1<<30)-1);
                tq.push_back({r,x});
                tq.push_back({r+n/2,x});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            q+=4*k;
        }
        while(q+20<maxq)
        {
            int k=get_int_from_range(8,10);
            vector<pair<int,int>> tq;
            for(int i=0;i<k;i++)
            {
                int r=get_int_from_range(0,n/2-1);
                int x=get_int_from_range(0,(1<<30)-1);
                tq.push_back({r,x});
                tq.push_back({r+n/2,x});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            q+=2*k;
        }
		save_test_case(tc,n,q,a,queries);
	}
}
void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(38,43)*4620;
		int maxq=200000,q=0;
		vector<int> a=generate_array(n);
		if(get_int_from_range(0,1)==0) a=generate_const_array(n);
		vector<int> b=a;
		vector<pair<int,int> > queries;
		while(q+20<maxq)
        {
            int k=get_int_from_range(8,10);
            vector<pair<int,int>> tq;
            for(int i=0;i<k;i++)
            {
                int r=get_int_from_range(0,n/2-1);
                int x=get_int_from_range(0,(1<<30)-1);
                tq.push_back({r,x});
                tq.push_back({r+n/2,x});
            }
            shuffle(tq.begin(),tq.end(),rng);
            for(int i=0;i<2*k;i++)
            {
                b[tq[i].first]^=tq[i].second;
                queries.push_back({tq[i].first+1,b[tq[i].first]});
            }
            q+=2*k;
        }
		save_test_case(tc,n,q,a,queries);
	}
}
int main(){
	generate_subtask_1(3,4);
	generate_subtask_2(5,8);
	generate_subtask_3(9,14);
	generate_subtask_4(15,22);
	return 0;
}
