#include<bits/stdc++.h>
using namespace std;

void naiveStringMatch(const string& s, const string& p) {
    int n = s.length();
    int m = p.length();
    int i,j;
    for ( i = 0; i <= n - m; ++i) { 
        for ( j = 0; j < m; ++j) {  
            if (s[i + j] != p[j]) {
                break; 
            }
        }
        if (j == m) { 
            cout << "Pattern found at index " << i << endl;
        }
        else{
            cout<<"Pattern not found"<<endl;
        }
    }
}

int main() {
    string s, p;
    cout << "Enter the text: ";
    cin >> s;
    cout << "Enter the pattern to search for: ";
    cin >> p;

    naiveStringMatch(s, p);

    return 0;
}
