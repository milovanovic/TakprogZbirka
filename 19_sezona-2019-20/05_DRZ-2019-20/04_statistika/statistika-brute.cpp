#include <cstdio>
#include <cassert>

const int N = 1000;
int city[N][N];
int n, m;

int solve(int i0, int j0, int h, int w)
{
    int mm = 1<<30, cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i >= i0 && i < i0+h && j >= j0 && j < j0+w) continue;
            if(city[i][j] < mm)
            {
                mm = city[i][j];
                cnt = 1;
            }
            else if(city[i][j] == mm)
                cnt++;
        }
    return cnt;
}

int main()
{
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &city[i][j]);

    while(q--)
    {
        int i, j, h, w;
        scanf("%d %d %d %d", &i, &j, &h, &w);
        i--; j--;  // 0-indexing
        printf("%d\n", solve(i, j, h, w));
    }

    return 0;
}
