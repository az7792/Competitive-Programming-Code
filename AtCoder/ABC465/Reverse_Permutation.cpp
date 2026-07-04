#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}

void func(int l, int r, int p, vector<int> &ans, bool is_p, const string &str)
{
    if (l >= r)
    {
        ans[l] = p + 1;
        return;
    }
    if (is_p)
    {
        if (str[p] == 'o')
        {
            ans[l] = p + 1;
            func(l + 1, r, p - 1, ans, !is_p, str);
        }
        else
        {
            ans[r] = p + 1;
            func(l, r - 1, p - 1, ans, is_p, str);
        }
    }
    else
    {
        if (str[p] == 'o')
        {
            ans[r] = p + 1;
            func(l, r - 1, p - 1, ans, !is_p, str);
        }
        else
        {
            ans[l] = p + 1;
            func(l + 1, r, p - 1, ans, is_p, str);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> ans(n);
    func(0, n - 1, n - 1, ans, true, str);
    cout << ans << endl;
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