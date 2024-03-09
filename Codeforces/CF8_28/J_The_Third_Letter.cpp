#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int fa[MAX];
ll len[MAX];
int Find(int x)
{
    if (fa[x] != x)
    {
        int t = fa[x];
        fa[x] = Find(fa[x]);
        len[x] += len[t];
    }
    return fa[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        len[i] = 0;
    }

    ll a, b, d;
    bool ok = true;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> d;
        int f1 = Find(a);
        int f2 = Find(b);
        if (f1 != f2)
        {
            fa[f1] = f2;
            len[f1] += d + len[b] - len[a];
        }
        else
        {
            ll Len = len[a] - len[b];
            if (Len != d)
                ok = false;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}