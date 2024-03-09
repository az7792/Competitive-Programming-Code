#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> L(n + 1);
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> L[i];
        sum[i] = sum[i - 1] + L[i] + (i - 1);
    }
    ll l = 1, r = 1e15, mid;
    while (l < r)
    {
        mid = r - (r - l + 1) / 2;
        ll S = -1;
        ll M = 0;
        bool f = true;
        for (int i = 1; i <= n;)
        {
            if (S + L[i] + 1 > mid)
            {
                M++;
                S = -1;
            }
            else
            {
                S += L[i] + 1;
                i++;
            }
            if (M == m && i <= n)
            {
                f = false;
                break;
            }
        }
        if (f)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
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