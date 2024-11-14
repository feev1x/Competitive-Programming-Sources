/**
 *    author:  feev1x
 *    created: 08.11.2024 10:53:49
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

struct pt {
	ld x, y;
};
 
bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
 
bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
 
bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
 
 
ld dis(pt p, pt p1) {
	return sqrt((p.x - p1.x) * (p.x - p1.x) + (p.y - p1.y) * (p.y - p1.y));
}

signed main() {
  int n, l; scanf("%d%d", &n, &l);
	vector<pt> a(n);
	for (auto &[x, y]: a) scanf("%Lf%Lf", &x, &y);
	sort(a.begin(), a.end(), &cmp);
	auto p1 = a.front();
	auto p2 = a.back();
	vector<pt> up, down;
	up.emplace_back(p1);
	down.emplace_back(p1);
	for (int i = 1; i < a.size(); ++i) {
		if (i == a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i == a.size() - 1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	ld p = 0;
	vector<pt> v = up;
	reverse(down.begin(), down.end());
	for (auto x: down) v.emplace_back(x);
	for (int i = 1; i < v.size(); ++i) p += dis(v[i], v[i - 1]);
	p += acos(-1) * l * 1.80063263;
	printf("%.7Lf\n", p);  
  return 0;
}
