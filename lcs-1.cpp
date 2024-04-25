#include<bits/stdc++.h>
using namespace std;
int length;
string lcsString = "";
int lcs(string X, string Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1]) {
        lcsString = X[m - 1] + lcsString;
        return 1 + lcs(X, Y, m - 1, n - 1);
    } else {
        int lcs1 = lcs(X, Y, m, n - 1);
        int lcs2 = lcs(X, Y, m - 1, n);
        return max(lcs1, lcs2);
    }
}

int main() {
    string S1, S2;
    cout << "Enter first string:" << endl;
    cin>>S1;
    cout << "Enter second string :" << endl;
    cin>>S2;

    int m = S1.length();
    int n = S2.length();
    int lcsLength = lcs(S1, S2, m, n);
    length=lcsLength;
    cout << "Length of LCS is: " << lcsLength << endl;
    cout << "LCS is: " << lcsString << endl;
    return 0;
}
