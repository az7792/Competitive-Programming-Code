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
    if (str.size() < 3)
        cout << "No";
    else
    {
        if (str[0] == '<' && str.back() == '>')
        {
            for (int i = 1; i < str.size() - 1; ++i)
                if (str[i] != '=')
                {
                    cout << "No";
                    return;
                }
            cout << "Yes";
        }
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
