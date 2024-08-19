#include <bits/stdc++.h>
#define maxn 600000
using namespace std;
struct testcase {
    int n,m,q;
    /* type:
     *   0 - random graph
     *   1 - reconstruct
     *   2 - tree
     *   3 - path
     */
    int type;
    int t;
};

mt19937 rng(time(0));

long long get_int_from_range(long long l,long long r){
	assert(l<=r);
	return uniform_int_distribution<long long>(l,r)(rng);
}

long long get_int_from_range(long long l,long long r, long long t){
	assert(l<=r);
	assert(t);
	long long val = get_int_from_range(l, r);
	for(int i=1;i<abs(t);i++) {
        long long nx = get_int_from_range(l, r);
        if(t>0) val = max(val,nx);
        else val = min(val, nx);
	}
	return val;
}

vector<testcase> cases = {
/* Subtask 1: */
{10,15,1000,1,1},
{10,15,1000,1,-1},
{10,15,1000,1,5},
{10,15,1000,1,-5},
{10,15,1000,1,10},
{10,15,1000,1,-10},
{10,15,1000,1,20},
{10,15,1000,1,-20},
{16,15,1000,2,5},
{16,15,1000,2,-5},
{16,15,1000,2,20},
{16,15,1000,2,-20},
/* Subtask 2: */
{100,200,200,1,1},
{100,200,200,1,-1},
{100,200,200,1,5},
{100,200,200,1,-5},
{100,200,200,1,10},
{100,200,200,1,-10},
{100,200,200,1,20},
{100,200,200,1,-20},
{200,199,200,2,5},
{200,199,200,2,-5},
{200,199,200,2,10},
{200,199,200,2,-10},
{200,199,200,2,20},
{200,199,200,2,-20},
/*Subtask 3:*/
{1000,2000,1000,1,1},
{1000,2000,1000,1,-1},
{1000,2000,1000,1,5},
{1000,2000,1000,1,-5},
{1000,2000,5000,1,10},
{1000,2000,5000,1,-10},
{1000,2000,5000,1,20},
{1000,2000,5000,1,-20},
{500,2000,5000,1,1},
{500,2000,5000,1,-1},
{500,2000,5000,1,5},
{500,2000,5000,1,-5},
{500,2000,5000,1,10},
{500,2000,5000,1,-10},
{500,2000,5000,1,20},
{500,2000,5000,1,-20},
{2000,1999,5000,2,5},
{2000,1999,5000,2,-5},
{2000,1999,5000,2,10},
{2000,1999,5000,2,-10},
{2000,1999,5000,2,20},
{2000,1999,5000,2,-20},
{1000,2000,5000,0,1},
{1000,2000,5000,0,-1},
{1000,2000,5000,0,1},
{1000,2000,5000,0,-1},
/*Subtask 4:*/
{1900,3000,200000,1,1},
{1900,3000,200000,1,-1},
{1900,3000,200000,1,5},
{1500,3000,200000,1,-5},
{1900,3000,200000,1,10},
{1500,3000,200000,1,-10},
{1900,3000,200000,1,20},
{1500,3000,200000,1,-20},
{1500,3000,200000,1,1},
{1500,3000,200000,1,-1},
{1500,3000,200000,1,5},
{1500,3000,200000,1,-5},
{1500,3000,200000,1,10},
{1500,3000,200000,1,-10},
{1500,3000,200000,1,20},
{1500,3000,200000,1,-20},
{3000,2999,200000,2,5},
{3000,2999,200000,2,-5},
{3000,2999,200000,2,10},
{3000,2999,200000,2,-10},
{3000,2999,200000,2,20},
{3000,2999,200000,2,-20},
{2000,3000,200000,0,1},
{2000,3000,200000,0,-1},
{2000,3000,200000,0,1},
{2000,3000,200000,0,-1},
/*Subtask 5:*/
{100000,99999,200000,3,1},
{100000,99999,200000,3,1},
{100000,99999,200000,3,1},
/*Subtask 6:*/
{100000,99999,200000,2,1},
{100000,99999,200000,2,-1},
{100000,99999,200000,2,40},
{100000,99999,200000,2,-40},
/*Subtask 7:*/
{100000,99999,200000,2,100},
{100000,99999,200000,2,-100},
{100000,99999,200000,2,200},
{100000,99999,200000,2,-200},
{100000,200000,200000,1,100},
{100000,200000,200000,1,-100},
{100000,200000,200000,1,200},
{100000,200000,200000,1,-200},
{50000,200000,200000,1,100},
{50000,200000,200000,1,-100},
{50000,200000,200000,1,200},
{50000,200000,200000,1,-200},
{20000,200000,200000,1,100},
{20000,200000,200000,1,-100},
{20000,200000,200000,1,200},
{20000,200000,200000,1,-200},
{100000,200000,200000,0,1},
{50000,200000,200000,0,-1},
};

