/// To check two string anagram or not

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_anagram(string &s, string &s2)
{
    int arr[26]={};
    
    if((int)s.size()!=(int)s2.size()) return false;
    
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]>='a' && s[i]<='z') arr[s[i]-'a']++;
        if(s[i]>='A' && s[i]<='Z') arr[s[i]-'A']++;
        if(s2[i]>='a' && s2[i]<='z') arr[s2[i]-'a']--;
        if(s2[i]>='A' && s2[i]<='Z') arr[s2[i]-'A']--;
    }
    
    for(int i=0; i<26; i++)
    {
        if(arr[i]!=0) return false;
    }
    
    return true;
}

void solve()
{
    string s, s2;
    cin >> s >> s2;
    
    if(is_anagram(s, s2)) cout << "YES" << '\n';
    
    else cout << "NO" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}
