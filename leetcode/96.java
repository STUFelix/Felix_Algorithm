/*
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
时间复杂度 O(n)
空间复杂度 O(n)
    
*/

class Solution {
    public int numTrees(int n) {
        int[] res = new int[n+1];
        res[0]=1;
        res[1]=1;
        for(int i=2;i<=n;i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                sum =sum+res[j-1]*res[i-j];
            }
            res[i]=sum;
        }        
        return res[n];
    }
}
