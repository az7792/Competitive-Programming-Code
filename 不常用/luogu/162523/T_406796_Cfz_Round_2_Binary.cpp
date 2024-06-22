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
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];
    b[0] = a[0];
    for (int i = 1; i <= n; ++i)
        b[i] = b[i - 1] ^ a[i];
    vector<int> ans(n + 10, 0);
    if (a[0] == 0)
    {
        int len = n;
        ans[len - 1] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        if (a[i] == b[i - 1])
        {
            int len = n - i;
            ans[len - 1] = 1;
        }
    }
    if (a[n] == b[n - 1])
    {
        int c = 1;
        for (int i = 0; i <= n + 5; ++i)
        {
            int tc = c;
            c = ans[i] & c;
            ans[i] = ans[i] ^ tc;
            if (c == 0)
                break;
        }
    }

    for (int i = n + 5; i >= 0; --i)
    {
        if (ans[i] == 1)
        {
            for (int j = i; j >= 0; --j)
                cout << ans[j];
            cout << endl;
            return;
        }
    }
    cout << 0 << endl;
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
