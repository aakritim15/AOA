#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void combine(vector<int> &v,int l, int mid, int h) {
    int k=0;
    int i=l;
    int j=mid+1;
    vector<int> tmp(h-l+1);
    while (i<=mid && j<= h){
        if(v[i]<v[j])
        {
            tmp[k]=v[i];
            i++;
            k++;
        }
        else
        {
            tmp[k]=v[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        tmp[k]=v[i];
        i++;
        k++;
    }
    while(j <= h)
    {
        tmp[k]=v[j];
        j++;
        k++;
    }
    for(int a=0;a<h-l+1;a++){
        v[l+a]=tmp[a];
    }
}

void mergeSort(vector<int> &v,int l,int h,int n)
{
   if(l <h){
       int mid=(l+h) / 2;
       mergeSort(v,l,mid,n);
       mergeSort(v,mid+1,h,n);
       combine(v,l,mid,h);
   }

}


int main(){
    int n ;
    cout<<"Length of array:"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements:"<<endl;
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    v[n]=1e9;
    mergeSort(v,0,n-1,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// void combine(vector<int>& arr,int low, int mid, int high) {
//     int n1 = mid - low + 1;
//     int n2 = high - mid;
//     vector<int> L(n1), R(n2);
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[low + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];
//     int i = 0, j = 0, k = low;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }

// }
// void mergeSort(vector<int>& arr, int low, int high) {
//     if (low < high) {
//         int mid =( low + high )/ 2;

//             cout<<"Mid-element:"<<arr[mid]<<"\n";
//             cout<<"Before Sorting Array:"<<endl;
//             cout << "Unsorted Left Part: ";
//             for (int i = low; i <= mid; i++)
//                 cout << arr[i] << " ";
//             cout << endl;

//             cout << "Unsorted Right Part: ";
//             for (int i = mid + 1; i <= high; i++)
//                 cout << arr[i] << " ";
//             cout << endl;

//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);
//         combine(arr, low, mid, high);
//         cout<<endl;
//         if(high - low + 1 == arr.size())
//         {
//             cout<<"After Sorting Array:"<<endl;
//             cout << "Sorted Left Part: ";
//             for (int i = 0; i <= mid; i++)
//                 cout << arr[i] << " ";
//             cout << endl;
//             cout << "Sorted Right Part: ";
//             for (int i = mid + 1; i <= high; i++)
//                 cout << arr[i] << " ";
//             cout << endl;
//         }

//     }
// }
// int main() {
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter the elements of the array:\n";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << "Given array is:\n";
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     mergeSort(arr, 0, arr.size() - 1);
//     cout << "\nSorted array is \n";
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     return 0;
// }

