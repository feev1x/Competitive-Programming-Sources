// author: ponsaid

#include "bits/stdc++.h"

#define nemeshay ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define int long long
#define sigma signed 
#define pb push_back 
#define db long double
#define ar array

using namespace std;

const int N = 1e6 + 7, INF = 1e18;

struct point{
	db x, y;
};

db dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool check(point a, point b, point c) {
	db ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	db mx = max(ab, max(bc, ca)), sum = ab + bc + ca;
	return (mx < sum - mx);
}

void test_case(){
	db a, b, c; cin >> a >> b >> c;
	
	db cx, cy; cin >> cx >> cy;
	
	db x1 = cx, x2, x3, y1, y2 = cy, y3;
	
	if (cx * b + cx * c > (cx + 1) * b + (cx - 1) * c) {
		x2 = (cx * b + c) / b;
		x3 = cx - 1;
	}
	
	else {
		x2 = cx + 1;
		x3 = (cx * c - b) / c;
	}
	
	ar <int, 3> ys;
	if (cy * a + cy * c > (cy + 1) * a + (cy - 1) * c) {
		y1 = (cy * a + c) / a;
		y3 = cy - 1;
	}
	
	else {
		y1 = cy + 1;
		y3 = (cy * c - a) / c;
	}
	
	cout << fixed << setprecision(10);
	
//	assert(check({x1, y1}, {x2, y2}, {x3, y3}));
	assert(cx == (a * x1 + b * x2 + c * x3) / (a + b + c) && cy == (a * y1 + b * y2 + c * y3) / (a + b + c));
	
	cout << x1 << ' ' << y1 << '\n';
	cout << x2 << ' ' << y2 << '\n';
	cout << x3 << ' ' << y3 << '\n';
}

sigma main() {
	nemeshay
	
	int t = 1;
	while (t--) test_case();
}
