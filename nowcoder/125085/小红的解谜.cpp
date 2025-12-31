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
int a[4];

void solve()
{
     cout << "Happy New Year!All Of Us Love You!";
     return;
     /*
     1. 第1个未知数字是2。
     2. 第2个未知数字是1。
     3. 如果条件一和条件二均为真，那么条件四就为假，反之，如果条件一和条件二中存在一个条件为假，条件四就为真。
     4. 第3个未知数字不是0。
     5. 如果条件一和条件四之一为假，那么条件六就为真。
     6. 第3个未知数字是3。
     7. 条件四的真值和条件二的真值应当一致。
     8. 如果条件7为假，那么条件二和条件一都为真。
     9. 第1个未知数字不是1或0。
     10. 如果条件5和条件7是正确，那么条件9也是正确的。
     11. 条件6和条件1的真值应当相反。
     */
     for (int i = 0; i <= 3; ++i)
     {
          for (int j = 0; j <= 3; ++j)
          {
               for (int k = 0; k <= 3; ++k)
               {
                    bool b[12]{};
                    b[3] = b[5] = b[8] = b[10] = b[11] = 1;

                    a[1] = i, a[2] = j, a[3] = k;
                    b[1] = a[1] == 2;
                    b[2] = a[2] == 1;
                    b[4] = a[3] != 0;
                    b[6] = a[3] == 3;
                    b[9] = (a[1] != 0 && a[1] != 1);
                    if (b[1] && b[2])
                    {
                         b[3] = !b[4];
                    }
                    else if (!b[1] || !b[2])
                    {
                         b[3] = b[4];
                    }

                    if (!b[1] || !b[4])
                    {
                         b[5] = b[6];
                    }
                    b[7] = b[4] == b[2];
                    if (!b[7])
                    {
                         b[8] = (b[1] && b[2]);
                    }
                    if (b[5] && b[7])
                    {
                         b[10] = b[9];
                    }
                    b[11] = b[6] == !b[1];
                    if (b[3] && b[5] && b[8] && b[10] && b[11])
                    {
                         cout << a[1] << " " << a[2] << " " << a[3] << endl;
                    }
               }
          }
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