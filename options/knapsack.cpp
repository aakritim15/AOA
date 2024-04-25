#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w;
    int p;
    double ratio;

    Item(int w, int p) : w(w), p(p)
    {
        ratio = (double)p / (double)w;
    }
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fracKnapsack(int capacity, vector<Item>& items)
{
    sort(items.begin(), items.end(), compare);

    double tProfit = 0.0;
    int currWeight = 0;

    for (int i = 0; i < items.size(); ++i)
        {
        if (currWeight + items[i].w <= capacity)
        {
            currWeight += items[i].w;
            tProfit += items[i].p;
        }
        else
        {
            int remWeight = capacity - currWeight;
            tProfit += items[i].ratio * remWeight;
            break;
        }
    }

    return tProfit;
}

int main()
{
    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter weights and profits of items:\n";

    for (int i = 0; i < n; ++i)
    {
        int w, p;
        cin >> w >> p;
        items.push_back(Item(w, p));
    }

    double mxProfit = fracKnapsack(capacity, items);
    cout << "Maximum profit possible: " << mxProfit << endl;

    return 0;
}





//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    double value;
    double weight;
    double ratio; 
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double knapsack(vector<Item>& items, double capacity) {
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0;
    double remainingCapacity = capacity;

    for (int i = 0; i < items.size(); i++) {
        if (remainingCapacity >= items[i].weight) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += (remainingCapacity / items[i].weight) * items[i].value;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter value(profit) and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    double capacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;
    
    double maxValue = knapsack(items, capacity);
    
    cout << "Maximum profit: " << maxValue << endl;
    
    return 0;
}

