#include<iostream>
#include<vector>
#include<array>
#include<string>
using namespace std;
extern vector<vector<long long>> solve(string S_0, vector<string> S_ACGT, vector<long long> K, vector<long long> L, vector<long long> R);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s0; cin >> s0;
    string sa; cin >> sa;
    string sc; cin >> sc;
    string sg; cin >> sg;
    string st; cin >> st;

    int q; cin >> q;
    vector<long long> k(q);
    vector<long long> l(q);
    vector<long long> r(q);
    for (int i = 0; i < q; i += 1) cin >> k[i] >> l[i] >> r[i];

    for (auto v : solve(s0, {sa, sc, sg, st}, k, l, r)) {
	    for (auto x: v) cout << x << " ";
	    cout << "\n";
    }
    return 0;
}
