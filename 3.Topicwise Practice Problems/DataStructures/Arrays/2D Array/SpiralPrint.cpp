#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<< arr[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }

    int row_start = 0;
    int row_end = n-1;
    int column_start = 0;
    int column_end = m-1;

    while (row_start <= row_end && column_start <= column_end)
    {
        for (int col = column_start; col <= column_end; col++)
        {
            cout << arr[row_start][col]<<" ";
        }
        row_start++;
        for (int row= row_start; row <= row_end; row++)
        {
            cout << arr[row][column_end]<<" ";
        }
        column_end--;
        
            if (row_start <= row_end)
                for (int col = column_end; col >= column_start; col--)
                {
                    cout << arr[row_end][col] << " ";
                }
        row_end--;
        if (column_start <= column_end)
            for (int row = row_end; row >= row_start; row--)
            {
                cout << arr[row][column_start] << " ";
            }
        column_start++;
        }
}

int main()
{


    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
