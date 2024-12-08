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
	string temp;
	vector<string>s;
	unordered_map<char,vector<pair<ll,ll>>>m;
	while(cin>>temp){
		s.pb(temp);
	}
	forn(i,s.size()){
		forn(j,s[i].size()){
			if(s[i][j] != '.')
				m[s[i][j]].pb({i,j});
		}
	}
	for(auto p:m){
		for(int i=0;i<p.second.size();i++){
			for(int j = 0;j<p.second.size();j++){
				if(i==j)
					continue;

				ll x = p.second[j].first - p.second[i].first;
				ll y = p.second[j].second - p.second[i].second;

				x = p.second[i].first - x;
				y = p.second[i].second - y;
				if(x >= 0 && y >= 0 && x < s.size() && y < s[0].size()){
					s[x][y] = '#';
				}

			}
		}
	}
	ll ans = 0;
	forn(i,s.size()){
		forn(j,s[0].size()){
			if(s[i][j] == '#')
				ans++;
		}
	}
	cout<<ans;
}

void solve()
{
	string temp;
	vector<string>s;
	unordered_map<char,vector<pair<ll,ll>>>m;
	while(cin>>temp){
		s.pb(temp);
	}
	forn(i,s.size()){
		forn(j,s[i].size()){
			if(s[i][j] != '.')
				m[s[i][j]].pb({i,j});
		}
	}
	for(auto p:m){
		for(int i=0;i<p.second.size();i++){
			for(int j = 0;j<p.second.size();j++){
				if(i==j)
					continue;

				ll tx = p.second[j].first - p.second[i].first;
				ll ty = p.second[j].second - p.second[i].second;

				ll x = p.second[i].first - tx;
				ll y = p.second[i].second - ty;

				ll timer = 0;
				while(timer < 50 && x >= 0 && y >= 0 && x < s.size() && y < s[0].size()){
					s[x][y] = '#';
					timer ++;
					x = x - tx;
					y = y - ty;
				}

			}
		}
	}
	ll ans = 0;
	forn(i,s.size()){
		forn(j,s[0].size()){
			if(s[i][j] != '.')
				ans++;
		}
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