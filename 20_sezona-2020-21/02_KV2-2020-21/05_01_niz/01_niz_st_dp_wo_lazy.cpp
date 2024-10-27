#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int M=2*N;
const int inf=1e9+7;

int ls[M],rs[M],tsz,root;
int dp[M][2][2];

char s[N];
int C;
void init(int c){for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[c][j][k]=inf;}
/*void pull(int c){
	for(int l=0;l<2;l++){
		for(int r=0;r<2;r++){
			dp[c][l][r]=inf;
			for(int a=0;a<2;a++){
				for(int b=0;b<2;b++){
					dp[c][l][r]=min(dp[c][l][r],dp[ls[c]][l][a]+dp[rs[c]][b][r]+(a==1&&b==1?-C:0));
				}
			}
		}
	}
}*/

void pull(int c){
	for(int l=0;l<2;l++){
		for(int r=0;r<2;r++){
			dp[c][l][r]=min(dp[ls[c]][l][0],dp[ls[c]][l][1])+min(dp[rs[c]][0][r],dp[rs[c]][1][r]);
			dp[c][l][r]=min(dp[c][l][r],dp[ls[c]][l][1]+dp[rs[c]][1][r]-C);
		}
	}
}

void Build(int&c,int ss,int se){
	c=++tsz;init(c);
	if(ss==se){
		if(s[ss]=='1'){
			dp[c][0][0]=1;
			dp[c][1][1]=C;
		}else{
			dp[c][0][0]=0;
			dp[c][1][1]=C+1;
		}
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	pull(c);
}

void Set(int c,int ss,int se,int qi,char ch){
	if(ss==se){
		if(ch=='1'){
			dp[c][0][0]=1;
			dp[c][1][1]=C;
		}else{
			dp[c][0][0]=0;
			dp[c][1][1]=C+1;
		}
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,ch);
	else Set(rs[c],mid+1,se,qi,ch);
	pull(c);
}

int Ans(){return min({dp[root][0][0],dp[root][0][1],dp[root][1][0],dp[root][1][1]});}

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
		assert(l==r);
		for(int j=l;j<=r;j++){
			if(s[j]=='0'){
				Set(root,1,n,j,'1');
				s[j]='1';
			}else{
				Set(root,1,n,j,'0');
				s[j]='0';
			}
		}
		printf("%i\n",Ans());
	}
	return 0;
}
