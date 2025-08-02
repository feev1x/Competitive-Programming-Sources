/**
 *    author:  feev1x
 *    created: 27.07.2025 20:40:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a)
            std::cin >> u;

        int l = 0, r = n - 1;

        std::string res;

        int ls = 0;
        bool inc = false;
        while (l <= r) {
            if (inc) {
                if (a[l] < ls) {
                    ls = a[l++];
                    inc = false;
                    res += "L";
                } else if (a[r] < ls) {
                    ls = a[r--];
                    inc = false;
                    res += "R";
                } else {
                    if (a[r] > a[l]) {
                        ls = a[r--];
                        res += "R";
                    } else {
                        ls = a[l++];
                        res += "L";
                    }
                }
            } else {
                if (a[l] > ls) {
                    ls = a[l++];
                    inc = true;
                    res += "L";
                } else if (a[r] > ls) {
                    ls = a[r--];
                    inc = true;
                    res += "R";
                } else {
                    if (a[r] < a[l]) {
                        ls = a[r--];
                        res += "R";
                    } else {
                        ls = a[l++];
                        res += "L";
                    }
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
