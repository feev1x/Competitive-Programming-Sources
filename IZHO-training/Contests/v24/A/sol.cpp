#include <bits/stdc++.h>

inline bool chmin(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int64_t z = 0;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        z += u;
    }

    int64_t res = 1e18;
    int rx = 0, ry = 1, rz = 2;
    {
        int i = 0, j = 1, k = 2;
        int64_t x = a[0], y = a[1];

        auto Nx = [&](int i) {
            return (i + 1) % n;
        };

        z -= x;
        z -= y;
        for (int it = 0; it < n * 5; ++it) {
            if (chmin(res, std::max({x, y, z}) - std::min({x, y, z}))) {
                rx = i, ry = j, rz = k;
            }

            if (x > y) {
                if (z < y) {
                    x -= a[i];
                    z += a[i];

                    i = Nx(i);
                    if (i == j) {
                        x += a[j];
                        y -= a[j];

                        j = Nx(j);
                        if (j == k) {
                            assert(Nx(k) != i);

                            y += a[k];
                            z -= a[k];

                            k = Nx(k);
                        }
                    }
                } else {
                    z -= a[k];
                    y += a[k];

                    k = Nx(k);
                    if (k == i) {
                        x -= a[i];
                        z += a[i];

                        i = Nx(i);
                        if (i == j) {
                            x += a[j];
                            y -= a[j];

                            j = Nx(j);
                        }
                    }
                }
            } else {
                if (z > y) {
                    z -= a[k];
                    y += a[k];

                    k = Nx(k);
                    if (k == i) {
                        x -= a[i];
                        z += a[i];

                        i = Nx(i);
                        if (i == j) {
                            x += a[j];
                            y -= a[j];

                            j = Nx(j);
                        }
                    }
                } else if (z < x) {
                    x -= a[i];
                    z += a[i];

                    i = Nx(i);
                    if (i == j) {
                        x += a[j];
                        y -= a[j];

                        j = Nx(j);
                        if (j == k) {
                            assert(Nx(k) != i);

                            y += a[k];
                            z -= a[k];

                            k = Nx(k);
                        }
                    }
                } else {
                    y -= a[j];
                    x += a[j];

                    j = Nx(j);
                    if (j == k) {
                        y += a[k];
                        z -= a[k];

                        k = Nx(k);

                        if (k == i) {
                            x -= a[i];
                            z += a[i];

                            i = Nx(i);
                        }
                    }
                }
            }
        }
    }

    z = accumulate(a.begin(), a.end(), 0ll);
    std::reverse(a.begin(), a.end());

    {
        int i = 0, j = 1, k = 2;
        int64_t x = a[0], y = a[1];

        auto Nx = [&](int i) {
            return (i + 1) % n;
        };

        z -= x;
        z -= y;
        for (int it = 0; it < n * 5; ++it) {
            if (chmin(res, std::max({x, y, z}) - std::min({x, y, z}))) {
                rx = i, ry = j, rz = k;
            }

            if (x > y) {
                if (z < y) {
                    x -= a[i];
                    z += a[i];

                    i = Nx(i);
                    if (i == j) {
                        x += a[j];
                        y -= a[j];

                        j = Nx(j);
                        if (j == k) {
                            assert(Nx(k) != i);

                            y += a[k];
                            z -= a[k];

                            k = Nx(k);
                        }
                    }
                } else {
                    z -= a[k];
                    y += a[k];

                    k = Nx(k);
                    if (k == i) {
                        x -= a[i];
                        z += a[i];

                        i = Nx(i);
                        if (i == j) {
                            x += a[j];
                            y -= a[j];

                            j = Nx(j);
                        }
                    }
                }
            } else {
                if (z > y) {
                    z -= a[k];
                    y += a[k];

                    k = Nx(k);
                    if (k == i) {
                        x -= a[i];
                        z += a[i];

                        i = Nx(i);
                        if (i == j) {
                            x += a[j];
                            y -= a[j];

                            j = Nx(j);
                        }
                    }
                } else if (z < x) {
                    x -= a[i];
                    z += a[i];

                    i = Nx(i);
                    if (i == j) {
                        x += a[j];
                        y -= a[j];

                        j = Nx(j);
                        if (j == k) {
                            assert(Nx(k) != i);

                            y += a[k];
                            z -= a[k];

                            k = Nx(k);
                        }
                    }
                } else {
                    y -= a[j];
                    x += a[j];

                    j = Nx(j);
                    if (j == k) {
                        y += a[k];
                        z -= a[k];

                        k = Nx(k);

                        if (k == i) {
                            x -= a[i];
                            z += a[i];

                            i = Nx(i);
                        }
                    }
                }
            }
        }
    }

    int mn = std::min({rx, ry, rz}), mx = std::max({rx, ry, rz});
    std::cout << res << '\n' << mn + 1 << ' ' << rx + ry + rz - mn - mx + 1 << ' ' << mx + 1 << '\n';
    return 0;
}
