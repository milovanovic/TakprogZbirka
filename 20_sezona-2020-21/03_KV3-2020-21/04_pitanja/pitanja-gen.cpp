#include <bits/stdc++.h>
#define maxA 1000000000
#define maxN 200005
#define maxQ 200005

using namespace std;

long long n,q,st,d,tmp,pom,i,j,a[maxN],x[maxQ],y[maxQ],k[maxQ],cnt[1000005];
vector<long long> v;

mt19937 rnd(time(0));

long long rand64(){
return rnd()^((long long)rnd()<<31);
}

long long raspodela(){
long long tmp=rand64(),cnt=1;
while(tmp>0 && tmp%2){
    tmp/=2;
    cnt++;
}
return cnt;
}

long long mod(long long a,long long b){
long long ans=a%b;
if(ans<0) ans+=b;
return ans;
}

int main()
{
    ofstream fout("27.in.txt");
    cin>>n>>q>>st;
    d=2*sqrt(n);
    if(st==1) for(i=0;i<n;i++) a[i]=i+1;
    if(st==2) for(i=0;i<n;i++) a[i]=(i+1)*(i+1);
    if(st>2) for(i=0;i<n;i++) a[i]=mod(rand64(),maxA)+1;
    i=1;
    while(v.size()<q){
        for(j=0;j<i;j++) v.push_back(i);
        i++;
    }
    for(i=0;i<q;i++){
        tmp=rand64();
        if(mod(tmp,10)==0) k[i]=mod(rand64(),n)+1;
        if(mod(tmp,10)>0 && mod(tmp,10)<7) k[i]=raspodela();
        if(mod(tmp,10)>=7) k[i]=mod(rand64(),d)+1;
        tmp=rand64();
        x[i]=mod(rand64(),n/4)+1;
        pom=(n-x[i]-1)/k[i]+1;
        tmp=rand64();
        y[i]=x[i]+k[i]*(mod(rand64(),(pom+1)/2)+pom/2);
    }
    fout<<n<<"\n";
    for(i=0;i<n-1;i++) fout<<a[i]<<" ";
    fout<<a[n-1]<<"\n";
    fout<<q<<"\n";
    for(i=0;i<q;i++){
        fout<<x[i]<<" "<<y[i]<<" "<<k[i]<<"\n";
    }
    return 0;
}
