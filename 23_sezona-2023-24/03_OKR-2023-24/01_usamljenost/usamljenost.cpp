#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    vector<int> blokovi;
    blokovi.push_back(1);
    for (int i=1;i<(int)s.size();i++)
    {
        if (s[i]==s[i-1]) blokovi.back()++;
        else blokovi.push_back(1);
    }
    
    if ((int)blokovi.size()==1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    long long odg=0;
    odg+=blokovi[1]-1;
    for (int i=1;i<(int)blokovi.size()-1;i++)
    {
        if (blokovi[i]==1)
        {
            odg+=(long long)(blokovi[i-1]+1)*(blokovi[i+1]+1)-3;
        }
        else
        {
            odg+=(blokovi[i-1]-1);
            odg+=(blokovi[i+1]-1);
        }
    }
    odg+=blokovi[(int)blokovi.size()-2]-1;
    
    cout<<odg<<endl;
}