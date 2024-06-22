#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> S;
    for (int i = 1; i <= n;++i)
    {
        int tmp;
        cin >> tmp;
        S.emplace(tmp);
    }
    vector<int> st;
    map<int, bool> mp;
    for (int i = 1; i <= m;++i)
    {
        int tmp;
        cin >> tmp;
        st.emplace_back(tmp);
    }
    vector<int> ans;
    for (int i = st.size() - 1; i >= 0;--i)
    {
        if(mp[st[i]]==false)
            {
                ans.emplace_back(st[i]);
                S.erase(st[i]);
                mp[st[i]] = true;
            }
    }
    for(auto v:ans)
            cout << v << ' ';
    for(auto v:S)
            cout << v << " ";
        
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}