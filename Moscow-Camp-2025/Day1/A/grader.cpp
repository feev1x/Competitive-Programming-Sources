#include "grader.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
    	cin >> edges[i].first >> edges[i].second;
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
    	cin >> queries[i].first >> queries[i].second;
    }

    auto ans = Solve(n, m, q, edges, queries);
    for (auto i : ans) {
    	cout << i << '\n';
    }
}
