#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    int sa = 0, sb = 0, ga = 0, gb = 0, pa = 0, pb = 0;
    bool nwa = true, fr = true, tb = false;
    while (std::cin >> s) {
        for (int i = 0; i < s.size(); ++i) {
            if (tb) {
                nwa = ((pa + pb + 1) % 4) / 2;
                nwa = fr ^ nwa;
                if (nwa ^ (!(s[i] - '0'))) {
                    pa++;
                } else {
                    pb++;
                }
                if (pa > pb) {
                    if (pa >= 7 && pa - pb > 1) {
                        ga++;
                        pa = pb = 0;
                        tb = false;
                    }
                } else {
                    if (pb >= 7 && pb - pa > 1) {
                        gb++;
                        pa = pb = 0;
                        tb = false;
                    }
                }
            } else {
                nwa = fr ^ ((ga + gb) % 2);
                if (nwa ^ (!(s[i] - '0'))) {
                    pa++;
                } else {
                    pb++;
                }
                if (pa > pb) {
                    if (pa >= 4 && pa - pb > 1) {
                        ga++;
                        pa = pb = 0;
                    }
                } else {
                    if (pb >= 4 && pb - pa > 1) {
                        gb++;
                        pa = pb = 0;
                    }
                }
            }
            if (ga == 7 || gb == 7 || ga == 6 && gb < 5 || gb == 6 && ga < 5) {
                std::cout << ga << ':' << gb << '\n';
                if (ga > gb) {
                    sa++;
                } else {
                    sb++;
                }
                ga = gb = 0;
                fr = !fr;
                tb = false;
            }
            if (ga == 6 && gb == 6) {
                tb = true;
            }

            if (sa == 2 || sb == 2) {
                ga = gb = pa = pb = 0;
                break;
            }
        }
    }
    if (pa + pb + ga + gb > 0) {
        std::cout << ga << ':' << gb << '\n';
    }

    if (sa == 2) {
        std::cout << "A WINS\n";
    } else if (sb == 2) {
        std::cout << "B WINS\n";
    } else {
        std::cout << "MATCH INCOMPLETE\n";
    }
    return 0;
}
