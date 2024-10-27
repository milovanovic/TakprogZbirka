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
    freopen("09.in", "w", stdout);

    int n = 124;
    cout<<n<<endl;

    for (int i = 0;i<n-1;i++)
        cout<<getRnd()<<" ";

    cout<<getRnd();

    fclose(stdout);
}
