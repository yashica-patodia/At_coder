// dp[i][j] represents distrbuting j candies among firs ti people
// base case--dp[0][0]=1 i way of distributing 0 candies to 0 people
// dp[0][p>=1]-->0 0 ways of distributing more than one candies to 0 childer
// so how many candies do u want to give to the ith person let it be p
// p is between 0 to min(a[i],j)
// so dp[i][j]= sum of all such p's dp[i-1][j-p] p from 0 to min(a[i],j)
// and j runs from 0 to k
// ab max value of a[i] toh a[i]+1 allowed nahi hai so dp[i][0] to dp[i][j-a[i]-1] sum mein nahi aeyga
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
long long int MOD=1E9+7;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
void solve()
{
	lli n,k;
	cin>>n>>k;
	vector<lli>a(n+1);
	for(lli i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	lli dp[n+1][k+1];
	//mset(dp,0);
	dp[0][0]=1;
	for(lli i=1;i<=k;i++)
		dp[0][i]=0;
	for(lli i=1;i<=n;i++)
	{
		lli s[k+1];
		s[0]=(dp[i-1][0])%MOD;
		for(lli j=1;j<=k;j++)
		{
			s[j]=(s[j-1]%MOD+dp[i-1][j]%MOD)%MOD;
			//cout<<s[j]<<" ";
		}

		for(lli j=0;j<=k;j++)
		{
			if(j==0)
				dp[i][j]=s[0]%MOD;
			else
			{
				//lli ans=s[j];
				
				if(j-a[i]>=1)
				{
					//ans=(ans-s[j-a[i]-1]+MOD)%MOD;
					dp[i][j]=(s[j]-s[j-a[i]-1]+MOD)%MOD;
				}
				else
					dp[i][j]=s[j]%MOD;
				//dp[i][j]=ans;

			}

		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=k;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<dp[n][k]%MOD<<endl;
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	// clock_t start,end;
	// start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	solve();
	
}
