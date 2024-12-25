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
void solve()
{
	string s;
	vector<vector<string>>op;
	unordered_map<string,ll>val;
	bool temp = false;
	while(getline(cin,s)){
		if(s == ""){
			temp = true;
			continue;
		}
		if(temp){
			stringstream a(s);
			string p;
			vector<string> l;
			while(a>>p){
				if(p != "->")
					l.pb(p);
			}
			op.pb(l);
		}
		else{
			string temp = "";
			for(auto p:s){
				if(p == ':')
					break;
				temp += p;
			}
			val[temp] = s.back()-'0';
		}
	}
	while(op.size()){
		vector<vector<string>>temp;
		for(auto p:op){
			if(val.find(p[0]) == val.end() || val.find(p[2]) == val.end()){
				temp.pb(p);
				continue;
			}

			bool u = 0;
			if(p[1] == "AND")
				u = val[p[0]] & val[p[2]];
			else if(p[1] == "OR")
				u = val[p[0]] | val[p[2]];
			else 
				u = val[p[0]] ^ val[p[2]];
			val[p[3]] = u;
		}
		op = temp;
	}
	vector<pair<string,ll>>o;
	for(auto p:val){
		if(p.first[0] == 'z')
			o.pb(p);
	}
	ll ans = 0;
	sort(all(o));
	reverse(all(o));
	for(auto p:o){
		ans = ans*2 + p.second;
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