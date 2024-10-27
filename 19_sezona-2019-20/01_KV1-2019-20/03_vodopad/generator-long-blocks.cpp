#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    random_device dev;
    mt19937 rng(dev());
    int h = stoi(argv[1]);
    int n = stoi(argv[2]);
    uniform_int_distribution<mt19937::result_type> distribution(0, n - 1);

    assert(n * h <= 1000000);
    cout << h << " " << n << endl;
    for (int i = 0; i < h; i++) {
        vector<int> row(n, 0);
        set<int> positions;
        while (positions.size() < 3) {
            int idx = distribution(rng);
            positions.insert(idx);
            row[idx] = 1;
        }
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
