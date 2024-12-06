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


vector<pair<ll,ll>>moves = {{-1,0},{0,1},{1,0},{0,-1}};
void part1()
{
	vector<string>s;
	string t;
	while(cin>>t){
		s.push_back(t);
	}
	ll i = 0, j = 0;
	for(int x=0;x<(ll)s.size();x++){
		for(int y = 0;y<(ll)s[x].size();y++){
			if(s[x][y] == '^'){
				i = x;
				j = y;
			}
		}
	}
		ll ans = 0;
		ll moveIndex = 0;
		while( i >=0 && i <(ll)s.size() && j<(ll)s[i].size() && j >= 0){
			s[i][j] = 'X';
			ll x = i + moves[moveIndex].first;
			ll y = j + moves[moveIndex].second;
			if(x >=0 && x<(ll)s.size() && y>=0 && y<s[x].size() && s[x][y] == '#'){
				moveIndex = (moveIndex + 1)%moves.size();
				continue;
			}
			i = i + moves[moveIndex].first;
			j = j + moves[moveIndex].second;
		}
		forn(i,(ll)s.size()){
			cout<<s[i]<<"\n";
			forn(j,(ll)s[i].size()){
				if(s[i][j] == 'X')
					ans++;
			}
		}
		cout<<ans<<"\n";
}

//part 2
ll f(ll i,ll j, ll moveIndex, vector<string>&s,vector<vector<vector<ll>>>&dp){
	if(i < 0 || i >= s.size() || j < 0 || j >= s[i].size()){
		return 0;
	}
	if(dp[i][j][moveIndex] == 1){
		return 1;
	}
	dp[i][j][moveIndex] = 1;

	ll x = i + moves[moveIndex].first;
	ll y = j + moves[moveIndex].second;
	if(x >=0 && x<(ll)s.size() && y>=0 && y<s[x].size() && s[x][y] == '#'){
		moveIndex = (moveIndex + 1)%moves.size();
	}
	else{
		i = x;
		j = y;
	}
	return f(i,j,moveIndex,s,dp);
}

void solve()
{
	vector<string>s;
	string t;
	while(cin>>t){
		s.push_back(t);
	}
	ll i = 0, j = 0;
	for(int x=0;x<(ll)s.size();x++){
		for(int y = 0;y<(ll)s[x].size();y++){
			if(s[x][y] == '^'){
				i = x;
				j = y;
			}
		}
	}
	vector<vector<ll>>v;
		ll ans = 0;
		ll moveIndex = 0;
		for(int x=0;x<s.size();x++){
			for(int y =0;y<s[0].size();y++){
				if(s[x][y] != '^' && s[x][y] != '#'){
					s[x][y] = '#';
					vector<vector<vector<ll>>>dp(s.size(),vector<vector<ll>>(s[0].size(),vector<ll>(moves.size(),-1)));
					ans += f(i,j,0,s,dp);
					s[x][y] = '.';
				}
			}
		}
		cout<<ans<<"\n";
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