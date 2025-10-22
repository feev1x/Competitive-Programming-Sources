/**
 *    author:  feev1x
 *    created: 19.10.2025 17:06:29
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
    
    int n, k; std::cin >> n >> k;    

    std::vector<int> q(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> q[i], p[i] = i;

    int cnt = 0;
    do {
        std::vector<int> q1(n + 1);

        for (int i = 1; i <= n; ++i) {
            int u = i;

            for (int j = 0; j < k; ++j)
                u = p[u];

            q1[i] = u;
        }

        if (q1 == q) {
            cnt++;

//            for (int i = 1; i <= n; ++i)
//                std::cout << p[i] << " \n"[i == n];
        }
    } while (next_permutation(p.begin() + 1, p.end()));

    std::cout << cnt << '\n';
    return 0;
}
