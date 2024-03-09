#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
struct Node
{
    int rank;
    string name;
    bool operator<(const Node &a) const
    {
        return rank < a.rank;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    string str;
    vector<string> s1, s2;
    vector<string> tmp;
    map<string, bool> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        if (mp[str] == false)
        {
            mp[str] = true;
            s1.push_back(str);
        }
    }
    mp.clear();
    for (int i = 1; i <= m; ++i)
    {
        cin >> str;
        if (mp[str] == false)
        {
            mp[str] = true;
            s2.push_back(str);
        }
    }
    vector<string> ans;
    for (int i = 0; i < min(s1.size(), s2.size()); ++i)
    {
        ans.push_back(s1[i]);
        ans.push_back(s2[i]);
    }
    if (s1.size() > s2.size())
    {
        for (int i = s2.size(); i < s1.size(); ++i)
            ans.push_back(s1[i]);
    }
    else
    {
        for (int i = s1.size(); i < s2.size(); ++i)
            ans.push_back(s2[i]);
    }
    mp.clear();
    for (auto v : ans)
    {
        if (mp[v] == false)
        {
            mp[v] = true;
            cout << v << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}