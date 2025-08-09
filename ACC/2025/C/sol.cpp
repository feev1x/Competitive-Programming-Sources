#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        std::vector<int> a(n);

        bool flag = true;
        int val1 = -1, val2 = -1, cnt1 = 0, cnt2 = 0;
        for (auto &u: a) {
            std::cin >> u;

            if (val1 == -1 || val1 == u)
                cnt1++, val1 = u;
            else if (val2 == -1 || val2 == u)
                cnt2++, val2 = u;
            else
                flag = false;
        }

        if (!flag)
            std::cout << "NO\n";
        else if (val1 == -1 || val2 == -1 || std::abs(cnt1 - cnt2) <= 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}
