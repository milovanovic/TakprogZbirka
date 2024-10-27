#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 generator;

vector<int> counts(vector<int> a) {
    map<int, int> cnt;
    for (int x : a) {
        cnt[x]++;
    }
    vector<int> ret;
    for (auto x : cnt) {
        ret.push_back(x.second);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

string makeFileName(string path, int testIdx) {
    if (*path.rbegin() != '/') {
        path += '/';
    }
    stringstream ss;
    ss << path;
    ss << testIdx;
    ss << ".in";
    return ss.str();
}

void makeTest(int position, int offset, int n, string path, uniform_int_distribution<int> distribution, int testIdx) {
    string fileName = makeFileName(path, testIdx);
    freopen(fileName.c_str(), "w", stdout);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = distribution(generator);
    }
    vector<int> cnt = counts(a);
    if (position == 2) {
        position = cnt.size() - 1;
    } else if (position == 1) {
        position = cnt.size() / 2;
    }
    int k = cnt[position] + offset;
    if (k <= 0) {
        k = 1;
    }
    if (k > n) {
        k = n;
    }
    cout << n << " " << k << endl;
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    a.clear();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    if (argc < 4) {
        cerr << "n, path, testIdx";
        return 0;
    }
//    int n = stoi(argv[1]);
    string path = argv[2];
    int testIdx = stoi(argv[3]);

    int n = 1000000;
    uniform_int_distribution<int> distributionFull(-n, n);
    makeTest(0, -1, n, path, distributionFull, 3);
    makeTest(0, 0, n, path, distributionFull, 4);
    makeTest(0, 1, n, path, distributionFull, 5);
    makeTest(1, -2, n, path, distributionFull, 6);
    makeTest(1, -1, n, path, distributionFull, 7);
    makeTest(1, 1, n, path, distributionFull, 8);
    makeTest(1, 2, n, path, distributionFull, 9);
    makeTest(2, -1, n, path, distributionFull, 10);
    makeTest(2, 0, n, path, distributionFull, 11);
    makeTest(2, 1, n, path, distributionFull, 12);

    n = 1000;
    uniform_int_distribution<int> distributionQuadratic(-n, n);
    makeTest(0, 0, n, path, distributionQuadratic, 13);
    makeTest(1, -1, n, path, distributionQuadratic, 14);
    makeTest(1, 0, n, path, distributionQuadratic, 15);
    makeTest(1, 1, n, path, distributionQuadratic, 16);
    makeTest(2, 0, n, path, distributionQuadratic, 17);

    n = 1000000;
    uniform_int_distribution<int> distributionSmall(-1, 1);
    makeTest(0, 0, n, path, distributionSmall, 18);
    makeTest(1, -1, n, path, distributionSmall, 19);
    makeTest(1, 0, n, path, distributionSmall, 20);
    makeTest(1, 1, n, path, distributionSmall, 21);
    makeTest(2, 0, n, path, distributionSmall, 22);





    return 0;
}
