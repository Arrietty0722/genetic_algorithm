#include <functional>
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>

template <class RandomIter, class Predicate = std::less<typename std::iterator_traits<RandomIter>::value_type>>
static inline bool iter_sorting_swap(RandomIter a, RandomIter b, Predicate pred = Predicate())
{
    if (a > b)
    {
        return iter_sorting_swap(b, a);
    }
    return pred(*b, *a) ? std::iter_swap(a, b), true : false;
}

template <class RandomIter>
void bubble_sort(RandomIter first, RandomIter last)
{
    if (last - first <= 1)
    {
        return;
    }
    for (auto i = first; i != last; ++i)
    {
        std::cout << "i :" << *i << std::endl;
        for (auto j = last - 1; j > i; --j)
        {
            iter_sorting_swap(j, j - 1);
            std::cout << " j :" << *j << std::endl;
        }
    }
}

int main()
{
    std::vector<int> vec;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::generate_n(std::back_inserter(vec), 10, mt);
    bubble_sort(begin(vec), end(vec));
    std::cout << "fin" << std::endl;
    return 0;
}