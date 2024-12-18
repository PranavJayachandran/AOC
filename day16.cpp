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
	ll get_combo(ll n, ll a,ll b, ll c){
		if(n<4)
			return n;
		if(n == 4)
			return a;
		if(n==5)
			return b;
		return c;

	}
	void solve()
	{
		string x,y,z;
		cin>>x>>y>>z;
		ll a, b, c;
		a = stol(z);
		cin>>x>>y>>z;
		b = stol(z);
		cin>>x>>y>>z;
		c = stol(z);
		cin>>x>>y;

		v64 v;
		stringstream s(y);
		while(!s.eof()){
			string temp;
			getline(s,temp,',');
			v.pb(stol(temp));
		}		
		reverse(all(v));
		unordered_set<ll>q;
		q.insert(0);
		forn(i,v.size()){
			ll final = v[i];
			queue<ll>temp;
			for(auto p:q)
			{
				ll val = p;
				forn(j,8){
					ll a = val * 8 + j;
					ll b = a%8;
					ll k = b^3;
					ll z = a/ pow(2,k);
					b = (b ^ z)%8;
					if(b == final){
						temp.push(a);
					}
				}
			}				
			cout<<i<<"-> ";
			q.clear();
			while(!temp.empty()){
				q.insert(temp.front());
				cout<<temp.front()<<" ";
				temp.pop();
			}
			cout<<"\n";
		}
		ll ans = 1e18;
		for(auto p:q){
			ans = min(ans,p);
		}
		cout<<ans;
	}


	void part1()
	{
		string x,y,z;
		cin>>x>>y>>z;
		ll a, b, c;
		a = stol(z);
		cin>>x>>y>>z;
		b = stol(z);
		cin>>x>>y>>z;
		c = stol(z);
		cin>>x>>y;

		v64 v;
		stringstream s(y);
		while(!s.eof()){
			string temp;
			getline(s,temp,',');
			v.pb(stol(temp));
		}

		ll i = 0;
		v64 ans;
		while(1){
			if( i == v.size())
				break;
			if(v[i] == 0){
				ll c =get_combo(v[i+1],a,b,c);
				a = a/pow(2,c);
			}
			else if(v[i]==1){
				b = b ^ v[i+1];
			}
			else if(v[i] == 2){
				b = get_combo(v[i+1],a,b,c)%8;
			}
			else if(v[i]==3){
				if(a==0)
					;
				else{
					i = v[i+1];
					continue;
				}
			}
			else if(v[i]==4){
				b = b ^ c;
			}
			else if(v[i]==5){
				ans.pb(get_combo(v[i+1],a,b,c)%8);
			}
			else if(v[i]==6){
				b = a/ pow(2,get_combo(v[i+1],a,b,c));
			}
			else {
				c = a/pow(2,get_combo(v[i+1],a,b,c));
			}
			i+=2;
		}
		forn(i,ans.size()){
			cout<<ans[i];
			if(ans.size() - 1 > i){
				cout<<",";
			}
		}
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
	        part1();
	    }
	}	