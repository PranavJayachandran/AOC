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

bool f(vector<string>&n, string c, unordered_set<string>&u){
	for(auto p: n){
		if(u.find(p + "-" + c) == u.end() && u.find(c + "-" + p) == u.end())
			return false;
	}
	return true;
}

void solve()
{
	string s;
	unordered_set<string>comp,u;
	while(cin>>s){
		string a = s.substr(0,2), b = s.substr(3);
		comp.insert({a,b});
		u.insert(s);

	}

	vector<vector<string>>net;
	for(auto p:comp){
		net.pb({p});
	};
	for(int i=0;i<net.size();i++){
		for(auto c:comp){
			if(f(net[i],c,u)){
				net[i].pb(c);
			}
		}
	}
	string ans = "";
	for(auto p:net){
		vector<string>temp = p;
		if(p.size() * 3 > ans.size()){
			sort(all(temp));
			ans = "";
			for(auto l:temp){
				ans+=l+",";
			}
		}
	}
	cout<<ans.substr(0,ans.size()-1);
}


void part1()
{
	string s;
	unordered_set<string>t;
	unordered_set<string>u;
	while(cin>>s){
		t.insert(s);
		u.insert({s.substr(0,2), s.substr(3)});
	}
	ll ans = 0;
	for(auto a:u){
		for(auto b:u){
			for(auto c:u){
				if(a[0] != 't' && b[0] != 't' && c[0] != 't')
					continue;
				if(t.find(a + "-" + b) != t.end() || t.find(b + "-" + a) != t.end()){
					if(t.find(c + "-" + b) != t.end() || t.find(b + "-" + c) != t.end()){
						if(t.find(a + "-" + c) != t.end() || t.find(c + "-" + a) != t.end()){
							ans++;
						}	
					}
				}
			}
		}
	}
	cout<<ans/6;
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