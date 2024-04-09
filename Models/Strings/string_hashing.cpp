

// for usecase of this refer game on a cd problem in string_hashing folder
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};


void compute_hash(string const& s) {
    const int p = 31;
    const int m1 = 1e9 + 9;
    long long hash_value1 = 0;
    long long p_pow1 = 1;
    vector<long long> pref1(s.size(), 0);
    int i=1;
    for (char c : s) {
        hash_value1 = (hash_value1 + (c - 'a' + 1) * p_pow1) % m1;
        pref1[i] = (pref1[i - 1] + (s[i] - 'a' + 1) * p_pow1) % m1;
        p_pow1 = (p_pow1 * p) % m1;
    }

    // y 2 m2 values for the same string?
    // to avoid collisions

    const int m2 = 1e9 + 7;
    long long hash_value2 = 0;
    long long p_pow2 = 1;
    i = 1;
    vector<long long> pref2(s.size(), 0);
    for (char c : s) {
        hash_value2 = (hash_value2 + (c - 'a' + 1) * p_pow2) % m2;
        pref2[i] = (pref2[i - 1] + (s[i] - 'a' + 1) * p_pow2) % m2;
        p_pow2 = (p_pow2 * p) % m2;
    }
}


// example 1 Search for duplicate strings in an array of strings

vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

// O(n^2) solution to count the number of unique substrings of a string
// this is not the best solution, but it is simple and works well in practice
int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) { // l is the length of the substring
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}


// Rabin-Karp algorithm for string matching
/*
 Given two strings - a pattern  
$s$  and a text  
$t$ , determine if the pattern appears in the text and if it does, enumerate all its occurrences in $O(n + m)$ time complexity.
*/
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}