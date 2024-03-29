#include <bits/stdc++.h>

using namespace std;

int n, k;
int cur[26];
vector<int> path;

void dfs(int v)
{
    while (cur[v] < k) // to use it as visited
    {
        int u = cur[v];
        cur[v]++;
        dfs(u);
        path.push_back(u);
    }
}

int main()
{
    cin>>n>>k;
    dfs(0);
    cout<<"a";
    for (int i = 0; i < n - 1; ++i)
       cout<<char('a'+path[i % path.size()]);
    cout<<endl;   
}