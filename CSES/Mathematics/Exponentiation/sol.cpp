/**
 *    author:  feev1x
 *    created: 26.03.2025 16:07:02
**/
#include <bits/stdc++.h>
 
constexpr int MOD = 1e9 + 7;
 
inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}
 
inline int binpow(int a, int n) {
    int res = 1;
 
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
 
        a = mul(a, a);
        n >>= 1;
    }
 
    return res;
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    while (n--) {
        int a, b; std::cin >> a >> b;
 
        std::cout << binpow(a, b) << '\n';
    }
    return 0;
}

