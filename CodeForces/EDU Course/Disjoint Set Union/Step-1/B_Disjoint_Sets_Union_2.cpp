// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI 3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

// *********************** Code Begins ************************ //

class dsu
{
public:
    vector<int> parent, size, rank ,mn,mx;

    explicit dsu(int a)
    {
        parent.resize(a);
        size.resize(a);
        rank.resize(a);
        mn.resize(a);
        mx.resize(a);
        for (int i = 0; i < a; i++)
        {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
            mn[i] = i;
            mx[i] = i;
        }
    }

    int get(int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = get(parent[i]);
    }

    bool unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a != b)
        {
            if (rank[a] > rank[b])
                swap(a, b);
            parent[a] = b;
            size[b] += size[a];
            size[a] = 0;
            mn[b] = min(mn[b], mn[a]);
            mx[b] = max(mx[b],mx[a]);
            if (rank[a] == rank[b])
                rank[b]++;
            return true;
        }
        return false;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    dsu DSU(n+1);
    // cout << DSU.get(1) << " ";
    for(int i=0;i<q;i++)
    {
        string quer;
        cin >> quer;
     
        if (quer == "union")
        {
            int a, b;
            cin >> a >> b;
            DSU.unite(a, b);
        }
        else
        {
            int a;
            cin >> a;
            int par = DSU.get(a);
            cout << DSU.mn[par] << " " << DSU.mx[par]<< " " << DSU.size[par]<<endl;
        }
    }
    
}

signed main()
{
    FastIO;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        // cout<<"Case #"<< i <<": ";
        solve();
    }
}