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
