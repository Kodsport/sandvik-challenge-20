#include <bits/stdc++.h>
#include "validator.h"
using namespace std;

void run() {
	int n = Int(1, 1000);
    Space();
	int m = Int(1, 1'000'000'000);
	Endl();

    SpacedInts(n, 1, 1'000'000'000);
    SpacedInts(n-1, 1, 1'000'000'000);
    Eof();
}
