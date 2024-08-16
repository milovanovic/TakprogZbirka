#include <bits/stdc++.h>
using namespace std;
//"Pozajmljeno" od Tadije Sebeza
const string folder="testcases\\";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return l+rng()%(r-l+1);
}
void save_test_case(int tc,int t,vector<int> n,vector<vector<int>> a,vector<vector<int>> b){
	ofstream out(folder+to_string(tc)+".in");
	out<<t;
	for(int i=0;i<t;i++)
    {
        out<<"\n"<<n[i]<<"\n";
        for(int j=0;j<n[i];j++)
        {
            out<<a[i][j];
            if(j+1!=n[i]) out<<" ";
        }
        out<<"\n";
        for(int j=0;j<n[i];j++)
        {
            out<<b[i][j];
            if(j+1!=n[i]) out<<" ";
        }
    }
	out.close();
}
void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<int> n;
		vector<vector<int>> a,b;
		for(int i=0;i<t;i++)
        {
            n.push_back(get_int_from_range(29000,30000));
            vector<int> ta,tb;
            int x=get_int_from_range(-1000000000,1000000000);
            ta.push_back(x);
            if(get_int_from_range(0,1))
            {
                if(get_int_from_range(0,1)) tb.push_back(get_int_from_range(-1000000000,1000000000));
                else tb.push_back(-x);
            }
            else tb.push_back(x);
            for(int j=1;j<n[i];j++) ta.push_back(0);
            for(int j=1;j<n[i];j++) tb.push_back(0);
            shuffle(ta.begin(),ta.end(),rng);
            shuffle(tb.begin(),tb.end(),rng);
            for(int j=0;j<n[i];j++) ta[j]*=(1-2*(j&1));
            for(int j=0;j<n[i];j++) tb[j]*=(1-2*(j&1));
            a.push_back(ta);
            b.push_back(tb);
        }
		save_test_case(tc,t,n,a,b);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<int> n;
		vector<vector<int>> a,b;
		for(int i=0;i<t;i++)
        {
            n.push_back(get_int_from_range(29000,30000));
            vector<int> ta,tb;
            for(int j=0;j<n[i];j++)
            {
                int x=2*get_int_from_range(0,1)-1;
                ta.push_back(x);
                tb.push_back(x);
            }
            shuffle(ta.begin(),ta.end(),rng);
            shuffle(tb.begin(),tb.end(),rng);
            for(int j=0;j<n[i];j++) ta[j]*=(1-2*(j&1));
            for(int j=0;j<n[i];j++) tb[j]*=(1-2*(j&1));
            if(get_int_from_range(0,1))
            {
                for(int j=0;j<10;j++)
                {
                    int x=get_int_from_range(0,n[i]-1);
                    tb[x]=-tb[x];
                }
            }
            a.push_back(ta);
            b.push_back(tb);
        }
		save_test_case(tc,t,n,a,b);
	}
}

map<int,bool> mp;
void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<int> n;
		vector<vector<int>> a,b;
		for(int i=0;i<t;i++)
        {
            n.push_back(get_int_from_range(29000,30000));
            vector<int> ta,tb;
            mp.clear();
            for(int j=0;j<n[i];j++)
            {
                int x=get_int_from_range(-1000000000,1000000000);
                while(mp[abs(x)]) x=get_int_from_range(-1000000000,1000000000);
                mp[abs(x)]=true;
                ta.push_back(x);
                tb.push_back(x);
            }
            shuffle(ta.begin(),ta.end(),rng);
            shuffle(tb.begin(),tb.end(),rng);
            for(int j=0;j<n[i];j++) ta[j]*=(1-2*(j&1));
            for(int j=0;j<n[i];j++) tb[j]*=(1-2*(j&1));
            if(get_int_from_range(0,1))
            {
                if(get_int_from_range(0,2))
                {
                    for(int j=0;j<10;j++)
                    {
                        int x=get_int_from_range(-1000000000,1000000000);
                        while(mp[abs(x)]) x=get_int_from_range(-1000000000,1000000000);
                        mp[abs(x)]=true;
                        int y=get_int_from_range(0,n[i]-1);
                        if((tb[y]>0 && x<0) || (tb[y]<0 && x>0)) tb[y]=-x;
                        else tb[y]=x;
                    }
                }
                else
                {
                    for(int j=0;j<10;j++)
                    {
                        int x=get_int_from_range(0,n[i]-1);
                        tb[x]=-tb[x];
                    }
                }
            }
            a.push_back(ta);
            b.push_back(tb);
        }
		save_test_case(tc,t,n,a,b);
	}
}

void generate_subtask_4(int l,int r)
{
	for(int tc=l;tc<=r;tc++){
		int t=get_int_from_range(9,10);
		vector<int> n;
		vector<vector<int>> a,b;
		for(int i=0;i<t;i++)
        {
            n.push_back(get_int_from_range(29000,30000));
            vector<int> ta,tb;
            for(int j=0;j<n[i];j++)
            {
                int x=get_int_from_range(-1000,1000);
                ta.push_back(x);
                tb.push_back(x);
            }
            shuffle(ta.begin(),ta.end(),rng);
            shuffle(tb.begin(),tb.end(),rng);
            for(int j=0;j<n[i];j++) ta[j]*=(1-2*(j&1));
            for(int j=0;j<n[i];j++) tb[j]*=(1-2*(j&1));
            if(get_int_from_range(0,1))
            {
                if(get_int_from_range(0,2))
                {
                    for(int j=0;j<10;j++)
                    {
                        int x=get_int_from_range(-1000,1000);
                        int y=get_int_from_range(0,n[i]-1);
                        if((tb[y]>0 && x<0) || (tb[y]<0 && x>0)) tb[y]=-x;
                        else tb[y]=x;
                    }
                }
                else
                {
                    for(int j=0;j<10;j++)
                    {
                        int x=get_int_from_range(0,n[i]-1);
                        tb[x]=-tb[x];
                    }
                }
            }
            a.push_back(ta);
            b.push_back(tb);
        }
		save_test_case(tc,t,n,a,b);
	}
}
int main(){
	generate_subtask_1(2,4);
	generate_subtask_2(5,9);
	generate_subtask_3(10,14);
	generate_subtask_4(15,21);
	return 0;
}
