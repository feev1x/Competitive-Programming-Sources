#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::string s, t; std::cin >> s >> t;

    std::vector<int> pos(n + m);
    for (int i = 0, j = 0; i < n + m && j < n + m;) {
        if (s[i] == '0') {
            i++;
        } else {
            if (t[j] == '1') {
                pos[i] = j;
                i++, j++;
            } else {
                j++;
            }
        }
    }

    int ans = 0;
    {
        int r = -1, res = 0;
        for (int i = 0; i < n + m; ++i) {
            if (s[i] == '0') {
                continue;
            }

            int l = std::min(pos[i], i);

            if (r - l >= -1) {
                r++;
                res += !!r;
                continue;
            }

            int cnt = std::max(pos[i], i) - r - 1;

            if (cnt > 1) {
                res += cnt - 1;
            }

            r = std::max(pos[i], i);
        }

        int cnt = n + m - r - 1;

        if (cnt > 1) {
            res += cnt - 1;
        }

        ans = res;
    }

    {
        int r = -1, res = 0;
        for (int i = 0; i < n + m; ++i) {
            if (s[i] == '0') {
                continue;
            }

            int l = std::min(pos[i], i);

            if (r - l >= -1 && r != -1) {
                r++;
                res++;
                continue;
            }

            int cnt = std::max(pos[i], i) - r - 1;

            if (cnt > 1) {
                res += cnt - 1;
            }

            r = std::max(pos[i], i);
        }

        int cnt = n + m - r - 1;

        if (cnt > 1) {
            res += cnt - 1;
        }

        ans = std::max(ans, res);
    }

    std::cout << ans << '\n';
    return 0;
}
