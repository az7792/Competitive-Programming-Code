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
    ll n, p;
    cin >> n >> p;
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    ll L = -1, R = 1e9 + 10, mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        ll sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (h[i] > mid)
                sum += 2 * (h[i] - mid);
        }
        if (sum >= p)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L;
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