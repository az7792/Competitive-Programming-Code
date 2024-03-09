#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    map<string, pair<bool, bool>> mp;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (str == "1")
        {
            cin >> str;
            cout << (mp[str].first ? "yes\n" : "no\n");
        }
        else if (str == "2")
        {
            cin >> str;
            cout << (mp[str].second ? "yes\n" : "no\n");
        }
        else if (str == "sudo")
        {
            cin >> str;
            if (str == "rm")
            {
                cout << "wuwuwu";
                exit(0);
            }
            else
            {
                cin >> str;
                cin >> str;
                mp[str].first = true;
                mp[str].second = true;
            }
        }
        else
        {
            cin >> str;
            if (str == "-R")
            {
                cin >> str;
                mp[str].first = false;
            }
            else
            {
                cin >> str;
                mp[str].first = false;
                mp[str].second = false;
            }
        }
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