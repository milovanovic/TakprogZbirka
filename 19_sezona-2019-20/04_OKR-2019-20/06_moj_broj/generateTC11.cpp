#include<bits/stdc++.h>

using namespace std;

const int maxE = 1e8;

mt19937 rng(time(0));

int getRnd()
{
    return rng()%maxE + 1;
}
int main()
{
    freopen("11.in", "w", stdout);

    int n = 123;
    int cur = 0;
    cout<<n<<endl;

    for (int i = 0;i<n-1;i++)
        cout<<maxE - i * 1021<<" ";

    cout<<maxE-(n-1)*1021;

    fclose(stdout);
}


