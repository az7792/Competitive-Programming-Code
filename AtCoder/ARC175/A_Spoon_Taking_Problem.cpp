#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        p[i]--;
    }
    string str;
    cin >> str;
    ll L = 1, R = 1;

    // L
    vector<bool> vis(n, 0);
    vis[p[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        int l = p[i], r = (p[i] + 1) % n;
        if (vis[l] && vis[r])
        {
            L = 0;
            break;
        }

        if (str[p[i]] == 'R')
        {
            if (vis[r] == 0)
            {
                L = 0;
                break;
            }
        }
        else if (str[p[i]] == 'L')
        {
            if (vis[l] == 1)
            {
                L = 0;
                break;
            }
        }
        else
        {
            if (vis[l] == 0 && vis[r] == 1)
            {
                L *= 2ll;
                L %= MOD;
            }
        }
        vis[l] = 1;
    }
    // R
    vis = vector<bool>(n, 0);
    vis[(p[0] + 1) % n] = 1;
    for (int i = 1; i < n; ++i)
    {
        int l = p[i], r = (p[i] + 1) % n;
        if (vis[l] && vis[r])
        {
            R = 0;
            break;
        }

        if (str[p[i]] == 'R')
        {
            if (vis[r] == 1)
            {
                R = 0;
                break;
            }
        }
        else if (str[p[i]] == 'L')
        {
            if (vis[l] == 0)
            {
                R = 0;
                break;
            }
        }
        else
        {
            if (vis[l] == 1 && vis[r] == 0)
            {
                R *= 2ll;
                R %= MOD;
            }
        }
        vis[r] = 1;
    }

    if (str[p[0]] == 'R')
        cout << R;
    else if (str[p[0]] == 'L')
        cout << L;
    else
        cout << (L + R) % MOD;
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
