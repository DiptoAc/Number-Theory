#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl '\n'
#define INF 1e16
const ll N = 3e5+1;
ll M =1e9+7;
ll n,m;
ll big_mod(ll x,ll y,ll mod)
{
    ll ans=1;
    while(y)
    {
        if((y&1))
        {
            ans=(__int128)ans*x % mod; //If mod is a 2^63 range number. Then convert to __int128 before doing ops.
        }
        x = (__int128)x*x % mod;
        y>>=1;
    }
    return ans;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;
    cin>>tc;
    while(tc--)
    {
        ll a,b;
        cin>>a>>b>>n>>m>>M;
        ll div;
        if(a==1){div=n;}
        else
        {
            ll up = (big_mod(a,n,M*(a-1ll))-1ll)%(M*(1-a)); //This line required modular inverse, but this tech alowed me to solve the proble without mod inv
            if(up<0){up+=M*(a-1);}
            ll down = a-1;
            div = (up/down)%M;
        }
        ll ans = (__int128)m*b*div%M;

        ll add = (__int128)big_mod(a,n,M)*(m*(m+1)/2)%M;
        ans+=add;
        ans%=M;
        if(ans<0){ans+=M;}
        ans%=M;
        cout<<ans<<endl;
    }
}
//https://vjudge.net/contest/691403#problem/F
