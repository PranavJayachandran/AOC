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
	getline(cin,s);
	cout<<s;
    regex pattern(R"(mul\(\d+,\d+\)|(do\(\))|don't\(\))");	
    auto start = sregex_iterator(s.begin(),s.end(),pattern);
	auto end = sregex_iterator();
	long long ans = 0;
	bool isMul = true;
	for(auto i = start; i!= end; i++){
		string match = (*i).str();
		if(match == "don't()"){
			isMul = false;
			continue;
		}
		else if(match == "do()"){
			isMul = true;
			continue;
		}
		if(!isMul)
			continue;
		regex pattern(R"(\d+)");
		auto start = sregex_iterator(match.begin(),match.end(),pattern);
		auto end = sregex_iterator();
		ll temp = 1;
		for(auto j=start; j!= end; j++){
			string p = (*j).str();
			temp = temp * stoi(p);
		}
		ans += temp;
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