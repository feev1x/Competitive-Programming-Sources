#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s = "liechtenstein";
    int tt; std::cin >> tt;
    while (tt--) {
        int i; std::cin >> i;
        std::cout << s[i - 1] << '\n';
    }
    return 0;
}
