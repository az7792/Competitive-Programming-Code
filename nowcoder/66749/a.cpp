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
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a(n + 1, 0);
    vector<ll> h(n + 2, 0);
    vector<ll> sum(n + 1, 0);
    vector<ll> SUM(n + 1, 0);
    vector<int> p;
    h[n + 1] = 1e18;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        SUM[i] = a[i] + SUM[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = n; i >= 1; --i)
    {
        if (h[i] < h[i + 1])
            p.push_back(i);
    }
    sum[0] = 0;
    p.push_back(0);
    for (int i = p.size() - 2; i >= 0; --i)
    {
        int end = p[i] - k + 1;
        if (p[i] - k + 1 <= p[i + 1])
        {
            sum[p[i]] += sum[p[i + 1]];
            end = p[i + 1] + 1;
        }
        for (int j = end; j <= p[i]; ++j)
        {
            sum[p[i]] += a[j];
        }
    }
    reverse(all(p));
    while (q--)
    {
        ll x;
        cin >> x;
        if (h[x] < h[x + 1])
        {
            cout << sum[x] << endl;
        }
        else
        {
            int P = lower_bound(all(p), x) - p.begin();
            P--;
            if (x - k + 1 <= p[P])
            {
                cout << sum[p[P]] + SUM[x] - SUM[p[P]] << endl;
            }
            else
            {
                cout << SUM[x] - SUM[x - k] << endl;
            }
        }
    }
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