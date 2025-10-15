/**
 *    author:  feev1x
 *    created: 04.10.2025 18:14:48
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

        int cnt0 = std::count(s.begin(), s.end(), '0'), cnt1 = n - cnt0;

        std::vector<int> p0, p1;
        for (int i = 0; i < n; ++i)
            if (s[i] == '0')
                p0.emplace_back(i);
            else
                p1.emplace_back(i);

        if (!cnt0 || !cnt1) {
            std::cout << "0\n";
            continue;
        }

        int mx0 = std::max(p0.front(), n - 1 - p0.back()), mx1 = std::max(p1.front(), n - 1 - p1.back());
        for (int i = 1; i < p0.size(); ++i)
            mx0 = std::max(mx0, p0[i] - p0[i - 1] - 1);

        for (int i = 1; i < p1.size(); ++i)
            mx1 = std::max(mx1, p1[i] - p1[i - 1] - 1);

        std::cout << std::min((n - mx0) * 2 - cnt0, (n - mx1) * 2 - cnt1) << '\n';
    }
    return 0;
}
