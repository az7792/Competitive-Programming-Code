#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool num[200][200];
void solve()
{
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> F(n+1,0);
    vector<ll> sum(n+1,0);
    for (int i = 1; i <= n; ++i)
        cin >> F[i];
    sort(F.begin()+1,F.begin()+n+1, [&](ll a, ll b)
         { return a > b; });
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + F[i];
    int ct = (n + d - 1) / d;
    ll ans = 1e18;
    for (int i = 0; i <= ct; ++i)
    {
        ll tmp = i * p;
        if (i * d <= n)
            tmp += sum[n] - sum[i * d];
        ans = min(ans, tmp);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}