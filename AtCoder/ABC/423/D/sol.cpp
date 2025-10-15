/**
 *    author:  feev1x
 *    created: 14.09.2025 18:32:53
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
#define int int64_t
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::multiset<std::pair<int, int>> st;

    int ls = 0, sz = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c; std::cin >> a >> b >> c;

            while (st.size() && st.begin()->first <= ls) {
                sz -= st.begin()->second;
                st.erase(st.begin());
            }
        if (ls <= a || !i) {
            ls = a;

            while (st.size() && st.begin()->first <= ls) {
                sz -= st.begin()->second;
                st.erase(st.begin());
            }
        }

        while (st.size() && st.begin()->first <= ls) {
            sz -= st.begin()->second;
            st.erase(st.begin());
        }

        assert(ls && (st.empty() || st.begin()->first > ls));

        while (st.size() && sz + c > k) {
            sz -= st.begin()->second;
            ls = std::max(ls, st.begin()->first);
            st.erase(st.begin());
        }

        while (st.size() && st.begin()->first <= ls) {
            sz -= st.begin()->second;
            st.erase(st.begin());
        }

        st.emplace(ls + b, c);
        sz += c;

        assert(sz <= k);
        assert(ls >= a && (st.empty() || st.begin()->first > ls));

        std::cout << ls << '\n';
    }

    return 0;
}
