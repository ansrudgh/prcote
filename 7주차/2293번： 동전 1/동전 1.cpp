/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2293                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: rudghrnt12 <boj.kr/u/rudghrnt12>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2293                           #+#        #+#      #+#    */
/*   Solved: 2024/08/31 03:07:05 by rudghrnt12    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include<iostream>
#include<vector>
using namespace std;

int dp(int n, int k, vector<int> coin){
    vector<int> dp(k+1, 0);
    dp[0]=1;
    for(int i=0;i<n;i++) for(int j=coin[i];j<=k;j++) dp[j]+=dp[j-coin[i]];
    return dp[k];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];
    cout<<dp(n,k,coin)<<endl;
}