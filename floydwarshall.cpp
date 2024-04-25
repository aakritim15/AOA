#include <iostream>
#include <vector>
using namespace std;
int main() {
   int n;
   cout<<"Enter no. of vertices :";
   cin >>n;
   vector<vector<int>> v(n, vector<int>(n,1e9)),path(n,vector<int>(n));
   cout << "Enter the adjacency matrix (use 999 for absent edges):\n";
   for(int i =0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>v[i][j];
       }
   }
   for(int k =0;k<n;k++){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(v[i][k]+v[k][j]<v[i][j]){
                   path[i][j]=k+1;
                   v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
               }
           }
       }
   }
   cout<<endl<<"Distance:"<<endl;
   for(int i =0;i<n;i++){
       for(int j=0;j<n;j++){
           cout<<v[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl<<"Path:"<<endl;
   for(int i =0;i<n;i++){
       for(int j=0;j<n;j++){
           cout<<path[i][j]<<" ";
       }
       cout<<endl;
   }
   cout << endl << "Displaying paths" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] != 999)
            {
                cout << "Intermediate nodes from: " << i + 1 << " - " << j + 1<< ": ";
                int x = path[i][j];
                while(x != 0)
                {
                    cout << x << " ";
                    x = path[x-1][j];
                }
                cout << endl;
            }

        }
    }
   return 0;
}
