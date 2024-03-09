#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 5e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<int> G(n);
    vector<ll> sum(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> G[i];
    }
    sort(all(G));
    if (G[0] != 1)
    {
        cout << "NO\n";
        return;
    }
    sum[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (G[i] > sum[i - 1])
        {
            cout << "NO\n";
            return;
        }
        sum[i] = sum[i - 1] + G[i];
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}