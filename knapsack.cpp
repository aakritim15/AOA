#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> &v)
{
    cout << "The array is\n";
    for(int i = 0; i < v.size(); i++)
    {
        cout << "Item: " << v[i][0] << " Weight: " << v[i][1] << " Value: " << v[i][2] << "\n";
    }
}
bool by_weight(vector<int> a, vector<int> b) //weight ascending
{
    return a[1] < b[1];
}
bool by_value(vector<int> a, vector<int> b) //profit descending
{
    return a[2] > b[2];
}
bool by_ratio(vector<int> a, vector<int> b) //ratio descending
{
    return a[2]/a[1] > b[2]/b[1];
}

void greedy(vector<vector<int>> &v,  int m)
{
    vector<int> items;
    int value = 0; //profit
    int a = 0; //counter
    for(int i = 0; i < v.size(); i++)
    {
        if(m >= v[i][1])
        {
            a++;
            items.push_back(v[i][0]); 
            value += v[i][2];
            m -= v[i][1];
        }
        else
        {
            break;
        }
    }

    if(m == 0 || a == v.size())
    {
        cout << "items taken: ";
        for(auto &i: items)cout << i << " ";
        cout << "\n";
        cout << "value: " << value << "\n";
        return;
    }

    float fraction = (float)m/v[a][1];
    if(fraction != 0)
    {
        value += fraction * v[a][2];
    }
    cout << "items taken: ";
    for(auto &i: items)cout << i << " ";
    cout << fraction << " of " << v[a][0];
    cout << "\n";

    cout << "value: " << value << "\n";
    return;
}
int main()
{
    int n;
    cout << "Enter the number of items:\n";
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3));
    for(int i = 0; i < n; i++)
    {
        cout << "Enter weight and value of item " << i + 1 << ":\n";
        v[i][0] = i + 1; //item number
        cin >> v[i][1]; //weight
        cin >> v[i][2]; //profit
    }
    cout << "Enter the maximum capacity of a knapsack:\n";
    int m; cin >> m;
    cout << "Knapsack by weight:\n";
    sort(v.begin(), v.end(), by_weight);
    greedy(v, m);
    cout << "Knapsack by value:\n";
    sort(v.begin(), v.end(), by_value);
    greedy(v, m);
    cout << "Knapsack by ratio\n";
    sort(v.begin(), v.end(), by_ratio);
    greedy(v, m);
    // printArray(v);
}

