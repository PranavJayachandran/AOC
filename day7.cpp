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
bool f1(ll i, vector<ll>&nums,ll val,ll ans){
	if(i == nums.size()){
		if(val == ans)
			return 1;
		return 0;
	}

	return f1(i+1,nums,val*nums[i],ans)| f1(i+1,nums,val+nums[i],ans);
}
void part1()
{
	string s;
	ll result = 0;
	while(getline(cin,s)){
		stringstream ss(s);
		ll ans = 0;
		v64 nums;
		string p;
		while( ss >> p){
			if(p[p.size()-1] == ':'){
				ans = stol(p.substr(0,p.size()-1));
			}
			else{
				nums.pb(stol(p));
			}
		}
		if(nums.size() == 1){
			if(nums[0] == ans){
				result += ans;
			}
			continue;
		}
		if(f1(1,nums,nums[0],ans)){
			result += ans;
		}
	}
	cout<<result;
}

// part2
bool f2(ll i, vector<ll>&nums,ll val,ll ans){
	if(i == nums.size()){
		if(val == ans)
			return 1;
		return 0;
	}
	ll concat = stol(to_string(val) + to_string(nums[i]));
	return f2(i+1,nums,val*nums[i],ans)| f2(i+1,nums,val+nums[i],ans) | f2(i+1,nums,concat,ans);
}
void solve()
{
	string s;
	ll result = 0;
	while(getline(cin,s)){
		stringstream ss(s);
		ll ans = 0;
		v64 nums;
		string p;
		while( ss >> p){
			if(p[p.size()-1] == ':'){
				ans = stol(p.substr(0,p.size()-1));
			}
			else{
				nums.pb(stol(p));
			}
		}
		if(nums.size() == 1){
			if(nums[0] == ans){
				result += ans;
			}
			continue;
		}
		if(f2(1,nums,nums[0],ans)){
			result += ans;
		}
	}
	cout<<result;
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