/**
 *    author:  feev1x
 *    created: 04.02.2025 10:20:40
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline int max(int a, int b) {
    if (a > b) {
        return a;
    }
    
    return b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    int ans = 0;

    std::stack<int> stk;
    std::queue<int> q;
    std::vector<int> l(n), r(n);

    auto Size = [&](int le, int ri) {
        if (le > ri) {
            return ri + n - le + 1;
        } 
        
        return ri - le + 1;
    };

    for (int j = 0; j < n; ++j) {
        if (s[j] == '(') {
            stk.emplace(j);
        } else {
            if (stk.empty()) {
                q.emplace(j);
            } else {
                l[j] = stk.top();
                l[stk.top()] = stk.top();
                r[stk.top()] = j;
                r[j] = j;

                stk.pop();
            }
        }
    }

    while (q.size()) {
        l[q.front()] = stk.top();
        l[stk.top()] = stk.top();
        r[stk.top()] = q.front();
        r[q.front()] = q.front();

        stk.pop();
        q.pop();
    }

    int left = -1, sz = 0;
    
    for (int i = 0; i < n; ++i) {
        if (l[i] == i && Size(l[i], r[i]) > sz) {
            sz = Size(l[i], r[i]);

            left = l[i];
        }
    }

    for (int i = left; ; i = (i + 1) % n) {
        ans++;

        if (r[i] == (left - 1 + n) % n) {
            break;
        }


        i = r[i];
    }

    int res = ans;
    for (int _ = 0; _ < k && res < n / 2; ++_) {
        int mx = -INF, lf = -1, pr = -1, ii;

        for (int i = left; ; i = (i + 1) % n) {
            if ((i + 1) % n == r[i]) {
                i = r[i];

                if (r[i] == (left - 1 + n) % n) {
                    if (pr == -1) {
                        res = n / 2;
                    }

                    break;
                }

                continue;
            }

            int i1 = (i + 1) % n, i2 = (i + 2) % n;

            if (r[i1] == (r[i] - 1 + n) % n) {
                int cnt = 0;

                for (int j = i2; j != r[i1]; j = (j + 1) % n) {
                    cnt++;

                    j = r[j];
                }

                if (mx < cnt + 1) {
                    mx = cnt + 1;

                    lf = i1;
                    ii = i;
                    pr = 1;
                }
            } else {
                int cnt = 0;
                
                for (int j = i1; j != r[i]; j = (j + 1) % n) {
                    cnt++;

                    j = r[j];
                }

                if (mx < -ans + cnt + 1) {
                    mx = -ans + cnt + 1;

                    lf = i;
                    ii = i;
                    pr = 0;
                }

                for (int j = i1; j != r[i]; j = (j + 1) % n) {
                    int j1 = (j + 1) % n;

                    int cnt = 1;
                    for (int k = j1; k != r[j]; k = (k + 1) % n) {
                        cnt++;

                        k = r[k];
                    }

                    if (mx < cnt) {
                        mx = cnt;

                        lf = j;
                        ii = i;
                        pr = 2;
                    }

                    j = r[j];
                }
            }

            if (r[i] == (left - 1 + n) % n) {
                break;
            }
            
            i = r[i];
        }

        if (pr == -1) {
            break;
        }

        ans += mx;

        res = max(res, ans);

        int i = ii, i1 = (i + 1) % n, i2 = (i + 2) % n;
        if (pr == 0) {
            std::swap(l[lf], r[lf]);
        } else if (pr == 1) {
            int temp = r[lf], temp1 = r[i];

            l[temp] = temp, r[temp] = temp1;
            l[temp1] = temp, r[temp1] = temp1;
            r[i] = lf;
            l[lf] = i, r[lf] = lf;
        } else {
            int temp = r[lf], temp1 = r[i];

            r[i] = lf;
            l[lf] = i, r[lf] = lf;
            l[temp] = temp, r[temp] = temp1;
            l[temp1] = temp, r[temp1] = temp1;
        }
    
        for (i = 0; i < n; ++i) {
            int siz = Size(l[i], r[i]);

            if (siz > sz) {
                sz = siz;

                left = l[i];
            }
        }
    }

    std::cout << res << '\n';
    return 0;
}
