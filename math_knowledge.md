#卡塔兰数  
https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0  

```java
//辗转相除法求最大公约数
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
/*其复杂度在O(log max(a,b))以内*/
```

```cpp
//判断一个数是否为素数 O(n的开方)
bool is_prime(int n){
    for(int i=2;i*i <=n; i++){
        if(n % i ==0) return false;
    }
    return n != 1;
}

//埃氏筛法 时间复杂度O(nloglogn)
int prime[MAX_N];
bool is_prime[MAX_N + 1];

int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; i++ ) is_prime[i] =true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[++p] = i;
            for(int j = 2*i; j<=n; j += i) is_prime[j] = false;
        }
    }
    return p;
}


```
