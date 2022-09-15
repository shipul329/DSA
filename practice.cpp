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

void solve2() /// dp approach
{
    string s;
    cin >> s;

    int n=s.size(), mx_len=0;

    string ans="";

    vector<vector<int> > dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0, k=j+i; k<n; j++, k++)
        {
            if(j==k) dp[j][k]=1;

            else if(i==1)
            {
                if(s[j]==s[k])
                dp[j][k]=2;

                else dp[j][k]=0;
            }

            else{
                if(s[j]==s[k] && dp[j+1][k-1])
                dp[j][k]=dp[j+1][k-1]+2;
            }

            if(dp[j][k])
            {
                if(k-j+1 > mx_len)
                {
                    mx_len=k-j+1;

                    ans=s.substr(j, mx_len);
                }
            }
        }
    }

   // cout << ans << nn;
}

void solve() /// 
{
    string s;
    cin >> s;

    int n=s.size();

    int best_len=0;
    string best_s="";

    for(int mid=0; mid<n; mid++)
    {
        for(int x=0; mid-x>=0 && mid+x<n; x++)
        {
            if(s[mid-x]!=s[mid+x])
            {
                break; /// not matching
            }

            int len=2*x+1;

            if(len>best_len)
            {
                best_len=len;
                best_s=s.substr(mid-x, len);
            }
        }
    }

    for(int mid=0; mid<n-1; mid++)
    {
        for(int x=1; mid-x+1>=0 && mid+x<n; x++)
        {
            if(s[mid-x+1]!=s[mid+x]) break;

            int len=2*x;

            if(len>best_len)
            {
                best_len=len;

                best_s=s.substr(mid-x+1, len);
            }
        }
    }

    cout << best_len << nn; /// size of longest palindromic string
    cout << best_s << nn; /// longest palindromic string
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

