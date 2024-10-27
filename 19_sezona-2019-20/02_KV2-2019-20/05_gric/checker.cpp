#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define cin blabla
#define cout blablabaklldf

typedef long double ld;

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
		ld tacno = -12, takmicar = -12;
		sof >> tacno;
		ouf >> takmicar;
		if (tacno == -12)
			break;
		if (takmicar == -12)
			return -1;

		if (abs(tacno - takmicar) / max(ld(1), tacno) > 1e-6)
			return -1;
	}

	if (has_extra_tokens(ouf))
		return -1;
}
