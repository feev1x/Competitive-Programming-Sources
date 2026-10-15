#include "vision.h"
#include <bits/stdc++.h>

std::vector<int> getVisionPattern1d()
{
    return {3, 1, 1, 1, 2, 1};
}

int getMove1d(std::vector<int> v)
{
    int n = v.size(), m = n / 2;
    if (v[m] == 1) {
        if (v[m + 1] == 2 || v[m + 1] == 3 || v[m - 1] == 1) return m + 1;
        else return m - 1;
    } else if (v[m] == 2) {
        if (v[m + 2] == 3) return m + 2;
        else return m - 2;
    } else {
        if (v[m - 2] == 2) return m + 3;
        else return m - 3;
    }
}

std::vector<std::vector<int>> getVisionPattern2d()
{
    return {{3, 1, 1, 1, 2, 1},
            {1, 2, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 2, 1, 1},
            {2, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
    };
}

std::pair<int, int> getMove2d(std::vector<std::vector<int>> v)
{
    int n = v.size();
    int m = n / 2;
    int x = 0, y = 0;
    if (v[m][m] == 1) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 3) return {i, j};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 2) return {i, j};
        return {0, 0};
    } else if (v[m][m] == 2) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 3) return {i, j};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 2 && i != m && j != m) return {n - i - 1, n - j - 1};
    } else {
        if (v[m][m - 2] == 2) y = 3;
        else y = -3;
        if (v[m - 2][m] == 2) x = 3;
        else x = -3;
    }
    return {m + x, m + y};
}
