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

//#include <bits/stdc++.h>
// using namespace std;

// struct Item {
//     int w;
//     int p;
//     double ratio;

//     Item(int w, int p) : w(w), p(p)
//     {
//         ratio = (double)p / (double)w;
//     }
// };

// bool compare(Item a, Item b)
// {
//     return a.ratio > b.ratio;
// }

// double fracKnapsack(int capacity, vector<Item>& items)
// {
//     sort(items.begin(), items.end(), compare);

//     double tProfit = 0.0;
//     int currWeight = 0;

//     for (int i = 0; i < items.size(); ++i)
//         {
//         if (currWeight + items[i].w <= capacity)
//         {
//             currWeight += items[i].w;
//             tProfit += items[i].p;
//         }
//         else
//         {
//             int remWeight = capacity - currWeight;
//             tProfit += items[i].ratio * remWeight;
//             break;
//         }
//     }

//     return tProfit;
// }

// int main()
// {
//     int capacity;
//     cout << "Enter the capacity of knapsack: ";
//     cin >> capacity;

//     int n;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items;
//     cout << "Enter weights and profits of items:\n";

//     for (int i = 0; i < n; ++i)
//     {
//         int w, p;
//         cin >> w >> p;
//         items.push_back(Item(w, p));
//     }

//     double mxProfit = fracKnapsack(capacity, items);
//     cout << "Maximum profit possible: " << mxProfit << endl;

//     return 0;
// }






//#include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Item {
//     double value;
//     double weight;
//     double ratio; 
// };

// bool compare(Item a, Item b) {
//     return a.ratio > b.ratio;
// }

// double knapsack(vector<Item>& items, double capacity) {
//     sort(items.begin(), items.end(), compare);
    
//     double totalValue = 0;
//     double remainingCapacity = capacity;

//     for (int i = 0; i < items.size(); i++) {
//         if (remainingCapacity >= items[i].weight) {
//             totalValue += items[i].value;
//             remainingCapacity -= items[i].weight;
//         } else {
//             totalValue += (remainingCapacity / items[i].weight) * items[i].value;
//             break;
//         }
//     }
    
//     return totalValue;
// }

// int main() {
//     int n;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items(n);
    
//     for (int i = 0; i < n; ++i) {
//         cout << "Enter value(profit) and weight for item " << i + 1 << ": ";
//         cin >> items[i].value >> items[i].weight;
//         items[i].ratio = items[i].value / items[i].weight;
//     }

//     double capacity;
//     cout << "Enter the maximum capacity of the knapsack: ";
//     cin >> capacity;
    
//     double maxValue = knapsack(items, capacity);
    
//     cout << "Maximum profit: " << maxValue << endl;
    
//     return 0;
// }

