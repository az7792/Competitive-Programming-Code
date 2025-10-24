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

string codepoint_to_utf8(unsigned int cp)
{
     string utf8;
     if (cp <= 0x7F)
     {
          utf8 += static_cast<char>(cp);
     }
     else if (cp <= 0x7FF)
     {
          utf8 += static_cast<char>(0xC0 | ((cp >> 6) & 0x1F));
          utf8 += static_cast<char>(0x80 | (cp & 0x3F));
     }
     else if (cp <= 0xFFFF)
     {
          utf8 += static_cast<char>(0xE0 | ((cp >> 12) & 0x0F));
          utf8 += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
          utf8 += static_cast<char>(0x80 | (cp & 0x3F));
     }
     else if (cp <= 0x10FFFF)
     {
          utf8 += static_cast<char>(0xF0 | ((cp >> 18) & 0x07));
          utf8 += static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
          utf8 += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
          utf8 += static_cast<char>(0x80 | (cp & 0x3F));
     }
     return utf8;
}

void solve()
{
     // int n = 22;
     // cin >> n;
     // while (n--)
     // {
     //      string str;
     //      cin >> str;
     //      unsigned long long decimal = std::stoull(str, nullptr, 2);
     //      //std::cout << decimal << endl;
     //      cout << codepoint_to_utf8(decimal) << endl;
     // }
     cout << "1024";
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