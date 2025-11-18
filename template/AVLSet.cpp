#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVLSet
{
protected:
     struct Node
     {
          T key;
          Node *left, *right;
          int height, size;

          Node(const T &k) : key(k), left(nullptr), right(nullptr),
                             height(1), size(1) {}
     };

     Node *root = nullptr;

     inline int h(Node *t) const { return t ? t->height : 0; }
     inline int sz(Node *t) const { return t ? t->size : 0; }

     void update(Node *t)
     {
          t->height = max(h(t->left), h(t->right)) + 1;
          t->size = sz(t->left) + sz(t->right) + 1;
     }

     // 平衡因子
     inline int balanceFactor(Node *t)
     {
          return h(t->left) - h(t->right);
     }

     // 左旋
     Node *rotateLeft(Node *x)
     {
          Node *y = x->right;
          x->right = y->left;
          y->left = x;
          update(x);
          update(y);
          return y;
     }

     // 右旋
     Node *rotateRight(Node *y)
     {
          Node *x = y->left;
          y->left = x->right;
          x->right = y;
          update(y);
          update(x);
          return x;
     }

     // 平衡节点t
     Node *balance(Node *t)
     {
          update(t);
          int bf = balanceFactor(t);

          if (bf > 1) // 左边失衡
          {
               if (balanceFactor(t->left) < 0)
                    t->left = rotateLeft(t->left);
               return rotateRight(t);
          }
          else if (bf < -1) // 右边失衡
          {
               if (balanceFactor(t->right) > 0)
                    t->right = rotateRight(t->right);
               return rotateLeft(t);
          }
          return t;
     }

     // 插入
     virtual Node *insert(Node *t, const T &key)
     {
          if (!t)
               return new Node(key);
          if (key < t->key) // key < t->key
               t->left = insert(t->left, key);
          else if (t->key < key) // key > t->key
               t->right = insert(t->right, key);
          else           // key == k->key
               return t; // 已存在
          return balance(t);
     }

     // 最小
     Node *findMin(Node *t)
     {
          return t->left ? findMin(t->left) : t;
     }

     // 移除最小的节点，但不删除
     Node *removeMin(Node *t)
     {
          if (!t->left)
               return t->right;
          t->left = removeMin(t->left);
          return balance(t);
     }

     // 删除节点
     Node *erase(Node *t, const T &key)
     {
          if (!t)
               return nullptr;
          if (key < t->key) // <
               t->left = erase(t->left, key);
          else if (t->key < key) // >
               t->right = erase(t->right, key);
          else // ==
          {
               Node *L = t->left;
               Node *R = t->right;
               delete t;
               if (!R)
                    return L;
               Node *m = findMin(R);
               m->right = removeMin(R);
               m->left = L;
               return balance(m);
          }
          return balance(t);
     }

     // 第k大 (0-index)
     Node *kth(Node *t, int k) const
     {
          if (!t)
               return nullptr;
          int leftSize = sz(t->left);
          if (k < leftSize)
               return kth(t->left, k);
          if (k == leftSize)
               return t;
          return kth(t->right, k - leftSize - 1);
     }

     // 存在
     bool contains(Node *t, const T &key) const
     {
          if (!t)
               return false;
          if (key < t->key) // <
               return contains(t->left, key);
          else if (t->key < key) // >
               return contains(t->right, key);
          else //==
               return true;
     }

     // 找 >= key 的最小节点，同时携带当前节点在树中的排名
     // @param base 之前的节点个数
     pair<Node *, int> lower_bound_with_rank(Node *t, const T &key, int base) const
     {
          if (!t)
               return {nullptr, base}; // 路径走到底，排名就是 base

          if (t->key < key)
          {
               // 只能向右走
               // 右子树中的元素排名起点 = base + leftSize + 1
               return lower_bound_with_rank(t->right, key, base + sz(t->left) + 1);
          }
          else
          { // 左子树可能更优，基准排名不变
               auto res = lower_bound_with_rank(t->left, key, base);
               if (res.first)
                    return res;

               // 左子树没找到，这个节点就是答案，
               // 它的 rank = base + 左子树大小
               return {t, base + sz(t->left)};
          }
     }

     pair<Node *, int> upper_bound_with_rank(Node *t, const T &key, int base) const
     {
          if (!t)
               return {nullptr, base};

          if (key < t->key)
          {
               auto res = upper_bound_with_rank(t->left, key, base);
               if (res.first)
                    return res;

               return {t, base + sz(t->left)};
          }
          else
          {
               return upper_bound_with_rank(t->right, key, base + sz(t->left) + 1);
          }
     }

public:
     void insert(const T &key) { root = insert(root, key); }
     void erase(const T &key) { root = erase(root, key); }
     bool contains(const T &key) const { return contains(root, key); }
     int size() const { return sz(root); }

     // lower_bound(x) → (>=x 的节点, 它的排名)
     // 找不到时 → (nullptr, size())
     pair<const T *, int> lower_bound(const T &key) const
     {
          auto res = lower_bound_with_rank(root, key, 0);
          if (!res.first)
               return {nullptr, size()};
          return {&(res.first->key), res.second};
     }

     pair<const T *, int> upper_bound(const T &key) const
     {
          auto res = upper_bound_with_rank(root, key, 0);
          if (!res.first)
               return {nullptr, size()};
          return {&(res.first->key), res.second};
     }

     // ==
     pair<const T *, int> find(const T &key) const
     {
          auto res = lower_bound_with_rank(root, key, 0);
          if (!res.first || res.first->key < key || key < res.first->key)
               return {nullptr, size()};
          return {&(res.first->key), res.second};
     }

     const T &operator[](int k) const
     {
          Node *n = kth(root, k);
          if (!n)
               throw out_of_range("index out of range");
          return n->key;
     }
};

