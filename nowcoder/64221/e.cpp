#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
double PI = 2 * asin(1.0);
// double PI = 3.1415926;
void solve()
{
    double n;
    cin >> n;
    double A = n * cos((18.0 / 180) * PI);
    double C = n * sin((18.0 / 180) * PI);
    double B = C / tan((36.0 / 180) * PI);
    map<char, pair<double, double>> mp;
    mp['E'].first = 0, mp['E'].second = A;
    mp['A'].first = n + C, mp['A'].second = 0;
    mp['D'].first = -(n + C), mp['D'].second = 0;
    mp['B'].first = (A + B) * cos((54.0 / 180) * PI), mp['B'].second = -((A + B) * sin((54.0 / 180) * PI)) - B;
    mp['C'].first = -((A + B) * cos((54.0 / 180) * PI)), mp['C'].second = -((A + B) * sin((54.0 / 180) * PI)) - B;

    for (auto [x, y] : mp)
    {
        y.first++;
        y.first--;
        y.second++;
        y.second--;
        printf("%c: %.2lf %.2lf\n", x, y.first, y.second);
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}