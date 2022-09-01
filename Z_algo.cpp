#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll mod=1e9+7;

const ll mx=2e5+7;

auto z_algo(string s)
{
    ll sz=s.size();

    ll l=0, r=0;

    vector<ll>v(sz);

    for(ll i=1; i<sz; i++)
    {
        if(i>r)
        {
            l=r=i;

            while(r<sz && s[r]==s[r-l])
            {
                r++;
            }
            
            v[i]=r-l;
            r--;
        }

        else{
            ll idx=i-l;

            if(i+v[idx]<=r)
            v[i]=v[idx];

            else{
                l=i;

                while(r<sz && s[r]==s[r-l])
                {
                    r++;
                }

                v[i]=r-l;
                r--;
            }
        }
    }

    return v;
}

ll z[1000005];
 
void solve()
{
    string s, sb;
    cin >> s >> sb;

    string tot=sb+'$'+s;

    auto z=z_algo(tot);
    auto zz=z_algo(s);

    for(auto it:zz) /// for longest substring
    {
        cout << it << " "; 


    }

    for(ll i=0; i<z.size(); i++) /// find pattern in string
    {
        if(z[i]==sb.size())
        cout << i-sb.size()-1 << nn;
    }
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
