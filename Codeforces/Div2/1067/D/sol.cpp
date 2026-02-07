#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::string s, t; std::cin >> s >> t;
    
    int l = -1;

    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        bool old = (i ? s[i - 1] == '0' : true);

        if (s[i] == '1' && old) {
            l = i;
        } else if (s[i] == '0' && !old) {
            int sz = i - l;

            if (sz > 1) {
                res.emplace_back(l, i - 1);
            } else {
                if (l > 1) {
                    res.emplace_back(l - 2, l - 1);
                    res.emplace_back(l - 2, l);
                } else if (i + 1 < n && s[i + 1] == '0') {
                    res.emplace_back(i, i + 1);
                    res.emplace_back(l, i + 1);
                } else {
                    assert(s[i + 1] == '1');

                    res.emplace_back(l, i + 1);
                    
                    s[i + 1] = '0';
                    s[i] = '1';
                    l = i;
                    continue;
                }
            }
        }
    }

    if (s.back() == '1') {
        int i = n, sz = i - l;

        if (sz > 1) {
            res.emplace_back(l, i - 1);
        } else {
            if (l > 1) {
                res.emplace_back(l - 2, l - 1);
                res.emplace_back(l - 2, l);
            } else {
                assert(false);
            }
        }
    }

    auto Do = [&](auto &&self, int l, int r) -> void {
        if (r - l + 1 == 1) {
            if (l > 1) {
                res.emplace_back(l - 2, l);
                res.emplace_back(l - 2, l - 1);
            } else {
                res.emplace_back(r, r + 2);
                res.emplace_back(r + 1, r + 2);
            }

            return;
        }

        if (r - l + 1 == 3) {
            if (l > 0) {
                res.emplace_back(l - 1, r - 1);
                res.emplace_back(l, r - 1);
                res.emplace_back(l + 1, r);
                res.emplace_back(l - 1, r - 1);
            } else {
                res.emplace_back(l + 1, r + 1);
                res.emplace_back(l + 1, r);
                res.emplace_back(l, r - 1);
                res.emplace_back(l + 1, r + 1);
            }

            return;
        }

        if (r - l + 1 == 5) {
            res.emplace_back(l, l + 1);
            res.emplace_back(r - 1, r);
            res.emplace_back(l + 1, r - 1);

            return;
        }

        res.emplace_back(l, r);

        self(self, l + 1, r - 1);
    };

    for (int i = 0; i < n; ++i) {
        if (t[i] == '1' && (!i || t[i - 1] == '0')) {
            int r = i;

            while (r < n && t[r] == '1' && (r + 1 == n || t[r + 1] == '0')) {
                r += 2;
            }

            r -= 2;
            
            if (r < i) {
                continue;
            }

            Do(Do, i, r);

            i = r;
        }
    }

    l = -1;
    std::swap(s, t);
    for (int i = 0; i < n; ++i) {
        bool old = (i ? s[i - 1] == '0' : true);

        if (s[i] == '1' && old) {
            l = i;
        } else if (s[i] == '0' && !old) {
            int sz = i - l;

            if (sz > 1) {
                res.emplace_back(l, i - 1);
            }
        }
    }

    if (s.back() == '1') {
        int i = n, sz = i - l;

        if (sz > 1) {
            res.emplace_back(l, i - 1);
        }
    }

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u + 1 << ' ' << v + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
