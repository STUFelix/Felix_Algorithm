#外部排序
外部排序指的是大文件的排序，即待排序的记录存储在外存储器上，待排序的文件无法一次装入内存，
需要在内存和外部存储器之间进行多次数据交换，以达到排序整个文件的目的。  
— — — —归并排序  

#冒泡排序 插入排序  
交换两个相邻元素正好消去1个逆序对。  
插入排序的时间复杂的：（I表示逆序对的数量） T(N,I) = O(N+I)  
定理：任意N个不同元素组成的序列平均具有N(N-1)/4个逆序对。  
定理：任意仅以交换相邻两元素来排序的算法，其平均时间复杂度为Ω(N^2)。  
这意味着：要提高算法效率，我们必须  
1、每次消去不止一个逆序对。  
2、每次交换相隔较远的两个元素。  

```C
void InsertionSort(ElementType A[],int N){
  int P,i;
  ElementType temp;
  
  for(p=1;p<N;p++){
    temp = A[p];//取出未排序的第一个元素
    for(i=p;i>0 &&A[i-1]>temp;i--){
      A[i]=A[i-1];//依次与已排序的比较并后移
     }
     A[i] =temp;//放进合适的位置
  }
}
```

#希尔排序 by Donald shell  
定义增量序列Dm>Dm-1>……>D1=1;  
对每个Dk进行"Dk-间隔"排序  
注意：“Dk-间隔”有序的序列，在执行"Dk-1 ——间隔"排序后，仍然是"Dk-间隔"有序的。  
  增量元素不互质，则小增量可能根本不起作用。  
故有 Hibbard增量序列(Dk = 2^k-1)    Sedgewick增量序列{1,5,19,41,109,...}  

```C
void ShellSort( ElementType A[], int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
     int Si, D, P, i;
     ElementType Tmp;
     /* 这里只列出一小部分增量 */
     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
      
     for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
         ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
 
     for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
         for ( P=D; P<N; P++ ) { /* 插入排序*/
             Tmp = A[P];
             for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                 A[i] = A[i-D];
             A[i] = Tmp;
         }
}
```
