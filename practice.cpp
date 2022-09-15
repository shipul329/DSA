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

bool isvalid(string s)
{
    stack<char>st;

    int n=s.size();

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push(s[i]);

        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(st.empty()) return false;

            else if(s[i]==')' && st.top()!='(') return false;
            else if(s[i]=='}' && st.top()!='{') return false;
            else if(s[i]==']' && st.top()!='[') return false;

            else st.pop();
        }
    }

    if(st.empty()) return true;

    return false;
}

void solve()
{
    string s;
    cin >> s;

    if(isvalid(s)) cout << "YES" << nn;

    else cout << "NO" << nn;
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

