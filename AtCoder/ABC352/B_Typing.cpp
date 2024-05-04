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
void solve()
{
    string s, t;
    cin >> s >> t;
    set<int> ans;
    int sp = 0;
    for (int i = 0; i < t.size(); ++i)
    {
        char v = t[i];
        if (v != s[sp])
            ans.insert(i + 1);
        else
            sp++;
    }
    for (int i = 1; i <= t.size(); ++i)
    {
        if (ans.find(i) == ans.end())
            cout << i << " ";
    }
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
