/**
 *    author:  feev1x
 *    created: 06.02.2025 11:45:46
**/
#include <bits/stdc++.h>

int main() {
    int xr = 0;

    while (true) {
        int x; std::cin >> x;

        xr ^= x;

        std::cout << "XOR " << xr << '\n';
    }
    return 0;
}
