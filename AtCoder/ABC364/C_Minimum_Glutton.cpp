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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(all(a)), sort(all(b));
    reverse(all(a));
    reverse(all(b));
    ll sum = 0;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        a1++;
        if (sum > x)
            break;
    }
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += b[i];
        a2++;
        if (sum > y)
            break;
    }
    cout << min(a1, a2);
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
