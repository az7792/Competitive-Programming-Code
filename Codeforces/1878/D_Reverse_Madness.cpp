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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "?" + s;
    vector<int> a(k + 1, 0), b(k + 1, 0);
    for (int i = 1; i <= k; ++i)
        cin >> a[i];
    for (int i = 1; i <= k; ++i)
        cin >> b[i];

    vector<int> c(k + k + 2);
    for (int i = 1, j = 1; i <= k + k; ++i)
    {
        c[i] = (i % 2 == 1 ? a[j] : b[j]);
        if (i % 2 == 0)
            j++;
    }
    int q;
    cin >> q;
    vector<int> mp(n + 1, 0);
    vector<int> df(n + 10, 0);
    for (int i = 1; i <= k; ++i)
        for (int j = a[i]; j <= b[i]; ++j)
            mp[j] = i;

    while (q--)
    {
        int x;
        cin >> x;
        int p = lower_bound(c.begin() + 1, c.begin() + k + k + 1, x) - c.begin();
        int P = (p + 1) / 2; // lp rp
        int l = min(x, a[P] + b[P] - x);
        int r = max(x, a[P] + b[P] - x);
        df[l]++;
        df[r + 1]--;
    }
    for (int i = 1; i <= n; ++i)
        df[i] += df[i - 1];
    vector<char> str(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (mp[i] == 0 || df[i] % 2 == 0)
            str[i] = s[i];
        else
        {
            int L = a[mp[i]], R = b[mp[i]];
            str[L + R - i] = s[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << str[i];
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