/*
Noor is a teacher. She wants to give some chocolates to the students in her class.
All the students sit in a line and each of them has a score according to performance.
Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Sample Input:
4
1 4 4 6
sample Output:
6
Sample Input:
3
8 7 5
sample Output:
6
*/
#include<bits/stdc++.h>
using namespace std;
int getMin(int *arr, int n){
	int dp[n];
    dp[0]= 1;
    for(int i=1; i<n; i++){		//checking left dependency
        if(arr[i] > arr[i-1])
            dp[i]= 1+ dp[i-1];
        else
            dp[i]= 1;
    }
    //after the 1st loop the last dp[n-1] is fixed as it depends on the elements left to it
    for(int i= n-2; i>=0; i--){	//checking right dependency because elements(except n-1) depends on left as well as right
        if(arr[i] > arr[i+1] && dp[i] <= dp[i+1])	//case 8 7 5
            dp[i]= 1+ dp[i+1];
        //else remains same
    }
    int sum= 0; //total number of
    for(int i=0; i<n; i++){
        sum += dp[i];
    }
    return sum;
}
int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete []arr;
}

