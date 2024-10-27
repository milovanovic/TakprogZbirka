#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ull unsigned long long
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

const int K=101,N=103;
const ll mod=1LL<<61;
ll add(ll a,ll b){return min(a+b,mod);}
ll dp[N][N][K];
int main()
{
    for(int k=0;k<K;k++)
        for(int val=0;val<=k;val++)
            dp[0][val][k]=1;
    for(int i=1;i<N;i++) ///Izracunaj DP na gore
        for(int val=0;val<N;val++)
            for(int k=0;k<K;k++)
            {
                if(val<N-1)
                    dp[i][val][k]=dp[i-1][val+1][k];
                else
                    dp[i][val][k]=0;
                if(val!=0)
                    dp[i][val][k]=add(dp[i][val][k],dp[i-1][val-1][k]);
                else
                    if(k)
                        dp[i][val][k]=add(dp[i][val][k],dp[i-1][val][k-1]);
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
        if(dp[n][val][k]<s)
        {
            printf("Ne postoji\n");
            continue;
        }
        string ans;
        while(n)
        {
            n--;
            if(dp[n][val+1][k]>=s)
                val++,ans+='(';
            else
                if(val!=0)
                    ans+=')',s-=dp[n][val+1][k],val--;
                else
                    ans+=')',s-=dp[n][val+1][k],k--;
        }
        cout << ans << endl;
    }

    return 0;
}
