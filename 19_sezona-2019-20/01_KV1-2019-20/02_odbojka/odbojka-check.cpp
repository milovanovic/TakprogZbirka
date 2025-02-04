#include<bits/stdc++.h>

using namespace std;

int n,a;

int valid(int x, int y)
{
    if (x<a && y<a)
        return 0;
    if (x==a && y<=a-2)
        return 1;
    if (y==a && x<=a-2)
        return 1;
    if (abs(x-y)==2)
        return 1;
    return 0;
}

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    ifstream fout(argv[1]); //od takmicara
	ifstream fsol(argv[2]); //tacno resenje
	ifstream fin(argv[3]); //ulaz

	int k = 0;
    string line;
    ifstream tak(argv[1]);

    while (getline(tak, line))
        k++;

	fin >> n >> a;

	int rez;
	fsol >> rez;

	int x;
	fout >> x;
	if (min(rez,x)==-1 && max(rez,x)!=-1)
        return -1;
    else
        if (max(rez,x)==-1)
            return 0;
    
	if (k<3 || k>5)
        return -1;

    int y;
    fout >> y;
    if (!valid(x,y))
        return -1;

	int s1=0,s2=0;

	if (x>y)
        s1++;
    else
        s2++;

	int uk=x+y;

    for (int i=2; i<=k; i++)
    {
        int x,y;
        fout >> x >> y;

        if (!valid(x,y)) //ako nije validan rezultat u nekom setu
            return -1;

        if (x>y)
            s1++;
        else
            s2++;

        uk+=x+y;
        if (uk>n)
            return -1;
	if (max(s1,s2)==3)
		break;
    }

	if (has_extra_tokens(fout))
		return -1;

	if (max(s1,s2)!=3 || min(s1,s2)>=3 || uk!=n)
        return -1;
    else
        return 0;
}
