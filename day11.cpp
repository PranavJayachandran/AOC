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
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void part1()
{
	vector<ll>v;
	ll p;
	while(cin>>p)
		v.pb(p);

	forn(i,25){
		vector<ll>a;
		forn(j,v.size()){
			ll num = log10(v[j]);
			if(v[j] == 0){
				a.pb(1);
			}
			else if(num %2 != 0){
				num = num /2+1;
				ll u = pow(10,num);
				ll o = v[j]/u;
				ll k = v[j]%u;
				a.pb(o);
				a.pb(k);
			}
			else{
				a.pb(v[j]*2024);
			}
		}
		v = a;	
	}
	cout<<v.size();
}

ll f(ll val, ll times, map<pair<ll,ll>,ll> &m){
	if(times == 0)
		return 1;
	if(m.find({val,times})!=m.end())
		return m[{val,times}];
	ll num = log10(val);
	if(val == 0)
		return m[{val,times}] = f(val+1,times-1,m);
	else if(num % 2 != 0){
		num = num/2 + 1;
		ll u = pow(10,num);
		return m[{val,times}] = f(val/u,times-1,m) + f(val%u, times-1,m);
	}
	else
		return m[{val,times}] = f(val*2024,times-1,m);
}
void solve()
{
	vector<ll>v;
	ll p;
	while(cin>>p)
		v.pb(p);

	ll ans = 0;
	map<pair<ll,ll>,ll>m;
	forn(i,v.size()){
		ans += f(v[i],75,m);
	}
	cout<<ans;
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