/**
 *    author:  feev1x
 *    created: 30.10.2025 13:16:26
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
    
    int64_t n, f0, c, d; std::cin >> n >> f0 >> c >> d;    

    std::string s; std::cin >> s;

    s = " " + s;
    
    int64_t ls = -1;
    for (int i = n; i >= 1; --i)
        if (s[ls] == 'F') {
            ls = i;
            break;
        }

    int64_t l = 0, r = 1e15, ans = -1;
    while (l <= r) {
        int64_t m = l + r >> 1;
        
        int64_t fi = f0;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'F' && fi + c + 1 > m)
                flag = false;

            if (s[i] == 'F')
                fi = fi - d;
            else
                fi = std::min(fi + c, std::max(fi, m - c - 1));

            if (fi < 0)
                flag = false;
        }

        if (flag)
            r = m - 1, ans = m;
        else
            l = m + 1;
    }

    if (ans == -1) {
        std::cout << "NO\n";
        exit(0);
    }

    std::cout << "YES\n" << ans << '\n';

    int64_t fi = f0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'F')
            std::cout << fi + c + 1 << " \n"[i == n], fi = fi - d;
        else {
            fi = std::min(fi + c, std::max(fi, ans - c - 1));
            std::cout << std::min(fi, ans) << " \n"[i == n];
        }
    }

    return 0;
}
