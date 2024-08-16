#include <bits/stdc++.h>

using namespace std;

bool ima[26];
int cnt=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n,k; cin>>n>>k;
    string s; cin>>s;
    int duz=1;
    for (int i=0;i<n;i++)
    {
        int c=s[i]-'a';
        if (!ima[c]) ima[c]=true,cnt++;
        if (cnt==k)
        {
            cnt=0;
            for (int j=0;j<k;j++) ima[j]=false;
            duz++;
        }
        cout<<duz<<" ";
    }
}
