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
	vector<pair<string,string>>vs;
	ll ans = 0;
	while(cin>>s){
		if(s.find('|') != string::npos){
			string a,b;
			ll i = 0;
			while(i<(ll)s.size() && s[i] != '|')
				a+=s[i++];
			i++;
			while(i<(ll)s.size())
				b+=s[i++];
			vs.pb({a,b});
		}
		else if(s.find(',') != string::npos){
			stringstream ss(s);
			string word;
			vector<string>temp;
			unordered_set<string>st;
			while(!ss.eof()){
				getline(ss,word,',');
				temp.pb(word);
				st.insert(word);
			}
			unordered_map<string,ll>in;
			unordered_map<string,vector<string>>g;
			forn(i,vs.size()){
				if(st.find(vs[i].first) != st.end() && st.find(vs[i].second) != st.end() ){
					g[vs[i].first].pb(vs[i].second);
					in[vs[i].second]++;
				}
			}
			bool isValid = true;
			ll i = 0 ;
			while(i < (ll)temp.size()){
				if(in[temp[i]] > 0){
					isValid = false;
				}
				for(auto p:g[temp[i]])
					in[p]--;
				i++;
			}
			if(!isValid){
				ans += stoi(temp[temp.size()/2]);
			}
		}
	}
	cout<<ans;
}

void solve()
{
	string s;
	vector<pair<string,string>>vs;
	ll ans = 0;
	while(cin>>s){
		if(s.find('|') != string::npos){
			string a,b;
			ll i = 0;
			while(i<(ll)s.size() && s[i] != '|')
				a+=s[i++];
			i++;
			while(i<(ll)s.size())
				b+=s[i++];
			vs.pb({a,b});
		}
		else if(s.find(',') != string::npos){
			stringstream ss(s);
			string word;
			vector<string>temp;
			unordered_set<string>st;
			while(!ss.eof()){
				getline(ss,word,',');
				temp.pb(word);
				st.insert(word);
			}
			unordered_map<string,ll>in;
			unordered_map<string,vector<string>>g;
			forn(i,vs.size()){
				if(st.find(vs[i].first) != st.end() && st.find(vs[i].second) != st.end() ){
					g[vs[i].first].pb(vs[i].second);
					in[vs[i].second]++;
				}
			}
			bool isValid = true;
			ll i = 0 ;
			unordered_map<string,ll>l = in;
			queue<string>q;
			while(i < (ll)temp.size()){
				if(in[temp[i]] > 0){
					isValid = false;
				}
				for(auto p:g[temp[i]])
					in[p]--;
				i++;
			}
			in = l;
			forn(i,(ll)temp.size()){
				if(in[temp[i]] == 0){
					q.push(temp[i]);

				}
			}
			vector<string>o;
			while(!q.empty()){
				o.pb(q.front());
				string w = q.front();
				q.pop();
				for(auto p:g[w]){
					in[p]--;
					if(in[p]==0)
						q.push(p);
				}
			}
			if(!isValid){
				ans += stoi(o[o.size()/2]);
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