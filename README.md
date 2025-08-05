# competitive_programming

TODO:
    Notes about Tail Recursion
    Master's theorem
    Read square root soln 3, leetcode.com/problems/sqrtx
    Why just Binary search why not N-ary search, (for example ternary search (split into 3) or why not more) what is the answer to this?

WTF:
    calculating square root 
    lets say question is we have to find root floored, 
        root(x) = 2 * root(x/4) [recursive relation]
        base conditions -> root(0) = 0, root(1) = 1

        so code becomes 
            ```c++
            int square_root_recur(int x) {
                if (x < 2) return x;

                int left = square_root_recur(x >> 2) << 1;
                int right = left + 1;
                return (long long) right * right > x ? left : right;
            }
            ```
