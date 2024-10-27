#include<bits/stdc++.h>
#define N 105

using namespace std;

int n, k, t;
char board[N][N];
char str[N];

const int DI[] = {1, 1, 1, 0};
const int DJ[] = {-1, 0, 1, 1};

char winner()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int d = 0; d < 4; d++)
            {
                int di = DI[d], dj = DJ[d];
                int cnt_x = 0, cnt_o = 0;
                for(int x = 0; x < k; x++)
                {
                    int ii = i + di*x, jj = j + dj*x;
                    if(ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                    if(board[ii][jj] == 'X') cnt_x++;
                    if(board[ii][jj] == 'O') cnt_o++;
                }

                // Ne moramo da brinemo o slucaju gde su obojica
                // pobedili, jer onda svakako prvi check (niko ne
                // pobedjuje pre T) pada, a ako je taj prosao na
                // konacnoj tabli samo trenutni igrac moze da pobedi.
                if(cnt_x == k) return 'X';
                if(cnt_o == k) return 'O';
            }

    return '.';
}

int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r"); //Takmicarev output
    FILE* fsol = fopen(argv[2], "r"); //Komisijski output: samo da li postoji resenje
    FILE* fin = fopen(argv[3], "r"); //Input

    int possible;
    
    fscanf(fin, "%d %d %d", &n, &k, &t);
    fscanf(fsol, "%d", &possible);

    if(!possible)
    {
        if(fgets(str, N, fout) == NULL)
            return -1;  // greska u citanju
        str[8] = '\0';
        if(strcmp(str, "nemoguce") != 0)
            return -1;  // ocekujemo "nemoguce" a dobili smo nesto drugo
        return 0;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(fscanf(fout, " %c", &board[i][j]) != 1)
                return -1;  // nije bilo nicega da se ucita
    
    int last_i, last_j;
    if(fscanf(fout, "%d %d", &last_i, &last_j) != 2)
        return -1;  // probali smo da ucitamo i nije bilo
    last_i--; last_j--;
    
    int n_x = 0, n_o = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'X') n_x++;
            else if(board[i][j] == 'O') n_o++;
            else if(board[i][j] != '.') return -1;  // nevalidno polje

    int exp_x = (t + 1) / 2;
    int exp_o = t - exp_x;
    if(n_x != exp_x || n_o != exp_o) return -1;

    if(last_i < 0 || last_i >= n || last_j < 0 || last_j >= n) return -1;

    char should_win = (t % 2 == 0) ? 'O' : 'X';
    if(winner() != should_win) return -1;  // ne pobedjuje ko treba
    if(board[last_i][last_j] != should_win) return -1;  // poslednji potez nema smisla
    board[last_i][last_j] = '.';
    if(winner() != '.') return -1;  // ovo nije bio poslednji potez
    
    return 0;
}
