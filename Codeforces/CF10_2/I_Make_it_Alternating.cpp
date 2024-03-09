#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll jc[MAX];
void init()
{
    jc[0] = 1;
    for (ll i = 1; i < MAX; ++i)
        jc[i] = (jc[i - 1] * i) % MOD;
}
void solve()
{
    int n;
    string str;
    cin >> str;
    n = str.size();
    vector<pair<char, int>> S;
    for (int i = 0; i < n; ++i)
    {
        char ch = str[i];
        if (S.empty())
            S.push_back({ch, 1});
        else
        {
            if (S.back().first == ch)
            {
                S.back().second++;
            }
            else
            {
                S.push_back({ch, 1});
            }
        }
    }
    ll sum = 0, ans = 1;
    for (auto &[x, y] : S)
        sum += y, ans = (ans * y) % MOD;
    ans = (ans * jc[(sum - S.size())]) % MOD;
    cout << sum - S.size() << " " << ans << endl;
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
