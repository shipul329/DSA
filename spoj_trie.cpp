/// problem : https://www.spoj.com/problems/PHONELST/

#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

struct trie{
    unordered_map<char, trie*>mp; /// node bole dibe jodi kono character er corrosponding node ache ki na

    bool isend;

    trie()
    {
        isend=false;
    }
};

struct trie *root;
bool flag=true;

void insert(string s)
{
    struct trie *cur=root;

    for(auto ch:s)
    {
        if(cur->isend==true) flag=false; /// tar mane er age emn ekta string ache jeta ekhan porjonto sesh that means emn ekta sub string already ache

        if(!cur->mp.count(ch))
        cur->mp[ch]=new trie;

        cur=cur->mp[ch];
    }

    cur->isend=true;

    for(int i=0; i<26; i++) /// for letter
    {
        if(cur->mp.count(i+'a')) /// 9112 and 911 er jonno 
        flag=false;              /// 2nd string 911 sesh but 9112 er 2 exist kore ei khetrew possible na
    }

    /*
     for(int i=0; i<10; i++) /// for number
    {
        if(cur->mp.count(i+'0'))
        flag=false;
    }
    */
}

void solve()
{
    flag=true;

    int n;
    cin >> n;

    root=new trie;

    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;

        insert(s);
    }

    if(flag==false)
    cout << "NO" << nn;

    else cout << "YES" << nn;
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

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
