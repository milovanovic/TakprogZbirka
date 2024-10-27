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
int pd[20][2*maxV];//table for first down move
int pu[20][2*maxV];//table for first up move
set<int> st;

int sub(int x, int y)
{
    return c[x].l >= c[y].l && c[x].r <= c[y].r;
}

int left(int x, int y)
{
    return c[x].l < c[y].l;
}

int find(int t, int x, int len) //find interval on distance l from interval x to the left
{
    if (len<0) return 0;

    for (int i = 19;i>=0;i--){
        if (len&(1<<i) && !t) x = pd[i][x];
        if (len&(1<<i) && t) x = pu[i][x];
    }

    return x;
}
int search(int x, int y)
{
    int rz = -1;

    int xi = x;
    int len = 0;

    //down up moves
    for (int i = 19; i>=0;i--)
    {
       if (pd[i][xi] && left(pd[i][xi], y))
       {
           len+=(1<<i);
           xi = pd[i][xi];
       }
    }

    //check around few intervals

     for (int i = -2; i<=2;i++)
     {
         int z = find(0, x, len + i);
         if (z==y && (rz==-1 || rz > len + i)) rz  = len + i;
         if ((sub(z, y) || sub(y, z)) &&  (rz==-1 || rz > len + i + 1)) rz = len + i + 1;
     }

     //up down moves
     xi = x;
     len = 0;
     for (int i = 19; i>=0;i--)
    {
       if (pu[i][xi] && left(pu[i][xi], y))
       {
           len+=(1<<i);
           xi = pu[i][xi];
       }
    }
       //check around again
       for (int i = -2; i<=2;i++)
     {
         int z = find(1, x, len + i);
         if (z==y && (rz==-1 || rz > len + i)) rz  = len + i;
         if ((sub(z, y) || sub(y, z)) &&  (rz==-1 || rz > len + i + 1)) rz = len + i + 1;
     }

    return rz;
}
int main()
{
    scanf("%d%d",&n,&q);

    assert(n<=maxV && q<=maxV && n>=1 && q>=1);

    for (int i = 1; i<=n; i++)
        cnt[i] = 2;

    int lf = 0; //lf for finding leftmost subinterval
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
   //find leftmost super-interval
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

    //building table
    for (int  j = 1; j<=n; j++)
    {
        pu[1][j] = pd[0][pu[0][j]];
        pd[1][j] = pu[0][pd[0][j]];

        if (sub(j, pu[1][j]) || sub(pu[1][j], j)) pu[1][j] = 0;
        if (sub(j, pd[1][j]) || sub(pd[1][j], j)) pd[1][j] = 0;
    }

    for (int i = 2; i<20; i++)
        for (int j = 1 ; j<=n; j++)
        {
            pu[i][j] = pu[i-1][pu[i-1][j]];
            pd[i][j] = pd[i-1][pd[i-1][j]];
        }
    //--------------------------------

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

