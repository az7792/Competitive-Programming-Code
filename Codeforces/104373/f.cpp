#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n, sum = 0;
    cin >> n;
    priority_queue<pii> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], q.push({a[i], i}), sum += a[i];
    ll N = n - 1;
    ll ct = 1;
    while (!q.empty() && q.top().first >= N)
    {
        ll now = q.top().first - N - ct;
        ll p = q.top().second;
        q.pop();
        q.push({now, p});
        N--;
        ct++;
        if (ct >= n)
        {
            cout << "Recurrent\n";
            return;
        }
    }
    ct--;
    vector<pii> ans;
    while (!q.empty())
    {
        ans.push_back({q.top().first + ct, q.top().second});
        q.pop();
    }
    sort(all(ans), [](pii a, pii b)
         { return a.second < b.second; });
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " \n"[i == ans.size() - 1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
