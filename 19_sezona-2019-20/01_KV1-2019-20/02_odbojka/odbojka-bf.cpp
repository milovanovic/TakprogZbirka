#include <bits/stdc++.h>

using namespace std;

int n,a;

int x[15],rez[15];

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

void bt(int i, int k, int t)
{
    if (i>2*k)
    {
        if (t!=n)
            return;
        int p1=0,p2=0,ok=1;
        for (int i=1; i<=k; i++)
            if (valid(x[2*i-1],x[2*i]))
            {
                if (x[2*i-1]>x[2*i])
                    p1++;
                else
                    p2++;
                if (max(p1,p2)==3 && i<k)
                {
                    ok=0;
                    break;
                }
            }
            else
            {
                ok=0;
                break;
            }

            if (ok && p1!=p2 && max(p1,p2)==3)
            {
                /*for (int i=1; i<=k; i++)
                    printf("%d:%d ",x[2*i-1],x[2*i]);
                printf("\n");*/
                for (int i=1; i<=2*k; i++)
                    rez[i]=x[i];
                rez[0]=k;
                //printf("%d\n",k);
                //exit(0);
            }
        return;
    }
    x[i]=0;
    for (x[i]=0; x[i]<=n-t; x[i]++)
        //if ((i%2) || (i%2==0 && valid(x[i-1],x[i])))
            bt(i+1,k,t+x[i]);
    x[i]=0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> a;
	rez[0]=0;
    for (int k=3; k<=5; k++)
    {
        bt(1,k,0);
    }

	if (!rez[0])
		printf("NE");
	else
		printf("DA\n");
    for (int i=1; i<=rez[0]; i++)
        printf("%d:%d ",rez[2*i-1],rez[2*i]);
}
