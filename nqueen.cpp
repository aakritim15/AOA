#include <bits/stdc++.h>
using namespace std;
void nqueen(int i, int n, vector<int> &col, vector<int> &d1, vector<int> &d2, vector<vector<char>> & board)
{
    if(i == n)
    {
        cout << "\nBoard :\n";
        for(int k = 0; k < n; k++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[k][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(int j = 0; j < n; j++)
    {
        if(!col[j] && !d1[abs(i + j)] && !d2[n+i-j])
        {
            board[i][j] = 'Q';
            col[j] =1;
            d1[abs(i + j)] = 1;
            d2[n+i-j] = 1;
            nqueen(i + 1, n, col, d1, d2, board);


            board[i][j] = '.';
            col[j] =0;
            d1[abs(i + j)] = 0;
            d2[n+i-j] = 0;
        }
    }
}


int main()
{
    cout << "Enter the size of board(n-queen):\n";
    int n; 
    cin >> n;
    vector<int> col(n), d1(n+2), d2(2* n+2); //diagonal 1 & 2
    vector<vector<char>> board(n, vector<char>(n, '.'));
    nqueen(0, n, col,d1,d2,board);
}
