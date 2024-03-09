#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll n, m, LCM;
ll ok(ll mid)
{
    ll a = mid / n;
    ll b = mid / m;
    ll c = mid / LCM;
    return a + b - 2 * c;
}
void solve()
{
    ll k;
    cin >> n >> m >> k;
    LCM = lcm(n, m);
    ll l = 1, r = 2e18, mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        ll tmp = ok(mid);
        if (tmp < k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
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
