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
int pd[20][2*maxV], pu[20][2*maxV];
set<int> st;

int sub(int x, int y)
{
    return c[x].l >= c[y].l && c[x].r <= c[y].r;
}

int search(int x, int y)
{
    int rz = -1;

    for (int k = 0; k<2; k++)
    {
        int xi = x;
        for (int i =  0; i<=n; i++)
        {
            if ((i+k) &1)
            {
                if (sub(y, pd[0][xi]) || sub(pd[0][xi], y))
                {
                    int val = -1;
                    if (y == pd[0][xi]) val = i + 1; else
                        val = i +  2;

                     if (rz == -1 || rz > val) rz = val;
                    break;
                }
                xi = pd[0][xi];
            }
            else
            {
                if (sub(y, pu[0][xi]) || sub(pu[0][xi], y))
                {
                    int val = -1;
                    if (y == pu[0][xi]) val = i + 1; else
                        val = i + 2;

                    if (rz == -1 || rz > val) rz = val;
                    break;
                }
                xi = pu[0][xi];
            }
        }
    }

    return rz;
}
int main()
{
    scanf("%d%d",&n,&q);

    assert(n<=maxV && q<=maxV && n>=1 && q>=1);

    for (int i = 1; i<=n; i++)
        cnt[i] = 2;

    int lf = 0;
    for (int i = 1; i<=2*n; i++)
    {
        scanf("%d",&a[i]);
        assert(a[i]<=n && a[i]>0 && cnt[a[i]]);
        cnt[a[i]]--;
        if (cnt[a[i]])
        {
            c[a[i]].l = i;
        }
        else
        {
            c[a[i]].r = i;
            if (c[lf].l > c[a[i]].l) pd[0][a[i]] = lf;
            if (c[lf].l < c[a[i]].l) lf = a[i];
        }
    }

    for (int i = 2*n; i>0; i--)
    {
        if (c[a[i]].r == i)
        {
            st.insert(i);
        }
        else
        {
            int val = *st.rbegin();
            st.erase(c[a[i]].r);
            if (val > c[a[i]].r) pu[0][a[i]] = a[val];
        }
    }

    while(q--)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        assert(x!=y && x<=n && x>=1 && y<=n && y>=1);

        if (c[x].l > c[y].l) swap(x, y);

        if (sub(y, x))
        {
            printf("1\n");
            continue;
        }

        int rez = search(x, y);

        printf("%d\n", rez);
    }

    return 0;
}


