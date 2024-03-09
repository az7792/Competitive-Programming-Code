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
bool ok(ll x)
{
    vector<int> a;
    while (x != 0)
    {
        a.push_back(x % 10);
        x /= 10;
    }
    int L = a.size();
    for (int i = 0; i <= L - i - 1; ++i)
    {
        if (a[i] != a[L - i - 1])
            return 0;
    }
    return 1;
}
void solve()
{
    ll N;
    cin >> N;
    vector<ll> tmp;
    for (ll x = 1; x <= 1e6; ++x)
    {
        ll X = x * x * x;
        if (ok(X))
            tmp.push_back(X);
    }
    cout << tmp[upper_bound(all(tmp), N) - tmp.begin() - 1];
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
