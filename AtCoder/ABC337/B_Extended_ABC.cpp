#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    string str;
    cin >> str;
    int L = -1, R = str.size();
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != 'A')
            break;
        else
            L = i;
    }
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] != 'C')
            break;
        else
            R = i;
    }
    for (int i = L + 1; i <= R - 1; ++i)
        if (str[i] != 'B')
        {
            cout << "No\n";
            return;
        }
    cout << "Yes";
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
