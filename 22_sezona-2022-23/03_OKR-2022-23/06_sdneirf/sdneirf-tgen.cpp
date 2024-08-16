#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
void save_test_case(int tc,int n,int m,vector<vector<int>> mat){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" "<<m;
	for(int i=0;i<n;i++)
    {
        out<<"\n";
        for(int j=0;j<m;j++)
        {
            out<<mat[i][j];
            if(j+1!=m) out<<" ";
        }
    }
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=2;
		int m=2;
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000000));
            mat.push_back(tmp);
        }
		save_test_case(tc,n,m,mat);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=1;
		int m=get_int_from_range(1400,1500);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000000));
            mat.push_back(tmp);
        }
		save_test_case(tc,n,m,mat);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=2;
		int m=get_int_from_range(1400,1500);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000000));
            mat.push_back(tmp);
        }
		save_test_case(tc,n,m,mat);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1));
            mat.push_back(tmp);
        }
		save_test_case(tc,n,m,mat);
	}
}
void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int n=get_int_from_range(1400,1500);
		int m=get_int_from_range(1400,1500);
		vector<vector<int>> mat;
		for(int i=0;i<n;i++)
        {
            vector<int> tmp;
            for(int j=0;j<m;j++) tmp.push_back(get_int_from_range(0,1000000000));
            mat.push_back(tmp);
        }
		save_test_case(tc,n,m,mat);
	}
}
int main(){
	generate_subtask_1(3,4);
	generate_subtask_2(5,6);
	generate_subtask_3(7,10);
	generate_subtask_4(11,16);
	generate_subtask_5(17,22);
	return 0;
}
