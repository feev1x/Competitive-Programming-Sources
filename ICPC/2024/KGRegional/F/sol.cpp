/**
 *    author:  feev1x
 *    created: 30.10.2025 10:47:23
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
    
    int n; std::cin >> n;

    int s, f; std::cin >> s >> f;

    std::vector<int64_t> add(n + 1);
    std::vector<std::pair<int, bool>> sl;
    for (int i = 0; i < n; ++i) {
        int l, r; std::cin >> l >> r;

        if (r < s || l > f)
            continue;

        l = std::max(l, s);
        r = std::min(r, f);

        sl.emplace_back(l, 1);
        sl.emplace_back(r, 0);
    }

    std::sort(sl.begin(), sl.end());

    int old = s, cnt = 0;
    for (auto [i, ad]: sl) {
        add[cnt] += i - old;

        if (ad)
            cnt++;
        else
            cnt--;

        old = i;
    }


    if (old < f)
        add[cnt] += f - old;

    int64_t res = add[0];
    for (int i = 1; i <= n; ++i)
        std::cout << res << " \n"[i == n], res += add[i];

    return 0;
}
