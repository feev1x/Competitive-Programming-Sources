/**
 *    author:  feev1x
 *    created: 11.01.2025 18:21:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n), used(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0, j = 0; i < n && j < n; ++i) {
        if (used[i]) {
            continue;
        }

        while (j < n && a[j] / 2 < a[i]) {
            j++;
        }

        if (j < n) {
            used[j] = true;
            cnt++;
            j++;
        }
    }

    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }

    for (int i = n - 1, j = n - 1; i >= 0 && j >= 0; --i) {
        if (used[i]) {
            continue;
        } 

        while (j >= 0 && a[i] / 2 < a[j]) {
            j--;
        }

        if (j >= 0) {
            used[j] = true;
            cnt1++;
            j--;
        }
    }

    for (int i = (n + 1) / 2 - 1, j = n; i >= 0 && j >= 0; --i) {
        if (j > i && a[j] / 2 >= a[i]) {
            j--;
            cnt2++;
        }
    }


    for (int i = 0, j = (n + 1) / 2; i < n && j < n; ++j) {
        if (j > i && a[j] / 2 >= a[i]) {
            i++;
            cnt3++;
        }
    }

    std::cout << std::max({cnt, cnt1, cnt2, cnt3}) << '\n';
    return 0;
}
