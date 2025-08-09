/**
 *    author:  feev1x
 *    created: 09.08.2025 16:18:22
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
        
    std::vector<std::string> s1, s2;
    std::unordered_map<std::string, std::string> mp;

    std::string s;

    bool flag = false;
    while (std::getline(std::cin, s)) {
        if (s == "\\end{thebibliography}")
            break;

        if (s == "\\begin{thebibliography}{99}") {
            flag = true;
            continue;
        }
        
        if (flag) {
            std::string t, st;

            bool in = false, out = false;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '{' && !out) {
                    in = true;
                    continue;
                }

                if (s[i] == '}' && !out) {
                    in = false;
                    out = true;
                    continue;
                }

                if (in)
                    t += s[i];
                else if (out)
                    st += s[i];
            }

            mp[t] = st;

            s2.emplace_back(t);
        } else {
            std::string t, st;

            bool in = false;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '\\') {
                    in = true;

                    i += 5;
                    continue;
                }

                if (s[i] == '}' && in) {
                    in = false;

                    s1.emplace_back(t);
                    t.clear();
                    continue;
                }

                if (in)
                    t += s[i];
            }
        }
    }

    if (s1 == s2) {
        std::cout << "Correct\n";
        exit(0);
    }

    std::cout << "Incorrect\n";
    std::cout << "\\begin{thebibliography}{99}\n";
    for (auto u: s1)
        std::cout << "\\bibitem{" << u << "}" << mp[u] << '\n';

    std::cout << "\\end{thebibliography}\n";
    return 0;
}
