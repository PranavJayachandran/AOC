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
vector<pair<ll, ll>> moves = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
void part1()
{
    string s;
    vector<string> v(71, string(71, '.'));
    ll counter = 0;
    while (cin >> s)
    {
        stringstream u(s);
        string a, b;
        getline(u, a, ',');
        getline(u, b, ',');
        v[stoi(b)][stoi(a)] = '#';
        counter++;
        if (counter == 1024)
            break;
    }
    forn(i, v.size())
            cout
        << v[i] << "\n";
    priority_queue<vector<ll>> pq;
    vector<vector<ll>> dis(v.size(), vector<ll>(v[0].size(), 1e18));
    dis[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty())
    {
        v64 temp = pq.top();
        pq.pop();
        for (auto p : moves)
        {
            ll x = temp[1] + p.first;
            ll y = temp[2] + p.second;

            if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size() || v[x][y] == '#')
                continue;

            if (dis[x][y] > temp[0] + 1)
            {
                dis[x][y] = temp[0] + 1;
                pq.push({dis[x][y], x, y});
            }
        }
    }
    cout << dis[70][70];
}

void solve()
{
    string s;
    vector<pair<ll, ll>> t;
    while (cin >> s)
    {
        stringstream u(s);
        string a, b;
        getline(u, a, ',');
        getline(u, b, ',');
        t.pb({stol(b), stol(a)});
    }
    ll low = 0, high = t.size() - 1;
    ll ans = 1e9;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        vector<string> v(71, string(71, '.'));
        forn(i, mid + 1)
        {
            v[t[i].first][t[i].second] = '#';
        }

        priority_queue<vector<ll>> pq;
        vector<vector<ll>> dis(v.size(), vector<ll>(v[0].size(), 1e18));
        dis[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            v64 temp = pq.top();
            pq.pop();
            for (auto p : moves)
            {
                ll x = temp[1] + p.first;
                ll y = temp[2] + p.second;

                if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size() || v[x][y] == '#')
                    continue;

                if (dis[x][y] > temp[0] + 1)
                {
                    dis[x][y] = temp[0] + 1;
                    pq.push({dis[x][y], x, y});
                }
            }
        }
        if (dis[70][70] >= 1e18)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<ans<<" "<<t[ans].first<<" "<<t[ans].second<<"\n";
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