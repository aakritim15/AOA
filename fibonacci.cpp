#include<bits/stdc++.h>
using namespace std;

void fibonacci(int n) {
    int p = 0;
    int c = 1;
    cout << "Fibonacci Series up to " << n << " terms:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << p << " ";
        int next = p + c;
        p = c;
        c = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the terms for Fibonacci series: ";
    cin >> n;
    fibonacci(n);
    return 0;
}
