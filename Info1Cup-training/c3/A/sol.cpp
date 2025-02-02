/**
 *    author:  feev1x
 *    created: 30.01.2025 09:01:32
**/
#include <bits/stdc++.h>

constexpr int N = 5000;

int64_t dp[N][N];
int mex[N][N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;
    
    bool s1 = true, s2 = q <= 200, s3 = n <= 5000, s4 = true;
    std::vector<int> a(n), left(n + 1, -1), right(n + 1, n + 5), cnt(n + 1);
    for (auto &u: a) {
        std::cin >> u;

        cnt[u]++;

        if (u == 0) {
            s1 = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (cnt[u] != 1) {
            s4 = false;
        }
    }

    if (s3) {
        auto b = a;

        std::sort(b.begin(), b.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] == a[j]) {
                    left[i] = j;
                }
            }

            for (int j = i + 1; j < n; ++j) {
                if (a[i] == a[j]) {
                    right[i] = j;
                    
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (b[i] == mex[0][n - 1]) {
                mex[0][n - 1]++;
            }
        }

        for (int l = 0; l < n; ++l) {
            for (int r = n - 2; r >= l; --r) {
                if (a[r + 1] < mex[l][r + 1] && left[r + 1] < l) {
                    mex[l][r] = a[r + 1];
                } else {
                    mex[l][r] = mex[l][r + 1];
                }
            }

            if (l + 1 < n) {
                if (mex[l][n - 1] > a[l] && right[l] > n - 1) {
                    mex[l + 1][n - 1] = a[l];
                } else {
                    mex[l + 1][n - 1] = mex[l][n - 1];
                }
            }
        }

        for (int sz = 1; sz <= n; ++sz) {
            for (int l = 0; l + sz - 1 < n; ++l) {
                int r = l + sz - 1;

                dp[l][r] += mex[l][r];

                if (sz > 1) {
                    dp[l][r] += dp[l + 1][r] + dp[l][r - 1];
                }
                
                if (sz > 2) {
                    dp[l][r] -= dp[l + 1][r - 1];
                }
            }
        }
    }

    std::vector<int> pos(n);
    if (s4) {
        for (int i = 0; i < n; ++i) {
            pos[a[i]] = i;
        }


    }

    while (q--) {
        int l, r; std::cin >> l >> r; l--, r--;
        
        if (r - l > 200) {
            s2 = false;
        }

        if (s1) {
            std::cout << "0\n";
        } else if (s2) {
            int64_t res = 0;

            for (int i = l; i <= r; ++i) {
                std::set<int> st;

                for (int j = 0; j <= r - i + 1; ++j) {
                    st.emplace(j);
                }

                for (int j = i; j <= r; ++j) {
                    st.erase(a[j]);

                    res += *st.begin();
                }
            }

            std::cout << res << '\n';
        } else if (s3) {
            std::cout << dp[l][r] << '\n';
        }
    }
    return 0;
}
