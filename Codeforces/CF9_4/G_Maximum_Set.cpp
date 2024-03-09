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
    ll l, r, len;
    cin >> l >> r;
    for (int i = 1; i <= 32; ++i)
    {
        if (l * (1ll << i) > r)
        {
            len = i;
            break;
        }
    }
    if (len == 1)
    {
        cout << "1 " << (r - l + 1) << "\n";
        return;
    }
    cout << len << ' ';
    ll M3 = (1ll << (len - 2)) * 3;
    ll M2 = 1ll << (len - 1);
    ll ans = 0;
    ll L = l, R = r, mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        if (mid * M2 > r)
        {
            R = mid - 1;
        }
        else
        {
            L = mid;
        }
    }
    ans += L - l + 1;
    L = l, R = r, mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        if (mid * M3 > r)
        {
            R = mid - 1;
        }
        else
        {
            L = mid;
        }
    }
    L = (L * M3 <= r ? L : L - 1);
    ans += ((L - l + 1) % MOD * (len - 1) % MOD) % MOD;
    cout << ans % MOD;
    cout << endl;
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