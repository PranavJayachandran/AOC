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
void f(string s,int index,ll &a, ll &b){
	ll i = index;
	for(;i<s.size();i++){
			if(s[i]==',')
				break;
			a = a*(10) + (s[i]-'0');
		}
	i+= 4;
	for(;i<s.size();i++){
		b = b*10 + (s[i]-'0');
	}
}
void part1()
{
	string a,b,c;
	ll ans = 0;
	while(getline(cin,a)){
		getline(cin,b);
		getline(cin,c);
		ll ax=0, bx=0,ay=0,by=0;
		ll x=0,y=0;
		f(a,12,ax,ay);
		f(b,12,bx,by);
		f(c,9,x,y);
		ll o = 1e9;
		for(ll i =0;;i++){
			ll tx = x-ax*i;
			ll ty = y-ay*i;
			if(tx <0 || ty<0)
				break;
			if(tx%bx == 0 && ty%by ==0 && tx/bx == ty/by){
				o = min(o,i*3+tx/bx);
			}
		}
		if(o != 1e9)
			ans+=o;
		if(getline(cin,c));
	}
	cout<<ans;
}

void solve()
{
	string a,b,c;
	ll ans = 0;
	while(getline(cin,a)){
		getline(cin,b);
		getline(cin,c);
		ll ax=0, bx=0,ay=0,by=0;
		ll x=0,y=0;
		f(a,12,ax,ay);
		f(b,12,bx,by);
		f(c,9,x,y);
		x+=10000000000000;
		y+=10000000000000;

		ll o = 1e9;
		ll p = (x*by - y*bx) / (ax*by - ay*bx);
		ll q = ( x- p*ax)/bx;
		x = x - p*ax - q*bx;
		y = y - p*ay - q*by;
		if(x == 0 && y == 0)
			ans+=(p*3 + q);
		if(getline(cin,c));
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