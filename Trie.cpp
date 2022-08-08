#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll mod=1e9+7;

const ll mx=2e5+7;

struct trie{ /// structure of trie
    struct trie *child[26];
    bool isend; /// to check string end or not if end then we will mark end that node

    trie()
    {
        memset(child, 0, sizeof(child));
        isend=false;
    }
};

struct trie *root; /// decleration

void insert(string s)
{
    struct trie *cur=root;

    for(char ch:s)
    {
        int idx=ch-'a'; /// indexing

        if(cur->child[idx]==NULL) /// checking for child
        {
            cur->child[idx]=new trie; /// if no child then create new node 
        }

        cur=cur->child[idx]; /// change current node
    }

    cur->isend=true; /// once traverse all the string 
}

bool search(string s)
{
    struct trie *cur=root; /// we have to start from the top that's why at the begenning we will deal with root node

    for(char ch:s)
    {
        int idx=ch-'a';

        if(cur->child[idx]==NULL) /// if edge not found then return false
        return false;

        cur=cur->child[idx];
    }

    return cur->isend;
}
 
void solve()
{

    root=new trie; /// and we make it
    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        insert(s);
    }

    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;

        if(search(s))
        cout << s << " is present" << nn;

        else cout << s << " is not present" << nn;
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
