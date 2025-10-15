/**
 *    author:  feev1x
 *    created: 17.09.2025 21:58:21
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string s; std::cin >> s;

        if (n & 1) {
            std::cout << "-1\n";
            continue;
        }

        int cnt = 0, cnt1 = 0;

        std::stack<char> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || stk.top() != s[i])
                stk.emplace(s[i]);
            else
                cnt++, stk.pop();
        }

        bool op = (stk.empty() || stk.top() == ')' ? true : false);

        cnt1 = stk.size();

        assert(cnt1 % 2 == 0);
        if (cnt == 0 && !op) {
            std::cout << "-1\n";
            continue;
        }

        if (cnt % 2 == 0) {
            for (int i = 0; i < cnt; ++i)
                std::cout << '(';

            if (!op) {
                std::cout << ')';
                cnt1 -= 2;
            }

            for (int i = 0; i < cnt1 / 2; ++i)
                std::cout << "()";

            if (!op)
                std::cout << '(';

            for (int i = 0; i < cnt; ++i)
                std::cout << ')';

            std::cout << '\n';
            continue;
        }

        std::cout << "-1\n";
    }
    return 0;
}
