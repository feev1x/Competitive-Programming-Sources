/**
 *    author:  feev1x
 *    created: 14.11.2025 20:39:37
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        std::string s; std::cin >> s;

        int n = s.size();
        bool flag = false;
        for (int i = 1; i < s.size(); ++i)
            if ((s[i] == '<' || s[i] == '*') && (s[i - 1] == '*' || s[i - 1] == '>'))
                flag = true;

        for (int i = 0; i + 1 < s.size(); ++i)
            if ((s[i] == '>' || s[i] == '*') && (s[i + 1] == '*' || s[i + 1] == '<'))
                flag = true;

        if (flag) {
            std::cout << "-1\n";
            continue;
        }

        int res = 1;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '<')
                res = std::max(res, i + 1);
            else if (s[i] == '>')
                res = std::max(res, n - i);

        for (int i = 1; i < s.size(); ++i)
            if (s[i] == '*') {
                if (s[i - 1] == '<')
                    res = std::max(res, i + 1);
                else
                    res = std::max(res, n - i + 2);
            }

        for (int i = 0; i + 1 < s.size(); ++i)
            if (s[i] == '*') {
                if (s[i + 1] == '<')
                    res = std::max(res, i + 3);
                else
                    res = std::max(res, n - i);
            }


        std::cout << res << '\n';
    }
    return 0;
}
