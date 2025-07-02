#include "grader.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tn = 1; tn <= t; ++tn) {
        int n;
        cin >> n;
        vector<long long> a;
        for (int i = 0; i < n; ++i) {
            long long num;
            cin >> num;
            a.push_back(num);
        }
        vector<pair<long long, long long>> res = solve(a);
        if (res.size() == 0u) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (pair<long long, long long> p : res) {
                cout << p.first << " " << p.second << "\n";
            }
        }
    }
}
