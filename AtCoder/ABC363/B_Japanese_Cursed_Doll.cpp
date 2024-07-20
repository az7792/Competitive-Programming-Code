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
int ct(vector<int> a, int t)
{
    int tt = 0;
    for (int i = 1; i < a.size(); ++i)
        if (a[i] >= t)
            tt++;
    return tt;
}
void solve()
{
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int st = 0;
    if (ct(a, t) >= p)
    {
        cout << 0;
        return;
    }
    for (int i = 1; i <= 10000; ++i)
    {
        for (int j = 1; j <= n; ++j)
            a[j]++;
        if (ct(a, t) >= p)
        {
            cout << i;
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
