#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

void cout_size(vector<int> &v)
{
    //1.3 capacity 与 size区别
    cout << v.size();
    cout << '\n';
    cout << v.capacity();
    cout << '\n';
}

void cout_vec(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << '\n';
}

template <typename T>
void quick_remove(std::vector<T> &v, std::size_t idx)
{
    if (idx < v.size())
    {
        v.at(idx) = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove(std::vector<T> &v,
                  typename std::vector<T>::iterator it)
{
    if (it != std::end(v))
    {
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main()
{

    vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

    //1.1 remove
    const auto new_end(remove(begin(v), end(v), 2));

    // for (auto i : v)
    // {
    //     cout << i << ", ";
    // }
    // cout << '\n';
    // cout_size(v);

    //1.2 erase
    v.erase(new_end, end(v));

    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << '\n';

    //1.3 capacity 与 size区别
    // cout_size(v);

    //1.4 尾部插入
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        //cout_size(v);
    }

    //1.5 释放多余空间 跟java的gc一样，不一定执行
    v.shrink_to_fit();

    //1.6 手动指定内存空间
    v.reserve(100);

    // //1.7 无序vector删除元素
    // quick_remove(v, 10);
    // quick_remove(v, std::find(std::begin(v), std::end(v), 1));



    return 0;
}
