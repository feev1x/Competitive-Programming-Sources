/**
 *    author:  feev1x
 *    created: 06.08.2025 21:06:18
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

        std::string res;

        int cnt = 0;

        std::vector<int> p(n + 1), c(n + 2), ar(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (__builtin_popcount(i) == 1)
                res += "1";
            else
                res += "0";

            if (res.back() == '1' && s[i - 1] == '0')
                cnt++;

            ar[i] = (res.back() == '0' && s[i - 1] == '1');
        }

        for (int x = 1; x <= n; ++x) {
            int num = x;

            for (int i = 0; i < 20; ++i) {
                if (x >> i & 1) {
                    int nx = num ^ (1 << i);
                    num--;

                    if (s[num] == '0') {
                        c[nx + 1]++;
                        c[num + 2]--;
                    }

                    num = nx;
                }
            }
        }

        int sm = 0;
        for (int i = 1; i <= n; ++i) {
            sm += c[i];
            p[i] = p[i - 1];

            assert(sm >= 0);
            if (!sm)
                p[i] += ar[i];
        }

        cnt += p[n];

        while (true) {
            int idx = -1, mx = 0;

            int num = n;
            for (int i = 0; i < 20; ++i) 
                if (n >> i & 1) {
                    int nx = num ^ (1 << i);
                    num--;

                    if (__builtin_popcount(num) == 1)
                        continue;

                    int cn = p[num + 1] - p[nx];
                    if (s[num] == '0' && cn) {
                        assert(false);
                        cnt -= cn;
                    } else if (s[num] == '1' && cn) {
                        if (mx < cn)
                            mx = cn, idx = num;

                    }

                    num = nx;
                }

            if (idx == -1)
                break;


            num = idx;

            s[num] = '0';

            cnt -= p[n];

            for (int x = 1; x <= n; ++x) {
                int num = x;

                for (int i = 0; i < 20; ++i) {
                    if (x >> i & 1) {
                        int nx = num ^ (1 << i);
                        num--;

                        if (s[num] == '0') {
                            c[nx + 1]++;
                            c[num + 2]--;
                        }

                        num = nx;
                    }
                }
            }

            int sm = 0;
            for (int i = 1; i <= n; ++i) {
                sm += c[i];
                p[i] = p[i - 1];

                assert(sm >= 0);
                if (!sm)
                    p[i] += (res[i - 1] == '0' && s[i - 1] == '1');
            }

            cnt += p[n];
        }

        if (res.back() == '1')
            std::cout << "-1\n";
        else
            std::cout << cnt << '\n';
    }
    return 0;
}
