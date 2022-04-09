#include <functional>
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// practice DP

// Case1
//  int main()
//  {
//      int N;
//      int tmp;
//      vector<int> A;
//      cin >> N;
//      for (int n = 0; n != N; ++n)
//      {

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

// Case2
//  int findSumOfDigits(int n)
//  {
//      int sum = 0;
//      while (n > 0)
//      {
//          sum += n % 10;
//          n /= 10;
//      }
//      return sum;
//  }

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

// Case3
//  int main()
//  {
//      int N;
//      int a[110];
//      cin >> N;
//      for (int i = 0; i < N; ++i)
//          cin >> a[i];

//     sort(a, a + N, greater<int>());
//     int Alice = 0;
//     int Bob = 0;
//     for (int i = 0; i < N; ++i)
//     {
//         if (i % 2 == 0)
//         {
//             Alice += a[i];
//         }
//         else
//         {
//             Bob += a[i];
//         }
//         cout << Alice - Bob << endl;
//     }
//     return 0;
// }

// case4
//  int n, W;
//  // int weight[110], value[110];
//  // int weight[6], value[6];
//  int dp[10][10010];

// int main()
// {
//     // cin >> n >> W;
//     // for (int i = 0; i < n; ++i)
//     //     cin >> value[i] >> weight[i];
//     n = 6;
//     W = 9;
//     int weight[6] = {2, 1, 3, 2, 1, 5};
//     int value[6] = {3, 2, 6, 1, 3, 85};
//     for (int w = 0; w <= W; ++w)
//         dp[0][w] = 0;
//     for (int i = 0; i <= n; ++i)
//     {
//         for (int w = 0; w <= W; ++w)
//         {
//             if (w >= weight[i])
//             {
//                 dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
//             }
//             else
//             {
//                 dp[i + 1][w] = dp[i][w];
//             }
//             if (dp[i][w] < 10)
//             {
//                 cout << dp[i][w] << "  ";
//             }
//             else
//             {
//                 cout << dp[i][w] << " ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Case5
int n, W;
// int weight[110], value[110];
// int weight[6], value[6];
bool dp[10][10010];

int main()
{
    // cin >> n >> W;
    // for (int i = 0; i < n; ++i)
    //     cin >> value[i] >> weight[i];
    // n = 6;
    n = 3;
    // W = 9;
    W = 10;
    // int a[n] = {2, 1, 3, 2, 1, 5};
    int a[n] = {7, 5, 3, 0};
    for (int w = 0; w <= W; ++w)
    {
        dp[0][w] = false;

        if (w == 0)
        {
            dp[0][w] = true;
        }
    }

    for (int i = 0; i <= n; ++i)
    // for (int i = 1; i <= n; ++i)
    {
        cout << a[i]
             << " "
             << " ";
        for (int w = 0; w <= W; ++w)
        {
            dp[i + 1][w] |= dp[i][w];
            if (w >= a[i])

                dp[i + 1][w] |= dp[i][w - a[i]];

            if (dp[i][w] < 10)
            {
                cout << dp[i][w] << "  ";
            }
            else
            {
                cout << dp[i][w] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

// end