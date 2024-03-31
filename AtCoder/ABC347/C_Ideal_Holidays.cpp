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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    ll l = 0, r = a - 1;
    for (int i = 1; i < n; ++i)
    {
        ll len = d[i] - d[0];
        ll L = l + len;
        ll R = r + len;
        ll al = 0, ar = 0;
        if (L % (a + b) >= a && R % (a + b) >= a)
        {
            cout << "No";
            return;
        }
        if (L % (a + b) >= a)
            al = a + b - (L % (a + b));
        else
            ar = (R % (a + b)) - (a - 1);

        l += al;
        r -= ar;
        if (l > r || l >= a)
        {
            cout << "No";
            return;
        }
    }
    if (l <= r)
        cout << "Yes";
    else
        cout << "No";
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
