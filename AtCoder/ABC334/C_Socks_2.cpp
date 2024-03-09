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
    ll n, k;
    cin >> n >> k;
    vector<int> num;
    vector<ll> a(k+2);
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i];
    }
    if (k % 2 == 0)
    {
        ll ans = 0;
        for (int i = 1; i + 1 <= k; i += 2)
            ans += abs(a[i] - a[i + 1]);
        cout << ans;
    }
    else
    {
        vector<ll> suml(k + 2), sumr(k + 2);
        for (int i = 2; i <= k; i += 2)
            suml[i] = suml[i - 2] + abs(a[i] - a[i - 1]);
        for (int i = k - 1; i >= 0;i-=2)
            sumr[i] = sumr[i + 2] + abs(a[i] - a[i + 1]);
        ll ans = 1e18;
        for (int i = 1; i <= k;i+=2)
        {
            ans = min(ans, suml[i - 1] + sumr[i + 1]);
        }
        cout << ans;
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
