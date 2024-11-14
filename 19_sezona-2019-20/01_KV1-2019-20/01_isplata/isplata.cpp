#include <array>
#include <iostream>
#include <string>

std::array<int, 10> costs{0, 1, 1, 2, 2, 1, 2, 2, 3, 3};

int main()
{
    int total = 0;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        total += costs[s[i] - '0'];
    }

    std::cout << total << "\n";
}
