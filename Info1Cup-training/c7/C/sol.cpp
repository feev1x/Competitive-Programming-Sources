/**
 *    author:  feev1x
 *    created: 05.02.2025 09:30:56
**/
#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, ind = 0; std::cin >> n >> k;

    int N = n + k;

    std::vector<int> a(N);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    for (int s = 0; s <= k; ++s) {
        for (int e = N - 1, cn = 0; cn <= k && e > s; --e, ++cn) {
            if (e - s + 1 < n) {
                break;
            }

            int sum = a[s] + a[e], cnt = 0, l = s, r = e;
            while (l < r && cnt < n) {
                if (cnt + (r - l + 1) < n) {
                    break;
                }

                if (a[l] + a[r] == sum) {
                    cnt += 2;
                    --r;
                    ++l;
                } else if (a[l] + a[r] > sum) {
                    --r;
                } else {
                    ++l;
                }
            }

            if (cnt == n) {
                std::deque<int> left, right;
                l = s, r = e, cnt = 0;
                while (l <= r && cnt < n) {
                    if (a[l] + a[r] == sum) {
                        cnt += 2;
                        left.emplace_back(a[l]);
                        right.emplace_front(a[r]);
                        --r;
                        ++l;
                    } else if (a[l] + a[r] > sum) {
                        --r;
                    } else {
                        ++l;
                    }
                }

                for (auto u: left) {
                    std::cout << u << ' ';
                }

                for (auto u: right) {
                    std::cout << u << ' ';
                }

                std::cout << '\n';

                exit(0);
            }
        }
    }
    return 0;
}
