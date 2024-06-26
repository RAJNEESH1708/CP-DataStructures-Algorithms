#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define sz(v) (ll)(v.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vec) \
    sort(all(vec));      \
    vec.resize(unique(all(vec)) - vec.begin());                              // remove Duplicate
#define generate_random(vec) generate(all(vec), rand);                       // fill vec with ramdom nums
#define rotate_by_k(vec, k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a));                                 // Create a set from a vector
#define is_present(vec, key) binary_search(all(vec), key);                   // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<32>(n);                                         // binary representation of a number
#define min4(a, b, c, d) min({a, b, c, d});                                  // min of four elements
#define min3(a, b, c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)   // zeros before first setbit
#define mod 1000000007                     // 1e9+7
#define mod1 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg1 cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define ump unordered_map<int, int>

typedef tuple<int, int, int> tuplei;

// assign and update min and max values.
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

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
inline ll power(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res *= a;
        a *= a, n /= 2;
    }
    return res;
}
inline void printArr(vector<int> v)
{
    for (auto val : v)
        cout << val << ' ';
    cout << endl;
}

// ********************************* Code Begins ********************************** //
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool possibility(vector<vector<char>> &paint, int &n, int &m)
{
    forn(i, n)
    {
        forn(j, m)
        {
            int count = 0;
            forn(k, 4)
            {
                if (i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < m and paint[i+dx[k]][j+dy[k]]!='#')
                {
                    count++;
                }
            }
            if (count < 2)
            {
                return 0;
            }
        }
    }
    return 1;
}
bool isvalidmove(int x, int y, int n, int m, vector<vector<char>> &paint){
    if(x>=0 and x<n and y>=0 and y<m and paint[x][y]!='#') return 1;
    return 0;
}
bool check(int x, int y, int n, int m, vector<vector<char>> &paint){
    if(x>=0 and x<n and y>=0 and y<m and paint[x][y]=='^') return 1;
    return 0;
}
void solve()
{

        /* this is wrong submission */
    int n, m, tree = 0,rock=0;
    cin >> n >> m;
    vector<vector<char>> paint(n, vector<char>(m));
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> paint[i][j];
            if (paint[i][j] == '^')
                tree++;
            else if (paint[i][j] == '#')
                rock++;
        }
    }
    if (tree == 0)
    {
        cout << "Possible" << endl;
        forn(i, n)
        {
            forn(j, m)
            {
                cout << paint[i][j];
            }
            cout << endl;
        }
        return;
    }

//    forn(i, n)
//    {
//        forn(j, m)
//        {
//            if (paint[i][j] == '.')
//            {
//                paint[i][j] = '^';
//            }
//        }
//    }

    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++){
            if(paint[i][j]!='#'){
                int ok=0;
                for(int k=0;k<4;k++){
                    if(isvalidmove(i+dx[k],j+dy[k],n,m,paint)){
                        ok++;
                    }
                }
                if(ok>=2){
                    paint[i][j] = '^';
                }
            }
        }
    }
    bool poss = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (paint[i][j] == '^')
            {
                int ok = 0;
                for (int k = 0; k < 4; k++)
                {
                    if (check(i + dx[k], j + dy[k], n, m, paint))
                    {
                        ok++;
                    }
                }
                if (ok<2) {
                    //deb2(i,j);
                    poss=0;
                    goto pr;
                }
            }
        }
    }
    pr:
    if (poss)
    {
        cout << "Possible" << endl;
        forn(i, n)
        {
            forn(j, m)
            {
                cout << paint[i][j];
            }
            cout << endl;
        }
    }
    else
        cout << "Impossible" << endl;
}

signed main()
{
    freopen("second_second_friend_input.txt", "r", stdin);
    freopen("second_second_friend_output.txt", "w", stdout);
    FastIO;
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        cout << "Case #" << test_case << ": ";
        solve();
    }
}