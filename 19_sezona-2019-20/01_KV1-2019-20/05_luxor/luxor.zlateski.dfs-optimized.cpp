#include <cstdint>
#include <iostream>
#include <tuple>

using std::uint64_t;

uint64_t a, b;
uint64_t sx, sy;

bool search(uint64_t digit, uint64_t mask, uint64_t x)
{
    uint64_t y = x ^ b;

    if ((digit > 31) || (static_cast<double>(x) * y > 5e18) ||
        (((x * y) & mask) != (a & mask)))
    {
        return false;
    }

    if ((x * y == a))
    {
        sx = x;
        sy = y;
        return true;
    }

    return search(digit + 1, (mask << 1) + 1, x | (1ull << digit))
               ? true
               : search(digit + 1, (mask << 1) + 1, x);
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        if (search(0, 0, 0))
        {
            std::cout << sx << ' ' << sy << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }
}
