#include <bits/stdc++.h>

using namespace std;

const long long maxA = 1e9;

mt19937 rnd(1602);

long long rnd64(){
    return ((long long)rnd()<<31 ^ rnd());
}

void subtask1(string filename) {
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 50000;

    in<<n<<" "<<n<<endl;

    vector<int> c,d,tmp;
    long long res = 0;

    for(int i=0;i<n;i++) {
        tmp.clear();
        for(int j=0;j<4;j++){
            tmp.push_back(rnd64()%(maxA+1));
        }
        sort(tmp.begin(),tmp.end());
        res+=tmp[2];
        in<<tmp[0]<<" "<<tmp[2]<<endl;
        c.push_back(tmp[1]);
        d.push_back(tmp[3]);
    }
    
    for(int i=0;i<n;i++){
        in<<c[i]<<" "<<d[i]<<endl;
    }

    out<<res;
}

void subtask2(string filename) {
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 48000 + rnd64()%2000;
    int m = 48000 + rnd64()%2000;

    in<<n<<" "<<m<<endl;

    long long s = 0;

    for(int i=0;i<n;i++) {
        int a;
        a = rnd64()%(maxA+1);
        in<<a<<" "<<a<<endl;
        s+=a;
    }

    out<<s<<endl;

    vector<int> C;
    
    for(int i=0;i<m;i++){
        int l,u;
        l = max((long long)0,s-maxA*(m-i-1));
        u = min(maxA,s);

        int c = rnd64()%(u-l+1)+l;
        C.push_back(c);
        s-=c;
    }

    shuffle(C.begin(),C.end(),rnd);

    for(int i=0;i<m;i++){
        in<<C[i]<<" "<<C[i]<<endl;
    }
}

void subtask3(string filename) {
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 48000 + rnd64()%2000;
    int m = 48000 + rnd64()%2000;

    in<<n<<" "<<m<<endl;

    long long s = 0;

    for(int i=0;i<n;i++) {
        int a;
        a = rnd64()%(maxA+1);
        in<<a<<" "<<a<<endl;
        s+=a;
    }

    out<<s<<endl;

    long long s1=s,s2=s;
    vector<pair<long long,long long>> res;
    
    for(int i=0;i<m;i++){
        int l,u;
        l = max((long long)0,s2-maxA*(m-i-1));
        u = min(maxA,s1);

        long long c = rnd64()%(maxA+1);
        long long d = rnd64()%(maxA+1);

        if(c>d) swap(c,d);
        if(c>u) c = rnd64()%(u+1);
        if(d<l) d = rnd64()%(maxA+1-l)+l;

        res.push_back({c,d});
        s1-=c;
        s2-=d;
    }

    shuffle(res.begin(),res.end(),rnd);

    for(int i=0;i<m;i++){
        in<<res[i].first<<" "<<res[i].second<<endl;
    }
}

void subtask4(string filename, int t){
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 1;
    int m = 50000;

    in<<n<<" "<<m<<endl;

    int a = rnd64()%(maxA+1);
    int b = rnd64()%(maxA+1);
    if(a>b) swap(a,b);

    long long s1=b,s2=b,c,d,s=0,pom=b;
    vector<pair<long long,long long>> res;

    for(int i=0;i<m;i++){
        if(t==0){
            int l,u;
            l = max((long long)0,s2-maxA*(m-i-1));
            u = min(maxA,s1);

            int h = u/100000;
            c = rnd64()%(h+1);
            d = rnd64()%(maxA+1-c)+c;

            if(d<l) d = rnd64()%(maxA+1-l)+l;

            s1-=c;
            s2-=d;
        }
        else{
            int h = pom/100000;
            c = rnd64()%(h+1);
            d = rnd64()%(h+1);
            if(c>d) swap(c,d);

            pom-=d;
        }

        s+=d;
        res.push_back({c,d});
    }

    if(t%2==1){
        a=rnd64()%(s+1);
    }

    in<<a<<" "<<b<<endl;

    shuffle(res.begin(),res.end(),rnd);

    for(int i=0;i<m;i++){
        in<<res[i].first<<" "<<res[i].second<<endl;
    }

    out<<min(s,(long long) b);
}

void subtask5(string filename) {
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 48000 + rnd64()%2000;
    int m = 48000 + rnd64()%2000;

    in<<n<<" "<<m<<endl;

    long long s1 = 0, s2=0;

    for(int i=0;i<n;i++) {
        int b = rnd64()%(maxA+1);

        in<<0<<" "<<b<<endl;
        s1+=b;
    }
    
    for(int i=0;i<m;i++){
        int d = rnd64()%(maxA+1);

        in<<0<<" "<<d<<endl;
        s2+=d;
    }

    out<<min(s1,s2);
}

void subtask6(string filename) {
    ofstream in(filename+".in");
    ofstream out(filename+".out");

    int n = 48000 + rnd64()%2000;
    int m = 48000 + rnd64()%2000;

    in<<n<<" "<<m<<endl;

    long long s1 = 0, s2=0;
    long long c1=0, c2=0;

    for(int i=0;i<n;i++) {
        int a = rnd64()%(maxA+1);
        int b = rnd64()%(maxA+1);
        if(a>b) swap(a,b);

        in<<a<<" "<<b<<endl;
        s1+=b;
        c1+=a;
    }
    
    for(int i=0;i<m;i++){
        int c = rnd64()%(maxA+1);
        int d = rnd64()%(maxA+1);
        if(c>d) swap(c,d);

        in<<c<<" "<<d<<endl;
        s2+=d;
        c2+=c;
    }

    out<<min(s1,s2);
    if(max(c1,c2)>min(s1,s2)){
        cout<<"Greska u primeru "<<filename<<endl;
        // Sanse da dodje do ove greske su jako male
    }
}

void checkTestcase(string filename){
    ifstream in(filename+".in");
    ifstream out(filename+".out");

    long long s1=0, s2=0;
    long long c1=0, c2=0;

    int n,m;
    in>>n>>m;

    for(int i=0;i<n;i++){
        int a,b;
        in>>a>>b;

        if(a>b){
            cout<<"Greska u primeru "<<filename<<endl;
            return;
        }

        c1+=a;
        s1+=b;
    }

    for(int i=0;i<m;i++){
        int c,d;
        in>>c>>d;

        if(c>d){
            cout<<"Greska u primeru "<<filename<<endl;
            return;
        }

        c2+=c;
        s2+=d;
    }

    long long res;

    out>>res;

    if(res!=min(s1,s2)){
            cout<<"Greska u primeru "<<filename<<endl;
            return;
    }

    if(max(c1,c2)>min(s1,s2)){
        cout<<"Greska u primeru "<<filename<<endl;
        // Sanse da dodje do ove greske su jako male
    }
}

int main() {
    for(int i=3;i<=22;i++){
        string tmp = "./testcases/";
        if(i<10) tmp+="0";

        string filename = tmp+to_string(i);

        if(i<=4){
            subtask1(filename);
        }
        else if(i<=6){
            subtask2(filename);
        } else if(i<=9){
            subtask3(filename);
        } else if(i<=12){
            subtask4(filename,i%2);
        } else if(i<=18){
            subtask5(filename);
        } else{
            subtask6(filename);
        }

        checkTestcase(filename);
    }
	return 0;
}