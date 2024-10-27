#include<bits/stdc++.h>

using namespace std;

struct inter
{
    int l;
    int r;
};

const int maxi = 1e6+10;
const int maxV = 3e5;
const int inf = 1e9;

int a[maxi];
inter c[maxi];
vector<int> v[maxi];
int n, q;
int cnt[maxi];
set<int> st;

int sub(int x, int y)
{
    return c[x].l > c[y].l && c[x].r < c[y].r;
}

int main()
{
    scanf("%d%d",&n,&q);

    assert(n<=maxV && q<=maxV && n>=1 && q>=1);

    for (int i = 1; i<=n;i++)
        cnt[i] = 2;

    for (int i = 1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
        assert(a[i]<=n && a[i]>0 && cnt[a[i]]);
        cnt[a[i]]--;
        if (cnt[a[i]]) {
            c[a[i]].l = i;
            st.insert(i);
        }
        else {
            c[a[i]].r = i;
            assert(*st.rbegin() == c[a[i]].l);
            st.erase(*st.rbegin());
        }
    }



    return 0;
}
