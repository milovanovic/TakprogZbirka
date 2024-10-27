#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int M=2*N;
const int inf=1e9+7;

int ls[M],rs[M],tsz,root;
int sum[M][2],L[M][2],R[M][2],lzy[M];

char s[N];
int C;
int Get(int x){return min(x,C);}

void pull(int c,int ss,int se){
	int mid=ss+se>>1;
	for(int t=0;t<2;t++){
		sum[c][t]=sum[ls[c]][t]+sum[rs[c]][t]-Get(R[ls[c]][t])-Get(L[rs[c]][t])+Get(R[ls[c]][t]+L[rs[c]][t]);
		L[c][t]=L[ls[c]][t]==(mid-ss+1)?L[rs[c]][t]+(mid-ss+1):L[ls[c]][t];
		R[c][t]=R[rs[c]][t]==(se-mid)?R[ls[c]][t]+(se-mid):R[rs[c]][t];
	}
}

void Flip(int c){
	swap(sum[c][0],sum[c][1]);
	swap(L[c][0],L[c][1]);
	swap(R[c][0],R[c][1]);
	lzy[c]^=1;
}

void push(int c){
	if(lzy[c]){
		Flip(ls[c]);
		Flip(rs[c]);
		lzy[c]=0;
	}
}

void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){
		if(s[ss]=='1'){
			sum[c][0]=1;
			sum[c][1]=0;
			L[c][0]=R[c][0]=1;
			L[c][1]=R[c][1]=0;
		}else{
			sum[c][0]=0;
			sum[c][1]=1;
			L[c][0]=R[c][0]=0;
			L[c][1]=R[c][1]=1;
		}
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	pull(c,ss,se);
}

void Flip(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){Flip(c);return;}
	int mid=ss+se>>1;
	push(c);
	Flip(ls[c],ss,mid,qs,qe);
	Flip(rs[c],mid+1,se,qs,qe);
	pull(c,ss,se);
}

int Ans(){return sum[root][0];}

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(1<=C && C<=n);
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
		printf("%i\n",Ans());
	}
	return 0;
}
