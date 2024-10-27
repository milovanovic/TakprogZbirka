#include <bits/stdc++.h>
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
using namespace std;

const string folder="";

mt19937 rng(time(0));

int get_int_from_range(int l,int r){
	assert(l<=r);
	return uniform_int_distribution<int>(l, r)(rng);
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
///resenje
int solve(int N, int M, vector<int> p, vector<pair<int, int> > cards) {
    int dub[N+1];
    dub[1] = 0;
    for(int i = 2; i <= N; i++) {
        dub[i] = dub[p[i-2]] + 1;
    }
    map<int, int> cnt;
    for(auto x : cards) {
        cnt[x.first + dub[x.second]]++;
    }
    int rez = 0;
    for(auto x : cnt) {
        rez += x.second - x.second%2;
    }
    return rez;
}
///
void save_test_case(int tc,int n, int m, vector<int> p, vector<pair<int, int> > cards){
	ofstream out(folder+to_string(tc)+".in");
	out<<n<<" " << m << "\n";
	assert(p.size()==n-1);
	for(int i=0;i<n-1;i++){
		out<<p[i]<<" ";
	}
	out << "\n";
    assert(cards.size()==m);
    for(int i=0;i<m;i++) {
        out<<cards[i].first << ' ' << cards[i].second << '\n';
    }
	out.close();

    ofstream sol(folder+to_string(tc)+".out");
    sol << solve(n, m, p, cards);
    sol.close();
}
#define MAXN 100010
vector<int> adj[MAXN];
int dub[MAXN];

void dfs(int node, int prev, int previdx, vector<int> &p, int &idx) {
    if(prev != 0) {
        dub[idx] = dub[previdx]+1;
        p.push_back(previdx);
    }
    int idx1 = idx;
    for(auto x : adj[node]) {
        if(x != prev) {
            idx++;
            dfs(x, node, idx1, p, idx);
        }
    }
}

vector<int> generate_parents(vector<pair<int, int> > edges) {
    int n = edges.size()+1;
    for(int i = 1; i <= n; i++){
        adj[i].clear(); dub[i] = 0;
    }
    for(auto x : edges) {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    int idx = 1;
    vector<int> p;
    dfs(1, 0, 0, p, idx);
    return p;
}

void generate_t(int n, vector<pair<int, int> > &cards, int maxT) {
    vector<int> cuts;
    int m = cards.size();
    int idx = 0;
    while(cuts.empty() || idx <= m-1) {
        int cut = get_int_from_range(idx, m-1);
        cuts.push_back(cut);
        idx = cut+1;
    }
    int l = 0;
    PRINT(cuts.size());
    for(auto r : cuts) {
        int mind = 1000000000, maxd = 0;
        for(int i = l; i <= r; i++) {
            mind = min(mind, dub[cards[i].second]);
            maxd = max(maxd, dub[cards[i].second]);
        }
        int T = get_int_from_range(1+maxd, maxT+mind);
        for(int i = l; i <= r; i++) {
            cards[i].first = T-dub[cards[i].second];
        }
    }
    shuffle(cards.begin(), cards.end(), rng);
}

void generate_subtask_1(int l,int r){
	for(int tc=l;tc<=r;tc++){
        PRINT(tc);
		int n=get_int_from_range(900,1000);
		int m=get_int_from_range(900,1000);
		vector<int> p = generate_parents(generate_tree(n));
        vector<pair<int, int> > cards(m);
        for(int i = 0; i < m; i++) {
            cards[i].second = get_int_from_range(1, n);
        }
        generate_t(n, cards, 1000000000);
		save_test_case(tc,n,m,p,cards);
	}
}

void generate_subtask_2(int l,int r){
	for(int tc=l;tc<=r;tc++){
        PRINT(tc);
		int n=get_int_from_range(97000,100000);
		int m=get_int_from_range(97000,100000);
		vector<pair<int, int> > edges;
		for(int i = 1; i < n; i++) edges.push_back({i, i+1});
		vector<int> p = generate_parents(edges);
        vector<pair<int, int> > cards(m);
        for(int i = 0; i < m; i++) {
            cards[i].second = get_int_from_range(1, n);
        }
        generate_t(n, cards, 1000000000);
		save_test_case(tc,n,m,p,cards);
	}
}

void generate_subtask_3(int l,int r){
	for(int tc=l;tc<=r;tc++){
        PRINT(tc);
        int n=get_int_from_range(97000,100000);
		int m=get_int_from_range(97000,100000);
		vector<int> p = generate_parents(generate_tree(n));
        vector<pair<int, int> > cards(m);
        for(int i = 0; i < m; i++) {
            cards[i].second = get_int_from_range(1, n);
            cards[i].first = 1;
        }
		save_test_case(tc,n,m,p,cards);
	}
}

void generate_subtask_4(int l,int r){
	for(int tc=l;tc<=r;tc++){
        PRINT(tc);
		int n=get_int_from_range(97000,100000);
		int m=get_int_from_range(97000,100000);
		vector<int> p = generate_parents(generate_tree(n));
        vector<pair<int, int> > cards(m);
        for(int i = 0; i < m; i++) {
            cards[i].second = get_int_from_range(1, n);
        }
        generate_t(n, cards, 500000);
		save_test_case(tc,n,m,p,cards);
	}
}

void generate_subtask_5(int l,int r){
	for(int tc=l;tc<=r;tc++){
        PRINT(tc);
		int n=get_int_from_range(97000,100000);
		int m=get_int_from_range(97000,100000);
		vector<int> p = generate_parents(generate_tree(n));
        vector<pair<int, int> > cards(m);
        for(int i = 0; i < m; i++) {
            cards[i].second = get_int_from_range(1, n);
        }
        generate_t(n, cards, 1000000000);
		save_test_case(tc,n,m,p,cards);
	}
}

void generate_subtask_0(int l, int r) {
    ///1.in
    int N1 = 6, M1 = 6;
    vector<int> p1 = {1, 2, 2, 2, 4};
    vector<pair<int, int> > cards1 = {{3, 6}, {7, 3}, {7, 5}, {8, 5}, {7, 1}, {4, 4}};
    save_test_case(1, N1, M1, p1, cards1);
    ///2.in
    int N2 = 5, M2 = 10;
    vector<int> p2 = {1, 1, 1, 1};
    vector<pair<int, int> > cards2 = {{4, 4}, {3, 3}, {3, 4}, {2, 2}, {2, 3}, {2, 4}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};
    save_test_case(2, N2, M2, p2, cards2);
}

int main(){
    generate_subtask_0(1, 2);  ///samples, 2
	generate_subtask_1(3, 5);  ///N, M <= 1000, 3
	generate_subtask_2(6, 9);  ///p_i = i-1, 4
	generate_subtask_3(10, 13);///t_i = 1, 4
	generate_subtask_4(14, 18);///t_i <= 10^5, 5
	generate_subtask_5(19, 22);///ostalo, 4
	return 0;
}
