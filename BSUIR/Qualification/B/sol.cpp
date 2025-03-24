/**
 *    author:  feev1x
 *    created: 19.03.2025 15:09:48
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::string> s(n + 1);
    std::vector<bool> add(n + 1);
    std::getline(std::cin, s[0]);

    for (int i = 1; i <= n; ++i) {
        std::string ss; std::getline(std::cin, ss);


        if (ss.front() == 'l') {
            add[i] = true;

            for (int j = 4; ss[j] != ' '; ++j) {
                s[i] += ss[j];
            }
        } else {
            for (int j = 5; ss[j] != ')'; ++j) {
                s[i] += ss[j];
            }
        }
    }

    std::vector<int> par(n + 1);
    std::vector<bool> skip(n + 1);
    std::map<std::string, bool> del;
    std::stack<int> stk;

    for (int i = 1; i <= n; ++i) {
        if (add[i]) {
            stk.emplace(i);
        } else {
            if (s[stk.top()] == s[i]) {
                skip[i] = true;

                par[i] = stk.top();
                par[stk.top()] = i;
            }

            del[s[i]] = true;
        }

        while (stk.size() && del[s[stk.top()]]) {
            stk.pop();
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (skip[i] & skip[i - 1]) {
            par[par[i - 1]] = 0;
            par[i - 1] = 0;
        }
    }

    if (skip.back()) {
        par[par.back()] = 0;
        par.back() = 0;
    }

    std::string sp;
    for (int i = 1; i <= n; ++i) {
        if (par[i] && par[i] < i) {
            assert(skip[i]);

            sp.pop_back();

            std::cout << sp << '}' << '\n';

            continue;
        }

        if (skip[i]) {
            continue;
        }

        if (par[i]) {
            std::cout << sp << "{\n";

            sp += " ";
        }

        std::cout << sp;

        if (add[i]) {
            std::cout << "let " << s[i] << " = new();\n";
        } else {
            std::cout << "drop(" << s[i] << ");\n";
        }
    }
    return 0;
}
