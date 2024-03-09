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
bool ok(vector<vector<char>> a)
{
    int n = a[0].size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != a[n - j - 1][i])
                return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    vector<char> b(4);
    int ct = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            b[0] = a[i][j];
            b[1] = a[n - j - 1][i];
            b[2] = a[n - i - 1][n - j - 1];
            b[3] = a[n - (n - j - 1) - 1][n - i - 1];
            sort(all(b));
            for (int k = 0; k < 3;++k)
                ct += b[3] - b[k];
        }
    }
    cout << ct << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}