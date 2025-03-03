/**
 *    author:  feev1x
 *    created: 20.02.2025 15:48:52
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    std::string s; std::cin >> s;

    int cnt_all = std::count(s.begin(), s.end(), '1'), cnt = 0, pos = -1;
    for (int i = 0; i < n; ++i) {
        cnt += s[i] - '0';

        if (cnt_all & 1) {
            if (cnt_all - cnt == cnt - 1) {
                pos = i;

                break;
            }
        } else {
            if (2 * cnt == cnt_all) {
                pos = i;

                break;
            }
        }
    }

    int64_t res = 0;
    int posl = pos - 1, posr = pos + 1;
    for (int i = 1; i < n; ++i) {
        int j = pos + i;

        if (j < n && s[j] == '1') {
            res += j - posr;

            posr++;
        }

        j = pos - i;

        if (j >= 0 && s[j] == '1') {
            res += posl - j;

            posl--;
        }
    }

    std::cout << res << '\n';
    return 0;
}
