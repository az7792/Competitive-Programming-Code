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
    int n, r, R = 1;
    cin >> n >> r;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    while (R <= n)
    {
        bool f = false;
        for (int i = min(n, R + r - 1); i >= max(1, R - r + 1); --i)
        {
            if (a[i] == 1)
            {
                f = true;
                ans++;
                R = i + r;
                break;
            }
        }
        if (!f)
        {
            cout << -1;
            return;
        }
    }
    cout << ans;
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