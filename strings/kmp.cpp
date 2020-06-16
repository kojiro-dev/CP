vector<int> constructLps(const string &pat) {
    int m = pat.length();
    vector<int> lps(m);

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
    return lps;
}

vector<int> kmp(const string &s, const string &t) {
    int n = s.length(), m = t.length();

    vector<int> lps = constructLps(t), occur;
    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == t[j]) {
            i += 1;
            j += 1;
        }

        if (j == m) {
            occur.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n and s[i] != t[j]) {
            if (j != 0)
                j = lps[j-1];
            else i += 1;
        }
    }
    return occur;
}