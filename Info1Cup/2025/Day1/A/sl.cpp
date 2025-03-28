/**
 *    author:  feev1x
 *    created: 08.02.2025 17:02:17
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

std::string nex(std::string s, int i) {
    std::reverse(s.begin(), s.end());

    int nx = 1, n = s.size();

    for (int j = i; j < std::max(n, i + 1) || nx; ++j) {
        while (j >= n) {
            s += "0";
            n++;
        }

        if ((s[j] - '0') + nx > 9) {
            int num = (s[j] - '0' + nx);

            s[j] = num % 10 + '0';
            nx = num / 10;
        } else {
            s[j] += nx;
            nx = 0;

            break;
        }
    }

    std::reverse(s.begin(), s.end());

    return s;
}

inline bool comp(std::string a, std::string b) {
    if (a.size() > b.size()) {
        return true;
    } else if (a.size() < b.size()) {
        return false;
    } else {
        int n = a.size();

        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                return true;
            } else if (a[i] < b[i]) {
                return false;
            }
        }

        return false;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int d, k; std::cin >> d >> k;

        std::string s; std::cin >> s;

        auto s1 = s;

        int cnt = std::count(s.begin(), s.end(), '9');

        std::string ans1(d - 1, '9');

        ans1 = nex(ans1, std::max(0, d - 1 - k));

        int op1 = -1, op2 = -1, cnp = 0, cn0 = 0;

        for (int i = d - 1; i >= 0; --i) {
            if (!(s[i] == '1' && i == 0 || s[i] == '0')) {
                if (s[i] == '9') {
                    cnt--;
                }

                if (op1 == -1) {
                    op1 = std::max(cnt - k, 0);
                    op2 = i;
                } else {
                    int nx = d - std::max(cnt - k, 0) - 1, ns = std::max(cnt - k, 0), ch = i + cnp + 1;
                    assert(i < op2);
                    if (op2 <= d - op1 - 1) {
                        if (nx <= i || nx - i <= cn0) {
                            op1 = std::max(cnt - k, 0);
                            op2 = i;
                        }
                    } else {
                        if (ns > op1 && (nx < i || nx == i && ch <= d - op1 - 1)) {
                            op1 = std::max(cnt - k, 0);
                            op2 = i;
                        }
                    }
                }
            }

            if (s[i] == '0') {
                cn0++;
            } else {
                cn0 = 0;
            }

            if (s[i] == '9') {
                cnp++;
            } else {
                cnp = 0;
            }

            cnt++;
        }

        if (op1 == -1) {
            s = "1";
        } else {
            s[op2]--;

            for (int i = op2 + 1; i < d; ++i) {
                s[i] = '9';
            }

            s = nex(s, op1);
        }

        if (comp(s, ans1)) {
            std::cout << s << '\n';
        } else {
            std::cout << ans1 << '\n';
        }
    }
    return 0;
}
