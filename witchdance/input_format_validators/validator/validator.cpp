#include <bits/stdc++.h>
#include "validator.h"
using namespace std;

void run() {
	int n = Int(1, 200'000);
	Endl();
    for (int i = 0; i < n; i++) {
        FixedReal(-1'000'000'000, 1'000'000'000, 20); Space();
        FixedReal(-1'000'000'000, 1'000'000'000, 20); Space();
        FixedReal(0, 2*M_PI, 20); Endl();
    }
    Eof();
}
