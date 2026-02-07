#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    int c, q; std::cin >> c >> q;

    std::set<std::string> st;
    std::vector<std::string> s(n);
    for (auto &u: s) {
        std::cin >> u;

        st.emplace(u);
    }

    if (c == 2) {
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0) {
                    if (s[i][j] == 'R') {
                        c1++;
                    } else {
                        c2++;
                    }
                } else {
                    if (s[i][j] == 'R') {
                        c2++;
                    } else {
                        c1++;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0) {
                    std::cout << (c1 < c2 ? 'G' : 'R');
                } else {
                    std::cout << (c1 >= c2 ? 'G' : 'R');
                }
            }

            std::cout << '\n';
        }

        exit(0);
    }

    std::map<char, int> cnt1, cnt2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) {
                cnt1[s[i][j]]++;
            } else {
                cnt2[s[i][j]]++;
            }
        }
    }

    std::string t = "RGB";
    if (cnt1.size() < 3) {
        char ch = ' ';

        for (auto u: t) {
            if (!cnt1.count(u)) {
                ch = u;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) & 1) {
                    s[i][j] = ch;
                }
            }
        }
    } else if (cnt2.size() < 3) {
        char ch;

        bool flag = false;
        for (auto u: t) {
            if (!cnt2.count(u) && cnt1[u] > 0) {
                flag = true;
                ch = u;
                break;
            }
        }

        assert(flag);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0) {
                    s[i][j] = ch;
                }
            }
        }
    } else {
        char ch = 'R';

        if (cnt1[ch] > cnt2[ch]) {
            assert((n * m + 1) / 2 - cnt1[ch] + cnt2[ch] <= q);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if ((i + j) % 2 == 1) {
                        if (s[i][j] == ch) {
                            s[i][j] = 'G';
                        }
                    } else {
                        s[i][j] = ch;
                    }
                }
            }
        } else {
            assert(n * m / 2 - cnt2[ch] + cnt1[ch] <= q);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if ((i + j) % 2 == 0) {
                        if (s[i][j] == ch) {
                            s[i][j] = 'G';
                        }
                    } else {
                        s[i][j] = ch;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << s[i] << '\n';
    }

    return 0;
}
