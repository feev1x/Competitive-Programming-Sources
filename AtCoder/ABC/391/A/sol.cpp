/**
 *    author:  feev1x
 *    created: 01.02.2025 18:10:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::map<char, char> mp;

    mp['N'] = 'S';
    mp['E'] = 'W';
    mp['S'] = 'N';
    mp['W'] = 'E';

    for (int i = 0; i < s.size(); ++i) {
        s[i] = mp[s[i]];
    }

    std::cout << s << '\n';
    return 0;
}
