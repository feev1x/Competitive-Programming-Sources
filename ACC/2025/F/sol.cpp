#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::string s;

    std::getline(std::cin, s);

    s.clear();
    for (int i = 0; i < n; ++i) {
        std::string t; std::getline(std::cin, t);
        
        if (t.size() > s.size())
            while (s.size() < t.size()) s += '_';

        for (int j = 0; j < t.size(); ++j) {
            if (t[j] != '_')
                s[j] = t[j];
        }
    }

    std::cout << s << '\n';
    return 0;
}