int n;
char ins[50];
int p[maxn];
int d[maxn];
int asg[maxn];
int seg_asg[4*maxn];
int l[maxn];
int r[maxn];
int pos[maxn];
int onpos[maxn];
long long dist[maxn];
int ct = 0;
set<pair<int,int> > ex;
vector<int> ch[maxn];
void euler(int u) {
    pos[u]=ct;
    onpos[ct]=u;
    ct++;
    r[u]=l[u]=pos[u];
    for(auto v:ch[u]) {
        d[v]=d[u]+1;
        euler(v);
        r[u]=r[v];
    }
}
void build_seg_asg(int id,int l,int r) {
    if(l==r) {
        seg_asg[id]=asg[onpos[l]];
        return;
    }
    int m=(l+r)/2;
    build_seg_asg(id*2+1,l,m);
    build_seg_asg(id*2+2,m+1,r);
    seg_asg[id]=min(seg_asg[id*2+1],seg_asg[id*2+2]);
}
int query(int id,int l,int r,int x,int y) {
    if(y<l || r<x) return maxn;
    if(x<=l && r<=y) {
        return seg_asg[id];
    }
    int m=(l+r)/2;
    return min(query(id*2+1,l,m,x,y),query(id*2+2,m+1,r,x,y));
}
void update(int id,int l,int r,int p,int v) {
    if(l==r) {
        seg_asg[id] = v;
        return;
    }
    int m=(l+r)/2;
    if(p<=m) update(id*2+1,l,m,p,v);
    else update(id*2+2,m+1,r,p,v);
    seg_asg[id]=min(seg_asg[id*2+1],seg_asg[id*2+2]);
}
int get_pos(int id,int l,int r,int x,int y,int v) {
    if(y<l || r<x) return 0;
    int m=(l+r)/2;
    if(x<=l && r<=y) {
        if(v<seg_asg[id]) return 0;
        if(l==r) return l;
        if(seg_asg[id*2+1]==v) return get_pos(id*2+1,l,m,x,y,v);
        else return get_pos(id*2+2,m+1,r,x,y,v);
    }
    return get_pos(id*2+1,l,m,x,y,v)+get_pos(id*2+2,m+1,r,x,y,v);
}
void get_asg(int u) {
    int cval = asg[u];
    int mval = query(0,0,n-1,l[u],r[u]);
    int pmval = get_pos(0,0,n-1,l[u],r[u],mval);
    int vt = onpos[pmval];
    asg[vt] = cval;
    asg[u] = mval;
    update(0,0,n-1,pos[u],mval);
    update(0,0,n-1,pos[vt],cval);
    for(auto v:ch[u]) {
        d[v]=d[u]+1;
        get_asg(v);
    }
}
int m;
int edge_count=0;
set<pair<int,int> > st[maxn];
vector<pair<pair<int,int>,int> > edges;
vector<pair<pair<int,int>,int> > add_edges;
void dfs(int u) {
    st[u].clear();
    st[u].insert({asg[u],u});
    for(auto v:ch[u]) {
        dfs(v);
    }
    if(ch[u].size()==1) {
        for(auto v:ch[u]) {
            if(get_int_from_range(0,1)) edges.push_back({{u,v},dist[asg[v]]-dist[asg[u]]});
            else edges.push_back({{v,u},dist[asg[v]]-dist[asg[u]]});
            ex.insert({min(u,v),max(u,v)});
            edge_count++;
        }
    }
    else {
        for(auto v:ch[u]) {
            int totc=0;
            for(auto w:ch[u]) {
                if(w==v) continue;
                if(totc>20) break;
                set<pair<int,int> >::iterator it;
                it=st[w].lower_bound({asg[v],v});
                if(it==st[w].begin()) continue;
                it--;
                totc++;
                int itc=1;
                if(totc<=2) {
                    if(get_int_from_range(0,1)) edges.push_back({{(*it).second,v},dist[asg[v]]-dist[(*it).first]});
                    else edges.push_back({{v,(*it).second},dist[asg[v]]-dist[(*it).first]});
                    ex.insert({min((*it).second,v),max((*it).second,v)});
                    edge_count++;
                    itc++;
                    if(it==st[w].begin()) itc=3;
                    else it--;
                }
                while(itc<3) {
                    if(get_int_from_range(0,1)) add_edges.push_back({{(*it).second,v},dist[asg[v]]-dist[(*it).first]});
                    else add_edges.push_back({{v,(*it).second},dist[asg[v]]-dist[(*it).first]});
                    if(it==st[w].begin()) break;
                    it--;
                    itc++;
                }
            }
            if(totc<=1) {
                if(get_int_from_range(0,1)) edges.push_back({{u,v},dist[asg[v]]-dist[asg[u]]});
                else edges.push_back({{v,u},dist[asg[v]]-dist[asg[u]]});
                ex.insert({min(u,v),max(u,v)});
                edge_count++;
            }
        }
    }

    for(auto v:ch[u]) {
        if(st[v].size()>st[u].size()) swap(st[v],st[u]);
        for(auto x:st[v]) st[u].insert(x);
        st[v].clear();
    }
}
int main()
{
    int cnt = 2;
    for(testcase tc: cases)
    {
        sprintf(ins,"testcases/%d.in",cnt);
        fprintf(stderr,"Generating %d/%d into file: \"%s\"\n",cnt-1,cases.size(),ins);
        ct=0;
        edge_count=0;
        FILE* fl = freopen(ins,"w",stdout);
        int N=tc.n, M=tc.m, Q=tc.q;
        m=M;
        n=N;
        fprintf(fl,"%d %d %d\n",N,M,Q);
        int* U = new int[M+1];
        int* V = new int[M+1];
        int* W = new int[M+1];
        int* X = new int[Q+1];
        int* Y = new int[Q+1];
        int* Ans = new int[Q+1];
        edges.clear();add_edges.clear();
        vector<pair<int,int> > queries;
        ex.clear();
        int ad_iter=0;
        if(tc.type == 3) {
            vector<int> perm;
            for(int i=1;i<=N;i++) {
                perm.push_back(i);
            }
            random_shuffle(perm.begin(),perm.end());
            for(int i=1;i<N;i++) {
                if(get_int_from_range(0,1)) edges.push_back({{perm[i],perm[i-1]},get_int_from_range(1,1000000000)});
                else edges.push_back({{perm[i-1],perm[i]},get_int_from_range(1,1000000000)});
            }
        }
        else {
            p[1]=0;
            vector<int> perm;
            for(int i=2;i<=N;i++) {
                p[i]=get_int_from_range(1,i-1,tc.t);
                perm.push_back(i);
            }
            random_shuffle(perm.begin(),perm.end());
            for(int i=1;i<=N;i++) {
                ch[i].clear();
            }
            for(int i=2;i<=N;i++) {
                if(p[i]==1) ch[1].push_back(perm[i-2]);
                else ch[perm[p[i]-2]].push_back(perm[i-2]);
            }
            if(tc.type==0) {
                for(int u=1;u<=N;u++) {
                    for(auto v:ch[u]) {
                        if(get_int_from_range(0,1)) edges.push_back({{u,v},get_int_from_range(1,1000000000)});
                        else edges.push_back({{v,u},get_int_from_range(1,1000000000)});
                        ex.insert({min(u,v),max(u,v)});
                    }
                }
                edge_count=N-1;
            }
            else {
                for(int i=1;i<=N;i++) {
                    asg[i]=i-1;
                    dist[i-1]=get_int_from_range(1,1000000000);
                }
                dist[0]=0;
                sort(dist,dist+n);
                for(int i=1;i<=n;i++) {
                    while(dist[i]<=dist[i-1]) dist[i]++;
                }
                assert(dist[n]<=1000000000);
                euler(1);
                build_seg_asg(0,0,N-1);
                get_asg(1);
                if(tc.type==2) {
                    for(int u=1;u<=N;u++) {
                        for(auto v:ch[u]) {
                            //fprintf(stderr,"ok");
                            if(get_int_from_range(0,1)) edges.push_back({{u,v},dist[asg[v]]-dist[asg[u]]});
                            else edges.push_back({{v,u},dist[asg[v]]-dist[asg[u]]});
                            ex.insert({min(u,v),max(u,v)});
                        }
                    }
                    edge_count=N-1;
                }
                else {
                    dfs(1);
                    int cur_edge_count=edge_count;
                    random_shuffle(add_edges.begin(),add_edges.end());
                    cerr<<cur_edge_count<<" "<<cur_edge_count+0.7*(M-cur_edge_count)<<" "<<add_edges.size()<<endl;
                    for(int i=cur_edge_count;i<cur_edge_count+0.7*(M-cur_edge_count);i++) {
                        ad_iter++;
                        if(add_edges.empty()) break;
                        else edges.push_back(add_edges.back());
                        int u=add_edges.back().first.first;
                        int v=add_edges.back().first.second;
                        ex.insert({min(u,v),max(u,v)});
                        add_edges.pop_back();
                        edge_count++;
                    }
                }
            }
            for(int i=edge_count;i<M;i++) {
                int u=get_int_from_range(1,N);
                int v=get_int_from_range(1,N);
                while(u==v || ex.count({min(u,v),max(u,v)})) {
                    u=get_int_from_range(1,N);
                    v=get_int_from_range(1,N);
                }
                if(get_int_from_range(0,1)) edges.push_back({{u,v},get_int_from_range(abs(dist[u]-dist[v])+1,1000000000)});
                else edges.push_back({{v,u},get_int_from_range(abs(dist[u]-dist[v])+1,1000000000)});
                ex.insert({min(u,v),max(u,v)});
            }
        }
        for(int i=0;i<Q;i++) {
            queries.push_back({get_int_from_range(1,N),get_int_from_range(1,N)});
        }

        random_shuffle(edges.begin(),edges.end());
        random_shuffle(queries.begin(),queries.end());

        for(int i=1;i<=M;i++) {
            U[i] = edges[i-1].first.first;
            V[i] = edges[i-1].first.second;
            W[i] = edges[i-1].second;
        }

        for(int i=1;i<=Q;i++) {
            X[i] = queries[i-1].first;
            Y[i] = queries[i-1].second;
        }

        fprintf(stderr, "%d\n", ad_iter);

        for (int i=1; i<=M; i++) fprintf(fl,"%d %d %d\n",U[i],V[i],W[i]);
        for (int i=1; i<=Q; i++) fprintf(fl,"%d %d\n",X[i],Y[i]);

        delete[] U;
        delete[] V;
        delete[] W;
        delete[] X;
        delete[] Y;
        delete[] Ans;
        cnt++;
    }
}
