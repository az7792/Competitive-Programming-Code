#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
char g[200][200];
void solve()
{
    int n;
    cin >> n;
    vector<ll> ans;
    for (int i = 0; i < n; ++i)
    {
        ll num;
        cin >> num;
            ans.push_back(num);

        while (ans.size() > 1 && ans.back() == ans[ans.size() - 2])
        {
            ll tmp = ans.back() + 1;
            ans.pop_back();
            ans.pop_back();
            ans.push_back(tmp);
        }
    }
    cout << ans.size();
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
