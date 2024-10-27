#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int K=1e9;
const int K1=1e6;
const int N=200050;
const int maxn=2e5;
int t[N],k[N];
int l[N],r[N],x0[N];

ll ans[N];
void BruteForce(int n,int q){
	for(int qi=1;qi<=q;qi++){
		int L=l[qi],R=r[qi];
		ll X0=x0[qi];
		ll sum=0;
		for(int i=L;i<=R;i++){
			if(t[i]==1){
				X0=min(X0,(ll)k[i]);
			}else if(t[i]==2){
				X0=max(X0,(ll)k[i]);
			}else if(t[i]==3){
				X0+=k[i];
			}
			sum+=X0;
		}
		ans[qi]=sum;
	}
}

string ToStr(int tc){
	return tc<10?"0"+to_string(tc):to_string(tc);
}

void MakeEmpty(){
	for(int tc=1;tc<=27;tc++){
		{
			ofstream out("empty\\" + ToStr(tc) + ".in");
			out.close();
		}
		{
			ofstream out("empty\\" + ToStr(tc) + ".out");
			out.close();
		}
	}
}

void SaveOut(int tc,int n,int q){
	ofstream out("tests\\" + ToStr(tc) + ".out");
	for(int i=1;i<=q;i++){
		out<<ans[i]<<"\n";
	}
	out.close();
}

void Save(int tc,int n,int q){
	printf("Test %i - n=%i, q=%i\n",tc,n,q);
	ofstream out("tests\\" + ToStr(tc) + ".in");
	out<<n<<"\n";
	for(int i=1;i<=n;i++){
		out<<t[i];
		if(i==n)out<<"\n";
		else out<<" ";
	}
	for(int i=1;i<=n;i++){
		out<<k[i];
		if(i==n)out<<"\n";
		else out<<" ";
	}
	out<<q<<"\n";
	for(int i=1;i<=q;i++){
		out<<l[i]<<" "<<r[i]<<" "<<x0[i]<<"\n";
	}
	out.close();
	BruteForce(n,q);
	SaveOut(tc,n,q);
}

mt19937 rng(94821);

int RandInt(int maxk){
	int x=rng()%(maxk+1);
	if(rng()&1)x=-x;
	return x;
}

void RandomTest(int tc,int n,int q,int maxk=K,int ts=-1){
	for(int i=1;i<=n;i++){
		t[i]=rng()%3+1;
		if(ts!=-1)t[i]=ts;
		if(t[i]==3)k[i]=RandInt(min(K1,maxk));
		else k[i]=RandInt(maxk);
	}
	for(int i=1;i<=q;i++){
		l[i]=rng()%n+1;
		r[i]=rng()%n+1;
		if(l[i]>r[i])swap(l[i],r[i]);
		x0[i]=RandInt(maxk);
	}
	Save(tc,n,q);
}

void Examples(){
	RandomTest(1,5,2,10);
	RandomTest(2,10,6,20);
}

void Subtask1(){
	RandomTest(3,785,949,1000);
	RandomTest(4,1000,1000);
}

void Subtask2(){
	RandomTest(5,maxn/2-5142,maxn/2-4325,K,3);
	RandomTest(6,maxn/2-491,maxn-3912,K,3);
	RandomTest(7,maxn-123,maxn-193,K,3);
	RandomTest(8,maxn-94,maxn,K,3);
	RandomTest(9,maxn,maxn,K,3);
}

void Subtask3(){
	RandomTest(10,maxn/2-5142,maxn/2-4325,K,1);
	RandomTest(11,maxn/2-491,maxn-3912,K,1);
	RandomTest(12,maxn-123,maxn-193,K,1);
	RandomTest(13,maxn-94,maxn,K,1);
	RandomTest(14,maxn,maxn,K,1);
}

void Subtask4(){
	const int n=40000;
	RandomTest(15,n/3,n/2);
	RandomTest(16,n/2-312,n/2+4133);
	RandomTest(17,n-32,n-412);
	RandomTest(18,n-31,n-1);
	RandomTest(19,n-1,n);
	RandomTest(20,n,n);
}

void Subtask5(){
	RandomTest(21,maxn/3,maxn/3);
	RandomTest(22,maxn/2-3214,maxn-3214);
	RandomTest(23,maxn-1223,maxn/2);
	RandomTest(24,maxn-321,maxn-1);
	RandomTest(25,maxn-1,maxn-1);
	RandomTest(26,maxn,maxn);
	RandomTest(27,maxn,maxn);
}

int main(){
	MakeEmpty();
	Examples();
	Subtask1();
	Subtask2();
	Subtask3();
	Subtask4();
	Subtask5();
	return 0;
}
