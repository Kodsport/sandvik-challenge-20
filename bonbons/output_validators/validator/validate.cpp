#include <bits/stdc++.h>
#include "validate.h"

using namespace std;

int R, C;
int counts[3];

int read_sol(istream& is, feedback_function fail) {
	vector<string> grid(R);
	is >> grid[0];
	for (char& c : grid[0]) c = (char)toupper(c);
	if (grid[0] == "IMPOSSIBLE") return 0;
	for (int i = 1; i < R; i++) {
		is >> grid[i];
		for (char& c : grid[i]) c = (char)toupper(c);
	}

	int co[3] = {0, 0, 0};
	for (int i = 0; i < R; i++) {
		if ((int)grid[i].size() != C) fail("expected line to have width %d, got %d", C, (int)grid[i].size());
		for (int j = 0; j < C; j++) {
			char ch = grid[i][j];
			if (ch == 'A') co[0]++;
			else if (ch == 'B') co[1]++;
			else if (ch == 'C') co[2]++;
			else fail("found bad character in grid at pos %d, %d: %d", i, j, ch);
		}
	}
	for (int i = 0; i < 3; i++) if (co[i] != counts[i])
		fail("bad count: expected %d %c's, found %d", counts[i], 'A' + i, co[i]);
	string dummy;
	if (is >> dummy) fail("trailing garbage: %s", dummy.c_str());
	return 1;
}

int main(int argc, char **argv) {
	init_io(argc, argv);
	judge_in >> R >> C >> counts[0] >> counts[1] >> counts[2];

	int author_sol = read_sol(author_out, wrong_answer);
	int judge_sol = read_sol(judge_ans, judge_error);

	if (author_sol > judge_sol) {
		judge_error("Judge claimed WA, but contestant found a solution");
	}

	if (author_sol < judge_sol) {
		wrong_answer("Contestant claimed WA, but there is a solution");
	}

	accept();
}
