/**
 *    author:  feev1x
 *    created: 02.05.2025 16:37:28
**/
#include <bits/stdc++.h>

constexpr int N = 501;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::multiset<int> st;
    std::vector<int> a(n + 1);
    std::vector<int64_t> sum(n + 1);
    std::vector<int> cnt(N);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        st.emplace(a[i]);
        if (a[i] <= 500) {
            cnt[a[i]]++;
        }
    }

    {
        int64_t res = 0, l = (n + 1) / 2 - 1, r = n / 2;
        int nw = n;

        bool flag = n % 2 == 0;
        for (auto it = --st.end(); ; --it) {
            res += l * r * *it;

            sum[nw] = l * r;
            nw--;
            if (flag) {
                flag = false;
            } else {
                l--, r++;
                flag = true;
            }

            if (it == st.begin()) {
                break;
            }
        }

        for (int i = 2; i <= n; ++i) {
            sum[i] += sum[i - 1];
        }

        std::cout << res << '\n';
    }

    while (q--) {
        int i, x; std::cin >> i >> x;

        a[i] = x;


        int64_t res = 0, nw = n;
        for (int i = 500; i >= 0; --i) {
            res += (sum[nw] - sum[nw - cnt[i]]) * i; 

            nw -= cnt[i];
        }

        std::cout << res << '\n';
    }
    return 0;
}
