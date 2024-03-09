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
string str;
int f(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r;)
    {
        if (str[i] == '1')
        {
            i += 3;
            ans++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    cin >> str;
    int ans = 0;
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r)
            ans += f(l, r);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
