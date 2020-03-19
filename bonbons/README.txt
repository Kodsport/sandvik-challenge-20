Clearly, it is not possible if there are more than RC/2 cupcakes of any particular flavour.
Otherwise, it is possible, and the following construction can be proven to work.

Assume that A >= B >= C

First, we will fill in the following pattern, top-bottom, left-right.
X.X.X.
.X.X.X
X.X.X.
.X.X.X
Then, we will fill in the following pattern, top-bottom, left-right.
.X.X.X
X.X.X.
.X.X.X
X.X.X.

Whenever we place a cupcake, we pick the alphabetically smallest one that we still can place.
This means we will generally first try to place all A's, then B's, then C's, except this may not be possible at some points.

For example, consider the case with a 2x6 grid, 5 A's, 4 B's, 3 C's.
We would first place A's and B's in the following pattern:
A.A.A.
.A.A.B

Now, we can't naively fill in the remaining positions with only B's. This would result in the following conflict:
ABABAB
.A.A.B

However, we note that there exists a place where we can place the B:
ABABA.
BA.A.B

Since the A's and B's must have covered all points with even coordinate sum, the C's can be placed arbitrarily after this:
ABABAC
BACACB

The difficult part of the problem is to realize that there will always be enough places for the remaining B's, after the even pattern has been filled.
This can be proven in the following way.

Initially, we include (RC/2 - A) B's in the even part.
We then have that at most 2(RC/2 - A) = RC - 2A are now adjacent to a B, leaving (RC/2) - (RC - 2A) spots left.
We wish to prove that
B - (RC/2 - A) <= (RC/2) - (RC - 2A)
B <= (RC/2) - (RC - 2A) + (RC/2 - A)
B <= RC - (RC - 2A) - A
B <= 2A - A
B <= A
which is true by assumption.
