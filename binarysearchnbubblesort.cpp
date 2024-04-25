//iterative
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void bubbleSort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    
}
int binarySearch(int arr[],int k, int min,int max)
{
    while(max>=min)
    {
        int mid=(max+min)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k){
            min=mid+1;
        }
        else
        {
            max=mid-1;
        }
    }
    return -1;
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
    bubbleSort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    int k;
    cout<<"\nEnter the element to find:"<<endl;
    cin>>k;
    int result=binarySearch(arr,k,0,n-1);
    if (result!=-1){
        cout<<"Element found at "<<result+1<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}


//recursive

#include <stdio.h>
void bubble_sort(int arr[], int n);
int binary_search(int arr[], int k, int min, int max);
int main() {
    int arr[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int k;
    printf("Enter the element to search: ");
    scanf("%d", &k);

    int result = binary_search(arr, k, 0, n - 1);

    if (result != -1) {
        printf("Element is found.\n");
       // printf("Element is found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int k, int min, int max)
{
  if (max < min)
    return -1;
  else{
      int mid = (min+max)/2;
      if (arr[mid] > k)
        return binary_search(arr, k, min, mid-1);
      else if (arr[mid] < k)
        return binary_search(arr, k, mid+1, max);
      else
        return mid;
    }
}

