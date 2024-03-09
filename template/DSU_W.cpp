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
ll fa[MAX], val[MAX];
ll Find(ll p)
{
    if (p != fa[p])
    {
        ll t = fa[p];
        fa[p] = Find(fa[p]);
        val[p] += val[t];
    }
    return fa[p];
}
void solve()
{
    ll n, q, a, b, d;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    vector<ll> ans;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> d;
        // 一定要先求两个结点的集合结点，在下面反复用Find(p)会出问题
        ll FA = Find(a);
        ll FB = Find(b);
        if (FA == FB)
        {
            if (val[a] - val[b] == d)
                ans.push_back(i);
        }
        else
        {
            val[FA] = d + val[b] - val[a];
            fa[FA] = FB;
            ans.push_back(i);
        }
    }
    for (auto &v : ans)
        cout << v << " ";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}