/**
 *    author:  feev1x
 *    created: 15.11.2025 18:02:13
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::string t;

    int cnt = 0;
    for (auto u: s)
        if (u != '0')
            t += u;
        else
            cnt++;

    std::sort(t.begin(), t.end());
    
    std::cout << t[0];

    while (cnt--)
        std::cout << "0";

    t.erase(t.begin());

    std::cout << t << '\n';
    return 0;
}
