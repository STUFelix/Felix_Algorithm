```java  
/*
经典dp：爬楼梯
不难发现，这个问题可以被分解为一些包含最优子结构的子问题，即它的最优解可以从其子问题的最优解来有效地构建，我们可以使用动态规划来解决这一问题。

第 i 阶可以由以下两种方法得到：

在第 (i-1) 阶后向上爬一阶。

在第 (i-2) 阶后向上爬 22 阶。

所以到达第 i 阶的方法总数就是到第 (i-1) 阶和第 (i-2)阶的方法数之和。

令 dp[i] 表示能到达第 i 阶的方法总数：

dp[i]=dp[i-1]+dp[i-2]
dp[i]=dp[i−1]+dp[i−2]
*/
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}


爬楼梯： 时间复杂度 O(log(n))
空间复杂度O(1)的算法
Fibonacci Formula

public class Solution {
    public int climbStairs(int n) {
        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
}
```



优化原则：最优子结构性质  
优化函数的特点：任何最短路的子路径相对于子问题始、终点最短  
不满足优化原则，不能用动态规划  
[动态规划反例](https://github.com/STUFelix/Felix_Algorithm/blob/master/image/%E6%9C%80%E4%BC%98%E5%8C%96%E5%8E%9F%E5%88%99.jpg)  

动态规划设计要素：  
1.问题建模，优化的目标函数是什么？约束条件是什么？  
2.如何划分子问题（边界）？  
3.问题的优化函数值与子问题的优化函数值存在着什么依赖干洗？（递推方程）  
4.是否满足优化原则？  
5.最小子问题怎么样界定？其优化函数值，即初值等于什么？  

Catalan数 stirling公式  
