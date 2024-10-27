#include<bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxV = 3e5;
const int maxA = 1e6;

map<pii, int> mp;
int a[maxV + 10];
vector<int> v[maxV + 10], gr[maxA + 10];
int n, q;
map<int, pii> ans;
int cnt[maxA];
int firstNotZero = -1;

int check(int val, int step, int a, int b)
{
    long long xi = 1;

    while(step--)
    {
        xi*=val;
        if (xi*b>a) return 0;
    }

    if (xi * b > a) return 0;
    return 1;
}

int equals(int sz1, int num1, int sz2, int num2, int val)
{
    if (sz1 > sz2)
    {
        swap(sz1, sz2);
        swap(num1, num2);
    }

    if (sz2 % sz1) return 0;

    int val2 = sz2 / sz1;

    if (num1 > num2) return 0;

    long long xi = 1;

    num2-=num1;
    while(xi<=val2 && num2)
    {
        xi*=val;
        num2--;
    }

    return (xi == val2);
}
int comp(int sz1, int num1, int sz2, int num2, int val)
{
    if (equals(sz1, num1, sz2, num2, val)) return 0;

    num1-=num2;

    if (num1 < 0) return 1^check(val, -num1, sz2, sz1);

    return check(val, num1, sz1, sz2);

}

pii solve(int x)
{
    if (!cnt[x] || x <=1) return mkp(max(0, firstNotZero), max(0, firstNotZero));

    int ans = 0;
    int pozL = 0;
    int pozR = 0;

    for (int i:gr[x])
    {
        int sz = v[i].size();

        for (int l = 0; l<=min(sz - 1, 20); l++)
            for (int r = max(0, sz - 21); r<sz; r++)
            {
                if (r<l) continue;


                if (comp(pozR - pozL + 1, ans, v[i][r] - v[i][l] + 1, r - l +1, x))
                {
                    ans = r - l + 1;
                    pozR = v[i][r];
                    pozL = v[i][l];
                }
            }
    }

    return {pozL, pozR};
}

int main()
{
    cin>>n>>q;

    assert(n>0 && n<=maxV && q > 0 && q <= maxV);

    int curGr = 1;
    int curID = 0;
    for (int i = 0 ; i<n; i++)
    {
        scanf("%d",&a[i]);
        assert(a[i]>=0 && a[i]<=maxA);

        cnt[a[i]]++;
        if (a[i] && firstNotZero == -1) firstNotZero = i;

        if (!a[i]) curGr++;
        else
        {
            pii par = mkp(curGr, a[i]);
            if (!mp.count(par))
            {
                mp[par] = ++curID;
                gr[a[i]].pb(curID);
            }

            v[mp[par]].pb(i);
        }
    }

    while(q--)
    {
        int x;
        scanf("%d",&x);

        assert(x>=0 && x<=maxA);

        if (!ans.count(x))
            ans[x] = solve(x);

        printf("%d %d\n", ans[x].first, ans[x].second);
    }
}
