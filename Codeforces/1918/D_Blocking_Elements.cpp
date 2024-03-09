#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<ll> a;
bool ok(ll mid)
{
    ll l = 0, r = 1, sum = a[1];
    vector<ll> dp(a.size(), 0);
    dp[1] = a[1];
    set<pair<ll, ll>> S;
    S.insert({dp[0], 0});
    S.insert({dp[1], 1});
    for (r = 2; r < a.size(); ++r)
    {
        while (sum > mid)
        {
            sum -= a[l];
            l++;
        }
        while (!S.empty())
        {
            if ((*S.begin()).second < l - 1)
                S.erase(S.begin());
            else
                break;
        }
        dp[r] = a[r] + (*S.begin()).first;
        S.insert({dp[r], r});
        sum += a[r];
    }
    return dp.back() <= mid;
}
void solve()
{
    a.clear();
    int n;
    cin >> n;
    a.resize(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll l = 0, r = 1e15, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        bool f = ok(mid);
        if (f)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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
