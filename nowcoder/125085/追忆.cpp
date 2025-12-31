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
     string str = R"(
     
     
     
     
     
A	好多好多 2024！	点击查看	871/1799	未通过
B	同步	点击查看	525/4244	未通过
C	高精度	点击查看	187/442	未通过
D	烟花	点击查看	300/1260	未通过
E	华灯初上	点击查看	93/230	未通过
F	Hello 2025	点击查看	343/3348	未通过
G	完满年	点击查看	703/1463	未通过
H	2025 图	点击查看	143/646	未通过
I	好多好多 2025！	点击查看	87/410	未通过
J	八进制 2025	点击查看	436/994	未通过




)";

     int p = 0;
     int ct = 0;
     while (1)
     {
          p = str.find('/', p);
          if (p == string::npos)
          {
               return;
          }
          int a = 0, b = 0;
          string B;
          int ap = p + 1;
          while (str[ap] >= '0' && str[ap] <= '9')
          {
               a = a * 10 + str[ap] - '0';
               ap++;
          }
          int bp = p - 1;
          while (str[bp] >= '0' && str[bp] <= '9')
          {
               B.push_back(str[bp]);
               bp--;
          }
          reverse(all(B));
          b = stoi(B);
          cout << a << " ";
          ct++;
          if (p == string::npos)
          {
               return;
          }
          p++;
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