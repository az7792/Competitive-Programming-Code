#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<pair<ll, ll>> duan;
bool ok(ll k)
{
    ll L = 0, R = 0;
    for (int i = 0; i < duan.size(); ++i)
    {
        L -= k;
        R += k;
        if (L > duan[i].second || R < duan[i].first)
            return false;
        L = max(L, duan[i].first);
        R = min(R, duan[i].second);
    }
    return true;
}
void solve()
{
    duan.clear();
    int n;
    cin >> n;
    duan.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> duan[i].first >> duan[i].second;
    ll L = 0, R = 1e9, mid;
    while (L < R)
    {
        mid = (L + R) / 2;
        if (ok(mid))
            R = mid;
        else
            L = mid + 1;
    }
    cout << L << endl;
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
