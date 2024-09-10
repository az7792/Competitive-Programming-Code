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
    int n = s.size();
    vector<string> x;
    while (true)
    {
        vector<string> tmp;
        for (int i = 0; i < n; ++i)
            if (s[i] != t[i])
            {
                char tt = s[i];
                s[i] = t[i];
                tmp.push_back(s);
                s[i] = tt;
            }
        sort(all(tmp));
        if (tmp.size() == 0)
            break;
        s = *tmp.begin();
        x.push_back(s);
    }

    cout << x.size() << endl;
    for (auto v : x)
        cout << v << endl;
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
