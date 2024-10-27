#include <cstdio>
#define ld long long int
#define m32 0xffffffffll
ld t, a, b, r;
ld bp(ld x, ld k, ld f(ld))
{
	while (k) if (f(x + k) > 0) x += k; else k >>= 1;
	return f(x) > 0 ? x + 1 : x;
}
void resi()
{
	ld bm = b & m32, j = 0, h = 0;
	for (ld bb = bm; bb; bb >>= 1) j += bb & 1;
	if (j <= 16) for (ld s = m32 + 1; s; s = (s ^ bm ^ -1ll) + 1)
	{
		r = (r = b - 2 * (bm ^ (s &= bm))) > 0 ? r : -r;
		j = bp(r + 1, m32, [](ld x) { return r - x + a / x; });
		if (a % j == 0 && (j ^ (a / j)) == b && (h = j)) break;
	}
	else for (ld s = m32 + 1; s; s = (m32 ^ s ^ bm ^ -1ll) + 1)
	{
		r = b + 2 * (s &= bm ^ m32);
		j = bp(r / 2, r / 2 + 2, [](ld x) { return r - x - a / x; });
		if (a % j == 0 && (j ^ (a / j)) == b && (h = j)) break;
	}
	if (h) printf("%lld %lld\n", b ^ h,  h); else printf("-1\n");
}
int main()
{
	for (scanf("%lld", &t); t--; scanf("%lld%lld", &a, &b), resi());
	return 0;
}