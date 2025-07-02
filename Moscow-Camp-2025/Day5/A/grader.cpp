#include "grader.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;
    init(q);
    struct query {int ty, pr, w;};
    std::vector<query> qs(q);
    for (auto &q: qs) {
        cin >> q.ty >> q.pr;
        if (q.ty == 1) {
            cin >> q.w;
        }
    }
    std::vector<int> ans;
    for (auto &q: qs) {
        if (q.ty == 1) {
            add_leaf(q.pr, q.w);
        } else {
            ans.push_back(find_max(q.pr));
        }
    }
    for (int x : ans) {
        cout << x << '\n';
    }
}
