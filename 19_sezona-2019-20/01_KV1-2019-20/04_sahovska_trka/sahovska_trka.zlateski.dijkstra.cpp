#include <iostream>
#include <map>
#include <string>
#include <vector>

struct coordinate
{
    int p;
    int r;
    int c;
};

using map_t = std::multimap<int, coordinate>;

int visited[5][500][500];

map_t::iterator iterators[5][500][500];

int main()
{
    map_t map;

    int R, C;
    std::cin >> R >> C;

    std::vector<std::string> table(R);
    for (auto& r : table)
    {
        std::cin >> r;
    }

    auto const enqueue = [&](int value, int p, int r, int c) {
        if (r >= 0 && r < R && c >= 0 && c < C && table[r][c] == '.')
        {
            if (visited[p][r][c] != 2)
            {
                if (visited[p][r][c] == 1)
                {
                    if (value < iterators[p][r][c]->first)
                    {
                        auto coor = iterators[p][r][c]->second;
                        map.erase(iterators[p][r][c]);
                        iterators[p][r][c] = map.insert({value, coor});
                    }
                }
                else
                {
                    coordinate coor{p, r, c};
                    iterators[p][r][c] = map.insert({value, coor});
                    visited[p][r][c]   = 1;
                }
            }
        }
    };

    auto const try_swap = [&](int value, int r, int c) {
        for (int i = 0; i < 5; ++i)
        {
            enqueue(value + i + 1, i, r, c);
        }
    };

    std::vector<std::function<void(int, int, int)>> move_fns(5);

    // auto const move_king
    move_fns[0] = [&](int value, int r, int c) {
        int const dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int const dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; ++i)
        {
            enqueue(value + 1, 0, r + dr[i], c + dc[i]);
        }
    };

    // auto const move_bishop
    move_fns[1] = [&](int value, int r, int c) {
        int const dr[4] = {1, 1, -1, -1};
        int const dc[4] = {1, -1, 1, -1};

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; r + dr[i] * j >= 0 && r + dr[i] * j < R &&
                            c + dc[i] * j >= 0 && c + dc[i] * j < C &&
                            table[r + dr[i] * j][c + dc[i] * j] == '.';
                 ++j)
            {
                enqueue(value + 1, 1, r + dr[i] * j, c + dc[i] * j);
            }
        }
    };

    // auto const move_rook
    move_fns[2] = [&](int value, int r, int c) {
        int const dr[4] = {1, -1, 0, 0};
        int const dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; r + dr[i] * j >= 0 && r + dr[i] * j < R &&
                            c + dc[i] * j >= 0 && c + dc[i] * j < C &&
                            table[r + dr[i] * j][c + dc[i] * j] == '.';
                 ++j)
            {
                enqueue(value + 1, 2, r + dr[i] * j, c + dc[i] * j);
            }
        }
    };

    // auto const move_knight
    move_fns[3] = [&](int value, int r, int c) {
        int const dr[8] = {1, 1, 2, 2, -1, -1, -2, -2};
        int const dc[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        for (int i = 0; i < 8; ++i)
        {
            enqueue(value + 1, 3, r + dr[i], c + dc[i]);
        }
    };

    // auto const move_queen
    move_fns[4] = [&](int value, int r, int c) {
        int const dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int const dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; ++i)
        {
            for (int j = 1; r + dr[i] * j >= 0 && r + dr[i] * j < R &&
                            c + dc[i] * j >= 0 && c + dc[i] * j < C &&
                            table[r + dr[i] * j][c + dc[i] * j] == '.';
                 ++j)
            {
                enqueue(value + 1, 4, r + dr[i] * j, c + dc[i] * j);
            }
        }
    };

    enqueue(0, 0, 0, 0);

    while (map.size())
    {
        auto i = map.begin();
        auto v = i->first;
        auto c = i->second;

        if (c.r == R - 1 && c.c == C - 1)
        {
            std::cout << v << "\n";
            return 0;
        }

        map.erase(i);
        visited[c.p][c.r][c.c] = 2;

        try_swap(v, c.r, c.c);
        move_fns[c.p](v, c.r, c.c);
    }

    std::cout << "-1\n";
}
