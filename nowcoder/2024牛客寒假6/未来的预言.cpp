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
    scanf("BO%d", &n);
    string str;
    cin >> str;
    int win = (n + 1) / 2;
    int R = 0, P = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        char v = str[i];
        if (v == 'R')
        {
            R++;
        }
        else
        {
            P++;
        }
        if (R >= win)
        {
            cout << "kou!\n";
            cout << i + 1;
            return;
        }
        else if (P >= win)
        {
            cout << "yukari!\n";
            cout << i + 1;
            return;
        }
    }
    cout << "to be continued.\n";
    cout << str.size();
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
