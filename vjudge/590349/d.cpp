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
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<bool> f(w + 1, 0);
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] <= w)
            f[a[i]] = true;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[i] + a[j] <= w)
                f[a[i] + a[j]] = true;
            for (int k = j + 1; k < a.size(); ++k)
                if (a[i] + a[j] + a[k] <= w)
                    f[a[i] + a[j] + a[k]] = true;
        }
    }
    int ct = 0;
    for (int i = 1; i <= w; ++i)
        if (f[i])
            ct++;
    cout << ct;
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