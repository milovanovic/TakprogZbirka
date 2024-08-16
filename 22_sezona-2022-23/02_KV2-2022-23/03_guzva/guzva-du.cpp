# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

using namespace std;

# define BIG 1ll << 60;

int **mat;
long long **dp12;
long long **dp21;
long long **tot12;
long long **tot21;
long long **min1;
long long **min2;

void rezervisi(int m, int n) {
  mat = new int*[m];
  dp12 = new long long*[m];
  dp21 = new long long*[m];
  tot12 = new long long*[m];
  tot21 = new long long*[m];
  min1 = new long long*[m];
  min2 = new long long*[m];
  for (int i = 0; i < m; i++) {
    mat[i] = new int[n];
    dp12[i] = new long long[n];
    dp21[i] = new long long[n];
    tot12[i] = new long long[n];
    tot21[i] = new long long[n];
    min1[i] = new long long[n];
    min2[i] = new long long[n];
  }
}

void oslobodi(int m, int n) {
  for (int i = 0; i < m; i++) {
  	delete [] mat[i];
  	delete [] dp12[i];
  	delete [] dp21[i];
  	delete [] tot12[i];
  	delete [] tot21[i];
  	delete [] min1[i];
  	delete [] min2[i];
  }
  delete [] mat;
  delete [] dp12;
  delete [] dp21;
  delete [] tot12;
  delete [] tot21;
  delete [] min1;
  delete [] min2;
}

void pripremi(int m, int n) {
  int mp2;
  int np2;
  int i, j, k;
  
  mp2 = m + 2;
  np2 = n + 2;

  for (i = 0; i < mp2; i++) {
  	dp12[i][0] = BIG;
  	dp12[i][n+1] = BIG;
  	dp21[i][0] = BIG;
  	dp21[i][n+1] = BIG;
  	tot12[i][0] = BIG;
  	tot12[i][n+1] = BIG;
  	tot21[i][0] = BIG;
  	tot21[i][n+1] = BIG;
  }
  for (j = 0; j < np2; j++) {
  	dp12[0][j] = BIG;
  	dp12[m+1][j] = BIG;
  	dp21[0][j] = BIG;
  	dp21[m+1][j] = BIG;
  	tot12[0][j] = BIG;
  	tot12[m+1][j] = BIG;
  	tot21[0][j] = BIG;
  	tot21[m+1][j] = BIG;
  }

  dp12[1][1] = mat[1][1];
  for (i = 2; i <= m; i++) {
  	dp12[i][1] = dp12[i-1][1] + mat[i][1];
  }
  for (j = 2; j <= n; j++) {
  	dp12[1][j] = dp12[1][j-1] + mat[1][j]; 
    for (i = 2; i <= m; i++) {
  	  dp12[i][j] = min(dp12[i-1][j], dp12[i][j-1]) + mat[i][j];
    }
  }

  dp21[m][n] = mat[m][n];
  for (i = m-1; i >= 1; i--) {
  	dp21[i][n] = dp21[i+1][n] + mat[i][n];
  }
  for (j = n-1; j >= 1; j--) {
  	dp21[m][j] = dp21[m][j+1] + mat[m][j]; 
    for (i = m-1; i >= 1; i--) {
  	  dp21[i][j] = min(dp21[i+1][j], dp21[i][j+1]) + mat[i][j];
    }
  }

  for (i = 1; i <= m; i++) {
  	for (j = 1; j <= n; j++) {
  	  tot12[i][j] = dp12[i][j] + dp21[i][j+1];
  	  tot21[i][j] = dp21[i][j] + dp12[i][j-1];
	}
  }

  for (j = 1; j <= n; j++) {
  	min1[0][j] = tot12[0][j];
  	for (i = 1; i < mp2; i++) {
  	  min1[i][j] = min(min1[i-1][j],  tot12[i][j]);
	}
  	min2[m+1][j] = tot21[0][j];
  	for (i = m; i >= 0; i--) {
  	  min2[i][j] = min(min2[i+1][j],  tot21[i][j]);
	}
  }
}

long long resi(int k, int l) {
  return min(min1[k-1][l], min2[k+1][l]);
}

int main() {
  int q;
  int m, n;
  int k, l;
  scanf("%d%d", &m, &n);
  rezervisi(m+2, n+2);
  for (int i = 1; i <= m; i++) {
  	for (int j = 1; j <= n; j++) {
      scanf("%d", &mat[i][j]);
	}
  }
  pripremi(m, n);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &k, &l);
    printf("%lld\n", resi(k, l));
  }
  oslobodi(m+2, n+2);
  return 0;
}

