#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int> &v, int i, int k,  vector<vector<int>> &dp, vector<vector<int>> &p)
{
    if(i == k) return dp[i][k]= 0;
    int mn = 1e9;
    if(dp[i][k] != -1) return dp[i][k];
    for(int j = i; j < k; j++)
    {
        int x = (mcm(v, i, j, dp, p) + mcm(v, j+1, k, dp, p) + v[i-1] * v[j] * v[k]);
        if(x < mn)
        {
            mn = x;
            p[i][k] = j;
        }
    }
    return dp[i][k] = mn;
}
int main()
{
    cout << "Enter the number of dimensions: \n";
    int n;
    cin >> n;
    cout << "Enter the dimensions(d):\n";
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    vector<vector<int>> dp(n, vector<int>(n, -1)), r(n, vector<int>(n)), p(n, vector<int>(n));
    cout << "Minimum cost for matrix chain is: " << mcm(v, 1, n-1, dp, p) << endl;
    cout << "DP Matrix: \n";
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "P Matrix: \n";
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    stack<int> s;
    int a = n - 1;
    while(p[1][a] != 0)
    {
        s.push(a);
        a = p[1][a];
    }
    cout << "The way is: ";
    cout << 1 << " ";
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