template <typename T>
class AVLMultiSet : public AVLSet<T>
{
protected:
     using Node = typename AVLSet<T>::Node;
     using AVLSet<T>::root;
     using AVLSet<T>::balance;

     // 重写 insert，让重复元素也插入
     Node *insert(Node *t, const T &key) override
     {
          if (!t)
               return new Node(key);
          if (key < t->key)
               t->left = insert(t->left, key);
          else // key >= t->key，重复放右边
               t->right = insert(t->right, key);
          return balance(t);
     }

public:
     void insert(const T &key) { root = insert(root, key); }
};

void testSet()
{
     AVLSet<int> s;
     set<int> S;

     vector<int> cp;
     for (int i = 0; i <= 1000000; ++i)
     {
          int tmp = rand() % 1000000;
          cp.push_back(tmp);
     }
     clock_t t1 = clock();
     for (auto v : cp)
     {
          s.insert(v);
     }
     clock_t t2 = clock();
     cout << "AVLSet insert time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     t1 = clock();
     for (auto v : cp)
     {
          S.insert(v);
     }
     t2 = clock();
     cout << "std::set insert time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     // 删除测试
     for (int i = 0; i < 10000; ++i)
     {
          int tmp = rand() % 1000000;
          S.erase(tmp);
          s.erase(tmp);
          assert(S.size() == s.size());
     }

     // ----------- 遍历测试 -----------
     vector<int> A, B;

     t1 = clock();
     for (auto &v : S)
          A.push_back(v);
     t2 = clock();
     cout << "std::set traverse time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     t1 = clock();
     for (int i = 0; i < s.size(); ++i)
          B.push_back(s[i]);
     t2 = clock();
     cout << "AVLSet traverse time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     assert(A == B);

     // find测试
     bool findok = true;
     for (int i = 0; i < 10000; ++i)
     {
          int tmp = rand() % 1000000;
          auto t1 = s.find(tmp);
          auto t2 = S.find(tmp);

          if (t2 != S.end())
          {
               if (t1.first && (*t1.first == *t2))
                    ;
               else
               {
                    findok = false;
                    break;
               }
          }
          else
          {
               if (t1.first)
               {
                    findok = false;
                    break;
               }
          }
     }

     assert(findok);

     // ----------- lower_bound / upper_bound 测试 -----------
     bool boundok = true;
     for (int i = 0; i < 1000; ++i)
     {
          int tmp = rand() % 1000000;

          // AVLSet
          auto lb1 = s.lower_bound(tmp);
          auto ub1 = s.upper_bound(tmp);

          // std::set
          auto lb2 = S.lower_bound(tmp);
          auto ub2 = S.upper_bound(tmp);

          int val_lb1 = lb1.first ? *lb1.first : -1;
          int val_ub1 = ub1.first ? *ub1.first : -1;
          int val_lb2 = lb2 != S.end() ? *lb2 : -1;
          int val_ub2 = ub2 != S.end() ? *ub2 : -1;

          if (val_lb1 != val_lb2 || val_ub1 != val_ub2)
          {
               boundok = false;
               break;
          }
     }
     assert(boundok);
}

