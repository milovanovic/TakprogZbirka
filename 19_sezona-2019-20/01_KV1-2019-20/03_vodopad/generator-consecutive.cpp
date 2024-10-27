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
        if ((i & 1) == 1) {
            cout << "1 ";
        }
        for (int j = 1; j < n; j++) {
            cout << "0 ";
        }
        if ((i & 1) == 0) {
            cout << "1 ";
        }
        cout << endl;
    }
    return 0;
}
