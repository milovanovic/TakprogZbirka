#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=1e6,K=2;
int n,k;
vector<int> p;
bool possible;

vector<pair<int,int> > sta;

void print(int file=-1){
	if(file==-1){
		printf("%i %i\n",n,k);
		for(int i=0;i<n;i++)
			printf("%i ",p[i]);
		printf("\n");
		return;
	}
	string in="./testcases/";
	in+='0'+file/10;
	in+='0'+(file%10);
	string out=in+".out";
	in+=".in";
	cout << in << endl << out << endl;
	FILE *f=fopen(in.c_str(),"w");
	fprintf(f,"%i %i\n",n,k);
	for(int i=0;i<n;i++){
		fprintf(f,"%i",p[i]);
		if(i!=n-1)
			fprintf(f," ");
	}
	fprintf(f,"\n");
	fclose(f);
	f=fopen(out.c_str(),"w");
	fprintf(f,"%i\n",possible);
	fclose(f);
}

void rev(int l,int r,vector<int> &p){
	for(int j=l;r-j+l>j;j++)
  	swap(p[j],p[r-j+l]);
}
bool ok(vector<int> &p){
	for(int i=0;i<p.size();i++)
		if(p[i]!=i)
			return 0;
	return 1;
}
bool moze(vector<int> perm, int k){ //Search without breaking consecutive number groups
	if(ok(perm))
		return 1;
	if(k==0)
		return 0;
	vector<int> pos;
  for(int i=0;i<=n;i++)
  	if(abs(perm[i]-perm[i+1])!=1)
  		pos.push_back(i);
  if(pos.size()>2*k)
  	return 0;
  for(int l1=0;l1<pos.size();l1++){
		for(int r1=l1+1;r1<pos.size();r1++){
			rev(pos[l1]+1,pos[r1],perm);
			if(moze(perm,k-1))
				return 1;
			rev(pos[l1]+1,pos[r1],perm);
		}
	}
	return 0;
}
bool moze(){
  vector<int> perm(n+2);
  for(int i=1;i<=n;i++)
  	perm[i]=p[i-1];
  perm[n+1]=n+1;
  vector<int> pos;
  for(int i=0;i<=n;i++)
  	if(abs(perm[i]-perm[i+1])!=1)
  		pos.push_back(i);
  if(pos.size()==3){ //Special cases
		rev(pos[0]+1,pos[1]+1,perm);
		rev(pos[0]+2,pos[2],perm);
  	if(ok(perm))
				return 1;
		rev(pos[0]+2,pos[2],perm);
		rev(pos[0]+1,pos[1]+1,perm);
		
		rev(pos[1],pos[2],perm);
		rev(pos[0]+1,pos[2]-1,perm);
  	if(ok(perm))
				return 1;
		rev(pos[0]+1,pos[2]-1,perm);
		rev(pos[1],pos[2],perm);
  }
  
	return moze(perm,k);
}
void genPossible(){
	n=rng()%N+1;
	k=rng()%K+1;
	n=1e6;
	possible=1;
	p.resize(n);
	iota(p.begin(),p.end(),1);
	int mySwaps=rng()%(k+1);
	sta.clear();
	for(int i=0;i<mySwaps;i++){
		int l=rng()%n,r=rng()%n;
		if(l>r)
			swap(l,r);
		sta.push_back({l,r});
		rev(l,r,p);
	}
	assert(moze());
}

void genImpossible(){
	do{
		possible=0;
		n=rng()%N+1;
		k=rng()%K+1;
		p.resize(n);
		iota(p.begin(),p.end(),1);
		int mySwaps=rng()%5+k+1;
		sta.clear();
		for(int i=0;i<mySwaps;i++){
			int l=rng()%n,r=rng()%n;
			if(l>r)
				swap(l,r);
			sta.push_back({l,r});
			rev(l,r,p);
		}
	}while(moze());
}

int main()
{
		for(int i=1;i<=10;i++){
			if(rng()%3)
				genPossible();
			else
				genImpossible();
			print(i);
		}
    return 0;
}
