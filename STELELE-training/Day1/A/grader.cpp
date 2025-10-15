#include <bits/stdc++.h>
#include "joker.h"
#include "sol.cpp"

using namespace std;

int score = 0;
void solve(int N);

int n, L, R, n_oper;

const int nmax = 1e3 + 5;
int mat[nmax][nmax];

int query(std::vector<int> a) { 
   if(a.size() != n) { cerr << "Size Invalid!\n"; exit(-1); }
   int minim = a[L], maxim = a[L];
   for(int i = L + 1; i <= R; i++) minim = min(a[i], minim), maxim = max(a[i], maxim);
   
   int ans;
   if(n_oper % 2 == 0) ans = minim;
   else ans = maxim;
   
   cerr << "S-a apelat query(";
   for (int i = 0; i < a.size(); i++) {
      cerr << a[i];
      if (i < a.size() - 1) cerr << ", ";
   }
   cerr << ").\nAm raspuns " << ans << "\n\n";
   
   n_oper++;
   return ans;
}

void answer(int l, int r) {
   if(abs(l - L) + abs(r - R) > 1) {
      cerr << "Raspuns Incorect!\n";
      exit(0);
   }
   cout << l << ' ' << r << '\n';
   cerr << "Rezolvat in: " << n_oper << " queryuri\n";
   exit(0);
}

int main() {
    cin >> n;
    cin >> L >> R;
    solve(n);
	return 0;
}

