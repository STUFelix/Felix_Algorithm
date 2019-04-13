/*
迭代 iteration
http://www.pianshen.com/article/7634218855/
图解单向链表的反转

时间复杂度：O(n) 。 假设 n 是列表的长度，时间复杂度是 O(n)。

空间复杂度：O(1) 。
*/
```java
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```


/*
递归 Recursion
时间复杂度：O(n) 。 假设 n 是列表的长度，那么时间复杂度为 O(n)。

空间复杂度：O(n) 。 由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
*/
```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```
