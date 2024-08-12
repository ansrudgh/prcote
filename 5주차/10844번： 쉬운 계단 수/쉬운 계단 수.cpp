/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10844                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: rudghrnt12 <boj.kr/u/rudghrnt12>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10844                          #+#        #+#      #+#    */
/*   Solved: 2024/08/12 23:32:36 by rudghrnt12    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

long long stair(int N)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));
    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][8];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= 1'000'000'000;
        }
    }
    long long rt = 0;
    for (int i = 0; i <= 9; i++)
        rt += dp[N][i];
    return rt % 1'000'000'000;
}

int main()
{
    int N;
    cin >> N;
    cout << stair(N) << endl;
}