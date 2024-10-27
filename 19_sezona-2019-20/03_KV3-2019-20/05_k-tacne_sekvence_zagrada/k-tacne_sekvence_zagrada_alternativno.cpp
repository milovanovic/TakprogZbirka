#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int K=101,N=1003,off=70;
const ll mod=1LL<<61;
ll add(ll a,ll b){return min(a+b,mod);}
ll dp[N][K][2];
vector<char> vals[N][172];
vector<ll> vals2[N][172];
ll getVal(int i,int val,int k){
    int pos=i+k-val;
    if(pos<0)
        return 0;
    if(k==0&&(N-i-1)%2!=val%2)
        return 0;
    int gde=val-i+off;
    if(gde<0||gde>171)
        return mod;
    pos=lower_bound(all(vals[i][gde]),k)-vals[i][gde].begin();
    if(pos>=vals[i][gde].size()||vals[i][gde][pos]!=k){
        return mod;
    }
    return vals2[i][gde][pos];
}
int main()
{
    for(int i=0;i<K;i++)
        for(int k=0;k<=i;k++)
            dp[k][i][0]=1,vals[0][k+off].pb(i),vals2[0][k+off].pb(1);
    for(int i=1;i<N;i++)
        for(int val=0;val<N;val++)
            for(int k=0;k<K;k++)
            {
                int pos=i+k-val;
                if(pos<0)
                    continue;
                if(val<N-1)
                    dp[val][k][i&1]=dp[val+1][k][i&1^1];
                else
                    dp[val][k][i&1]=0;
                if(val!=0)
                    dp[val][k][i&1]=add(dp[val][k][i&1],dp[val-1][k][i&1^1]);
                else if(k){
                    dp[val][k][i&1]=add(dp[val][k][i&1],dp[val][k-1][i&1^1]);
                }
                if(k==0&&(N-i-1)%2!=val%2)
                    continue;
                if(dp[val][k][i&1]<mod)
                    vals[i][val-i+off].pb(k),vals2[i][val-i+off].pb(dp[val][k][i&1]);
            }
    int t;
    scanf("%i",&t);
    for(int i=0;i<t;i++)
    {
        int n,k=1,val=0;
        ll s;
        scanf("%i",&n);
        scanf("%i",&k);
        scanf("%lld",&s);
        if(getVal(n,val,k)<s)
        {
            printf("Ne postoji\n");
            continue;
        }
        string ans;
        while(n)
        {
            n--;
            if(getVal(n,val+1,k)>=s)
                val++,ans+='(';
            else
                if(val!=0)
                    ans+=')',s-=getVal(n,val+1,k),val--;
                else
                    ans+=')',s-=getVal(n,val+1,k),k--;
        }
        cout << ans << endl;
    }
    return 0;
}
