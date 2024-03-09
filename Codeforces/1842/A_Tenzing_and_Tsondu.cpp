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
vector<int> G(MAX, 0);
vector<int> S(MAX, 0);
void solve()
{
    int n, m;
    ll s1, s2;
    s1 = s2 = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> G[i],s1+=G[i];
    for (int i = 1; i <= m; ++i)
        cin >> S[i],s2+=S[i];
    if(s1==s2)
        cout << "Draw\n";
    else if(s1>s2)
        cout << "Tsondu\n";
        else
        cout << "Tenzing\n";
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