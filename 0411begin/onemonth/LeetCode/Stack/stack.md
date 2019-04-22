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
