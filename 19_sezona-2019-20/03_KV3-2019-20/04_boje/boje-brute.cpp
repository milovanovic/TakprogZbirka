#include <cstdio>

const int N = 1005;
bool block[N][N];
int colour[N][N];
int n, m;

const int DI[] = {-1, 1, 0, 0}, DJ[] = {0, 0, -1, 1};
void dfs(int i, int j, int col)
{
    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(block[i][j] || colour[i][j]) return;
    colour[i][j] = col;
    for(int d = 0; d < 4; d++)
        dfs(i + DI[d], j + DJ[d], col);
}

int main()
{
    int p;
    scanf("%d %d %d", &n, &m, &p);
    while(p--)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        i--; j--;
        block[i][j] = true;
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!block[i][j] && !colour[i][j])
                dfs(i, j, ++res);

    printf("%d\n", res);

    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j <= m; j++)
    //         printf("%c", j == m ? '\n' : block[i][j] ? '#' : (colour[i][j] + '0'));
    
    return 0;
}
