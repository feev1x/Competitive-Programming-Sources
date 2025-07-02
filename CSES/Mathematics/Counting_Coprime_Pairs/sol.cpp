/**
 *    author:  feev1x
 *    created: 29.03.2025 17:28:06
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<bool> prime(N, true), odd(N);

    prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (prime[i]) {
            odd[i] = true;

            for (int j = i * 2; j < N; j += i) {
                prime[j] = false;

                odd[j] = !odd[j];
            }
        }
    }

    int n; std::cin >> n;

    std::vector<int> cnt(N);    
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        std::vector<int> vs;
        for (int i = 2; i * i <= u; ++i) {
            if (u % i == 0) {
                cnt[i]++;
                
                cnt[u / i]++;

                vs.emplace_back(i);
                vs.emplace_back(u / i);
            }
        }

        std::sort(vs.begin(), vs.end());


        cnt[1]++;
        vs.emplace_back(1);
        if (u > 1) {
            cnt[u]++;
            vs.emplace_back(u);
        }

        std::cout << u << " : ";
        for (auto v: vs) {
            std::cout << v << ' ';
        }

        std::cout << '\n';
   }


    int64_t res = 0; 
    for (int i = 1; i < N; ++i) {
        if (odd[i]) {
            res -= (int64_t)cnt[i] * (cnt[i] - 1) / 2;
        } else {
            res += (int64_t)cnt[i] * (cnt[i] - 1) / 2;
        }
    }

    std::cout << res << '\n';
    return 0;
}
