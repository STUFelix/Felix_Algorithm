/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/



package leetcode;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		countAndSay(4);
	}

	public static String countAndSay(int n) {
		
		int count = 1;
		StringBuilder cur = new StringBuilder("1");
		StringBuilder prev;

		for (int i = 1; i < n; i++) {
			prev = cur;
			cur = new StringBuilder();
			char temp = prev.charAt(0);
			for (int j = 1; j < prev.length(); j++) {
				if (temp != prev.charAt(j)) {
					cur.append(count).append(prev.charAt(j));
					count = 1;
					temp = prev.charAt(j);
				} else {
					count ++;
				}
			}
		}

		return cur.toString();
	}

}
/*
Exception in thread "main" java.lang.StringIndexOutOfBoundsException: index 0,length 0
	at java.base/java.lang.String.checkIndex(String.java:3278)
	at java.base/java.lang.AbstractStringBuilder.charAt(AbstractStringBuilder.java:307)
	at java.base/java.lang.StringBuilder.charAt(StringBuilder.java:85)
	at leetcode.Main.countAndSay(Main.java:20)
	at leetcode.Main.main(Main.java:8)
*/

/*
  很是奇怪，为什么在leetcode上过得了，在eclipse上却报空指针异常错误。
*/

