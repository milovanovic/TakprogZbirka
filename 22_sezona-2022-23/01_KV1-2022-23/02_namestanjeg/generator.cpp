#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<int> gen(0,(int)1e9); ///(min, max) [min,max]
int random() {return gen(mt_rand);}
int random(int mn, int mx)
{
    return mt_rand()%(mx-mn+1)+mn;
}
const int mxN=5e5+5;
const int mod=998244353;
const int mxlogN=40;
const int mxK=26;
const int inf=1e9;
const int K=600;
int a[mxN],b[mxN];
string tostring(int x)
{
    return string(1,'0'+x/10)+string(1,'0'+x%10);
}
void print(int t, int n, int q)
{
    string s="testcases\\"+tostring(t)+".in";
    FILE* fout=fopen(s.c_str(),"w");
    fprintf(fout,"%d %d\n",n,q);
    for(int i=0; i<n; i++) fprintf(fout,"%d ",a[i]);
    fprintf(fout,"\n");
    for(int i=0; i<q; i++) fprintf(fout,"%d ",b[i]);
    fprintf(fout,"\n");
    fclose(fout);

}
///[1,7]
///[8,14]
///[15,24]
///[25,35]
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int t=1; t<=7; t++)
    {
        int n=2e5, q=2e5;
        int cntRange=random(1,n/10);
        int cnt=0, x;
        for(int i=0; i<n; i++)
        {
            if(cnt==0)
            {
                cnt=random(1,cntRange);
                x=random();
            }
            cnt--;
            a[i]=x;
        }
        random_shuffle(a,a+n);
        for(int i=0; i<q; i++)
        {
            if(random()&1) b[i]=a[random(0,n-1)];
            else b[i]=random();
        }
        print(t,n,q);
    }
}
