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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, ll> mp, tmp;
    ll ans = 0, tmpans = 0;
    for (int i = 0; i < n; ++i)
    {
        tmpans = tmpans + tmp[a[i]];
        ans += tmpans;
        mp[a[i]] += n - i;
        tmp[a[i]]++;
    }
    tmpans = ans;
    for (int i = 0; i < n; ++i)
    {
        mp[a[i]] -= n - i;
        tmpans = tmpans - mp[a[i]];
        ans += tmpans;
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