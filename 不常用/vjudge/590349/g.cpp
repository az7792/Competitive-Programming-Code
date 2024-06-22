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
    ll n, k, tmp;
    cin >> n >> k;
    vector<ll> a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp < 0)
            b.push_back(-tmp);
        else if (tmp > 0)
            a.push_back(tmp);
    }
    sort(all(a));
    sort(all(b));
    ll ans1 = 0, ans2 = 0;
    for (int i = b.size() - 1; i >= 0; i -= k)
        ans1 += 2 * b[i];
    ll a1 = 0;
    for (int i = a.size() - 1, ct = 1; i >= 0; i -= k, ct++)
    {
        if (ct == 1)
            a1 += a[i];
        else
            a1 += 2 * a[i];
    }
    ans1 += a1;
    for (int i = a.size() - 1; i >= 0; i -= k)
        ans2 += 2 * a[i];
    a1 = 0;
    for (int i = b.size() - 1, ct = 1; i >= 0; i -= k, ct++)
    {
        if (ct == 1)
            a1 += b[i];
        else
            a1 += 2 * b[i];
    }
    ans2 += a1;
    cout << min(ans1, ans2) << endl;
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