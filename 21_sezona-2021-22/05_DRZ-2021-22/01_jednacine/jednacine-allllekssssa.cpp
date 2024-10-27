#include<bits/stdc++.h>

using namespace std;

const long long maxV = 1000000000000000000;

long long a, b, x, y;

int getSumCif(long long x) {
	int sumCif = 0;

	while(x > 0) {
		sumCif+=x%10;
		x/=10;
	}

	return sumCif;
}

int main() {

	cin >> x >> y >> a >> b;

	assert(x > 0 && x <= maxV);
	assert(y > 0 && y <= maxV);
	assert(a >= 0 && a <= maxV);
	assert(b >= 0 && b <= maxV);

	bool hasSolution = false;
    int count = 0;

	for (int sumCif = 1; sumCif <= 200; sumCif++) {
		long long val = sumCif * a + b;
		if (2 * maxV / sumCif >= a && getSumCif(val) == sumCif && val >= x && val<=y) {
			hasSolution = true;
			printf("%lld\n", val);
            count++;
		}
	}

    assert(count <= 1);

	if (!hasSolution) {
		printf("-1\n");
	}

	return 0;
}