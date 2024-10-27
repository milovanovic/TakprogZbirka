#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_X = 100000000;
//const int MAX_X = 20;

mt19937 generator;
uniform_int_distribution<int> distribution(-MAX_X, MAX_X);


void generate(string filePath, int n) {
    fstream fs;
    fs.open(filePath, fstream::out);
    fs << n << " " << distribution(generator) << endl;
    for (int i = 0; i < n; i++) {
        fs << distribution(generator) << " ";
    }
    fs.close();
}

void generateExtreme(string filePath, int n, bool xLeft) {
    vector<int> a;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i] = distribution(generator);
    }
    sort(a.begin(), a.end());
    int x;
    if (xLeft) {
        x = a[0];
        a.erase(a.begin());
    } else {
        x = a[n];
        a.erase(a.begin() + n);
    }
    shuffle(a.begin(), a.end(), generator);
    fstream fs;
    fs.open(filePath, fstream::out);
    fs << n << " " << x << endl;
    for (int i = 0; i < n; i++) {
        fs << a[i] << " ";
    }
    fs.close();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    string path = argv[1];
    if (*path.rbegin() != '/') {
        path += "/";
    }
    // 6 sa n <= 10
    generate(path + "3.in", 10);
    generate(path + "4.in", 10);
    generate(path + "5.in", 10);
    generate(path + "6.in", 10);
    generate(path + "7.in", 10);
    generate(path + "8.in", 10);
    // 3 sa x levo
    generateExtreme(path + "9.in", 1000000, true);
    generateExtreme(path + "10.in", 1000000, true);
    generateExtreme(path + "11.in", 1000000, true);
    // 3 sa x desno
    generateExtreme(path + "12.in", 1000000, false);
    generateExtreme(path + "13.in", 1000000, false);
    generateExtreme(path + "14.in", 1000000, false);
    // 8 totalno random
    generate(path + "15.in", 1000000);
    generate(path + "16.in", 1000000);
    generate(path + "17.in", 1000000);
    generate(path + "18.in", 1000000);
    generate(path + "19.in", 1000000);
    generate(path + "20.in", 1000000);
    generate(path + "21.in", 1000000);
    generate(path + "22.in", 1000000);
    return 0;
}
