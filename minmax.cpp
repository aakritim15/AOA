//recusrive
#include<bits/stdc++.h>

using namespace std;

void MinMax(vector<int> &a, int l, int h, int *mn, int *mx)
{
    if (l == h)
    {
        *mn = a[l];
        *mx = a[h];
    }
    else if (h == l + 1)
    {
        if (a[l] <= a[h])
        {
            *mx = a[h];
            *mn = a[l];
        }
        else
        {
            *mx = a[l];
            *mn = a[h];
        }
    }
    else
    {
        int mid = (h + l) / 2;
        int mn1 = 10e5, mx1 = -10e6, mn2 = 10e5, mx2 = -10e6;
        MinMax(a, l, mid, &mn1, &mx1);
        MinMax(a, mid + 1, h, &mn2, &mx2);

        *mn = (mn1 < mn2) ? mn1 : mn2;
        *mx = (mx1 > mx2) ? mx1 : mx2;
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "\n" << "Enter the elements: ";
    for (auto& i : a)
    {
        cin >> i;
    }
    int mn = 10e5, mx = -10e5;
    MinMax(a, 0, a.size() - 1, &mn, &mx);
    cout << "Min:" << mn <<"\n" << " Max:" << mx << "\n";

    return 0;
}


//iteratvive
#include <bits/stdc++.h>
using namespace std;
void MinMax(const vector<int> &a, int &minVal, int &maxVal)
{
    if (a.empty())
    {
        cout << "Vector is empty." << endl;
        return;
    }
    minVal = maxVal = a[0];
    for (size_t i = 1; i < a.size(); ++i)
    {
        if (a[i] < minVal)
        {
            minVal = a[i];
        }
        else if (a[i] > maxVal)
        {
            maxVal = a[i];
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int minVal, maxVal;
    MinMax(a, minVal, maxVal);
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    return 0;
}