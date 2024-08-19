#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

const int maxn = 210;
const int maxk = 510;
int n, K, cnt, scc;

vector<vi> dp(maxn, vi(maxk, 0));
vi vis(maxn), spt(maxn), low(maxn), f(maxn), k(maxn), s(maxn), sk(maxn), ss(maxn), d(maxn), e[maxn], g[maxn];
stack<int> st;
set<pi> se;

void tardzan(int x){
    vis[x] = ++cnt; 
    low[x] = cnt;
    spt[x] = 1; 
    st.push(x);
    
    for(int y : e[x])
        if (!vis[y]){
            tardzan(y);
            low[x] = min(low[x], low[y]);
        } else if (spt[y]){
            low[x] = min(low[x], vis[y]);
        }

    if (low[x] == vis[x]){
        ++scc;
        int tmp;

        do {
            
            tmp = st.top(); 
            st.pop(); 
            spt[tmp] = 0;
            f[tmp] = scc;
            sk[scc] += k[tmp];
            ss[scc] += s[tmp];

        } while(tmp != x);
    }
}

void dfs(int x){
    
    for(int i = sk[x]; i <= K; ++i)
        dp[x][i] = ss[x];

    for(int y : g[x]){
        dfs(y);

        for(int j = K - sk[x]; j > -1; --j)
            for(int l = 0; l <= j; ++l)
                dp[x][j + sk[x]] = max(dp[x][j + sk[x]], dp[x][j + sk[x] - l] + dp[y][l]);
    }
}

signed main(){

	ios_base::sync_with_stdio(0); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	cin >> n >> K;

    for(int i = 1; i <= n; ++i){
    	int tmp;
        cin >> tmp; 

        if(!tmp) 
        	continue;
        
        e[tmp].push_back(i);
    }

    for(int i = 1; i <= n; ++i)
        cin >> s[i];

    for(int i = 1; i <= n; ++i)
        cin >> k[i];

    for(int i = 1; i <= n; ++i)
        if(!vis[i]) 
        	tardzan(i);

    for (int x = 1; x <= n; ++x){
        for (int y : e[x]){
            if (!se.count({f[x], f[y]}) && f[x] != f[y]){
                g[f[x]].push_back(f[y]); 
                ++d[f[y]];
                se.insert({f[x], f[y]});
            }
        }
    } 

    for(int i = 1; i <= scc; ++i)
        if (!d[i]) 
        	g[0].push_back(i);

    dfs(0);

    return cout << dp[0][K] << '\n', 0;
}