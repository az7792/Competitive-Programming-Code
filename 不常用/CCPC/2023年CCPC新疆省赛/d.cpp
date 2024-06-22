#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, l;
vector<int> p;
void dfs(int op)
{
    if (op == 0)
    {
        for (int i = 1; i < n; ++i)
        {
            if (p[i] > p[i - 1])
            {
                l = i;
                swap(p[i], p[i - 1]);
                dfs(1);
                swap(p[i], p[i - 1]);
            }
        }
    }
    else
    {
        for (int i = 1; i < n; ++i)
        {
            if (p[i] < p[i - 1] && i != l)
            {
                swap(p[i], p[i - 1]);
                for (auto v : p)
                    cout << v << " ";
                exit(0);
            }
        }
    }
}
void solve()
{
    cin >> n;
    p.resize(n, 0);
    for (int i = 0; i < n; ++i)
        cin >>
            p[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (p[j] > p[i])
                sum++;
    if (sum == 0 || sum == (n - 1) * n / 2)
    {
        cout << -1;
        return;
    }
    if (n <= 5)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = i + 1;
        do
        {
            int ct = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < i; ++j)
                    if (a[j] > a[i])
                        ct++;
            if (ct == sum && a != p)
            {
                for (auto v : a)
                    cout << v << " ";
                return;
            }
        } while (next_permutation(all(a)));
        cout << -1;
    }
    else
    {
        dfs(0);
        cout << -1;
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
