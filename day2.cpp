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
	string str;
	ll ans = 0;
	int count =0;
	while(getline(cin,str)){
		v64 v;
		stringstream s(str);
		int num;
		while(s>>num){
			v.pb(num);
		}
		if(v.size() == 1){
			ans ++; 
			continue;
		}
		for(ll j = 0;j<v.size();j++){
			v64 temp;
			for(ll i=0;i<v.size();i++){
				if(i != j)
					temp.pb(v[i]);
			}
					bool allinc = true, alldic = true;

			for(int i=0;i<temp.size()-1;i++){
			ll p = temp[i+1] - temp[i];
			if(p < 1 || p > 3){
				allinc = false;
			}
			p = 0-p;
			if(p<1 || p> 3){
				alldic = false;
			}
		}
			if(alldic || allinc){
				ans++;
				break;
			}
		}
		
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