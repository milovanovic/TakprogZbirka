#include "testlib.h"
#include <iostream>
using namespace std;


#define MAX4 200005
#define MAXN 1000000009

int main(int argc, char* argv[])
{

	registerGen(argc, argv, 1);

	int t = atoi(argv[1]);

    if (t == 1) printf("3 %d", rnd.next(1,MAXN));
    if (t == 2) printf("%d %d", rnd.next(1,5), rnd.next(1,5));
    if (t == 3) {
        int a = rnd.next(1, MAXN);
        printf("%d %d", a, a);
    }
    if (t == 4) printf("%d %d", rnd.next(MAX4/2, MAX4), rnd.next(MAX4/2, MAX4));
    if (t == 5) printf("%d %d", rnd.next(1, MAXN), rnd.next(1, MAXN));

    printf("\n");
	return 0;
}
