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
    string str = "wbwbwwbwbwbwwbwbwwbwbwbw";
    // w7 b5
    int a, b;
    cin >> a >> b;
    int num = min((a / 7), (b / 5));
    a -= num * 7;
    b -= num * 5;
    for (int i = 0; i < str.size(); ++i)
        for (int j = i; j < str.size(); ++j)
        {
            int cb = count(str.begin() + i, str.begin() + j + 1, 'b');
            int cw = count(str.begin() + i, str.begin() + j + 1, 'w');
            if (cb == b && cw == a)
            {
                cout << "Yes\n";
                return;
            }
        }
    cout << "No\n";
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
