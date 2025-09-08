/**
 *    author:  feev1x
 *    created: 07.09.2025 10:33:31
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

    int m = 1 << n;
    int val = k / m, cnt = k % m;

    if (cnt == 0) {
        std::cout << "0\n";

        for (int i = 0; i < m; ++i)
            std::cout << val << " \n"[i == m - 1];

        exit(0);
    }

    auto Rec = [&](auto &&self, int l, int r, int x) -> void {
        if (l == r) {
            assert(x <= 1);

            std::cout << val + x << " \n"[l == m - 1];
            return;
        }

        int mid = l + r >> 1;

        self(self, l, mid, x / 2);
        self(self, mid + 1, r, x - x / 2);
    };

    std::cout << "1\n";
    Rec(Rec, 0, m - 1, cnt);
    return 0;
}
