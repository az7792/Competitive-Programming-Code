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
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<ll> ans(n);
    ll Max = 0, Min = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        ans[i] = a[i].first;
        Min += a[i].first;
        Max += a[i].second;
    }
    if (Min > 0 || Max < 0)
    {
        cout << "No";
        return;
    }
    sum = Min;
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
    {
        if (sum == 0)
        {
            for (auto v : ans)
                cout << v << " ";
            return;
        }
        ll tmp = -sum;
        if (a[i].second - a[i].first < tmp)
        {
            sum += (a[i].second - a[i].first);
            ans[i] = a[i].second;
        }
        else
        {
            ans[i] = ans[i] - sum;
            sum = 0;
            for (auto v : ans)
                cout << v << " ";
            return;
        }
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
