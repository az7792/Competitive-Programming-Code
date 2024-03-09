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
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n + 2, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n;)
    {
        if (a[i] == 0)
        {
            map<ll, ll> mp;
            ll Max = 0;
            mp[sum[i]]++;
            while (a[++i] != 0)
            {
                mp[sum[i]]++;
            }
            for (auto &[x, y] : mp)
            {
                Max = max(Max, y);
            }
            ans += Max;
        }
        else
        {
            if (sum[i] == 0)
                ans++;
            i++;
        }
    }
    cout << ans << endl;
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