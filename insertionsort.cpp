#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void insertionSort(int arr[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=arr[i] ;
        j=i-1;
        while(j>=0 && arr[j]>k)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+ 1]=k;
    }
}
int main(){
    int arr[1000];
    int n ;
    cout<<"Length of array:"<<endl;
    cin>>n;
    cout<<"Enter elements:"<<endl;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
