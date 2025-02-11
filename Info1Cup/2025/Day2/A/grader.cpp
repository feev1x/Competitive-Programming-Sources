#include <iostream>
#include <vector>
#include "modulosum.h"
#include "sol.cpp"

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector <int> A(N), L(Q), R(Q), M(Q);
    for ( int i = 0; i < N; i ++ ) {
        cin >> A[i];
    }
    for ( int i = 0; i < Q; i ++ ) {
        cin >> L[i] >> R[i] >> M[i];
    }
    vector <long long> answer = solve( N, Q, A, L, R, M );

    for ( int i = 0; i < Q; i ++ ) {
        cout << answer[i] << '\n';
    }
    return 0;
}


