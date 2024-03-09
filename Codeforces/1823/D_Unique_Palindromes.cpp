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
    vector<int> x(k + 10, 0);
    vector<int> c(k + 10, 0);
    for (int i = 1; i <= k; ++i)
        cin >> x[i];
    for (int i = 1; i <= k; ++i)
        cin >> c[i];
    if (c[1] > x[1])
    {
        cout << "NO\n";
        return;
    }
    string str;
    for (int i = 1; i <= c[1] - 3; ++i)
        str.push_back('a');
    char tmp = 'b';
    for (int i = c[1] - 3 + 1; i <= x[1]; ++i)
    {
        str.push_back(tmp);
        tmp++;
        if (tmp == 'e')
            tmp = 'b';
    }
    for (int i = 2; i <= k; ++i)
    {
        int dx = x[i] - x[i - 1];
        int dc = c[i] - c[i - 1];
        if (dc > dx)
        {
            cout << "NO\n";
            return;
        }
        for (int j = 1; j <= dc; ++j)
            str.push_back('e' + i - 2);
        // tmp = 'b';
        for (int j = 1; j <= dx - dc; ++j)
        {
            str.push_back(tmp);
            tmp++;
            if (tmp == 'e')
                tmp = 'b';
        }
    }
    cout << "YES\n"
         << str << endl;
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