#include <cstdint>
#include <iostream>

using std::uint64_t;

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        bool     found = false;
        uint64_t a, b;
        std::cin >> a >> b;

        for (uint64_t x = 0; static_cast<double>(x) * x <= a; ++x)
        {
            uint64_t y = x ^ b;
            if (x * y == a)
            {
                std::cout << x << ' ' << y << "\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "-1\n";
        }
    }
}
