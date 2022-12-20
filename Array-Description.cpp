/*Chandraveer Singh*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
/*-----------------------MACROS-----------------------------------*/
 
#define fastio()         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD              1000000007
#define MOD1             998244353
#define INF              1e18
#define endl             "\n"
#define sz(x)            (int)x.size()
#define pb               push_back
#define ppb              pop_back
#define mp               make_pair
#define ff               first
#define ss               second
#define pi               3.141592653589793238462
#define all(x)           (x).begin(), (x).end()
#define setbits          __builtin_popcount
#define setbitsll        __builtin_popcountll
 
/*-----------------------Debugging--------------------------------*/
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
/*--------------------------Algorithms----------------------------*/
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void google(int t) {cout << "Case #" << t << ": ";}
 
/*--------------------------Code begins---------------------------*/
 
//Problem Link: https://cses.fi/problemset/task/1746
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<vector<ll>> dp(n, vector<ll>(m + 1));
    if (arr[0] != 0)
        dp[0][arr[0]] = 1;
    else {
        for (int i = 1; i <= m; ++i)
            dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                if (j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
 
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
 
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]);
            }
        }
        else {
            if (arr[i] - 1 >= 1)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;
 
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % MOD;
 
            if (arr[i] + 1 <= m)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
