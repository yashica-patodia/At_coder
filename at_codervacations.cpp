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
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
bool compv(const pair<int,int>&a,const pair<int,int> &b)
{
	return (a.ss>b.ss);
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	int n;
	cin>>n;
	int index=-1,temp=-2;
	lli sum=0;
	fr2(i,n)
	{
		// int a,b,c;
		// cin>>a>>b>>c;
		// if(a>=b && a>=c)
		// {
		// 	s=a;
		// 	index=1;
		// }
		// if(b>=a && b>=c)
		// {
		// 	s=b;
		// 	index=2;
		// }
		// if(c>=a && c>=b)
		// {
		// 	s=c;
		// 	index=3;
		// }

		// if( index!=temp)
		// 	sum+=s;
		// else
		// {

		// }
		// map<int,int>mp;
		// int a,b,c;
		// cin>>a>>b>>c;
		// mp[0]=a;
		// mp[1]=b;
		// mp[2]=c;
		// sort()
		// 	if(arr[0]>=arr[1] && arr[0]>=arr[2])
		// 	{
		// 		s=arr[0];
		// 		index=0;
		// 	}
		// else	if(arr[1]>=arr[0] && arr[1]>=arr[2])
		// 	{
		// 		s=arr[1];
		// 		index=1;
		// 	}
		// 	else if(arr[2]>=arr[1] && arr[2]>=arr[0])
		// 	{
		// 		s=arr[2];
		// 		index=2;
		// 	}
		// 	if(i==0 || temp!=index)
		// 	{
		// 		sum+=s;
		// 		temp=index;
		// 	}
		// 	else
		// 	{

		// 	}
		// sort(all(arr);
		vector<pair<int,int>>vec;
		int a,b,c;
		cin>>a>>b>>c;
		vec.pb(make_pair(0,a));
		vec.pb(make_pair(1,b));
		vec.pb(make_pair(2,c));
		sort(all(vec),compv);
		// for(auto j:vec)
			// cout<<j.ff<<" "<<j.ss<<" ";
		//vector<pair<int,int> > ::iterator it;
		for(auto j:vec)
		{
			if(temp!=j.ff)
			{
				sum+=j.ss;
				temp=j.ff;
				break;

			}
			// j--;
			// sum+=j.ss;
			// temp=j.ff;
			
		}
		//cout<<sum<<endl;
		//cout<<endl;
	}
cout<<sum<<endl;






	}