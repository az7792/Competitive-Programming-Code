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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool a = (t.substr(0, n) == s);
    bool b = (t.substr(m - n)==s);
    if(a&&b)
        cout << 0;
    else if(a&&!b)
        cout << 1;
    else if(!a&&b)
        cout << 2;
    else
        cout << 3;
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