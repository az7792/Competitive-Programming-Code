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
    int n, k;
    cin >> n >> k;
    vector<int> G(n + 10, 0);
    vector<int> T(n + 10, 0);
    vector<int> tmp;
    for (int i = 1; i <= n; ++i)
        cin >> G[i], T[G[i]] = i;
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (abs(i - T[i]) % k != 0)
        {
            ct++;
            tmp.eb(i);
        }
    }
    if (ct > 2||ct==1)
        cout << -1 << endl;
    else if(ct==0)
        cout << 0 << endl;
    else
    {
        int a = tmp[0];
        int b = tmp[1];
        if(abs(a-T[b])%k==0&&abs(b-T[a])%k==0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
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