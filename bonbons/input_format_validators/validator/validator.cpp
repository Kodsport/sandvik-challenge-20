#include <bits/stdc++.h>
#include "validator.h"
using namespace std;

void run() {
	int r = Int(2, 1000);
    Space();
	int c = Int(2, 1000);
	Endl();

	assert(r % 2 == 0);
	assert(c % 2 == 0);

	int a = Int(0, r * c);
	Space();
	int b = Int(0, r * c);
	Space();
	int c2 = Int(0, r * c);
	Endl();

	assert(a + b + c2 == r * c);
}
