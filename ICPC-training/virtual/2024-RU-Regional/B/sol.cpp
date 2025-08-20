/**
 *    author:  feev1x
 *    created: 17.08.2025 15:33:16
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<std::string> s;

    std::string t;
    while (std::getline(std::cin, t))
        s.emplace_back(t);

    {
        std::vector<std::string> new_s;

        for (int i = 0; i < s.size(); ++i) {
            bool flag = false;

            for (auto u: s[i])
                if (u != '\t' && u != ' ')
                    flag = true;

            if (flag)
                new_s.emplace_back(s[i]);
        }

        std::swap(s, new_s);
    }

    {
        std::vector<std::string> new_s;

        bool old = false;
        for (int i = 0; i < s.size(); ++i) {
            bool flag = false, fl1 = false;

            for (int j = 1; j < s[i].size(); ++j)
                if (s[i][j] == '$' && s[i][j - 1] == '$') {
                    flag = true;
                    break;
                } else if (s[i][j] != ' ' && s[i][j] != '\t' && s[i][j] != '$' || s[i][j - 1] != ' ' && s[i][j - 1] != '\t')
                    break;

            for (int j = s[i].size() - 1; j >= 0; --j) {
                if (s[i][j] == '$') {
                    fl1 = true;
                    break;
                }

                if (s[i][j] != ' ' && s[i][j] != '\t')
                    break;
            }

            if (flag) {
                if (!old)
                    new_s.emplace_back(s[i]);
                else
                    new_s.back() += s[i];

            } else {
                if (!fl1) {
                    if (!old)
                        new_s.emplace_back(s[i]);
                    else
                        new_s.back() += s[i];
                } else {
                    while (s[i].back() != '$')
                        s[i].pop_back();

                    s[i].pop_back();

                    if (!old)
                        new_s.emplace_back(s[i]);
                    else
                        new_s.back() += s[i];
                }
            }

            old = fl1;
        }

        std::swap(s, new_s);
    }

    {
        std::vector<std::string> new_s;

        for (int i = 0; i < s.size(); ++i) {
            bool flag = false;

            for (int j = 1; j < s[i].size(); ++j)
                if (s[i][j] == '$' && s[i][j - 1] == '$') {
                    flag = true;
                    break;
                } else if (s[i][j] != ' ' && s[i][j] != '\t' && s[i][j] != '$' || s[i][j - 1] != ' ' && s[i][j - 1] != '\t')
                    break;

            if (flag)
                continue;

            new_s.emplace_back(s[i]);
        }

        std::swap(s, new_s);
    }

    for (auto u: s)
        std::cout << u << '\n';
    return 0;
}
