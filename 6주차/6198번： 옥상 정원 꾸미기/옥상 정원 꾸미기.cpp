/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6198                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: rudghrnt12 <boj.kr/u/rudghrnt12>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6198                           #+#        #+#      #+#    */
/*   Solved: 2024/08/20 23:33:25 by rudghrnt12    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int N;
    cin>>N;
    long long ans=0;
    vector<int> h(N,0);
    for(int i=0;i<N;i++) cin>>h[i];

    stack<int> s;
    for(int i=0;i<N;i++){
        while(!s.empty() && s.top()<=h[i]) s.pop();
        ans += s.size();
        s.push(h[i]);
    }
    cout<<ans<<endl;
}