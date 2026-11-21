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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int R = n - 1;
    int L = 0;
    bool Rct[3]{0};
    bool Lct[3]{0};
    for (; R >= 0; --R)
    {
        Rct[str[R] - 'A'] = 1;
        if (Rct[0] && Rct[1] && Rct[2])
        {
            break;
        }
    }
    for (; L < n; ++L)
    {
        Lct[str[L] - 'A'] = 1;
        if (Lct[0] && Lct[1] && Lct[2])
        {
            break;
        }
    }

    // cout << L << " " << R << endl;

    vector<int> la(n, -1), lb(n, -1), lc(n, -1), ra(n, -1), rb(n, -1), rc(n, -1);

    if (str[0] == 'A')
        la[0] = 0;
    else if (str[0] == 'B')
        lb[0] = 0;
    else if (str[0] == 'C')
        lc[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (str[i] == 'A')
        {
            la[i] = i;
            lb[i] = lb[i - 1];
            lc[i] = lc[i - 1];
        }
        else if (str[i] == 'B')
        {
            la[i] = la[i - 1];
            lb[i] = i;
            lc[i] = lc[i - 1];
        }
        else if (str[i] == 'C')
        {
            la[i] = la[i - 1];
            lb[i] = lb[i - 1];
            lc[i] = i;
        }
    }
    if (str[n - 1] == 'A')
        la[n - 1] = n - 1;
    else if (str[n - 1] == 'B')
        lb[n - 1] = n - 1;
    else if (str[n - 1] == 'C')
        lc[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (str[i] == 'A')
        {
            ra[i] = i;
            rb[i] = rb[i + 1];
            rc[i] = rc[i + 1];
        }
        else if (str[i] == 'B')
        {
            ra[i] = ra[i + 1];
            rb[i] = i;
            rc[i] = rc[i + 1];
        }
        else if (str[i] == 'C')
        {
            ra[i] = ra[i + 1];
            rb[i] = rb[i + 1];
            rc[i] = i;
        }
    }

    // cout << la << endl
    //      << lb << endl
    //      << lc << endl;
    // cout << ra << endl
    //      << rb << endl
    //      << rc;

    if (L >= R)
    {
        cout << 0;
        return;
    }

    ll ans = 0;
    for (int i = L; i < R; ++i)
    {
        // [L + 1, n)
        int na = ra[i + 1];
        int nb = rb[i + 1];
        int nc = rc[i + 1];
        if (na == -1 || nb == -1 || nc == -1)
            break;
        int tempL = max({na, nb, nc});
        if (tempL >= R)
            break;
        ll len = R - tempL;
        ans += len;
    }
    cout << ans;
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