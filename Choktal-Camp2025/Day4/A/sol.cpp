/**
 *    author:  feev1x
 *    created: 04.07.2025 09:25:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> ans(n + 1);

    std::string s; std::cin >> s;

    bool flag = false;
    std::vector<int> sm;
    int cnt = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            cnt++;

            if (!i || s[i - 1] == '0') {
                cnt++;
            }
        }

        if (s[i] == '1') {
            flag = true;
        }
    }


    int c3 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && (!i || s[i - 1] == '0') && i + 1 < n && s[i + 1] == '0' && i + 2 < n && s[i + 2] == '1' && (i + 3 >= n || s[i + 3] == '0')) {
            c3++;

            i += 3;
        } else if (s[i] == '1' && (!i || s[i - 1] == '0') && (i + 1 >= n || s[i + 1] == '0')) {
            c2++;
        }
    }

    while (q--) {
        int k; std::cin >> k;

        if (!flag) {
            std::cout << (k >= 2 ? k : 0) << '\n';

            continue;
        }

        int res = cnt;
        if (c3 > k) {
            res += k * 3;
        } else if (c2 > k - c3) {
            res += c3 * 3 + (k - c3) * 2;
        } else {
            res += c3 * 3 + c2 * 2 + (k - c3 - c2);
        }

        std::cout << res << '\n';
    }
    return 0;
}
