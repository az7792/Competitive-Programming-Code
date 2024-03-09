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
void solve()
{
    int n;
    cin >> n;
    vector<set<int>> g(n);
    map<int, set<int>> mp;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int tmp;
            cin >> tmp;
            mp[tmp].insert(i);
            g[i].insert(tmp);
        }
    }
    int ans = 0;
    for (auto &[x, s] : mp)
    {
        set<int> S;
        for (int i = 0; i < n; ++i)
        {
            if (s.find(i) == s.end())
            {
                for (auto &v : g[i])
                    S.insert(v);
            }
        }
        ans = max(ans, (int)S.size());
    }

    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}