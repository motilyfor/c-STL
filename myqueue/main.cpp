#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <vector>

struct cmp
{
    bool operator()(const int &a, const int &b) const
    {

        return a > b; //大顶堆
    }
};

int main()
{
    using item_type = std::pair<int, std::string>;
    std::priority_queue<item_type> q;
    std::initializer_list<item_type> il{
        {1, "dishes"},
        {0, "watch tv"},
        {2, "do homework"},
        {0, "read comics"},
    };
    for (const auto &p : il)
    {
        q.push(p);
    }
    while (!q.empty())
    {
        std::cout << q.top().first << ": " << q.top().second << '\n';
        q.pop();
    }
    std::cout << '\n';

    std::vector<int> v(2);
    v[0] = 10;
    int *p = &v[0];
    std::cout << "vector第一个元素迭代指针*p=" << *p << std::endl;
    v.push_back(20);
    std::cout << "vector容量变化后原vector第1个元素迭代指针*p=" << *p << std::endl;

    std::deque<int> d(2);
    d[0] = 10;
    int *dq = &d[0];
    std::cout << "deque第一个元素迭代指针*q=" << *dq << std::endl;
    d.push_back(20);
    std::cout << "deque容量变化后第一个元素迭代器指针*q=" << *dq << std::endl;

}