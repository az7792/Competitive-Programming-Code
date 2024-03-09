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
bool ok(int x)
{
    if (x == 1)
        return 0;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0)
            return 0;
    return 1;
}
vector<int> ans;
bool f(int x)
{

    bool f = 0;
    for (int a = 0; a < ans.size(); ++a)
        for (int b = a + 1; b < ans.size(); ++b)
            for (int c = b + 1; c < ans.size(); ++c)
                if (ans[a] * ans[b] * ans[c] == x)
                {
                    return 1;
                }
    return 0;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = 1; i <= 100; ++i)
        if (ok(i))
            ans.push_back(i);
    for (int i = l; i <= r; ++i)
    {
        if (f(i) == 1)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1;
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
