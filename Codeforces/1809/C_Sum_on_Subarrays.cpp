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
vector<int> S;
void init()
{
    for (int i = 0; i <= 30; ++i)
    {
        S.eb((i + 1) * i / 2);
    }
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    int p = lower_bound(all(S), k) - S.begin();
    if (S[p] == k)
    {
        for (int i = 1; i <= p; ++i)
            cout << 1 << ' ';
        for (int i = p + 1; i <= n; ++i)
            cout << -1000 << ' ';
        cout << endl;
    }
    else
    {
        p--;
        int d = k - S[p];
        for (int i = 1; i <= d; ++i)
            cout << 2 << ' ';
        for (int i = d + 1; i <= p; ++i)
            cout << 1 << ' ';
        cout << -(p - d + 1) << ' ';
        for (int i = p + 2; i <= n; ++i)
            cout << -1000 << ' ';
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}