#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// R L U D
map<char, int> mp;
int tx[] = {1, -1, 0, 0};
int ty[] = {0, 0, 1, -1};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pii> xy(n + q + 100);
    for (int i = n - 1; i >= 0; --i)
        xy[i] = {n - i, 0};
    int ct = 1;
    for (int i = 1; i <= q; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            char ch;
            cin >> ch;
            int nx = xy[ct + n - 2].first + tx[mp[ch]];
            int ny = xy[ct + n - 2].second + ty[mp[ch]];
            xy[ct + n - 1] = {nx, ny};
            ct++;
        }
        else
        {
            int x;
            cin >> x;
            cout << xy[ct + n - x - 1].first <<' '<< xy[ct + n - x - 1].second<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    mp['R'] = 0;
    mp['L'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
