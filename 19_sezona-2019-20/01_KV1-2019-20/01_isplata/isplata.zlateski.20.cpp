#include <array>
#include <iostream>
#include <string>

std::array<int, 10> costs{0, 1, 1, 2, 2, 1, 2, 2, 3, 3};

// resenje podrazumeva da je takmicar sam izracunao tabelu

int main()
{
    int i;
    std::cin >> i;
    std::cout << costs[i] << "\n";
}
