

/*
    Problem: Given a string s of length n, find the number of different substrings of s.

    summation( [[0]-[n-1]](n-p[i]) ) - summation( [[0]-[n-2]](lcp[i]) ) == n*(n+1)/2 + n - summation( [[0]-[n-2]](lcp[i]) )

*/