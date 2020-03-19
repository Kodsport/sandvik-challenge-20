#include <bits/stdc++.h>
#include "validator.h"
using namespace std;

void run() {
	int n = Int(2, 100);
    Space();
	int m = Int(2, n * (n-1));
	Endl();

	int maxt = 1'000'000'000;
	for (int i = 0; i < n; i++) {
		int s = Int(1, maxt);
		Space();
		Int(s+1, maxt);
		Endl();
	}

	set<pair<int, int>> eds;
	for (int i = 0; i < m; i++) {
		int a = Int(0, n-1);
		Space();
		int b = Int(0, n-1);
		Endl();
		assert(a != b);
		assert(!eds.count(make_pair(a, b)));
		eds.insert(make_pair(a, b));
	}
}
