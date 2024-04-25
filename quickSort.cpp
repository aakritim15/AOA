#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int partition(int arr[],int l,int h){
    int p=arr[l];
    int i=l;
    int j=h+1;
    while(i<=j)
    {
        while(arr[i]<=p)
        {
            i++;
        }
        while(arr[j]>p)
        {
            j--;
        }
        if(i<=j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;

}
void quickSort(int arr[],int l,int h)
{
   if(l <h){
       int mid=partition(arr,l,h);
       quickSort(arr,l,mid-1);
       quickSort(arr,mid+1,h);
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
    arr[n]=1e9;
    quickSort(arr,0,n-1);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
