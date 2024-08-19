#include<bits/stdc++.h>
#define MAXN 3007
using namespace std;
mt19937 rng(time(0));
int main()
{
    int n,m;
    cin>>n>>m;
    int tc,o;
    cin>>tc>>o;
    ofstream out("testcases\\0"+to_string(tc)+".in");
    out<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(uniform_int_distribution<int>(1,o)(rng)==o) out<<'#';
            else out<<'.';
        }
        out<<endl;
    }
}
