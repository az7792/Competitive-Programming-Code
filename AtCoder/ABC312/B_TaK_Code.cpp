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
int n, m;
string str[110];
vector<pii> ans;

string L[5] = {"###.", "###.", "###.", "...."};
string R[5] = {"....", ".###", ".###", ".###"};
bool ok(int x, int y)
{

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (str[x + i][y + j] != L[i][j])
                return false;
        }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (str[x + i + 5][y + j + 5] != R[i][j])
                return false;
        }
    return true;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];
    }
    for (int i = 0; i + 8 < n; ++i)
        for (int j = 0; j + 8 < m; ++j)
        {
            if (ok(i, j))
            {
                ans.eb(i, j);
            }
        }
    sort(all(ans), [](pii a, pii b)
         {if(a.first==b.first)return a.second<b.second;
        return a.first < b.first; });
    for (auto &[x, y] : ans)
        cout << x + 1 << ' ' << y + 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}