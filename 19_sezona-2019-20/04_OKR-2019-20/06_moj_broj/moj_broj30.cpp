#include<bits/stdc++.h>

using namespace std;

const int maxN = 125;
int a[maxN];
int n;

int main()
{
    cin>>n;

    for (int i = 1; i <= n; i++)
        cin>>a[i];

    cout<<27<<endl;

    for (int i = 0; i<=26;i++)
        cout<<(1<<i)<<" ";
    cout<<endl;

    for (int i = 1; i<=n ;i++)
    {
        int nasao = 0;
        for (int j = 0; j < 27; j++)
            if (a[i]&(1<<j))
        {
            if (!nasao)
            {
                cout<<(1<<j)<<" ";
                nasao =  1;
            } else
            cout<<"+ "<<(1<<j)<<" ";
        }

        cout<<endl;
    }
}
