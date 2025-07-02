/**
 *    author:  feev1x
 *    created: 03.05.2025 13:23:48
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    
    while (tt--) {
        int n; std::cin >> n;

        std::map<int, int> odd, even;
        std::map<std::pair<int, int>, int> pre, pro;
        std::map<std::tuple<int, int, int>, int> tpe, tpo;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            if (i & 1) {
                odd[a[i]]++;

                if (i + 1 <= n) {
                    pro[{a[i], a[i + 1]}]++;
                }

                if (i + 1 <= n && a[i - 1] == a[i + 1]) {
                    tpo[{a[i - 1], a[i], a[i + 1]}]++;
                }
            } else {
                even[a[i]]++;

                if (i + 1 <= n) {
                    pre[{a[i], a[i + 1]}]++;
                }

                if (i + 1 <= n && a[i - 1] == a[i + 1]) {
                    tpe[{a[i - 1], a[i], a[i + 1]}]++;
                }
            }
        }

        int res = n;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int cost = 0;

                bool did = false;
                int cnt = 0;
                for (int k = 1; k <= n; ++k) {
                    if (k & 1) {
                        if (a[k] == i) {
                            cnt = 0;
                            did = false;
                            continue;
                        } else if (k + 1 <= n) {
                            if (a[k + 1] == i) {
                                cnt++;

                                if (cnt == 3) {
                                    did = !did;
                                }

                                if (did) {
                                    cost++;
                                    did = false;
                                } else {
                                    cost += 2;
                                    did = true;
                                }
                            } else {
                                cnt = 0;
                                cost++;
                                did = false;
                            }
                        } else {
                            cnt = 0;
                            cost++;
                            did = false;
                        }
                    } else {
                        if (a[k] == j) {
                            cnt = 0;
                            did = false;
                            continue;
                        } else if (k + 1 <= n) {
                            if (a[k + 1] == j) {
                                cnt++;

                                if (cnt == 3) {
                                    did = !did;
                                }

                                if (did) {
                                    cost++;
                                    did = false;
                                } else {
                                    cost += 2;
                                    did = true;
                                }
                            } else {
                                cnt = 0;
                                cost++;
                                did = false;
                            }
                        } else {
                            cnt = 0;
                            cost++;
                            did = false;
                        }
                    }
                }

                res = std::min(res, cost);
            }
        }

        std::cout << res << '\n';
    }

    return 0;
}
