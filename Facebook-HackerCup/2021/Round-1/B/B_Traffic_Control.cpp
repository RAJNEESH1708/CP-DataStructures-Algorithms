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
#define removeDuplicate(x)   sort(all(x)); x.erase(unique(all(x)),x.end())   //remove Duplicate
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
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
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

void solve()
{  
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>> mat(n,vector<int>(m,1000));
    int mid = (m+n-3)+1;
    int r=0,c=0,cnt = 1,sum1=0,sum2=0,sum3=0;
    while(r<n-1){
        r++;
        mat[r][c] = cnt;
        sum1 += mat[r][c];
    }
    r = n-1;
    while(c<m-1){
        c++;
        mat[r][c] = cnt;
        sum2 += mat[r][c];
    }
    r = 0, c = m-1, cnt = 1;
    while (r < n - 1)
    {
        r++;
        mat[r][c] = cnt;
        sum3 += mat[r][c];
    }
    //deb3(sum1,sum2,sum3);
    a = a - (sum1+sum2);
    b = b - (sum3+sum2);
    if(a<1 or b<1){
        cout << "Impossible"<<endl;
        return;
    }
    int tl = a;
    int tr = b;
    mat[0][0] = tl;
    mat[0][m-1] = tr;
    cout << "Possible" << endl;
    forn(i, n)
    {
        forn(j, m)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}

signed main()
{

    freopen("traffic_control_input.txt", "r", stdin);
    freopen("B_op.txt", "w", stdout);

    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
          cout<<"Case #"<< i <<": "; 
         solve();
        }        
}