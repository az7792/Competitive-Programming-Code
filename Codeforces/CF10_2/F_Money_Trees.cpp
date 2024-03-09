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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0), h(n + 2, 0), sum(n + 1, 0);
    vector<pii> G;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    int l = 0, r = 0, mid;
    h[n] = 1e18;
    for (int i = 0; i < n; ++i)
    {
        if (h[i] % h[i + 1] == 0)
            r++;
        else
        {
            G.push_back({l, r});
            l = r = i + 1;
        }
    }
    l = 0, r = n;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        bool ok = false;
        for (auto &[x, y] : G)
        {
            for (int i = x; i <= y + 1 - mid; ++i)
            {
                ll res = sum[mid + i - 1] - sum[i - 1];
                if (res <= k)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }
        if (ok)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
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