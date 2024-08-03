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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i)
        b[i] = b[i - 1] + a[i];
    ll l = 0, r = 5e15, mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        int p = upper_bound(a.begin() + 1, a.end(), mid) - a.begin();
        ll sum = b[p - 1] + mid * (n - p + 1);
        if (sum <= m)
            l = mid;
        else
            r = mid - 1;
    }
    if (l >= 1e15)
        cout << "infinite";
    else
        cout << l;
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
