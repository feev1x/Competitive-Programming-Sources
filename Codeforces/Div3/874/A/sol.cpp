/**
 *    author:  feev1x
 *    created: 06.03.2025 14:23:41
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string s; std::cin >> s;

        std::set<std::string> st;
        for (int i = 1; i < n; ++i) {
            std::string str;

            str += s[i - 1];
            str += s[i];

            st.emplace(str);
        }

        std::cout << st.size() << '\n';
    }
    return 0;
}
