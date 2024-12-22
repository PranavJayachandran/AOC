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
ll f(ll n){
	ll m = n*64;
	n = (m ^ n)%16777216;
	n = ((n/32) ^ n)%16777216;
	n = ((n*2048) ^ n)%16777216;
	return n; 

}
void solve()
{
	ll n;
	ll ans = 0;
	vector<vector<ll>>order, val;
	while(cin>>n){
		vector<ll>p;
		vector<ll>q;
		ll last = n%10;
		forn(i,2000){
			n = f(n);
			p.pb(n%10 - last);
			q.pb(n%10);
			last = n%10;
		}
		ans += n;
		order.pb(p);
		val.pb(q);
	}
	unordered_map<string,ll>m[order.size()];
	unordered_map<string,ll>v;
	string temp = "";
	ll ans2 = 0;
	for(int i=0;i<order.size();i++){
		for(int j=0;j<order[i].size()-3;j++){
			temp = "";
			for(int k=0;k<4;k++){
				temp += to_string(order[i][j+k]);
			}
			if(m[i].find(temp) == m[i].end()){
				m[i][temp] = val[i][j+3];
				v[temp] += val[i][j+3];
				ans2 = max(ans2,v[temp]);
			}
		}
	}
	cout<<ans2<<" "<<ans;
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