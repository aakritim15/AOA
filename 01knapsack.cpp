
// dp
#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
 
int main(void)
{
    // 0/1 Knapsack-dynamic programming
    // Input n is number of items u is capacity v is values(profit) vector w is weight vector
    int n, u;
    cout<<"Number of items:"<<endl;
    cin >> n ;
    cout<<"Capacity maximum:"<<endl;
    cin>> u;

    // 1 based indexing
    vector<int> w(n + 1), v(n + 1);
     cout<<"Weight values:"<<endl;
    for(int i = 1; i <= n; i++)cin >> w[i];
     cout<<"Profit values:"<<endl;
    for(int i = 1; i <= n; i++)cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(u + 1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= u; j++)
        {
            // According to the transition function
            if(i == 0 || j == 0)continue;
            else if(w[i] > j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i-1][j]);
        }
    }
    cout <<"maximum profit:" dp[n][u] << endl;
}