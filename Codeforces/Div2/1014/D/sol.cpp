/**
 *    author:  feev1x
 *    created: 29.03.2025 21:04:40
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string s; std::cin >> s;

        std::vector<int> res;
        int L = 0, I = 0, T = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                L++;
            } else if (s[i] == 'I') {
                I++;
            } else {
                T++;
            }
        }

        bool flag = true;
        for (int op = 1; op <= 2 * n && L != I || I != T; ++op) {
            int pos = -1;
            char ch;
            
            for (int i = 0; i + 1 < s.size(); ++i) {
                if (s[i] != s[i + 1]) {
                    if (s[i] == 'L' && s[i + 1] == 'I') {
                        if (T < L || T < I) {
                            pos = i;
                            ch = 'T';
                            T++;

                            break;
                        }
                    } else if (s[i] == 'L' && s[i + 1] == 'T') {
                        if (I < L || I < T) {
                            pos = i;
                            ch = 'I';
                            I++;

                            break;
                        }
                    } else if (s[i] == 'I' && s[i + 1] == 'L') {
                        if (T < I || T < L) {
                            pos = i;
                            ch = 'T';
                            T++;

                            break;
                        }
                    } else if (s[i] == 'I' && s[i + 1] == 'T') {
                        if (L < I || L < T) {
                            pos = i;
                            ch = 'L';
                            L++;

                            break;
                        }
                    } else if (s[i] == 'T' && s[i + 1] == 'L') {
                        if (I < T || I < L) {
                            pos = i;
                            ch = 'I';
                            I++;

                            break;
                        }
                    } else {
                        if (L < T || L < I) {
                            pos = i;
                            ch = 'L';
                            L++;

                            break;
                        }
                    }
                }
            }

            if (pos == -1) {
                for (int i = 0; i + 1 < s.size(); ++i) {
                    if (s[i] != s[i + 1]) {
                        if (s[i] == 'L' && s[i + 1] == 'I') {
                            pos = i;
                            ch = 'T';
                            T++;

                            break;
                        } else if (s[i] == 'L' && s[i + 1] == 'T') {
                            pos = i;
                            ch = 'I';
                            I++;

                            break;
                        } else if (s[i] == 'I' && s[i + 1] == 'L') {
                            pos = i;
                            ch = 'T';
                            T++;

                            break;
                        } else if (s[i] == 'I' && s[i + 1] == 'T') {
                            pos = i;
                            ch = 'L';
                            L++;

                            break;
                        } else if (s[i] == 'T' && s[i + 1] == 'L') {
                            pos = i;
                            ch = 'I';
                            I++;

                            break;
                        } else {
                            pos = i;
                            ch = 'L';
                            L++;

                            break;
                        }
                    }
                }
            }
            
            if (pos == -1) {
                flag = false;

                break;
            }

            res.emplace_back(pos + 1);

            std::string new_s;
            for (int i = 0; i <= pos; ++i) {
                new_s += s[i];
            }
            
            new_s += ch;

            for (int i = pos + 1; i < s.size(); ++i) {
                new_s += s[i];
            }

            s = new_s;
        }

        if (!flag || L != I || I != T) {
            std::cout << "-1\n";
        } else {
            std::cout << res.size() << '\n';

            for (auto u: res) {
                std::cout << u << '\n';
            }
        }
    }
    return 0;
}
