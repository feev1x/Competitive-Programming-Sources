/**
 *    author:  feev1x
 *    created: 06.02.2025 09:49:04
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ord tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::vector<ord> cho(31);
    std::vector<ord> necho(31);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int pw = 1;

        for (int j = 0; j < 31; ++j) {
            bool flag = false;
            int val = a[i] % pw;

            if ((a[i] / pw) & 1) {
                necho[j].insert(val);

                int inv = pw - val;

                int it = cho[j].order_of_key(inv);

                bool nw = false;
                if (cho[j].size()) {
                    nw ^= it & 1;
                }

                it = necho[j].order_of_key(inv);

                if (necho[j].size()) {
                    nw ^= (necho[j].size() - it) & 1;
                }

                flag ^= nw;
            } else {
                cho[j].insert(val);

                int inv = pw - val;

                int it = necho[j].order_of_key(inv);

                bool nw = false;
                if (necho[j].size()) {
                    nw ^= it & 1;
                }

                it = cho[j].order_of_key(inv);

                if (cho[j].size()) {
                    nw ^= (cho[j].size() - it) & 1;
                }

                flag ^= nw;
            }
            
            if (flag) {
                res ^= pw; 
            }

            pw <<= 1;
        }

    }

    std::cout << res << '\n';
    return 0;
}
