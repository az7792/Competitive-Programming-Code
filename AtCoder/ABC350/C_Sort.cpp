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
    vector<int> a(n);
    vector<int> sp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i]--;
        sp[a[i]] = i;
    }
    vector<pii> ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == i)
            continue;
        int lll = sp[i];
        int num = a[i];
        swap(a[i], a[sp[i]]);
        ans.push_back({i, sp[i]});
        sp[num] = lll;
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x + 1 << " " << y + 1 << endl;
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
