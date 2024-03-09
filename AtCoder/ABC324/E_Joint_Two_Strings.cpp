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
    string T;
    cin >> T;
    vector<ll> L(n, 0);
    vector<ll> R(n, 0);
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        ll ct = 0;
        for (int i = 0, j = 0; i < str.size() && j < T.size(); ++i)
        {
            if (T[j] == str[i])
                ct++, j++;
        }
        L[i] = ct;
        ct = 0;
        for (int i = str.size() - 1, j = T.size() - 1; i >= 0 && j >= 0; --i)
        {
            if (T[j] == str[i])
                ct++, j--;
        }
        R[i] = ct;
    }
    sort(all(L));
    sort(all(R));
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int len = T.size() - L[i];
        int p = lower_bound(all(R), len) - R.begin();
        ans += max(1ll * (ll)R.size() - p, 0ll);
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