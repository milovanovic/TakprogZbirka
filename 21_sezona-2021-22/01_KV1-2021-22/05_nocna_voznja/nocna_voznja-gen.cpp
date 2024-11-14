#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}

vector<pair<int,int>> generate_tree(int n){
	vector<int> prufer_code(n-2),deg(n,1);
	for(int&i:prufer_code)i=rng()%n,deg[i]++;
	set<int> leaf;
	for(int i=0;i<n;i++)if(deg[i]==1)leaf.insert(i);
	vector<pair<int,int>> edges;
	for(int i:prufer_code){
		int j=*leaf.begin();
		leaf.erase(j);
		if(rng()&1)edges.push_back({i+1,j+1});
		else edges.push_back({j+1,i+1});
		deg[i]--;
		if(deg[i]==1)leaf.insert(i);
	}
	if(rng()&1)edges.push_back({*leaf.begin()+1,n});
	else edges.push_back({n,*leaf.begin()+1});
	shuffle(edges.begin(),edges.end(),rng);
	return edges;
}

vector<int> generate_perm(int n){
	vector<int> perm;
	for(int i=0;i<n;i++) perm.push_back(i+1);
	shuffle(perm.begin(),perm.end(),rng);
	return perm;
}
vector<int> generate_swap(int n,int x)
{
    int a=0,b=0;
    while(a==b || a==x || b==x)
    {
        a=get_int_from_range(1,n);
        b=get_int_from_range(1,n);
    }
    vector<int> v; v.push_back(1); v.push_back(a); v.push_back(b);
    return v;
}
vector<int> generate_any_interval(int n,int x)
{
    int l=0,r=-1;
    while(l>r)
    {
        l=get_int_from_range(1,n);
        r=get_int_from_range(1,n);
    }
    if(!x) x=get_int_from_range(1,n);
    vector<int> v; v.push_back(2); v.push_back(l); v.push_back(r); v.push_back(x);
    return v;
}
vector<int> generate_short_interval(int n,int x)
{
    int l=0,r=-1;
    while(l>r)
    {
        l=get_int_from_range(1,n);
        r=get_int_from_range(l,min(l+20,n));
    }
    if(!x) x=get_int_from_range(1,n);
    vector<int> v; v.push_back(2); v.push_back(l); v.push_back(r); v.push_back(x);
    return v;
}
vector<int> generate_interval(int n,int x)
{
    if(rng()%10) return generate_short_interval(n,x);
    else return generate_any_interval(n,x);
}
vector<int> generate_query(int n,int x)
{
    if(rng()&1) return generate_swap(n,x);
    return generate_interval(n,x);
}
void save_test_case(int tc,int n,vector<int> perm,vector<pair<int,int>> edges,int q,vector<vector<int> >  queries){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<"\n";
	assert(edges.size()==n-1);
	assert(perm.size()==n);
	for(int i=0;i<n;i++) out<<perm[i]<<" ";
	out<<"\n";
	for(int i=0;i<n-1;i++){
		out<<edges[i].first<<" "<<edges[i].second<<"\n";
	}
	out<<q<<"\n";
	assert(queries.size()==q);
	for(int i=0;i<q;i++)
    {
        for(int j=0;j<queries[i].size();j++) out<<queries[i][j]<<" ";
        out<<"\n";
    }
	out.close();
}

void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(3600,4000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<int> perm=generate_perm(n);
		int q=get_int_from_range(3600,4000);
		vector<vector<int> > queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,0));
		save_test_case(tc,n,perm,edges,q,queries);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(70000,80000);
		vector<pair<int,int>> edges;
		vector<int> perm=generate_perm(n),permara=generate_perm(n);
		for(int i=0;i<n-1;i++)
        {
            if(rng()&1) edges.push_back({permara[i],permara[i+1]});
            else edges.push_back({permara[i+1],permara[i]});
        }
        shuffle(edges.begin(),edges.end(),rng);
		int q=get_int_from_range(70000,80000);
		vector<vector<int> > queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,0));
		save_test_case(tc,n,perm,edges,q,queries);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(70000,80000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<int> perm=generate_perm(n);
		int q=get_int_from_range(70000,80000);
		vector<vector<int> > queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,1));
		save_test_case(tc,n,perm,edges,q,queries);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(70000,80000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<int> perm=generate_perm(n);
		int q=get_int_from_range(70000,80000);
		vector<vector<int> > queries;
		for(int i=0;i<q;i++) queries.push_back(generate_interval(n,0));
		save_test_case(tc,n,perm,edges,q,queries);
	}
}

void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(70000,80000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<int> perm=generate_perm(n);
		int q=get_int_from_range(70000,80000);
		vector<vector<int> > queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,0));
		save_test_case(tc,n,perm,edges,q,queries);
	}
}

int main(){
	generate_subtask_1(2,3);
	generate_subtask_2(4,6);
	generate_subtask_3(7,11);
	generate_subtask_4(12,16);
	generate_subtask_5(17,21);
	return 0;
}
