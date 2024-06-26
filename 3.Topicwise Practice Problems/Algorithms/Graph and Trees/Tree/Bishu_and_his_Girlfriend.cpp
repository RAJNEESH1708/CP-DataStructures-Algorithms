#include <bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqmx priority_queue<int>                            // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>> //minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int *distances;
int *visited;

void dfs(int root, int dis, vector<int> adj[])
{
    distances[root] = dis;
    visited[root] = 1;
    for (auto nb : adj[root])
    {
        if (!visited[nb])
            dfs(nb, dis + 1, adj);
    }
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n; //number of nodes = n (1, 2 .....)
        // n-1 : number of edges
        vector<int> adj[n + 1];

        visited = new int[n + 1];
        distances = new int[n + 1];

        memset(distances, 0, (n + 1) * sizeof(int));
        memset(visited, 0, (n + 1) * sizeof(int));

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int q;
        cin>>q;
        int pos[q];
        for (int i = 0; i < q; i++)
        {   
            cin>>pos[i];
        }
        sort(pos,pos+q);
        dfs(1, 0, adj);
        int mindis=inf;
        for (int i = 0; i <q; i++)
        {
            mindis = min(distances[pos[i]],mindis);
        }
        int id;
        for (int i = 0; i < q; i++)
        {
            if(distances[pos[i]]==mindis)
              {id = pos[i];
              break;}
        }

        cout<<id<<endl;
    }
    return 0;
}