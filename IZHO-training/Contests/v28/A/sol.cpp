#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> pw(18, 1);
    for (int i = 1; i < 18; ++i) {
        pw[i] = pw[i - 1] * 3;
    }

    int type; std::cin >> type;

    if (type == 1) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n), b(n), c(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        for (auto &u: b) {
            std::cin >> u;
        }

        for (auto &u: c) {
            std::cin >> u;
        }

        std::vector<int> da(n, 1), db(n, 1);
        for (int i = 1; i < n; ++i) {
            da[i] = a[i] == a[i - 1];
            db[i] = b[i] == b[i - 1];
        }

        std::vector<int> ca;

        int nw = 0;
        for (int i = 0; i < n; ++i) {
            if (da[i] && db[i]) {
                continue;
            }

            if (ca.size() == nw / 18) {
                ca.resize(nw / 18 + 1);
            }

            if (!da[i] && db[i]) {
                ca[nw / 18] += pw[nw % 18];
            } else if (da[i] && !db[i]) {
                ca[nw / 18] += pw[nw % 18] * 2;
            }

            nw++;
        }

        if (n <= 100) {
            ca.clear();
            for (int i = 0; i < n; ++i) {
                if (ca.size() == i / 30) {
                    ca.resize(i / 30 + 1);
                }
     
                ca[i / 30] |= (1 << (i % 30)) * da[i];
            }
        }


        if (ca.size() > k) {
            std::cout << 1 << std::endl;
            std::cout << 1 << std::endl;
            exit(0);
        }

        std::cout << ca.size() << std::endl;

        for (auto u: ca) {
            std::cout << u << ' ';
        }

        std::cout << std::endl;
    } else {
        int n, ms, ma, mb, mc; std::cin >> n >> ms >> ma >> mb >> mc;

        std::vector<int> ca(ms);
        for (auto &u: ca) {
            std::cin >> u;
        }

        std::vector<int> as(ma), bs(mb), cs(mc), a(n), b(n), c(n);

        for (auto &u: as) {
            std::cin >> u;
        }

        for (auto &u: bs) {
            std::cin >> u;
        }

        for (auto &u: cs) {
            std::cin >> u;
        }

        if (ma == 1) {
            assert(mb == mc);

            for (int i = 0; i < n; ++i) {
                std::cout << 0 << ' ';
            }

            std::cout << std::endl;
            for (int i = 0; i < mb; ++i) {
                assert(cs[i] + bs[i] == cs.front() + bs.front());
                std::cout << bs[i] << ' ';
            }

            while (mb < n) {
                std::cout << bs.back() << ' ';
                mb++;
            }

            std::cout << std::endl;
            for (int i = 0; i < mc; ++i) {
                std::cout << cs[i] << ' ';
            }

            while (mc < n) {
                std::cout << cs.back() << ' ';
                mc++;
            }

            std::cout << std::endl;
            exit(0);
        }

        if (n <= 100) {
            as.emplace_back(-1e9);
            bs.emplace_back(-1e9);
            cs.emplace_back(-1e9);
            std::vector p(n + 1, std::vector(mb + 1, std::vector<std::array<int, 3>>(mc + 1, {-1, -1, -1})));

            std::vector<int> da(n);
            for (int i = 0; i < n; ++i) {
                da[i] = (ca[i / 30] >> (i % 30) & 1);
            }

            for (int i = 0, j = 0; i < n; ++i) {
                if (!da[i]) {
                    j++;
                }
 
                a[i] = as[j];
            }

            p[0][0][0] = {0, 0, 0};
            for (int i = 0; i + 1 < n; ++i) {
                for (int y = 0; y < mb; ++y) {
                    for (int z = 0; z < mc; ++z) {
                        if (p[i][y][z][0] == -1) {
                            continue;
                        }

                        for (int cy = 0; cy < 2; ++cy) {
                            for (int cz = 0; cz < 2; ++cz) {
                                if (y + cy < mb && z + cz < mc && a[i + 1] + bs[y + cy] + cs[z + cz] == as.front() + bs.front() + cs.front()) {
                                    p[i + 1][y + cy][z + cz] = {i, y, z};
                                }
                            }
                        }
                    }
                }
            }



            int i = n - 1, x = ma - 1, y = mb - 1, z = mc - 1;
            while (i != -1) {
                b[i] = bs[y];
                c[i] = cs[z];

                auto [ni, ny, nz] = p[i][y][z];

                if (i == 0) {
                    break;
                }

                i = ni, y = ny, z = nz;
            }

            for (int i = 0; i < n; ++i) {
                std::cout << a[i] << ' ';
            }
            std::cout << std::endl;
            for (int i = 0; i < n; ++i) {
                std::cout << b[i] << ' ';
            }
            std::cout << std::endl;
            for (int i = 0; i < n; ++i) {
                std::cout << c[i] << ' ';
            }
            std::cout << std::endl;
            exit(0);
        }

        for (int i = 0, j = 0; i < n; ++i) {
            if (j + 1 < as.size() && i && (i - 1) / 18 < ms && ca[(i - 1) / 18] / pw[(i - 1) % 18] % 3 != 2) {
                j++;
            }

            a[i] = as[j];

            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;

        for (int i = 0, j = 0; i < n; ++i) {
            if (j + 1 < bs.size() && i && (i - 1) / 18 < ms && ca[(i - 1) / 18] / pw[(i - 1) % 18] % 3 != 1) {
                j++;
            }

            b[i] = bs[j];
            std::cout << b[i] << ' ';
        }
        std::cout << std::endl;

        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] + b[i] + cs[j] != as.front() + bs.front() + cs.front()) {
                j++;
            }

            c[i] = cs[j];
            std::cout << c[i] << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}
