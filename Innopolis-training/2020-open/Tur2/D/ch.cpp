/**
 *    author:  feev1x
 *    created: 21.11.2024 16:20:03
**/
#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
void FermatFactors(int n) 
    { 
         
        // since fermat's factorization applicable 
        // for odd positive integers only 
        if(n <= 0) 
        { 
            cout << "[" << n << "]"; 
            return; 
        } 
     
        // check if n is a even number 
        if((n & 1) == 0) 
        { 
            cout << "[" << n / 2.0 << "," << 2 << "]"; 
            return; 
        } 
             
        int a = ceil(sqrt(n)) ; 
     
        // if n is a perfect root, 
        // then both its square roots are its factors 
        if(a * a == n) 
        { 
            cout << "[" << a << "," << a << "]"; 
            return; 
        } 
        int b; 
        while(true) 
        { 
            int b1 = a * a - n ; 
            b = (int)sqrt(b1) ; 
             
            if(b * b == b1) 
                break; 
            else
                a += 1; 
        } 
        cout << "[" << (a - b) << "," << (a + b) << "]" ; 
        return; 
    } 
int main() {
  FermatFactors(5459683);
  return 0;
}
