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

// *************************** Code Begins **************************** //

pair<pii,pii> mnf(pii a,pii b,pii c,pii d)
 {
      vector<pii> st;
      st.pb(a);
      st.pb(b);
      st.pb(c);
      st.pb(d);
      sort(all(st));
    return mp(*st.begin(),*(st.end()-1));  
 }


void solve()
{
    vector<int> v[4];
    forn(i,4)
     {
         int n;
         cin>>n;
         v[i].resize(n);
         forn(j,n)
             cin>>v[i][j];
     }
     forn(i,4)
        sort(all(v[i]));
     int a = 0, b = 0, c = 0, d = 0;
     while(1)
      {
          
          pii w = mp(v[0][a], a), x = mp(v[1][b], b), y = mp(v[2][c], c), z = mp(v[3][d], d);
          pair<pii,pii> vals = mnf(w, x, y, z);

          pii mn = vals.ff;
          pii mx = vals.ss;
        //   deb2(mn.ff,mx.ff);

          if(mn.ff==mx.ff)
             break;  
                     
           if (mn.ff == w.ff)
              a++;
           if (mn.ff == x.ff)
               b++;
           if (mn.ff == y.ff)
              c++;
           if (mn.ff == z.ff)
              d++;

        bool ok = 0;
          if (a == v[0].size())
             { a--; ok=1;}
  
          if (b == v[1].size())
             { b--; ok=1;}
       
          if (c == v[2].size())
             {c--; ok=1;}
          if (d == v[3].size())
             {d--; ok=1;}

        if(ok) break;

          //   deb2(a, b);
          //   deb2(c, d);
      }

    cout<<v[0][a]<<" "<<v[1][b]<<" "<<v[2][c]<<" "<<v[3][d]<<endl;
}

signed main()
{
    FastIO;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}