#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll fa[MAX];
ll find(int p)
{
    if (p != fa[p])
        fa[p] = find(fa[p]);
    return fa[p];
}

void solve()
{
    ll n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i], fa[i] = i;
    for (int i = 1; i <= n; ++i)
        cin >> b[i]; // 1丁真帝国
    for (int i = 1; i <= m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        if (b[u] == b[v] && b[u] == 1)
        {
            ll p1 = find(u);
            ll p2 = find(v);
            if (p1 != p2)
            {
                fa[p1] = p2;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (b[i] == 1)
            find(i);
    map<ll, ll> mp;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 1)
        {
            mp[fa[i]] += a[i];
        }
    }
    vector<ll> ans;
    for (auto [x, y] : mp)
        ans.push_back(y);
    if(ans.size()==0)
    {
        cout << 0;
        return;
    }
    sort(all(ans), [](ll a, ll b)
         { return a > b; });         
    if(k==0)
    {
        cout << ans[0];
        return;
    }
    ll sum = 0;
    for (int i = 0; i <= min(k - 1, (ll)ans.size() - 1); ++i)
        sum += ans[i];
    cout << sum;
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