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
    vector<int> a(n + 1, 0);
    int er = 0, on = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int ans = 4;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % k == 0)
        {
            cout << 0 << endl;
            return;
        }
        ans = min(ans, k - (a[i] % k));
        if (a[i] % 2 == 0)
            er++;
        else
            on++;
    }
    if (k == 2)
    {
        cout << 1 << endl;
        return;
    }
    if (k == 4)
    {
        if (er >= 2)
            ans = 0;
        else if (er == 1 && on >= 1)
            ans = min(ans, 1);
        else if (er == 0 && on >= 2)
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
