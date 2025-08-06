/**
 *    author:  feev1x
 *    created: 31.07.2025 21:52:49
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

inline int ask(std::vector<int> a) {
    if (a.size() > 1) {
        std::cout << "? " << a.size();

        for (auto u: a)
            std::cout << ' ' << u;

        std::cout << std::endl;
    } else
        return 0;

    int got; std::cin >> got;

    return got;
}

inline int ask(int l, int r) {
    if (r - l + 1 > 1) {
        std::cout << "? " << r - l + 1;

        for (int i = l; i <= r; ++i)
            std::cout << ' ' << i;

        std::cout << std::endl;
    } else 
        return 0;

    int got; std::cin >> got;

    return got;
}

constexpr int K = 6;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int s = -1, e = -1;
        if (ask(1, n)) {
            int l = 1, r = n;

            while (r - l + 1 > 2) {
                int m = l + r >> 1;

                if (ask(l, m))
                    r = m;
                else
                    l = m;
            }

            s = l, e = r;
        } else {
            s = n, e = 1;
        }

        std::string res;
        for (int i = 1; i <= n; ++i) {
            std::vector<int> vec, v1;

            int cnt = 0;
            for (int j = 0; i + j <= n; ++j) {
                int t = j + 1;

                if (vec.size() + t * 2 > 1000)
                    break;

                cnt = j;

                while (t--) {
                    vec.emplace_back(s);
                    vec.emplace_back(i + j);
                }
                
                vec.emplace_back(s);
                
                v1.emplace_back(s);
                v1.emplace_back(i + j);
                v1.emplace_back(s);
            }

            vec.pop_back();
            v1.pop_back();

            int got = ask(vec) + ask(v1);

            for (int j = 0; j <= cnt; ++j) {
                if (got >> (j + 1) & 1)
                    res += ")";
                else
                    res += "(";
            }

            i += cnt;
        }

        assert(res.size() == n);
        std::cout << "! " << res << std::endl;
    }

    return 0;
}
