#include <bits/stdc++.h>
#define maxn 42
#define maxl 5000000
using namespace std;
int t;
int n,s;
int m;
int mult[maxn];
int add[maxn];
int l[maxn];
int r[maxn];
int pot[maxl];
int potn;
void construct_pot(int i,int v) {
    if(i>m) {
        pot[potn++]=v;
        return;
    }
    int add_v = v + add[i];
    if(l[i]<=add_v && add_v<=r[i]) construct_pot(i+1,add_v);
    int mult_v = v * mult[i];
    if(l[i]<=mult_v && mult_v<=r[i]) construct_pot(i+1,mult_v);
}
struct func {
    int k,n;
    int l,r;
};
func v[maxl];
int vn=0;
void construct_linear(int i,func f) {
    if(f.l==f.r) {
        f.n=f.k*f.l+f.n;
        f.k=0;
    }
    if(i<=m) {
        v[vn++]=f;
        return;
    }
    int nl = f.l-add[i];
    int nr = f.r-add[i];
    int ml = max(l[i-1],nl);
    int mr = min(r[i-1],nr);
    if(ml<=mr) {
        func add_f = {f.k,f.k*add[i]+f.n,ml,mr};
        construct_linear(i-1,add_f);
    }
    if(mult[i]>0) {
        nl = f.l/mult[i];
        while(nl*mult[i]<f.l) nl++;
        while((nl-1)*mult[i]>=f.l) nl--;
        nr = f.r/mult[i];
        while(nr*mult[i]>f.r) nr--;
        while((nr+1)*mult[i]<=f.r) nr++;
    }
    else {
        if(mult[i]==0) {
            if(f.l<=0 && 0<=f.r) {
                nl = -1e9;
                nr = 1e9;
            }
            else {
                nl = 1e9;
                nr = -1e9;
            }
        }
        else {
            mult[i]*=-1;
            nl = f.l/mult[i];
            while(nl*mult[i]<f.l) nl++;
            while((nl-1)*mult[i]>=f.l) nl--;
            nr = f.r/mult[i];
            while(nr*mult[i]>f.r) nr--;
            while((nr+1)*mult[i]<=f.r) nr++;
            nl*=-1;
            nr*=-1;
            swap(nl,nr);
            mult[i]*=-1;
        }
    }
    ml = max(l[i-1],nl);
    mr = min(r[i-1],nr);
    if(ml<=mr) {
        func mult_f = {f.k*mult[i],f.n,ml,mr};
        construct_linear(i-1,mult_f);
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&s);
        for(int i=0;i<n;i++) {
            scanf("%d",&mult[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&add[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&l[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&r[i]);
        }
        m=(n-1)/2;
        potn=0;
        vn=0;
        construct_pot(0,s);
        sort(pot,pot+potn);
        construct_linear(n-1,{1,0,l[n-1],r[n-1]});
        bool hans=false;
        int mans=0;
        for(int i=0;i<vn;i++) {
            func f = v[i];
            int* it=lower_bound(pot,pot+potn,f.l);
            if(it!=pot+potn) {
                int x=*it;
                if(f.l<=x && x<=f.r) {
                    if(!hans || f.k*x+f.n>mans) {
                        hans=true;
                        mans=f.k*x+f.n;
                    }
                }
            }
            it=upper_bound(pot,pot+potn,f.r);
            if(it!=pot) {
                it--;
                int x=*it;
                if(f.l<=x && x<=f.r) {
                    if(!hans || f.k*x+f.n>mans) {
                        hans=true;
                        mans=f.k*x+f.n;
                    }
                }
            }

        }
        if(!hans) printf("nemoguce\n");
        else printf("%d\n",mans);
    }
    return 0;
}
