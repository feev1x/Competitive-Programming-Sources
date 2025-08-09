#include "bits/stdc++.h"
#define int long long
#define sigma signed
#define pb push_back
using namespace std;
sigma main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x = i, y = n - i;
        if (x * y == y * (y - 1) / 2 + x * (x - 1) / 2) {
            cout << "YES\n2\n";
            cout << x << ' ' << y << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
