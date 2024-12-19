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
bool isMatch(string a, string b){
	ll i =0, j =0;
	while(i < a.size() && j<b.size() && a[i] == b[j]){
		i++;
		j++;
	}
	return j == b.size();
}
ll dfs(vector<string>&v,string s,unordered_map<string,ll>&m){
	if(s.size() == 0)
		return 1;
	ll ans = 0;
	if(m.find(s) != m.end())
		return m[s];
	for(auto p:v){
		if(isMatch(s,p)){
			ans = ans + dfs(v,s.substr(p.size()),m);
		}
	}
	return m[s] = ans;
}
void solve()
{
	string s;
	getline(cin,s);
	vector<string>v;
	string temp ="";
	for(auto p:s){
		if(p == ','){
			v.pb(temp);
			temp = "";
			continue;
		}
		else if(p == ' ')
			continue;
		temp += p;
	}
	v.pb(temp);
	ll ans = 0;
	ll ans2 = 0;
	unordered_map<string,ll>m;
	while(cin>>s){
		if(dfs(v,s,m)){
			ans2 += dfs(v,s,m);
			ans++;
		}
	}
	cout<<ans2;
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