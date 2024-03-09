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
map<ll, ll> mp;
vector<int> G;
vector<int> S;
void solve()
{
    G.clear();
    S.clear();
    int n;
    cin >> n;
    for (int i = 0, tmp; i < n; ++i)
    {
        cin >> tmp;
        G.eb(tmp);
        S.eb(tmp);
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    sort(all(G), [](int a, int b)
         { return a < b; });
    for (int i = 0; i < n; ++i)
    {
        if (S[i] % 2 != G[i] % 2)
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
    cout.tie(nullptr);
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