#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> distribution(1, 6);
    int h = stoi(argv[1]);
    int n = stoi(argv[2]);

    assert(n * h <= 1000000);
    cout << h << " " << n << endl;
    for (int i = 0; i < h; i++) {
        vector<int> row(n, 0);
        while ((count(row.begin(), row.end(), 1) == 0)) {
            row.clear();
            for (int j = 0; j < n; j++) {
                if (argc >= 5 && j > 0 && row[j - 1] == 0) {
                    row.push_back(1);
                } else {
                    row.push_back(distribution(rng) <= 4);
                }

            }
        }
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
