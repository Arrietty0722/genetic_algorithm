#include <functional>
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// int main()
// {
//     int N;
//     int tmp;
//     vector<int> A;
//     cin >> N;
//     for (int n = 0; n != N; ++n)
//     {

//         cin >> tmp;
//         A.push_back(tmp);
//     }

//     int res = 0;
//     while (true)
//     {
//         bool exist_odd = false;
//         for (int i = 0; i < N; ++i)
//         {
//             if (A[i] % 2 != 0)
//                 exist_odd = true;
//         }

//         if (exist_odd)
//             break;

//         for (int i = 0; i < N; ++i)
//         {
//             A[i] /= 2;
//         }
//         ++res;
//     }

//     cout << res << endl;

//     return 0;
// }

// int findSumOfDigits(int n)
// {
//     int sum = 0;
//     while (n > 0)
//     {
//         sum += n % 10;
//         n /= 10;
//     }
//     return sum;
// }

// int main()
// {
//     int N, A, B;
//     cin >> N >> A >> B;
//     int total = 0;
//     for (int i = 1; i <= N; ++i)
//     {
//         int sum = findSumOfDigits(i);
//         if (sum >= A && sum <= B)
//         {
//             total += i;
//         }
//     }
//     cout << total << endl;
//     return 0;
// }

int main()
{
    int N;
    int a[110];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    sort(a, a + N, greater<int>());
    int Alice = 0;
    int Bob = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0)
        {
            Alice += a[i];
        }
        else
        {
            Bob += a[i];
        }
        cout << Alice - Bob << endl;
    }
    return 0;
}