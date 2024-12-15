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
void f(ll &x,ll &y,vector<string>&grid, pair<ll,ll>p){
	ll a = x, b = y;
	bool canMove = false;
	while(1){
		a += p.first;
		b += p.second;
		if(a>=grid.size() || b>=grid[0].size() && a<0 || b<0 || grid[a][b] =='#'){
			canMove = false;
			break;
		}
		if(grid[a][b] == '.'){
			canMove = true;
			break;
		}
	}
	if(!canMove)
		return;
	while( a!= x || b != y){
		grid[a][b] = grid[a-p.first][b-p.second];
		a -= p.first;
		b -= p.second;
	}
	grid[x+p.first][y+p.second] = '@';
	grid[x][y] = '.';
	x += p.first;
	y += p.second;
}
void part1()
{
	string temp;
	vector<string>grid;
	string step = "";
	ll x = 0, y= 0;
	bool istep = false;
	while(getline(cin,temp)){
		if(temp == ""){
			istep = true;
			continue;
		}
		if(istep){
			step+=temp;
		}
		else{
			grid.pb(temp);
		}
	}
	forn(i,grid.size()){
		forn(j,grid[0].size()){
			if(grid[i][j] == '@'){
				x = i;
				y = j;
			}
		}
	}
	for(auto p : step){
		if(p == '<'){
			f(x,y,grid,{0,-1});
		}
		else if(p == '^'){
			f(x,y,grid,{-1,0});
		}
		else if(p == '>'){
			f(x,y,grid,{0,1});
		}
		else{
			f(x,y,grid,{1,0});
		}
		// forn(i,grid.size()){
		// 	forn(j,grid[0].size())
		// 		cout<<grid[i][j];
		// 	cout<<"\n";
		// }
	}
	ll ans = 0;
	forn(i,grid.size()){
		forn(j,grid[0].size()){
			if(grid[i][j] == 'O'){
				ans += i*100 + j;
			}
		}
	}
	cout<<ans;
}


void f2(ll &x,ll &y,vector<string>&grid, pair<ll,ll>p){
	ll a = x, b = y;
	bool canMove = false;
	while(1){
		a += p.first;
		b += p.second;
		if(a>=grid.size() || b>=grid[0].size() && a<0 || b<0 || grid[a][b] =='#'){
			canMove = false;
			break;
		}
		if(grid[a][b] == '.'){
			canMove = true;
			break;
		}
	}
	if(!canMove)
		return;
	while( a!= x || b != y){
		grid[a][b] = grid[a-p.first][b-p.second];
		a -= p.first;
		b -= p.second;
	}
	grid[x+p.first][y+p.second] = '@';
	grid[x][y] = '.';
	x += p.first;
	y += p.second;
}


//Part2
ll counter = 0;

bool bfs(vector<string>&grid, pair<ll,ll>p, vector<pair<ll,ll>>v){
	vector<pair<ll,ll>>temp;
	set<pair<ll,ll>>s;
	forn(i,v.size()){
		ll a = v[i].first + p.first;
		ll b = v[i].second + p.second;
		if(a>=grid.size() || b>=grid[0].size() && a<0 || b<0 || grid[a][b] =='#')
			return false;

		if(grid[a][b] == '['){
			s.insert({a,b});
			s.insert({a,b+1});
		}
		else if(grid[a][b] == ']'){
			s.insert({a,b});
			s.insert({a,b-1});
		}
	}
	for(auto p:s){
		temp.pb({p});
	}
	if(temp.size() == 0){
		forn(i,v.size()){
			ll a = v[i].first + p.first;
			ll b = v[i].second + p.second;
			grid[a][b] = grid[v[i].first][v[i].second];
			grid[v[i].first][v[i].second]='.';

		}
		return true;
	}
	bool isPossible = bfs(grid,p,temp);
	if(isPossible){
		forn(i,v.size()){
			ll a = v[i].first + p.first;
			ll b = v[i].second + p.second;
			grid[a][b] = grid[v[i].first][v[i].second];
			grid[v[i].first][v[i].second]='.';

		}
	}
	return isPossible;
}


void f3(ll &x, ll &y, vector<string>&grid, pair<ll,ll>p){
	vector<pair<ll,ll>>v;
	v.pb({x,y});
	bool o = bfs(grid,p,v);
	if(o){
		grid[x][y] = '.';
		grid[x+p.first][y+p.second] = '@';
		x += p.first;
		y+= p.second;
	}
}

void solve()
{
	string temp;
	vector<string>grid;
	string step = "";
	ll x = 0, y= 0;
	bool istep = false;
	while(getline(cin,temp)){
		if(temp == ""){
			istep = true;
			continue;
		}
		if(istep){
			step+=temp;
		}
		else{
			string p = "";
			for(auto l:temp){
				if(l == '#')
					p+="##";
				if( l == '.')
					p+="..";
				if( l == 'O')
					p+="[]";
				if(l == '@')
					p+="@.";
			}
			grid.pb(p);
		}
	}
	forn(i,grid.size()){
		forn(j,grid[0].size()){
			if(grid[i][j] == '@'){
				x = i;
				y = j;
			}
		}
	}
	for(auto p : step){
		if(p == '<'){
			f2(x,y,grid,{0,-1});
		}
		else if(p == '^'){
			f3(x,y,grid,{-1,0});
		}
		else if(p == '>'){
			f2(x,y,grid,{0,1});
		}
		else{
			f3(x,y,grid,{1,0});
		}
	}
	ll ans = 0;
	forn(i,grid.size()){
		forn(j,grid[0].size()){
			if(grid[i][j] == '['){
				ans += i*100 + j;
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