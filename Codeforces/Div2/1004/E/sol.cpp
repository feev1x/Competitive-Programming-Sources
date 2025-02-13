/**
 *    author:  feev1x
 *    created: 11.02.2025 21:49:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        int cnt0 = 0;
        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;

            if (!u) {
                cnt0++;
            }
        }

        int res = n - cnt0;

        bool flag = false;
        if (a[0] == 0) {
            flag = true;
        } else {
            std::set<int> st;
            std::multiset<int> st1;
            
            for (int i = 1; i <= n; ++i) {
                st.emplace(i);
                if (a[i - 1]) {
                    st1.emplace(a[i - 1]);
                }
            }

            for (int i = n - 1; i >= 0; --i) {
                if (!a[i]) {
                    if (*st1.begin() >= *st.begin()) {
                        flag = true;
                    }
                } else {
                    if (*st1.begin() < *st.begin()) {
                        flag = false;
                    }

                    st1.erase(st1.find(a[i]));
                }

                st.erase(a[i]);
            }
        }

        std::cout << res + flag << '\n';
    }
    return 0;
}
