/**
 *    author:  feev1x
 *    created: 08.09.2025 21:03:26
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
        int k; int64_t x; std::cin >> k >> x;

        if (x == (1ll << k)) {
            std::cout << "0\n";
            continue;
        }
        
        int st = -1, ls = -1;
        for (int64_t i = 0; i <= k; ++i)
            if (x >> i & 1) {
                st = i;
                break;
            }

        for (int i = k; i >= 0; --i)
            if (x >> i & 1) {
                ls = i;
                break;
            }

        std::vector<int> op;
        int64_t a = 1ll << k, b = 1ll << k;
        for (int i = st + 1; i <= k; ++i) {
            if (x >> i & 1) {
                op.emplace_back(2);

                assert(!(b & 1));
                a += b >> 1;
                b >>= 1;
            } else {
                op.emplace_back(1);

                assert(!(a & 1));
                b += a >> 1;
                a >>= 1;
            }
        }

        while (a > x) {
            a >>= 1;
            op.emplace_back(1);
        }

        assert(a == x);
        
        std::cout << op.size() << '\n';
        for (int i = 0; i < op.size(); ++i)
            std::cout << op[i] << " \n"[i + 1 == op.size()];
    }
    return 0;
}
