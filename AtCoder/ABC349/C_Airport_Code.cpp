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
    vector<int> p(3, -1);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == t[0] + 32)
        {
            p[0] = i;
            break;
        }
    }
    if (p[0] != -1)
    {
        for (int i = p[0] + 1; i < s.size(); ++i)
        {
            if (s[i] == t[1] + 32)
            {
                p[1] = i;
                break;
            }
        }
    }
    if (p[1] != -1)
    {
        for (int i = p[1] + 1; i < s.size(); ++i)
        {
            if (s[i] == t[2] + 32)
            {
                p[2] = i;
                break;
            }
        }
    }
    if (p[2] != -1)
        cout << "Yes";
    else
    {
        if (p[1] != -1 && t[2] == 'X')
            cout << "Yes";
        else
            cout << "No";
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
