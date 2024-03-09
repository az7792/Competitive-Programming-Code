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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = k - 1, ct = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] % k == 0)
            ans = 0;
        if (a[i] % 2 == 0)
            ct++;
        ans = min(ans, k - a[i] % k);
    }
    if (k == 4)
    {
        if (ct >= 2)
            ans = 0;
        else if (ct == 1)
            ans = min(ans, 1);
        else
            ans = min(ans, 2);
    }
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