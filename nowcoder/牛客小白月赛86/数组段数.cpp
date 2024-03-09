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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            sum[i] = sum[i - 1];
        else
            sum[i] = sum[i - 1] + 1;
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l] + 1 << endl;
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
