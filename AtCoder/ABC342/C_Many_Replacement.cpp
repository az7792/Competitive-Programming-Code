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
    vector<char> mp(26);
    for (int i = 0; i < 26; ++i)
        mp[i] = i + 'a';
    string str;
    cin >> str;
    int q;
    cin >> q;
    while (q--)
    {
        char a, b;
        cin >> a >> b;
        for (int i = 0; i < 26; ++i)
            if (mp[i] == a)
                mp[i] = b;
    }
    for (auto v : str)
    {
        cout << mp[v - 'a'];
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
