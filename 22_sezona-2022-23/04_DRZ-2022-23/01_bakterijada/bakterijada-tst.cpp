# include <bits/stdc++.h>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

# define MAXN 100100

int t, n;

long long A[MAXN];

long long rez;

int main() {
  int i, j, k;
  scanf("%d", &t);
  while (t-- > 0) {
  	scanf("%d", &n);
  	for (i = 1; i <= n; i++)
  	  scanf("%lld", &A[i]);
  	sort(A+1, A+1+n);
  	rez = n * A[n];
  	for (i = 1; i < n; i++)
  	  rez += (i + 1) * A[i];
  	printf("%lld\n", rez);
  }
  return 0;
}
