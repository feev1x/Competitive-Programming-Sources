#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d, a, b; std::cin >> n >> d >> a >> b;

    std::vector<int> m(n);
    for (auto &u: m) {
        std::cin >> u;
    }

    std::sort(m.begin(), m.end(), std::greater<>());

    int res = 0;
    while (m.size() > a) {
        res = (res + mul(m.back(), m.back())) % MOD;
        m.pop_back();
    }

    std::stack<std::pair<int, int>> stk;
    for (int i = 0; i < a - b; ++i) {
        if (stk.empty() || stk.top().first != m[i]) {
            stk.emplace(m[i], 1);
        } else {
            stk.top().second++;
        }
    }

    for (int i = a - b; i < a && d > 0; ++i) {
        int diff = m[i] - stk.top().first + 1;

        
    }


    std::cout << res << '\n';
    return 0;
}
