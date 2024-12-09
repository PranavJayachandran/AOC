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
void part1()
{
	string s;
	cin>>s;
	v64 p;
	for(ll i=0;i<s.size();i++){
		for(ll j=0;j<(s[i]-'0');j++){
			p.pb((i%2 == 1)? -1 : i/2);
		}
	}
	ll i = 0, j = p.size()-1;
	while(i<j){
		if(p[j] == -1)
			j--;
		else{
			while(i < p.size() && p[i] != -1){
				i++;
			}
			if(i<j){
				swap(p[i],p[j]);
			}
			j--;
		}
	}
	ll ans = 0 ;
	forn(i,p.size()){
		if(p[i]==-1)
			break;
		ans += (p[i])*i;
	}
	cout<<ans;
}

//part2
void solve(){
	string s;
	cin>>s;
	v64 p;
	for(ll i=0;i<s.size();i++){
		for(ll j=0;j<(s[i]-'0');j++){
			p.pb((i%2 == 1)? -1 : i/2);
		}
	}
	ll j = p.size()-1;
	while(j>=0){
		if(p[j] == -1){
			j--;
			continue;
		}
		ll count = 0;
		ll val = p[j];
		while(j>=0 && p[j] == val){
			j--;
			count++;
		}
		ll i = 0;
		ll index = -1;
		while(i<j){

			bool take = true;
			for(int k=0;k<count;k++){
				if(i+k > j){
					take = false;
					break;
				}
				if(p[i+k] != -1){
					take = false;
					break;
				}
			}
			if(take){
				index = i;
				break;
			}
			i++;
		}
		if(index == -1){
			continue;
		}
		ll o = j;
		while(count > 0){
			swap(p[index + count-1],p[j+count]);
			count--;
		}
	}
	ll ans = 0;
	forn(i,p.size()){
		if(p[i]!=-1)
			ans+=(p[i]*i);
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