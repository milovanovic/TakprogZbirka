#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);

    if(n == 1) {

      cout << 3 << ' ' << 4 << endl;

      cout << 21 << ' ' << 34 << endl;
      cout << 100 << ' ' << 100 << endl;
      cout << 56 << ' ' << 78 << endl;

      cout << 2 << ' ' << 3 << ' ' << 25 << endl;
      cout << 1 << ' ' << 2 << ' ' << 100 << endl;
      cout << 1 << ' ' << 3 << ' ' << 50 << endl;
      cout << 2 << ' ' << 3 << ' ' << 70 << endl;

    } else if(n == 2) {

      cout << 8 << ' ' << 5 << endl;

      cout << 1 << ' ' << 2 << endl;
      cout << 4 << ' ' << 7 << endl;
      cout << 7 << ' ' << 12 << endl;
      cout << 1 << ' ' << 8 << endl;
      cout << 7 << ' ' << 7 << endl;
      cout << 4 << ' ' << 6 << endl;
      cout << 6 << ' ' << 9 << endl;
      cout << 9 << ' ' << 10 << endl;

      cout << 2 << ' ' << 6 << ' ' << 6 << endl;
      cout << 4 << ' ' << 6 << ' ' << 7 << endl;
      cout << 5 << ' ' << 8 << ' ' << 12 << endl;
      cout << 1 << ' ' << 8 << ' ' << 10 << endl;
      cout << 2 << ' ' << 7 << ' ' << 7 << endl;

    }
}
