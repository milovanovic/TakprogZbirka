#include <iostream>
#include <string>

#define MAXN 3000

int poklapanje(std::string& s, int n, int p, int j) {
  if (p - j < 0 || p + j - 1 >= n) {
    return 0;
  }
  return s[p - j] == s[p + j - 1];
}

int max(int x, int y) {
  return x > y? x : y;
}

std::string s;
int n;
int dp[MAXN + 1][MAXN + 1];
int broj_poklapanja;
int resenje;

int main() {
  // efikasnost standardnog ulaza i izlaza
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // ulaz
  std::cin >> s;
  n = s.length();

  // inicijalizacija DP
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = (i == j) - 1;
    }
  }

  // DP rekurentna veza
  for (int i = 0; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      for (int t = 2; t <= i - j; t++) {
        broj_poklapanja = 0;
        for (int x = 1; x <= t && x <= j; x++) {
          broj_poklapanja += poklapanje(s, n, n - i + j, x);
        }
        dp[i][j] = max(dp[i][j], dp[i - j][t] + broj_poklapanja);
      }
    }
  }
  
  // resenje: sve dozvoljene duzine prvog reda
  resenje = dp[n][0];
  for (int i = 1; i <= n; i++) {
    resenje = max(resenje, dp[n][i]);
  }

  // izlaz
  std::cout << resenje << std::endl;
  return 0;
}
