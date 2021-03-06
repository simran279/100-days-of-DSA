/*
Anandi and Jagya were getting married again when they have achieved proper age.
Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings.
Each bessing is in the form of a string consisting of lowercase charaters(a-z) only.
But he can give only one blessing of K length because some priest told him to do so.
Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has.
Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum.
If he is not able to generate a common subsequence of length K then the happiness is 0 (zero).
Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0
*/
#include<bits/stdc++.h>
using namespace std;
int dp[102][102][102], lcs[102][102];
int main(){
    int t, m, n, k;
    cin>>t;
    string str1, str2;
    while(t--){
        cin>>str1>>str2;
        m= str1.length();
        n= str2.length();
        cin>>k;
        memset(dp, 0, sizeof(dp));
        memeset(lcs, 0, sizeof(lcs));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    for(int z=0; z<=k; z++)
                        dp[i][j][z]= 0;
                    lcs[i][j]= 0;
                }
                else if(str1[i-1]== str2[j-1]){
                    lcs[i][j]= 1+lcs[i-1][j-1];
                    for(int z=0; z<= lcs[i][j]; z++){
                        if(z==0)
                            dp[i][j][z]= 0;
                        else
                            dp[i][j][z]= max(dp[i-1][j-1][z-1]+ (int)str[i-1], dp[i-1][j-1][z]);
                    }
                }
                else{
                    lcs[i][j]= max(lcs[i][j-1], lcs[i-1][j]);
                    for(int z=0; z<=lcs[i][j]; z++)
                        dp[i][j][z]= max(dp[i-1][j][z], dp[i][j-1][z]);
                }
            }
        }
        if(lcs[m][n] <k)
            cout<<"0"<<endl;
        else
            cout<<dp[m][n][k]<<endl;
    }
}
