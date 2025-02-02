#include <iostream>
#include "caesar.h"
#include "caesar.cpp"
using namespace std;
/*
This file needs to be compiled along with the header caesar.h and
the file caesar.cpp. This means that you have to put these files
in the same project and run them together.
*/

/*
This file allows you to test your source code by giving it the
problem's input.
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n, q;
    cin >> n >> q;
    char a[n + 10], b[n + 10];
    cin >> a >> b;

    init(n, q, a, b);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
   return 0;
}
