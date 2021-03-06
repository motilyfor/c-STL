#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

using namespace std;

static void print(const vector<int> &v)
{
    copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // cout << is_sorted(begin(v), end(v)) << '\n';

    // random_shuffle(begin(v), end(v));

    // cout << is_sorted(begin(v), end(v)) << '\n';
    // print(v);

    // sort(begin(v), end(v));

    // cout << is_sorted(begin(v), end(v)) << '\n';
    // print(v);

    // 2.ι¨εζεΊ
    random_shuffle(begin(v), end(v));

    print(v);

    partition(begin(v), end(v), [](int i){ return i < 5; });

    print(v);

    random_shuffle(begin(v), end(v));

    auto middle(next(begin(v), int(v.size()) / 2));
    partial_sort(begin(v), middle, end(v));

    print(v);

    struct mystruct
    {
        int a;
        int b;
    };

    vector<mystruct> mv{{5, 100}, {1, 50}, {-123, 1000}, {3, 70}, {-10, 20}};

    sort(begin(mv), end(mv),
         [](const mystruct &lhs, const mystruct &rhs)
         {
             return lhs.b < rhs.b;
         });

    for (const auto &[a, b] : mv)
    {
        cout << "{" << a << ", " << b << "} ";
    }
    cout << '\n';
}