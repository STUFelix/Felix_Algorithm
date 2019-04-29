#卡塔兰数  
https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0  

```java
//辗转相除法求最大公约数
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
```
