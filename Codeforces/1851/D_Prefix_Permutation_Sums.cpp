#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, bool> mp;
vector<ll> G(MAX, 0);
void solve()
{
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> G[i];
    ll len=0;
    int ct = 0;
    for (int i = 1; i < n; ++i)
    {
        if (G[i] <= G[i - 1])
        {
            cout << "NO\n";
            return;
        }
        if (G[i] - G[i - 1] > n)
        {
            len = G[i] - G[i - 1];
            ct++;
        }
        else
        {
            if (mp.find(G[i] - G[i - 1]) != mp.end())
            {
                len = G[i] - G[i - 1];
                ct++;
            }
            mp[G[i] - G[i - 1]] = true;
        }
    }

    vector<int> S;
    if (ct>=2)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (mp.find(i) == mp.end())
            S.eb(i);
    if (S.size() == 1)
    {
        cout << "YES\n";
        return;
    }
    if (S.size() > 2)
    {
        cout << "NO\n";
        return;
    }
    if(S[0]+S[1]==len)    
        cout << "YES\n";    
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/