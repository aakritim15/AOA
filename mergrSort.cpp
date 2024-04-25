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


