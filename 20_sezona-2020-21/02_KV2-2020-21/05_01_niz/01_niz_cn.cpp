#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int inf=1e9+7;

const int M=2*N;

char s[N];
int C;

int ls[M],rs[M],tsz,root,lzy[M],sum[M];
void flip(int c,int ss,int se){
	sum[c]=(se-ss+1)-sum[c];
	lzy[c]^=1;
}
void push(int c,int ss,int se){
	if(lzy[c]){
		int mid=ss+se>>1;
		flip(ls[c],ss,mid);
		flip(rs[c],mid+1,se);
		lzy[c]=0;
	}
}
void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){sum[c]=s[ss]=='1';return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	sum[c]=sum[ls[c]]+sum[rs[c]];
}
void Flip(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){flip(c,ss,se);return;}
	push(c,ss,se);
	int mid=ss+se>>1;
	Flip(ls[c],ss,mid,qs,qe);
	Flip(rs[c],mid+1,se,qs,qe);
	sum[c]=sum[ls[c]]+sum[rs[c]];
}

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(C==n);
	assert(1<=q && q<=200000);

	scanf("%s",s+1);
	assert(strlen(s+1)==n);
	for(int i=1;i<=n;i++)assert(s[i]=='0' || s[i]=='1');

	Build(root,1,n);

	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		assert(1<=l && l<=r && r<=n);
		Flip(root,1,n,l,r);
		printf("%i\n",sum[root]);
	}
	return 0;
}
