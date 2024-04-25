#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string& p) {
    int m = p.length();
    int len = 0;

    for (int i = 1; i < m; ++i) {
        while (len > 0 && p[i] != p[len]) {
            len = lps[len - 1]; 
        }
        if (p[i] == p[len]) {
            ++len;
        }
        lps[i] = len;
    }
    return lps;
}


void kmpSearch(const string& s, const string& p) {
    int n = s.length();
    int m = p.length();
    vector<int> lps = computeLPS(p);
    int j = 0;

    for (int i = 0; i < n; ++i) { /
        while (j > 0 && s[i] != p[j]) {
            j = lps[j - 1]; 
        }
        if (s[i] == p[j]) {
            ++j;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j + 1 << endl;
            j = lps[j - 1]; 
        }
    }
}

int main() {
    string s, p;
    cout << "Enter the text: ";
    cin >> s;
    cout << "Enter the pattern to search: ";
    cin >> p;
    kmpSearch(s, p);

    return 0;
}
