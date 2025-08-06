/**
 *    author:  feev1x
 *    created: 02.08.2025 12:48:56
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
    
    int n, a, b; std::cin >> n >> a >> b;

    std::string s; std::cin >> s;

    s = ' ' + s;

    int cnt = 0;
    for (int i = 0; i + a <= n;) {
        bool flag = false;

        for (int j = i + a; j > i; --j)
            if (s[j] == 's') {
                flag = true;
                i = j;
                break;
            }

        cnt++;
        if (!flag) {
            std::cout << "-1\n";
            exit(0);
        }
    }

    for (int i = 0; i + b <= n;) {
        bool flag = false;

        for (int j = i + b; j > i; --j)
            if (s[j] == 'e') {
                flag = true;
                i = j;
                break;
            }

        cnt++;
        if (!flag) {
            std::cout << "-1\n";
            exit(0);
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
