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
vector<int> G(MAX, 0), sum(MAX, 0);
void solve()
{
    int n;
    set<int> S;
    S.emplace(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i];
        sum[i] = i == 1 ? G[i] : sum[i - 1] ^ G[i];
        S.emplace(sum[i]);
    }
    int ans = 0;
    for(auto v:S)
        for(auto v1:S)
            ans = max(ans, v ^ v1);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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