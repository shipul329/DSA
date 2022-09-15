/// count number of substrings in given string s in O(|s|) time
/// manacher algorithm

#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
#define for0(i, n) for(ll i=0; i<n; i++)
#define for1(i, n) for(ll i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll mod=1e9+7;

void solve()
{
    string s;
    cin >> s;

    string t;

    for(auto x:s)
    {
        t+=x;
        t+='#';
    }

    ll n=t.size();

    ll ans=0;

    vector<ll>v(n);

    for(ll i=0, l=0, r=0; i<n; i++)
    {
        if(i<r)
        {
            v[i]=min(r-i, v[l+r-i]);
        }

        while(i+v[i] < n && i-v[i]>=0 && t[i+v[i]]==t[i-v[i]])
        {
            v[i]++;
        }

        if(i+v[i] > r)
        {
            l=i-v[i];
            r=i+v[i];
        }

        if(i&1)
        {
            ans+=v[i]/2;
        }

        else{
            ans+=(v[i]+1)/2-1;
        }
    }

    cout << ans << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    solve();

    return 0;
}

