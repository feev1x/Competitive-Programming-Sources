/**
 *    author:  feev1x
 *    created: 24.11.2025 15:59:51
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::stack<int> stk;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        while (stk.size() && a[stk.top()] <= a[i])
            stk.pop();

        std::cout << (stk.size() ? stk.top() : -1) << '\n';

        stk.emplace(i);
    }

    return 0;
}
