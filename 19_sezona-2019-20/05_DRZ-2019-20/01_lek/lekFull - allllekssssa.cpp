#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int,int>
const int maxN = 1e6+10;

vector<pii> ans;
int a[maxN];
int n;

int main()
{
    cin>>n;

    for (int i = 1;i<=n;i++)
        scanf("%d",&a[i]);

    int last = 0;
    for (int i = 1;i<=n;i++)
        if (a[i]!=i)
    {
         if (last >= i) return !printf("Nema spasa\n");
         ans.pb({i, a[i]});
         last = a[i];
         reverse(a + i , a + a[i] + 1);
         i--;
    }

    printf("Svet je spasen\n%d\n",(int) ans.size());
    for (auto i:ans)
        printf("%d %d\n",i.first, i.second);
}
