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
map<char, int> mp;
map<char, char> win;
map<char, char> los;
void solve()
{
    win['R'] = 'P';
    win['S'] = 'R';
    win['P'] = 'S';

    los['R'] = 'S';
    los['S'] = 'P';
    los['P'] = 'R';

    mp['R'] = 0;
    mp['S'] = 1;
    mp['P'] = 2;
    mp['*'] = 3;
    int n;
    string str;
    cin >> n >> str;
    str = '*' + str;
    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
    for (int i = 1; i <= n; ++i)
    {
        char Win = win[str[i]];
        char Los = los[str[i]];
        char Pin = str[i];
        // Win
        for (int j = 0; j < 3; ++j)
            if (mp[Win] != j)
                dp[i][mp[Win]] = max(dp[i][mp[Win]], dp[i - 1][j]);
        dp[i][mp[Win]]+=1;
        //Pin
        for (int j = 0; j < 3; ++j)
            if (mp[Pin] != j)
                dp[i][mp[Pin]] = max(dp[i][mp[Pin]], dp[i - 1][j]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
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
