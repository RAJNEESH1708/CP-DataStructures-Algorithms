#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int,int> pii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1'000'000'007;
//========================================

void solve() {
  ll a[11];
   fo(i,10) cin>>a[i];
   ll k;
   cin>>k;
   ll ans=0;
   for (size_t i = 10; i >=1; i--)
   {
      if(a[i] and a[i]<=k)
       {
           k = k - a[i];
           a[i]=0;
           
       }       
   }
   for (size_t i = 10; i >= 1; i--)
   {
       if(a[i])
       {
           ans = i;
           break;
       }        
   }

   cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    //deb(t);
    while(t--) {
      solve();
    }
    return 0;
}


