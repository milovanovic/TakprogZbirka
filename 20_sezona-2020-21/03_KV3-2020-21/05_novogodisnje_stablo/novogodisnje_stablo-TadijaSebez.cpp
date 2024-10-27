#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=200050;
const int M=2*N;

vector<int> E[N];
bool vis[N];
int lid[N],rid[N],tid,seq[N],par[N],b[N];
void DFS(int u,int p){
	par[u]=p;
	lid[u]=++tid;
	seq[tid]=u;
	vis[u]=1;
	for(int v:E[u]){
		assert(!vis[v] || v==p);
		if(v!=p)DFS(v,u);
	}
	rid[u]=tid;
}

int root,tsz,ls[M],rs[M],col[M],sum[M],lzy[M];
void Build(int&c,int ss,int se){
	c=++tsz;lzy[c]=sum[c]=0;
	if(ss==se){col[c]=b[seq[ss]];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void upd(int c,int x){
	col[c]=lzy[c]=x;
	sum[c]=0;
}
void push(int c){
	if(lzy[c]){
		upd(ls[c],lzy[c]);
		upd(rs[c],lzy[c]);
		lzy[c]=0;
	}
}
void Set(int c,int ss,int se,int qi){
	sum[c]++;
	if(ss==se)return;
	int mid=ss+se>>1;
	push(c);
	if(qi<=mid)Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
void Clr(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){upd(c,x);return;}
	int mid=ss+se>>1;
	push(c);
	Clr(ls[c],ss,mid,qs,qe,x);
	Clr(rs[c],mid+1,se,qs,qe,x);
	sum[c]=sum[ls[c]]+sum[rs[c]];
}
int Get(int c,int ss,int se,int qi){
	if(ss==se)return col[c];
	int mid=ss+se>>1;
	push(c);
	if(qi<=mid)return Get(ls[c],ss,mid,qi);
	else return Get(rs[c],mid+1,se,qi);
}

int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	assert(1<=n && n<=200000 && 1<=q && q<=200000);
	for(int i=1,u,v;i<n;i++){
		scanf("%i %i",&u,&v);
		assert(1<=u && u<=n && 1<=v && v<=n);
		E[u].pb(v);E[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		scanf("%i",&b[i]);
		assert(1<=b[i] && b[i]<=n);
	}
	DFS(1,0);
	Build(root,1,n);
	for(int i=2;i<=n;i++)if(b[i]!=b[par[i]])Set(root,1,n,lid[i]);
	while(q--){
		int u,c;
		scanf("%i %i",&u,&c);
		assert(1<=u && u<=n && 1<=c && c<=n);
		Clr(root,1,n,lid[u],rid[u],c);
		if(u!=1&&Get(root,1,n,lid[u])!=Get(root,1,n,lid[par[u]])){
			Set(root,1,n,lid[u]);
		}
		printf("%i\n",sum[root]+1);
	}
	return 0;
}