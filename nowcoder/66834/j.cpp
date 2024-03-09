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
    vector<int> tmp(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp[i];
        sum += tmp[i];
    }
    double L = 100, R = 0;
    for (int i = 1; i <= 100; ++i)
    {
        vector<int> t = tmp;
        t.push_back(i);
        sort(all(t));
        int tt = sum + i - t[0] - t.back();
        L = min(L, 1.0 * tt / (n - 1));
        R = max(R, 1.0 * tt / (n - 1));
    }
    cout << fixed << L << ' ' << R;
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