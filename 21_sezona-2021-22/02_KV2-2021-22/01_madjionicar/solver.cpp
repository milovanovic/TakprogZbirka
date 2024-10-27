#include <bits/stdc++.h>
#define MAXN 20007
using namespace std;
const string folder="testcases\\";
int p[MAXN];
int main()
{
    for(int tc=1;tc<=22;tc++)
    {
        cout<<tc<<endl;
        ifstream in(folder+to_string(tc)+".in");
        ofstream out(folder+to_string(tc)+".out");
        int n,k;
        in>>n>>k;
        for(int i=0;i<n;i++) in>>p[i];
        for(int i=0;i<n;i++) if(p[i]==k) out<<p[(i+1)%n];
    }
}
