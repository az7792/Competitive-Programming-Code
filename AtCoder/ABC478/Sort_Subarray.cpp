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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    if (a.size() <= k)
    {
        cout << "Yes";
        return;
    }

    vector<int> b = a;
    sort(all(b));

    int L = -1, R = n;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
            L++;
        else
            break;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == b[i])
            R--;
        else
            break;
    }

    if (L == n - 1)
    {
        cout << "Yes";
        return;
    }

    if (R - L - 1 <= k)
    {
        cout << "Yes";
    }
    else
    {
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