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
    freopen("10.in", "w", stdout);

    int n = 124;
    int cur = 0;
    cout<<n<<endl;

    for (int i=0;i<27;i++){
        cout<<(1<<i)<<" ";
        cur++;
    }

    int st = 3;
    for (int i = 1; i<=16;i++){
        cout<<st<<" ";
        st*=3;
        cur++;
    }

    st = 5;
    for (int i = 1; i<=11;i++){
        cout<<st<<" ";
        st*=5;
        cur++;
    }

    st = 10;
    for (int i = 1;i<9;i++){
       cout<<st<<" ";
       st*=10;
       cur++;
    }

   for (int i = cur+1;i<n;i++)
     cout<<getRnd()<<" ";

    cout<<getRnd();

    fclose(stdout);
}

