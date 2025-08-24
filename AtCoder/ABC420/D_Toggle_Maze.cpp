#include <bits/stdc++.h>
using namespace std;
vector<int> make1(string strArr);
vector<vector<int>> make2(string strArr);
#define endl '\n'
// leetcode--------start
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
class Solution
{
public:
     int beautifulSplits(vector<int> &nums)
     {
          return 1;
     }
};
// leetcode--------end
void solve()
{
     int n, m;
     cin >> n >> m;
     vector<string> g(n);
     vector<vector<bool>> viso(n, vector<bool>(m, false));
     vector<vector<bool>> visx(n, vector<bool>(m, false));
     pii S, G;
     for (int i = 0; i < n; ++i)
          cin >> g[i];
     for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
               if (g[i][j] == 'S')
                    S = {i, j};
               else if (g[i][j] == 'G')
                    G = {i, j};

     struct Node
     {
          int x, y, st;
          char ch;
     };

     queue<Node> Q;
     Q.push({S.first, S.second, 0, 'o'});
     viso[S.first][S.second] = true;
     while (!Q.empty())
     {
          Node t = Q.front();
          Q.pop();
          if (g[t.x][t.y] == 'G')
          {
               cout << t.st;
               return;
          }
          for (int i = 0; i < 4; ++i)
          {
               int nx = t.x + tx[i];
               int ny = t.y + ty[i];
               if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
               if (g[nx][ny] == '#')
                    continue;
               if (g[nx][ny] == t.ch || g[nx][ny] == '.' || g[nx][ny] == 'G' || g[nx][ny] == 'S')
               {
                    if (t.ch == 'o' && viso[nx][ny])
                         continue;
                    if (t.ch == 'x' && visx[nx][ny])
                         continue;
                    if (t.ch == 'x')
                         visx[nx][ny] = true;
                    else
                         viso[nx][ny] = true;
                    Q.push({nx, ny, t.st + 1, t.ch});
               }
               else if (g[nx][ny] == '?')
               {
                    char tch = (t.ch == 'o' ? 'x' : 'o');
                    if (tch == 'o' && viso[nx][ny])
                         continue;
                    if (tch == 'x' && visx[nx][ny])
                         continue;
                    if (tch == 'x')
                         visx[nx][ny] = true;
                    else
                         viso[nx][ny] = true;
                    Q.push({nx, ny, t.st + 1, tch});
               }
               // {
               //      for (int j = 0; j < 4; ++j)
               //      {
               //           int nnx = nx + tx[j];
               //           int nny = ny + ty[j];
               //           if (nnx < 0 || nny < 0 || nnx >= n || nny >= m)
               //                continue;
               //           if (g[nnx][nny] == '#')
               //                continue;
               //           if (nnx == t.x && nny == t.y)
               //           {
               //                if (g[nnx][nny] != '.' && g[nnx][nny] != 'S' && g[nnx][nny] != 'G')
               //                     continue;
               //           }
               //           if (g[nnx][nny] == '.' || g[nnx][nny] == 'G' || g[nnx][nny] == 'S')
               //           {
               //                char tch = (t.ch == 'o' ? 'x' : 'o');
               //                if (tch == 'o' && viso[nnx][nny])
               //                     continue;
               //                if (tch == 'x' && visx[nnx][nny])
               //                     continue;
               //                if (tch == 'x')
               //                     visx[nnx][nny] = true;
               //                else
               //                     viso[nnx][nny] = true;
               //                Q.push({nnx, nny, t.st + 2, tch});
               //           }
               //           else if (g[nnx][nny] == 'o' && 'x' == t.ch)
               //           {
               //                if (viso[nnx][nny])
               //                     continue;
               //                viso[nnx][nny] = true;
               //                Q.push({nnx, nny, t.st + 2, 'o'});
               //           }
               //           else if (g[nnx][nny] == 'x' && 'o' == t.ch)
               //           {
               //                if (visx[nnx][nny])
               //                     continue;
               //                visx[nnx][nny] = true;
               //                Q.push({nnx, nny, t.st + 2, 'x'});
               //           }
               //           else if (g[nnx][nny] == '?')
               //           {
               //                if (t.ch == 'o' && viso[nnx][nny])
               //                     continue;
               //                if (t.ch == 'x' && visx[nnx][nny])
               //                     continue;
               //                if (t.ch == 'x')
               //                     visx[nnx][nny] = true;
               //                else
               //                     viso[nnx][nny] = true;
               //                Q.push({nnx, nny, t.st + 2, t.ch});
               //           }
               //      }
               // }
          }
     }
     cout << -1;
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

vector<int> make1(string strArr)
{
     vector<int> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(1, strArr.size() - 2);
     stringstream stream(strArr);
     while (getline(stream, item, ','))
     {
          result.push_back(stoi(item));
     }
     return result;
}
vector<vector<int>> make2(string strArr)
{
     vector<vector<int>> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(2, strArr.size() - 4);
     stringstream stream(strArr);
     bool first = true;
     while (getline(stream, item, ']'))
     {
          if (!item.empty())
          {
               if (!first)
                    item = item.substr(2);
               vector<int> innerResult = make1("[" + item + "]");
               result.push_back(innerResult);
               first = false;
          }
     }
     return result;
}
