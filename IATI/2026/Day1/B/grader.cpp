#include<iostream>
#include<vector>
using namespace std;
extern vector<int> solve(vector<int> A);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t ;
    for (int test=1; test<=t; test++) {
        int n;
        cin >> n ;
        vector <int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i] ;
        }

        for (auto ind : solve(a)) {
            cout << ind << " ";
        }
        cout << endl ;
    }
    cout << endl ;
    return 0;
}
