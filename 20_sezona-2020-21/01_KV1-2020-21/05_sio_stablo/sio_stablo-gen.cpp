#include <bits/stdc++.h>
using namespace std;

const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}

template<typename T> T get_from_array(vector<T> options){
	assert(!options.empty());
	return options[get_int_from_range(0,(int)options.size()-1)];
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

vector<char> generate_labels(int n){
	vector<char> labels(n);
	for(char&c:labels)c=get_from_array<char>({'S','I','O'});
	return labels;
}


vector<char> generate_labels_one_S(int n){
	vector<char> labels(n);
	int idx=get_int_from_range(0,n-1);
	labels[idx]='S';
	for(int i=0;i<n;i++)if(i!=idx)labels[i]=get_from_array<char>({'I','O'});
	return labels;
}

void save_test_case(int tc,int n,vector<pair<int,int>> edges,vector<char> labels){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<"\n";
	assert(edges.size()==n-1);
	assert(labels.size()==n-1);
	for(int i=0;i<n-1;i++){
		out<<edges[i].first<<" "<<edges[i].second<<" "<<labels[i]<<"\n";
	}
	out.close();
}

void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(270000,300000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<char> labels=generate_labels_one_S(n-1);
		save_test_case(tc,n,edges,labels);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(900,1000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<char> labels=generate_labels(n-1);
		save_test_case(tc,n,edges,labels);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(270000,300000);
		vector<pair<int,int>> edges;
		for(int i=1;i<n;i++)edges.push_back({i,i+1});
		vector<char> labels=generate_labels(n-1);
		save_test_case(tc,n,edges,labels);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(270000,300000);
		vector<pair<int,int>> edges;
		for(int i=2;i<=n;i++)edges.push_back({i,i/2});
		vector<char> labels=generate_labels(n-1);
		save_test_case(tc,n,edges,labels);
	}
}

void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(270000,300000);
		vector<pair<int,int>> edges=generate_tree(n);
		vector<char> labels=generate_labels(n-1);
		save_test_case(tc,n,edges,labels);
	}
}

int main(){
	generate_subtask_1(2,3);
	generate_subtask_2(4,6);
	generate_subtask_3(7,11);
	generate_subtask_4(12,16);
	generate_subtask_5(17,26);
	return 0;
}
