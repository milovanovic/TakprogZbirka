#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}
int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);
	int Q;
	inf >> Q;
	for(int i=0;i<Q;i++){
        string moj,takmicar;
        sof >> moj;
        ouf >> takmicar;
        if(moj!=takmicar)
            return -1;
        if(moj=="Ne"){
            sof >> moj;
            ouf >> takmicar;
            if(moj!=takmicar)
                return -1;
        }
	}
    if(has_extra_tokens(ouf))
        return -1;
    return 0;
}
