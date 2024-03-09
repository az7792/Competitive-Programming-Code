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
    int n,Max=0;
    cin >> n;
    vector<int> G(300, 0);
    for (int i = 1, tmp; i <= n; ++i)
    {
        cin >> tmp;
        Max = max(Max, tmp);
        G[tmp]++;
    }
    for (int i = 0; i <= Max; ++i)
    {
        if (G[i] < G[i + 1])
        {
            cout << "NO\n";
            return;
        }
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
/*




*/