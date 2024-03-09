#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    string str;
    cin >> str;
    int n = str.size();
    int End = 0;
    int Z = 0;
    int sum = 0;
    for (auto v : str)
    {
        if (v == '+')
        {
            sum++;
            if (sum == 1)
                Z = 1;
        }
        else if (v == '-')
        {
            sum--;
            if (sum < End)
                End = 0;
            Z = min(Z, sum);
        }
        else if (v == '1')
        {
            if (End != 0)
            {
                cout << "NO\n";
                return;
            }
            Z = sum;
        }
        else
        {
            if (End == 0)
                End = sum;
            if ((End <= Z && End != 0) || End == 1 || End == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}