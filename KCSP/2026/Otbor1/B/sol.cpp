#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto Get = [&](std::array<std::array<int, 3>, 3> a, char c) {
        auto b = a;

        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= 2; ++j) {
                switch(c) {
                    case '0': {
                        b[i][j] = a[i][j];
                        break;
                    } case '1': {
                        b[j][i] = a[i][j];
                        break;
                    } case '2': {
                        b[2 - j + 1][2 - i + 1] = a[i][j];
                        break;
                    } case 'H': {
                        b[2 - i + 1][j] = a[i][j];
                        break;
                    } case 'V': {
                        b[i][2 - j + 1] = a[i][j];
                        break;
                    } case 'A': {
                        b[j][2 - i + 1] = a[i][j];
                        break;
                    } case 'B': {
                        b[2 - i + 1][2 - j + 1] = a[i][j];
                        break;
                    } default: {
                        b[2 - j + 1][i] = a[i][j];
                        break;
                    }
                }
            }
        }

        return b;
    };

    std::array<std::array<int, 3>, 3> a;

    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            a[i][j] = (i - 1) * 2 + j - 1;
        }
    }

    auto b = a;

    std::string s; std::cin >> s;
    for (auto u: s) {
        a = Get(a, u);
    }

    std::string t = "012HVABC";

    for (auto u: t) {
        if (Get(b, u) == a) {
            std::cout << u << '\n';
            exit(0);
        }
    }

    assert(false);
    return 0;
}
