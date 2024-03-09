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
ll get(vector<ll> &a)
{
    int n = a.size() - 1;
    vector<ll> dp(n + 1);
    dp[0] = -1e9;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    ll Ma = *max_element(all(dp));
    return Ma;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    bool fza = 1, fzb = 1, ffa = 1, ffb = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < 0)
            fza = 0;
        if (a[i] >= 0)
            ffa = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] < 0)
            fzb = 0;
        if (b[i] >= 0)
            ffb = 0;
    }
    ll Maz = get(a);
    ll Mbz = get(b);
    for (int i = 1; i <= n; ++i)
        a[i] = -a[i];
    for (int i = 1; i <= m; ++i)
        b[i] = -b[i];
    ll Maf = get(a);
    ll Mbf = get(b);
    ll ans;
    if (fza && ffb)
    {
        cout << (*min_element(a.begin() + 1, a.end())) * (*max_element(b.begin() + 1, b.end()));
    }
    else if ((ffa && fzb))
    {
        cout << (*max_element(a.begin() + 1, a.end())) * (*min_element(b.begin() + 1, b.end()));
    }
    else
    {
        cout << max(Maz * Mbz, Maf * Mbf);
    }
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
