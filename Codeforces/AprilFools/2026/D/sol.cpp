#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    if (n == 1) std::cout << "walk";
    else if (n == 2) std::cout << "no";
    else if (n == 3) std::cout << "no";
    else if (n == 4) std::cout << "no";
    else if (n == 5) std::cout << "yes";
    else if (n == 6) std::cout << "yes";
    else if (n == 7) std::cout << "backwards";
    else std::cout << "1";
    return 0;
}
