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
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    set<int> tmp;
    int ans = 0;
    int len = mp.size();
    for (int i = n; i >= 1; --i)
    {
        tmp.insert(a[i]);
        mp[a[i]]--;
        if (mp[a[i]] == 0)
            mp.erase(a[i]);
        if (tmp.size() == len)
        {
            ans++;
            tmp.clear();
            len = mp.size();
        }
    }
    cout << ans << endl;
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
