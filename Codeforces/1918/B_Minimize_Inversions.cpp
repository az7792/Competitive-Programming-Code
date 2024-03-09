#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    sort(all(a), [](pii a, pii b)
         { return a.first + a.second < b.first + b.second; });
    for (auto [x, y] : a)
        cout << x << " ";
    cout << endl;
    for (auto [x, y] : a)
        cout << y << " ";
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
