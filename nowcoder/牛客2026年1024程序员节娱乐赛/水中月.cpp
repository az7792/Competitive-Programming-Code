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
    int a[] = {895, 424, 546, 396, 932, 505, 619, 919, 994, 205, 602, 223, 419, 377, 686};

    std::vector<int> bits;
    for (auto v : a)
        for (int i = 9; i >= 0; --i)
            bits.push_back((v >> i) & 1);

    reverse(all(bits));

    for (int i = 0; i + 8 <= bits.size(); i += 8)
    {
        uint8_t byte = 0;
        for (int j = 0; j < 8; ++j)
            byte = (byte << 1) | bits[i + j];

        uint8_t inv = ~byte;
        //uint8_t inv = byte;
        cout << (char)inv;
    }
    cout << '\n';
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