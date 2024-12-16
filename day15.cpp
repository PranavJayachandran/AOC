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
vector<pair<ll,ll>>dx = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
void part1()
{
	string temp;
	vector<string>s;
	while(cin>>temp){
		s.pb(temp);
	}
	ll x,y;
	forn(i,s.size()){
		forn(j,s[0].size()){
			if(s[i][j] == 'S'){
				x = i;
				y = j;
			}
		}
	}

	ll ans = 0;
	vector<vector<vector<ll>>>vis(s.size(),vector<vector<ll>>(s[0].size(),vector<ll>(4,1e9)));
	priority_queue<pair<ll,vector<ll>>, vector<pair<ll,vector<ll>>>, greater<pair<ll,vector<ll>>>>pq;
	pq.push({0,{x,y,0}});
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();

		if(s[p.second[0]][p.second[1]] == 'E'){
			cout<<p.first<<" ";
			break;
		}

		if(vis[p.second[0]][p.second[1]][(p.second[2]+1)%4] > p.first + 1000){
			vis[p.second[0]][p.second[1]][(p.second[2]+1)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+1)%4}});
		}

		if(vis[p.second[0]][p.second[1]][(p.second[2]+3)%4] > p.first + 1000){
			vis[p.second[0]][p.second[1]][(p.second[2]+3)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+3)%4}});
		}
		ll nx = p.second[0] + dx[p.second[2]].first;
		ll ny = p.second[1] + dx[p.second[2]].second;

		if(nx < 0 || ny < 0 || nx >= s.size() || ny >= s[0].size() || s[nx][ny] == '#')
			continue;

		if(vis[nx][ny][p.second[2]] > p.first  + 1 ){
			vis[nx][ny][p.second[2]] = p.first + 1; 
			pq.push({p.first + 1, {nx,ny,p.second[2]}});
		}
	}



}

void solve()
{
	string temp;
	vector<string>s;
	while(cin>>temp){
		s.pb(temp);
	}
	ll x,y;
	forn(i,s.size()){
		forn(j,s[0].size()){
			if(s[i][j] == 'S'){
				x = i;
				y = j;
			}
		}
	}

	vector<vector<vector<ll>>>vis1(s.size(),vector<vector<ll>>(s[0].size(),vector<ll>(4,1e9)));
	priority_queue<pair<ll,vector<ll>>, vector<pair<ll,vector<ll>>>, greater<pair<ll,vector<ll>>>>pq;
	pq.push({0,{x,y,0}});
	vis1[x][y][0] = 0;
	ll ex,ey;
	ll ans = 1e9;
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();

		if(s[p.second[0]][p.second[1]] == 'E'){
			ans = p.first;
			ex = p.second[0];
			ey = p.second[1];
			break;
		}

		if(vis1[p.second[0]][p.second[1]][(p.second[2]+1)%4] > p.first + 1000){
			vis1[p.second[0]][p.second[1]][(p.second[2]+1)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+1)%4}});
		}

		if(vis1[p.second[0]][p.second[1]][(p.second[2]+3)%4] > p.first + 1000){
			vis1[p.second[0]][p.second[1]][(p.second[2]+3)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+3)%4}});
		}
		ll nx = p.second[0] + dx[p.second[2]].first;
		ll ny = p.second[1] + dx[p.second[2]].second;

		if(nx < 0 || ny < 0 || nx >= s.size() || ny >= s[0].size() || s[nx][ny] == '#')
			continue;

		if(vis1[nx][ny][p.second[2]] > p.first  + 1 ){
			vis1[nx][ny][p.second[2]] = p.first + 1; 
			pq.push({p.first + 1, {nx,ny,p.second[2]}});
		}
	}
	vector<vector<vector<ll>>>vis2(s.size(),vector<vector<ll>>(s[0].size(),vector<ll>(4,1e9)));
	vis2[ex][ey][0]=0;
	vis2[ex][ey][1]=0;
	vis2[ex][ey][2]=0;
	vis2[ex][ey][3]=0;

	pq.push({0,{ex,ey,0}});
	pq.push({0,{ex,ey,1}});
	pq.push({0,{ex,ey,2}});
	pq.push({0,{ex,ey,3}});
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();

		if(s[p.second[0]][p.second[1]] == 'S'){
			continue;
		}

		if(vis2[p.second[0]][p.second[1]][(p.second[2]+1)%4] > p.first + 1000){
			vis2[p.second[0]][p.second[1]][(p.second[2]+1)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+1)%4}});
		}

		if(vis2[p.second[0]][p.second[1]][(p.second[2]+3)%4] > p.first + 1000){
			vis2[p.second[0]][p.second[1]][(p.second[2]+3)%4] = p.first + 1000;
			pq.push({p.first+1000,{p.second[0],p.second[1],(p.second[2]+3)%4}});
		}
		ll nx = p.second[0] + dx[(p.second[2]+2)%4].first;
		ll ny = p.second[1] + dx[(p.second[2]+2)%4].second;

		if(nx < 0 || ny < 0 || nx >= s.size() || ny >= s[0].size() || s[nx][ny] == '#')
			continue;

		if(vis2[nx][ny][p.second[2]] > p.first  + 1 ){
			vis2[nx][ny][p.second[2]] = p.first + 1; 
			pq.push({p.first + 1, {nx,ny,p.second[2]}});
		}
	}

	ll count = 0;
	forn(i,s.size()){
		forn(j,s[0].size()){
			forn(k,4){
				if(vis1[i][j][k] + vis2[i][j][k] == ans){
					s[i][j] = 'O';
				}
			}
		}
	}

	forn(i,s.size()){
		forn(j,s[i].size()){
			if(s[i][j] == 'O')
				count++;
		}
	}
	cout<<count;



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