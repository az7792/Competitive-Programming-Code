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
    string str;
    cin >> str;
    for (auto &v : str)
        if ('a' <= v && v <= 'z')
            v = '0';
        else
            v = '1';
    // 111000
    vector<ll> one(str.size() + 2);
    vector<ll> zero(str.size() + 2);
    for (int i = 0; i < str.size(); ++i)
    {
        one[i + 1] = one[i];
        zero[i + 1] = zero[i];
        if (str[i] == '1')
            one[i + 1]++;
        else
            zero[i + 1]++;
    }
    ll ans = 1e9;
    for (int i = 1; i < str.size(); ++i)
    {
        ans = min(ans, zero[i] + one[str.size()] - one[i]);
        //cout << ans << endl;
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
