#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
pair<pair<int,int>,int> generate_query(int n,int m,int maxK)
{
    return {{get_int_from_range(1,n),get_int_from_range(1,m)},get_int_from_range(0,maxK)};
}
pair<pair<int,int>,int> generate_sus_x_query(int x,int n,int m,int maxK)
{
    return {{x+1,get_int_from_range(1,m)},get_int_from_range(0,maxK)};
}
pair<pair<int,int>,int> generate_sus_y_query(int y,int n,int m,int maxK)
{
    return {{get_int_from_range(1,n),y+1},get_int_from_range(0,maxK)};
}
void save_test_case(int tc,int n,int m,int q,vector<vector<int>> mat, vector<pair<pair<int,int>,int>> queries){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<m<<" "<<q;
	for(int i=0;i<n;i++)
    {
        out<<"\n";
        for(int j=0;j<m;j++)
        {
            out<<mat[i][j];
            if(j+1!=m) out<<" ";
        }

    }
    for(int i=0;i<q;i++) out<<"\n"<<queries[i].first.first<<" "<<queries[i].first.second<<" "<<queries[i].second;
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(4,5);
		int m=get_int_from_range(5,5);
		int q=get_int_from_range(195000,200000);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1));
            mat.push_back(tmp);
        }
        int maxK=1000000;
		vector<pair<pair<int,int>,int>> queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,m,maxK));
		save_test_case(tc,n,m,q,mat,queries);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		int q=get_int_from_range(195000,200000);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000));
            mat.push_back(tmp);
        }
        int maxK=5;
		vector<pair<pair<int,int>,int>> queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,m,maxK));
        save_test_case(tc,n,m,q,mat,queries);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		int q=get_int_from_range(195000,200000);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000));
            mat.push_back(tmp);
        }
        int maxK=200;
		vector<pair<pair<int,int>,int>> queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,m,maxK));
		save_test_case(tc,n,m,q,mat,queries);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		int q=get_int_from_range(195000,200000);
		vector<vector<int>> mat;
		int x=get_int_from_range(0,n-1);
		int y=get_int_from_range(0,m-1);
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++)
            {
                if(i==x && j==y) tmp.push_back(1);
                else tmp.push_back(0);
            }
            mat.push_back(tmp);
        }
        int maxK=100000;
		vector<pair<pair<int,int>,int>> queries;
		for(int i=0;i<q;i++)
        {
            int k=get_int_from_range(0,2);
            if(k==0) queries.push_back(generate_query(n,m,maxK));
            if(k==1) queries.push_back(generate_sus_x_query(x,n,m,maxK));
            if(k==2) queries.push_back(generate_sus_y_query(y,n,m,maxK));
        }
		save_test_case(tc,n,m,q,mat,queries);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		int q=get_int_from_range(95000,300000);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000));
            mat.push_back(tmp);
        }
        int maxK=1000000;
		vector<pair<pair<int,int>,int>> queries;
		for(int i=0;i<q;i++) queries.push_back(generate_query(n,m,maxK));
		save_test_case(tc,n,m,q,mat,queries);
	}
}
int main(){
	generate_subtask_1(2,2);
	generate_subtask_2(3,3);
	generate_subtask_3(4,5);
	generate_subtask_4(6,8);
	generate_subtask_5(9,11);
	generate_subtask_1(12,12);
	generate_subtask_2(13,13);
	generate_subtask_3(14,15);
	generate_subtask_4(16,18);
	generate_subtask_5(19,21);
	return 0;
}
