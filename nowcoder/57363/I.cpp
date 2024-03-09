// 未完成
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 5e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
set<int> S;
ll sum[MAX];
bool ok(int L, int R)
{
    set<int>::iterator it = S.lower_bound(L);
    if (it == S.end())
        return false;
    if (*it <= R)
        return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<pii, pii>> len(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> len[i].first.first >> len[i].first.second;
        cin >> len[i].second.first >> len[i].second.second;
        int L = max(len[i].first.first, len[i].second.first);
        int R = min(len[i].first.second, len[i].second.second);
        if (L <= R)
        {
            sum[min(len[i].first.first, len[i].second.first)]++;
            sum[max(len[i].first.second, len[i].second.second) + 1]--;
        }
        else
        {
            sum[len[i].first.first]++;
            sum[len[i].first.second + 1]--;
            sum[len[i].second.first]++;
            sum[len[i].second.second + 1]--;
        }
    }
    for (int i = 1; i <= 5e5; ++i)
    {
        sum[i] += sum[i - 1];
        if (sum[i] == n)
            S.emplace(i);
    }
    ll ans = 1;
    for (int i = 1; i <= n; ++i)
    {

        bool f1 = ok(len[i].first.first, len[i].first.second);
        bool f2 = ok(len[i].second.first, len[i].second.second);
        if (f1 && f2)
            ans = (ans * 2ll) % MOD;
        else if (f1 || f2)
            ;
        else
        {
            cout << 0;
            return;
        }
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