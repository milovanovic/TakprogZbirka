#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ans += cnt[x - y];
        cnt[x - y] += 1;
    }
    printf("%lld\n", ans);
    return 0;
}
