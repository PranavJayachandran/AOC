#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

// part1
v64 dx = {-1, 0, 1, 0};
v64 dy = {0, 1, 0, -1};
ll f1(ll i, ll j, vector<string> &s, vector<vector<ll>> &vis, ll val)
{
    if (i >= s.size() || j >= s[0].size() || i < 0 || j < 0 || s[i][j] == '.')
        return 0;
    if (s[i][j] != (val + '0'))
        return 0;
    if (s[i][j] == '9')
    {
        vis[i][j] = 1;
        return 1;
    }
    val += 1;
    ll ans = 0;
    forn(k, dx.size())
    {
        ans += f1(dx[k] + i, dy[k] + j, s, vis, val);
    }
    return ans;
}
void part1()
{
    vector<string> s;
    string temp;
    while (cin >> temp)
        s.pb(temp);
    ll ans = 0;
    forn(i, s.size())
    {
        forn(j, s[i].size())
        {
            if (s[i][j] == '0')
            {
                vector<vector<ll>> vis(s.size(), vector<ll>(s[0].size(), -1));

                f1(i, j, s, vis, 0);
                forn(i, vis.size())
                {
                    forn(j, vis[0].size())
                    {
                        if (vis[i][j] == 1)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}

// part2
ll f(ll i, ll j, vector<string> &s, vector<vector<ll>> &vis, ll val)
{
    if (i >= s.size() || j >= s[0].size() || i < 0 || j < 0 || s[i][j] == '.')
        return 0;
    if (s[i][j] != (val + '0'))
        return 0;
    if (s[i][j] == '9')
    {
        return 1;
    }
    val += 1;
    ll ans = 0;
    forn(k, dx.size())
    {
        ans += f(dx[k] + i, dy[k] + j, s, vis, val);
    }
    return ans;
}
void solve()
{
    vector<string> s;
    string temp;
    while (cin >> temp)
        s.pb(temp);
    ll ans = 0;
    vector<vector<ll>> vis(s.size(), vector<ll>(s[0].size(), -1));
    forn(i, s.size())
    {
        forn(j, s[i].size())
        {
            if (s[i][j] == '0')
            {
                ans += f(i, j, s, vis, 0);
            }
        }
    }

    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;

    while (t--)
    {
        solve();
    }
}