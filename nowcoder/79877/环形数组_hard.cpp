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
    ll n, m, x;
    cin >> n >> m >> x;
    ll l = 1, r = min((n + 1) / 2, (m + 1) / 2), mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        ll num = 1 + (mid - 1) * (2 * m + 2 * n + 4 - 4 * mid);
        // cout<<num<<endl;
        if (num <= x)
            l = mid;
        else
            r = mid - 1;
    }
    mid = l;
    ll k = mid, xx, yy, P = 1 + (mid - 1) * (2 * m + 2 * n + 4 - 4 * mid);
    n = n - 2 * (k - 1), m = m - 2 * (k - 1);
    if (x <= P + m - 1)
    {
        xx = k, yy = x - P + k;
    }
    else if (x <= P + m - 1 + n - 1)
    {
        P = P + m - 1;
        xx = x - P + k, yy = k + m - 1;
    }
    else if (x <= P + m - 1 + n - 1 + m - 1)
    {
        P = P + m - 1 + n - 1;
        yy = k + m - 1 - x + P, xx = k + n - 1;
    }
    else
    {
        P = P + m - 1 + n - 1 + m - 1;
        yy = k, xx = k + n - 1 - x + P;
    }
    cout << xx << " " << yy << endl;
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