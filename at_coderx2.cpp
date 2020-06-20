///exchange arguments to find sorting condition
//order matters
//consider two elemenys
//suppose 1 is always above 2 
//then it means S2>=W1 && S1<W2
//adding bothbof them S2+W2>S1+W1
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
lli N=10000001;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
void solve()
{
	int n;
	cin>>n;
	//cout<<n;

	//vector<pair<lli,pair<lli,lli> > >v;
	vector<pair<int,pair<int,int> > >v;
	for(int i=0;i<n;i++)
	{
		int w,s,val;
		cin>>w>>s>>val;
		//cout<<w;
		v.push_back({s+w,{w,val}});
		//v.push_back(MP(s+w,MP(w,val)));
	}
	sort(all(v));
	//cout<<v[0].ff<<v[0].ss.ff<<v[0].ss.ss<<endl;
	//lli dp[N]={0};
	vector<lli>dp(N,0);
	for(int i=0;i<n;i++)
	{
		int st=v[i].ff;
		int w=v[i].ss.ff;
		int val=v[i].ss.ss;
		//cout<<st<<" "<<w<<" "<<val<<endl;
		for(int j=st-w;j>=0;j--)
		{
			if(j+w<=st)
				dp[j+w]=max(dp[j+w]*1LL,(dp[j]+val)*1LL);

		}
	}

	cout<<*max_element(all(dp))<<endl;
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	
	
	solve();
	
	
}
