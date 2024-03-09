#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 4e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll x, Min = 0, f = 0;
    cin >> x;
    bitset<61> b(x);
    vector<int> ans;
    for (int i = 60; i >= 0; --i)
    {
        if (b[i] == 1)
        {
            if (f == 0)
            {
                f = 1;
                for (int j = 1; j <= i; ++j)
                    ans.push_back(j);
            }
            else
            {
                ans.push_back(0);
                int j = 0;
                for (j = 0; j < i; ++j)
                {
                    ans[ans.size() - 1 - j] = ans[ans.size() - 1 - j - 1];
                }
                ans[ans.size() - 1 - j] = Min--;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto v : ans)
        cout << v << " ";
    cout << endl;
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
