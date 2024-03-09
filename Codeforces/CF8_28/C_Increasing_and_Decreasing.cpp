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
    int x, y, n, ct = 0;
    cin >> x >> y >> n;
    vector<int> ans;
    ans.push_back(y);
    for (int i = 1; i < n; ++i)
    {
        ct += i;
        ans.push_back(y - ct);
    }
    if (ans.back() >= x)
    {
        ans.pop_back();
        ans.push_back(x);
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i] << " \n"[i == 0];
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}