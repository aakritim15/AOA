#include<bits/stdc++.h>
using namespace std;

pair<int, string> findLCS( string& a,string& b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> v(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                v[i][j] = v[i - 1][j - 1] + 1;
            } else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs = a[i - 1] + lcs;
            i--;
            j--;
        } else if (v[i - 1][j] > v[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {v[m][n], lcs};
}

int main() {
    cout << "Enter two strings to find LCS:\n";
    string a, b;
    cin >> a >> b;
    auto result = findLCS(a, b);
    cout << "\nLength of LCS is: " << result.first << "\n";
    cout << "LCS is: " << result.second << "\n";

    return 0;
}
