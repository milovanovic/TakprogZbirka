#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define OK 0
#define WA -1

int main(int argc, char *argv[]) {
    ifstream ouf(argv[1]); //Takmicar
    ifstream sof(argv[2]); //Komisija
    ifstream inf(argv[3]); //Input

    long long n, gb, rb, rg;
    inf >> n >> gb >> rb >> rg;

    string possible;
    sof >> possible;

    string found;
    ouf >> found;
    if(found != possible) return WA;
    if(possible == "nemoguce") return OK;
    
    long long r, g, b;
    ouf >> r >> g >> b;
    if(ouf.fail()) return WA;

    if(r < 1 || g < 1 || b < 1) return WA;
    if(r > n || g > n || b > n) return WA;
    if(r + g + b != n) return WA;

    if(r + g + 1 < rg) return WA;
    if(g + b + 1 < gb) return WA;
    if(r + b + 1 < rb) return WA;

    return OK;
}
