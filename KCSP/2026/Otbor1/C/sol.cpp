#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int s; std::cin >> s;

    std::map<int, int> mp;

    mp[0] = 1;

    int sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;
        
        sum += u;

        res += mp[sum - s];

        mp[sum]++;
    }

    std::cout << res << '\n';
    return 0;
}
