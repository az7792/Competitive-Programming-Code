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
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    vector<pii> pos(n + 1, {-1, -1});
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> a[i];
        if (pos[a[i]].first == -1)
            pos[a[i]].first = i;
        else
            pos[a[i]].second = i;
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
       // cout << pos[i].first << " " << pos[i].second << endl;
        if (pos[i].first + 2 == pos[i].second)
            ct++;
    }
    cout << ct;
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
