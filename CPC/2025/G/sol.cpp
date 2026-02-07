#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::string s; std::cin >> s;

    std::vector<int> pe(n + 1), st(n + 2);
    for (int i = 0; i < n; ++i) {
        pe[i + 1] = pe[i] + (s[i - 1] == 'e');
    }

    for (int i = n; i >= 1; --i) {
        st[i] = st[i + 1] + (s[i - 1] == 't');
    }

    auto Get = [&](int i) {
        return pe[i] + st[i + 1];
    };

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (Get(ans) > Get(i)) {
            ans = i;
        }
    }

    std::cout << Get(ans) << '\n';
    for (int i = 1; i <= ans; ++i) {
        std::cout << 't';
    }

    for (int i = ans + 1; i <= n; ++i) {
        std::cout << 'e';
    }

    std::cout << '\n';
    return 0;
}