void testMultiset()
{
     AVLMultiSet<int> s;
     multiset<int> S;

     vector<int> cp;
     for (int i = 0; i <= 100000; ++i)
     {
          int tmp = rand() % 1000; // 重复率高
          cp.push_back(tmp);
     }

     // ----------- 插入测试 -----------
     clock_t t1 = clock();
     for (auto v : cp)
          s.insert(v);
     clock_t t2 = clock();
     cout << "AVLMultiset insert time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     t1 = clock();
     for (auto v : cp)
          S.insert(v);
     t2 = clock();
     cout << "std::multiset insert time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     // ----------- 删除测试（随机删除元素） -----------
     for (int i = 0; i < 10000; ++i)
     {
          int tmp = rand() % 1000;
          S.erase(S.find(tmp)); // multiset erase 删除单个元素
          s.erase(tmp);         // AVLMultiset erase 删除单个节点
          assert(S.size() == s.size());
     }

     // ----------- 遍历测试 -----------
     vector<int> A, B;

     t1 = clock();
     for (auto &v : S)
          A.push_back(v);
     t2 = clock();
     cout << "std::multiset traverse time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     t1 = clock();
     for (int i = 0; i < s.size(); ++i)
          B.push_back(s[i]);
     t2 = clock();
     cout << "AVLMultiset traverse time: " << (t2 - t1) * 1000 / CLOCKS_PER_SEC << " ms\n";

     assert(A == B);

     // ----------- find 测试 -----------
     bool findok = true;
     for (int i = 0; i < 10000; ++i)
     {
          int tmp = rand() % 1000;
          auto t1 = s.find(tmp);
          auto t2 = S.find(tmp);

          if (t2 != S.end())
          {
               if (t1.first && (*t1.first == *t2))
                    ;
               else
               {
                    findok = false;
                    break;
               }
          }
          else
          {
               if (t1.first)
               {
                    findok = false;
                    break;
               }
          }
     }
     assert(findok);

     // ----------- lower_bound / upper_bound 测试 -----------
     bool boundok = true;
     for (int i = 0; i < 1000; ++i)
     {
          int tmp = rand() % 1000;

          // AVLMultiset
          auto lb1 = s.lower_bound(tmp);
          auto ub1 = s.upper_bound(tmp);

          // std::multiset
          auto lb2 = S.lower_bound(tmp);
          auto ub2 = S.upper_bound(tmp);

          int val_lb1 = lb1.first ? *lb1.first : -1;
          int val_ub1 = ub1.first ? *ub1.first : -1;
          int val_lb2 = lb2 != S.end() ? *lb2 : -1;
          int val_ub2 = ub2 != S.end() ? *ub2 : -1;

          if (val_lb1 != val_lb2 || val_ub1 != val_ub2)
          {
               boundok = false;
               break;
          }
     }
     assert(boundok);
}

int main()
{
     testSet();
     cout << "====================\n";
     testMultiset();
     return 0;
}