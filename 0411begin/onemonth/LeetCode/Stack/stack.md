```java
/*字母倒叙输出，理解栈*/
private static void printReserve(char[] str){
  helper(0,str);
}
private static void helper(int index,char[] str){
  if(str == null|| index>=str.length){
      return ;
  }
  helper(index+1,str);
  System.out.print(str[index]);
}

```

------------------

```java
/**
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed. 
Given 1->2->3->4, you should return the list as 2->1->4->3.

 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head ==null || head.next ==null){
            return head;
        }
        ListNode second = head.next;
        ListNode third = second.next;
        
        second.next = head;
        head.next = swapPairs(third);
        
        return second;
    }
}

```


```java
public class Main {
    
  private static int helper_non_tail_recursion(int start, int [] ls) {
    if (start >= ls.length) {
      return 0;
    }
    // not a tail recursion because it does some computation after the recursive call returned.
    return ls[start] + helper_non_tail_recursion(start+1, ls);
  }

  public static int sum_non_tail_recursion(int [] ls) {
    if (ls == null || ls.length == 0) {
      return 0;
    }
    return helper_non_tail_recursion(0, ls);
  }

  //---------------------------------------------

  private static int helper_tail_recursion(int start, int [] ls, int acc) {
    if (start >= ls.length) {
      return acc;
    }
    // this is a tail recursion because the final instruction is the recursive call.
    return helper_tail_recursion(start+1, ls, acc+ls[start]);
  }
    
  public static int sum_tail_recursion(int [] ls) {
    if (ls == null || ls.length == 0) {
      return 0;
    }
    return helper_tail_recursion(0, ls, 0);
  }
}

```


```java
class Solution {
    double sum=0;
    public double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if( n > 0){
            sum = x*myPow(x,n-1);
        }else{
            sum = (1/x)*myPow(x,n+1);
        }
        return sum;
    }
}
/*to deal with the stackOverflow question*/
O (logn) solution in Java
public class Solution {
        public double pow(double x, int m) {
            double temp=x;
            if(m==0)
            return 1;
            temp=pow(x,m/2);
            if(m%2==0)
            return temp*temp;
            else 
            {
            if(m > 0)
                return x*temp*temp;
            else
                return (temp*temp)/x;
            }
          
    }
```
