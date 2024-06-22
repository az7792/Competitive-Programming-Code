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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (b[l] < b[r])
        {
            ans += a[l];
            a[l + 1] += b[l];
            l++;
        }
        else
        {
            ans += a[r];
            a[r - 1] += b[r];
            r--;
        }
    }
    if (l == r)
        ans += a[l];
    cout << ans << endl;
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