* 假设现在文本串S匹配到i位置，模式串P匹配到j位置
  * 如果 j = -1，或者当前字符匹配成功（即S[i] == P[j]）,令 i++ ，j++ 继续匹配下一个字符
  * 如果 j ！= -1，且当前字符匹配失败（即S[i] != P[j]）,则令 i 不变， j = next[j]。此举 意味着匹配失败时，模式串P相对于文本串S向右移动了j - next[j]位
  
next数组各值的含义:代表当前字符之前的字符串中，有多大长度的相同前缀后缀。例如如果next[j] = k,代表j之前的字符串中有最大长度为k的相同前缀后缀。

```c
int KmpSearch(char* s,char* p){
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while(i < sLen && j < pLen){
      if(j == -1 || s[i] == p[j]){
          i++;
          j++;
      }
      else{
        j = next [j];
      }
    }
    if( j == pLen){
        return i - j;
    }else{
      return -1;
    }

}
```
next数组的求解：找最大对称长度的前缀后缀，然后整体右移一位，初值赋为-1
（当然，你也可以直接计算某个字符对应的next值，就是看这个字符之前的字符串中有多大长度的相同前缀后缀）
```c
void GetNext(char *p,int next[]){
    int pLen = strlen[p];
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < pLen -1){
        if(k == -1 || p[j] == p[k]){
            //如果p[k] == p [j],则next[j+1] = next[j] + 1 = k+1;
            ++ k;
            ++ j;
            next [j] = k;
            
          /*GetNext的优化
          为什么要优化？
             问题出在不该出现p[j] = p[ next[j] ]。为什么呢？
             理由是：当p[j] != s[i] 时，下次匹配必然是p[ next [j]] 跟s[i]匹配，如果p[j] = p[ next[j] ]，必然导致后一步匹配失败
             因为p[j]已经跟s[i]失配，然后你还用跟p[j]等同的值p[next[j]]去跟s[i]匹配，很显然，必然失配），所以不能允许p[j] = p[ next[j ]]。
             如果出现了p[j] = p[ next[j] ]咋办呢？如果出现了，则需要再次递归，即令next[j] = next[ next[j] ]。
             
             原代码： next [j] = k;
             优化后的代码： if（p[j] != p[k]）
                                next[j] = k;
                           else{
                              next[j] = next[k];
                          }
          
          */
        }
        else{
          k = next[k];
          /*为何递归前缀索引k = next[k]，就能找到长度更短的相同前缀后缀呢？这归结到next数组的含义*/
        }
    }
}
```
