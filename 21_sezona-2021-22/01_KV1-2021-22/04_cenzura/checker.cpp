#include<bits/stdc++.h>
#define MAXN 200007
using namespace std;
string og,zb,nj;
const int partial=80;
int main(int argc, char *argv[])
{
    ifstream ouf(argv[1]); //Takmicar
	ifstream sof(argv[2]); //Komisija
	ifstream inf(argv[3]); //Input
	inf>>og>>zb;
	int sol=0,tsol=0;
	sof>>sol;
	ouf>>tsol;
	if(tsol!=sol) return -1;
    ouf>>nj;
    if(nj.size()!=og.size()) return partial;
    for(int i=0;i<nj.size();i++) if(nj[i]!=og[i] && nj[i]!='*') return partial;
    int cnt=0;
    for(int i=0;i<nj.size();i++) if(nj[i]=='*') cnt++;
    if(cnt!=sol) return partial;
    int d=0;
    for(int i=0;i<nj.size();i++)
    {
        if(zb[d]==nj[i]) d++;
        if(d==zb.size()) return partial;
    }
    return 100;
}

