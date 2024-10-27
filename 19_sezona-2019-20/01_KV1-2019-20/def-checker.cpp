#include <iostream>
#include <string>
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

	while (1) {
		string a, b;
		sof >> a;
		if (a.size() == 0) {
			if (has_extra_tokens(ouf)) {
				return -1;
			} else {
				return 0;
			}
		} else {
			ouf >> b;
			if (a != b) {
				return -1;
			}
		}
	}
}
