/**
 *    author:  feev1x
 *    created: 16.03.2025 10:23:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; int64_t r; std::cin >> n >> q >> r;

    std::queue<std::array<int64_t, 3>> qx, qy;
    q += n;
    
    int64_t lstmx = 0, lstmy = 0, lstx = 0, lsty = 0, cntx = 0, cnty = 0;
    bool lsx = false, lsy = false;
    while (q--) {
        int64_t tm; std::cin >> tm;
        char ch; std::cin >> ch;

        while (true) {
            bool flag = false;

            while (qx.size() && std::max(lstmx, qx.front()[1]) + qx.front()[0] <= tm) {
                flag = true;

                if (lsx != qx.front()[2]) {
                    qx.front()[1] += r;
                    lstmx += r;
                    lsx = !lsx;
                } else {
                    lstmx = std::max(lstmx, qx.front()[1]) + qx.front()[0];
                    cntx++;
                    lstx = lstmx;

                    qx.pop();
                }
            }

            while (qy.size() && std::max(lstmy, qy.front()[1]) + qy.front()[0] <= tm) {
                flag = true;

                if (lsy != qy.front()[2]) {
                    qy.front()[1] += r;
                    lstmy += r;
                    lsy = !lsy;
                } else {
                    lstmy = std::max(lstmy, qy.front()[1]) + qy.front()[0];
                    cnty++;
                    lsty = lstmy;

                    qy.pop();
                }
            }

            if (!flag) {
                break;
            }
        }

        if (ch == 'A' || ch == 'S') {
            int64_t w; std::cin >> w;

            bool bl = ch == 'A';

            if (qx.size() <= qy.size()) {
                if (qx.empty() && cntx == 0) {
                    lsx = bl;
                }

                qx.push({w, tm, bl});
            } else {
                if (qy.empty() && cnty == 0) {
                    lsy = bl;
                }

                qy.push({w, tm, bl});
            }
        } else {
            if (ch == 'X') {
                std::cout << cntx << ' ' << lstx << '\n';
            } else {
                std::cout << cnty << ' ' << lsty << '\n';
            }
        }
    }
    return 0;
}
