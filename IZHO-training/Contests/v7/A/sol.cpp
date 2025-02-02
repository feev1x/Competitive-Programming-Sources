/**
 *    author:  feev1x
 *    created: 11.01.2025 09:04:46
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        std::string s, t; std::cin >> s >> t;

        std::map<char, std::vector<int>> mp;
        std::map<char, std::vector<char>> mp1;
        std::map<std::string, int> dp, used;
        bool flag = true;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].emplace_back(i);
        }

        for (auto [key, val]: mp) {
            char ch = t[val[0]];

            for (auto u: val) {
                if (t[u] != ch) {
                    flag = false;
                }
            }

            mp1[ch].emplace_back(key);
        }

        if (!flag) {
            std::cout << "-1\n";
            continue;
        }

        std::map<char, char> mp2;
        int cnt = 0, cnt_g = 0;
        for (auto [key, val]: mp1) {
            flag = false;

            for (auto u: val) {
                if (u == key) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                mp2[key] = key;
                cnt--;
                cnt_g++;
            } else {
                mp2[key] = val[0];
            }
            cnt += (int)val.size();
        }

        if (mp2.size() == 52 && cnt_g < 52) {
            std::cout << "-1\n";
            continue;
        }

        int cn = 0;
        for (auto [key, val]: mp2) {
            if (key == val) {
                continue;
            }
            for (auto [key1, val1]: mp2) {
                if (key1 == val1 || (key != val1 || val != key1)) {
                    continue;
                }
                cn++;
            }
        }

        std::cout << cnt + cn / 2 << '\n';
    }
    return 0;
}
