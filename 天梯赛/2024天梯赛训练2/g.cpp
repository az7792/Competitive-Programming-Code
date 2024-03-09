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
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        string str;
        cin >> str;
        int sum = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            sum += (str[n - i - 1] == 'y' ? (1 << i) : 0);
        }
        cout << (1 << n) - sum << endl;
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
