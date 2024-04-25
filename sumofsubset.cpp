#include <bits/stdc++.h>
using namespace std;
int total=0;
void sumsubset(int i, int n, vector<int> &v, int k, vector<int> &temp)
{
    if(k < 0)
        return;
    if(k == 0)
    {
        cout << "Elements of subset are: \n";
        for(auto &i: temp)cout << i << " ";
        cout << "\n";
        total++;
        return;
    }
    if(i == n)
        return;
    sumsubset(i + 1, n, v, k, temp);
    temp.push_back(v[i]);
    sumsubset(i + 1, n, v, k - v[i], temp);
    temp.pop_back();
}
int main()
{
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;

    vector<int> v(n);
    cout << "Enters the elements:\n";
    for(auto &i: v)
        cin >> i;

    cout << "Enter the target sum:\n";
    int k; //max sum
    cin >> k;
    vector<int> temp;
    sumsubset(0, n, v, k, temp);
    cout<<"Total Subsets: "<<total<<endl;
}
