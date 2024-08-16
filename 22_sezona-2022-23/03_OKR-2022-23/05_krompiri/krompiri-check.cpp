#include<bits/stdc++.h>
#define maxN 50005

using namespace std;

long long a[maxN],b[maxN],c[maxN],d[maxN],n,m,k;
long long total = 0, cntR[maxN] = {0}, cntC[maxN] = {0};
long long maxKrompira, takKrompira;

int main(int argc, char *argv[])
{
    ifstream fout(argv[1]); //Takmicarev output
	ifstream fsol(argv[2]); //Komisijski output
	ifstream fin(argv[3]); //Input

    fin>>n>>m;

    for(int i=0;i<n;i++){
        fin>>a[i]>>b[i];
    }

    for(int i=0;i<m;i++){
        fin>>c[i]>>d[i];
    }

    fsol>>maxKrompira;

    if(!(fout>>takKrompira))
    {
        return -1;
    }

    if(takKrompira!=maxKrompira) return -1;

    if(!(fout>>k))
    {
        return -1;
    }

    if(k<0) return -1;

    for(long long i=0;i<k;i++){
        long long x,y,cnt;

        if (fout >> x)
		{
			if (fout >> y)
			{
				if(fout >> cnt){
                    x--; y--;
                    if(x<0 || x>=n) return -1;
                    if(y<0 || y>=m) return -1;
                    if(cnt<0) return -1;

                    cntR[x]+=cnt;
                    cntC[y]+=cnt;
                    total+=cnt;
                }
                else
                {
                    return -1; // nema dovoljno brojeva
                }
			}
			else
			{
				return -1; // nema dovoljno brojeva
			}
		}
		else
		{
			return -1; // nema dovoljno brojeva
		}
    }

    long long tmp;
    if(fout>>tmp){
        return -1;
    }

    if(total!=maxKrompira) return -1;

    for(int i=0;i<n;i++){
        if(cntR[i]<a[i] || cntR[i]>b[i]) {
            return -1;
        }
    }

    for(int i=0;i<m;i++){
        if(cntC[i]<c[i] || cntC[i]>d[i]) {
            return -1;
        }
    }

    fin.close();
    fout.close();
    fsol.close();
    return 0;
}