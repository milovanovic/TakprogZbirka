#include <cstdio>
#include <algorithm>

const int N = 100005;
int x[N], y[N], z[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    for(int i = 0; i < n; i++) scanf("%d", &y[i]);
    for(int i = 0; i < n; i++) scanf("%d", &z[i]);

    for(int i = 0; i < n; i++) z[i] = y[z[i] - 1];
    std::sort(x, x + n);
    std::sort(z, z + n);

    int i = 0, j = 0, cnt = 0;
    long long res = 0;

    while(i < n) {
        int nx = 0, nz = 0;

        while(j < n && z[j] < x[i]) j++;
        while(j < n && z[j] == x[i]) {
            j++;
            nz++;
        }

        int curr = x[i];
        while(i < n && x[i] == curr) {
            i++;
            nx++;
        }

        res += (long long)nx * (long long)nz;
    }

    printf("%lld\n", res);
    return 0;
}
