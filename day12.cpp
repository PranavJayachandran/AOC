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
v64 dx = {-1,0,1,0};
v64 dy = {0,1,0,-1};

vector<vector<ll>>y;

int f(int i,int j,vector<vector<ll>>&vis,vector<string>t,char ch, ll &o){
	if(i < 0 || j < 0 || i>= t.size() || j >= t[0].size() || t[i][j] != ch)
		return 1;
	vis[i][j] = 1;
	y[i][j] = 1;
	o++;
	int ans = 0;
	for(int k = 0;k<4;k++){
		ll x = dx[k] + i;
		ll y = dy[k] + j;
		if(x < 0 || y < 0 || x >= t.size() || y >= t[0].size()){
			ans += f(x,y,vis,t,ch,o);
			continue;
		}
		if(vis[i+dx[k]][j+dy[k]] == 0 || t[x][y] != ch)
		ans += f(i+dx[k],j+dy[k],vis,t,ch,o);
	}
	return ans;
}
void solve()
{
	vector<string>t;
	string s;
	while(cin>>s){
		t.pb(s);
	}

	ll ans = 0;
	vector<vector<ll>>vis(t.size(),vector<ll>(t[0].size(),0));
	forn(i,t.size()){
		forn(j,t[i].size()){
			if(vis[i][j] != 1){
				ll o = 0;
				y.clear();
				y.resize(t.size(),vector<ll>(t[0].size(),0));
				f(i,j,vis,t,t[i][j],o);	
				ll peri = 0;
				unordered_set<ll>u;
				forn(i,y.size()){
					unordered_set<ll>g;
					if(y[i][0] == 1){
						if(i == 0 || ( i>  0 && y[i-1][0] != 1))
							peri++;
						g.insert(-1);
					}
					forn(j,y[0].size()-1){
						if(y[i][j] != y[i][j+1]){
							if(i == 0 || ( i >  0 && y[i-1][j] != y[i][j]) || (i>0 && y[i-1][j+1]  != y[i][j+1])){
								peri++;
							}
						}
					}
					if(y[i][y[i].size()-1] == 1){
						if(i == 0 || ( i>  0 && y[i-1][y[i].size()-1] != 1))
							peri ++; 
					}
					u = g;
				}
				u.clear();
				forn(j,y[0].size()){
					unordered_set<ll>g;

					if(y[0][j] == 1){ 
						if(j == 0 || (j>0 && y[0][j-1]) != 1)
							peri++;
					}
					forn(i,y.size()-1){
						if(y[i][j] != y[i+1][j]){
							if(j == 0 || (j>0 && y[i][j-1]) != y[i][j] || ( j > 0 && y[i+1][j-1] != y[i+1][j]))
								peri++;
						}
					}
					if(y[y.size()-1][j] == 1){
						if(j == 0 || (j>0 && y[y.size()-1][j-1]) != 1)
							peri++;
					}
					u = g;
				}
				ans += peri * o;
			}
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