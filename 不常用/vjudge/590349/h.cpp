#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 1e9;
    for (int i = 0; i <= 9; ++i)
    {
        int t = 0;
        vector<int> num(n, 0);
        vector<bool> f(n, 0);
        while (true)
        {
            bool ok = true;
            for (int j = 0; j < n; ++j)
                num[j] = a[j][(t % 10)] - '0';
            for (int j = 0; j < n; ++j)
                if (num[j] == i && !f[j])
                {
                    f[j] = true;
                    break;
                }
            for (int j = 0; j < n; ++j)
                if (f[j] == false)
                {
                    ok = false;
                    break;
                }
            if (ok)
                break;
            t++;
        }
        ans = min(t, ans);
    }
    cout << ans;
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