#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx             priority_queue<int> // maxheap
#define pqmn             priority_queue<int,vector<int>,greater<int> > // minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
       int c;
       cin>>c;
       //2^d==d
       int temp=c;
       c |= c >> 1;
       c |= c >> 2;
       c |= c >> 4;
       c |= c >> 8;
       c |= c >> 16;
       c++;
       int d=c;
       c = temp;
       
       int mask = (d-1)/2;

       int mx = (mask)*(c^mask);
       cout<<mx<<endl;
       
    }
    return 0;
}