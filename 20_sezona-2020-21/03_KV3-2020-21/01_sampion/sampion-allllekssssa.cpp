#include<bits/stdc++.h>


using namespace std;


const long long maxV = 1e15;
long long x, y, t;

int main()
{
	cin >> x >> y >> t;

	assert(x <= maxV && x > 0);
	assert(y <= 1000 && y > 0);
	assert(t <= maxV && t > 0);

	printf("%lld\n", t + (t - 1) / x * y);
}