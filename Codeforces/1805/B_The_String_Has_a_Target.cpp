#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[str[i]].push_back(i);
    for (auto &[x, y] : mp)
    {
        if (y.size() != 0)
        {
            int p = y.back();
            cout << str[p];
            for (int i = 0; i < n; ++i)
            {
                if (i != p)
                    cout << str[i];
            }
            cout << endl;
            return;
        }
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