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
string key = "XMAS";

void day1()
{
	v64 dx = {-1,-1,0,1,1,1,0,-1};
	v64 dy = {0, 1,1,1,0,-1,-1,-1};
	vector<string>s;
	string t;
	while(cin>>t){
		s.pb(t);
	}
	ll ans = 0;
	for(int i=0;i<(ll)s.size();i++){
		for(int j=0;j<(ll)s[i].size();j++){
			for(int k=0;k<(ll)dx.size();k++){
				ll x = i;
				ll y = j;
				ll index = 0;
				while(x>=0 && x<(ll)s.size() && y>=0 && y<(ll)s[0].size() && index < (ll)key.size() && s[x][y] == key[index]){
					x += dx[k];
					y += dy[k];
					index++;
				}
				if(index == 4)
					ans++;
			}
		}
	}
	cout<<ans;
}

void solve(){
	vector<string>s;
	string t;
	while(cin>>t){
		s.pb(t);
	}
	ll ans = 0;
	for(ll i = 0; i <(ll)s.size()-2;i++){
		for(ll j = 0; j<(ll)s[0].size();j++){
			bool one = false;
			if((s[i][j] == 'M' && s[i+1][j+1] == 'A' && s[i+2][j+2] == 'S') || (s[i][j] == 'S' && s[i+1][j+1] == 'A' && s[i+2][j+2] == 'M'))
				one = true;
			bool two = false;
			if((s[i+2][j] == 'M' && s[i+1][j+1] == 'A' && s[i][j+2] == 'S') || (s[i+2][j] == 'S' && s[i+1][j+1] == 'A' && s[i][j+2] == 'M'))
				two = true;

			if(one && two)
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