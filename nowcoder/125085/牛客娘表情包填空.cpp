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
     cout << "22" << endl; // 1
     cout << "46" << endl; // 2
     cout << "49" << endl; // 3
     cout << "29" << endl; // 4 ?
     cout << "11" << endl; // 5
     cout << "45" << endl; // 6
     cout << "17" << endl; // 7 33 43
     cout << "53" << endl; // 8
     cout << "08" << endl; // 9
     cout << "13" << endl; // 10
     cout << "47" << endl; // 11
     cout << "25" << endl; // 12
     //      cout << "13" << endl; // 10
     //      cout << "47" << endl; // 11
     //      cout << "25" << endl; // 12
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