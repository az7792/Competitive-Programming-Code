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
bool cmp(ll a,ll b)
{
    return a > b;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pll> G(n + 1);
    map<ll, multiset<ll>> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i].first >> G[i].second;
        mp[G[i].first].emplace(G[i].second);
    }
    ll ans = 0;
    vector<ll> ttt;
    for (auto &[x, y] : mp)
    {
        if (y.size() <= 1)
        {
            if (y.size() == 1)
            {
                ttt.emplace_back(*y.begin());
            }
            continue;
        }
        auto it = y.end();
        it--;
        ll s = *it;
        ttt.emplace_back(s);
        it--;
        ll t = *it;
        ans = max(s + t / 2, ans);
    }
    sort(all(ttt),cmp);
    if(ttt.size()<=1)
        ;
    else
    {
        ans = max(ans, ttt[0] + ttt[1]);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}