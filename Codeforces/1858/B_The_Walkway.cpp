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
    ll n, m, d, st;
    cin >> n >> m >> d;
    vector<ll> s(m + 2);
    vector<ll> S(m + 2);
    s[0] = 1;
    s[m + 1] = n + 1;
    for (int i = 1; i <= m; ++i)
        cin >> s[i];
    if (s[1] == 1)
        st = 1;
    else
        st = 0;

    ll ans = 0;
    ll Max = 0, ct = 0;
    for (int i = st; i <= m; ++i)
    {
        S[i] = (s[i + 1] - s[i] - 1) / d + 1;
        ans += S[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        ll ne = (s[i + 1] - s[i - 1] - 1) / d + 1;
        ll ol = S[i - 1] + S[i];
        if (ol - ne > Max)
            ct = 1;
        else if (ol - ne == Max)
            ct++;
        Max = max(Max, ol - ne);
    }
    cout << ans - Max << ' ' << ct << endl;
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