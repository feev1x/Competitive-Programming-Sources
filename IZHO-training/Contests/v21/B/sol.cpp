#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    std::vector<int> a(n);
    std::vector<int> cnt(n);
    std::vector<std::set<int>> st(n);
    std::vector<int> mp;
    for (auto &u: a) {
        std::cin >> u; --u;

        cnt[u]++;
    }

    auto Remove = [&](int x) {
        if (cnt[x] == 0) {
            return;
        }

        for (int i = 0; i < mp.size(); ++i) {
            if (mp[i] == cnt[x]) {
                if (st[mp[i]].size() == 1) {
                    st[mp[i]].erase(st[mp[i]].begin());
                    mp.erase(mp.begin() + i);
                } else {
                    st[mp[i]].erase(x);
                }

                return;
            }
        }
    };

    auto Add = [&](int x) {
        if (cnt[x] == 0) {
            return;
        }

        for (int i = 0; i < mp.size(); ++i) {
            if (mp[i] == cnt[x]) {
                st[mp[i]].emplace(x);
                return;
            }

            if (mp[i] > cnt[x]) {
                mp.emplace(mp.begin() + i, cnt[x]);
                st[mp[i]].emplace(x);
                return;
            }
        }

        mp.emplace_back(cnt[x]);
        st[cnt[x]].emplace(x);
    };
    
    for (int key = 0; key < n; ++key) {
        Add(key);
    }


    while (q--) {
        int i, x; std::cin >> i >> x; --i, --x;

        Remove(a[i]);

        cnt[a[i]]--;

        Add(a[i]);

        a[i] = x;

        Remove(x);

        cnt[x]++;

        Add(x);

        std::vector<int> mx, mn, sz;
        for (auto key: mp) {
            sz.emplace_back(key);
            mx.emplace_back(*--st[key].end());
            mn.emplace_back(*st[key].begin());
        }

        int max = sz.back();
        for (int i = (int)mx.size() - 2; i >= 0; --i) {
            max = std::max(max, sz[i]);

            mx[i] = std::max(mx[i + 1], mx[i]);
            mn[i] = std::min(mn[i + 1], mn[i]);
        }

        int res = 0;
        for (int i = (int)mx.size() - 1, j = 0; i >= 0; --i) {
            while (max > sz[i] + sz[j]) {
                j++;
            }

            res = std::max({res, mx[j] - mn[i], mx[i] - mn[j]});
        }

        std::cout << res << '\n';
    }

    return 0;
}
