#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void selectionSort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int tmp =arr[min];
        arr[min]=arr[i];
        arr[i]=tmp;
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
    selectionSort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
