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
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    vector<ll> dp(n + 2, 1e18);
    dp[n + 1] = 0;
    set<ll> s;
    s.insert(0);
    ll sum = 0;
    for (int i = n; i >= 1; --i)
    {
        dp[i] = a[i] + *s.begin();
        s.insert(dp[i] - b[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        dp[i] += sum;
        sum += b[i];
    }
    cout << *min_element(dp.begin() + 1, dp.begin() + m + 1) << endl;
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
