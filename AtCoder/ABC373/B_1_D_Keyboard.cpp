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
    string s;
    cin >> s;
    vector<int> a(26);
    for (int i = 0; i < s.size(); ++i)
        a[s[i] - 'A'] = i;
    int ans = 0;
    int now = a[0];
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        ans += abs(a[i - 'A'] - now);
        now = a[i - 'A'];
    }
    cout << ans;
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