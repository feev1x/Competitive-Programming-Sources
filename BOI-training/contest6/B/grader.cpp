#include <iostream>
#include <vector>
#include "highest.h"
#include "sol.cpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    int m;
    cin >> m;
    
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<int> results = solve(v, w, queries);
    
    for (int i = 0; i < m; i++) {
        cout << results[i] << "\n";
    }
    
    return 0;
}
