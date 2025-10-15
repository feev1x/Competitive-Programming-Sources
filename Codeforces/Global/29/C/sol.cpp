/**
 *    author:  feev1x
 *    created: 20.09.2025 20:55:48
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
        
        s = ' ' + s;

        bool s1 = true, s2 = false, s3 = false, s4 = false;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '1') {
                if (s2)
                    s3 = true;
                else
                    s3 = false;

                if (s1 || s4)
                    s4 = true;
                else
                    s4 = false;

                s1 = s2 = false;
            } else {
                bool ns1 = false, ns2 = false, ns3 = false, ns4 = false;

                if (s3 || s1 || s2)
                    ns1 = true;

                if (s1 || s2 || s4)
                    ns2 = true;

                s1 = ns1;
                s2 = ns2;
                s3 = s4 = false;
            }
        }

        if (s1 || s2 || s4)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
