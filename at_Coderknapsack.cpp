#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
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
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
// double startTime;
// double getCurrentTime()
// {
// 	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
// }

// lli pwr(lli x,lli n)
// {
// 	lli res=1;
// 	for(; n!=0;n>>=1)
// 	{
// 		if(n&1)
// 			res=(res*x)%MOD;
// 		x=(x*x)%MOD;
// 	}
// 	return res;
// }
// lli inver(lli num)
// {
// 	return pwr(num,MOD-2);
// }
// lli findncr(lli n,lli r)
// {
// 	r=min(r,n-r);
// 	if(n==0||n==1||r==0)
// 		return 1;
// 	lli numer=1;
// 	for(lli i=n;i>=n-r+1;i--)
// 		numer=(numer*i)%MOD;
// 	lli den=1;
// 	for(lli i=2;i<=r;i++)
// 		den=(den*i)%MOD;
// 	den=inver(den);
// 	lli res=(numer*den)%MOD;
// 	return res;
// }
// lli gcd(lli a,lli b)
// {
// 	if(b==0)
// 		return a;
// 	else
// 		return gcd(b,a%b);
// }
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	lli n,w;
	cin>>n>>w;
	//cout<<n<<" ";
	lli vecw[n+1]={0};
	lli vecv[n+1]={0};
	//cout<<n<<w<<" ";
	for(lli i=1;i<=n;i++)
	cin>>vecw[i]>>vecv[i];
	vector<vector<lli> >dp(n+1,vector<lli>(w+1,0));
	//dp[n+1][w+1]={0}
	for(lli i=1;i<=n;i++)
	{
		for(lli  j=1;j<=w;j++)
		{
			if(j<vecw[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],(vecv[i]+dp[i-1][j-vecw[i]]));
		}
	}
	cout<<dp[n][w]<<endl;
}