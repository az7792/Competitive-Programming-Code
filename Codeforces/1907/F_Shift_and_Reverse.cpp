#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> a;
bool ok(int l, int r, int op)
{
    int n = a.size();
    bool f = true;
    if (op == 0) // up
    {
        for (int i = l + 1; i <= r; ++i)
            if (a[i] < a[i - 1])
            {
                f = false;
                break;
            }
    }
    else // down
    {
        for (int i = l + 1; i <= r; ++i)
            if (a[i] > a[i - 1])
            {
                f = false;
                break;
            }
    }
    return f;
}
void solve()
{
    a.clear();
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (ok(0, n - 1, 0))
    {
        cout << "0\n";
        return;
    }
    if (ok(0, n - 1, 1))
    {
        cout << "1\n";
        return;
    }
    int ans1 = 1e9, ans2 = 1e9;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            if (ok(i, n - 1, 0) && a[n - 1] <= a[0])
            {
                // 1
                ans1 = min(n - i, 2 + i);
            }
            break;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            if (ok(i, n - 1, 1) && a[n - 1] >= a[0])
            {
                // 2
                ans2 = min(n - i + 1, 1 + i);
            }
            break;
        }
    }
    if (ans1 == 1e9 && ans2 == 1e9)
        cout << "-1\n";
    else
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
