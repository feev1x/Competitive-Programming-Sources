/**
 *    author:  feev1x
 *    created: 06.08.2025 20:33:01
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

        std::vector<int> a(n), b(n);
        for (auto &u: a)
            std::cin >> u;

        for (auto &u: b)
            std::cin >> u;

        std::vector<int> v;
        for (int i = 0; i < n; ++i)
            if (a[i] == b[i])
                v.emplace_back(a[i]);

        std::sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int mex = v.size();
        for (int i = 0; i < v.size(); ++i)
            if (i != v[i]) {
                mex = i;
                break;
            }

        for (int i = 0; i < n; ++i) {
            if (a[i] == mex || b[i] == mex) {
                v.emplace_back(mex);

                std::sort(v.begin(), v.end());

                mex = v.size();
                for (int i = 0; i < v.size(); ++i)
                    if (i != v[i]) {
                        mex = i;
                        break;
                    }

                break;
            }
        }

        std::cout << mex << '\n';
    }
    return 0;
}
