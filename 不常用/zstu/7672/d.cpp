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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    vector<int> ans;
    int l = 1, r = n;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 1)
                ans.push_back(a[r--]);
            else
                ans.push_back(a[l++]);
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 1)
                ans.push_back(a[l++]);
            else
                ans.push_back(a[r--]);
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << endl;
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
