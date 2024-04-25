
//
#include <bits/stdc++.h>
using namespace std;
int matrixMult(vector<int> &dim, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &k)
{
    if (i == j)
        dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = 1e9;
    for (int r = i; r < j; ++r) //r=parenthesis
    {
        int a = (matrixMult(dim, i, r, dp, k) + matrixMult(dim, r + 1, j, dp, k) + dim[i - 1] * dim[r] * dim[j]);
        if (a < mn)
        {
            mn = a;
            k[i][j] = r;
        }
    }
    return dp[i][j] = mn;
}
int main()
{
    int n;
    cout << "Enter the number of dimension: ";
    cin >> n;
    vector<int> dim(n);
    cout << "Enter the dimensions: ";
    for (auto &i : dim)
        cin >> i;
    vector<vector<int>> dp(n, vector<int>(n, -1)), k(n, vector<int>(n));  /// dp=cost   k=parenthesis
    cout << "Minimum cost of multiplications is " << matrixMult(dim, 1, n - 1, dp, k) << endl;
    stack<int> st;
    int b = n - 1;
    while (k[1][b] != 0)
    {
        st.push(b);
        b = k[1][b];
    }
    cout << "Path: ";
    cout << 1 << " ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}