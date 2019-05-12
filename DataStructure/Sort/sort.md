# 表排序
当待排的每一个对象都拥有巨大的数据量时，如是一个多G的电影，如果按照普通的方法进行排序，每次都移动这么大的数据量，这是件很恐怖的事情。  
怎么解决？  
利用间接排序 对指向这些对象的指针进行排序（定义一个指针数组作为“表”table）  
如果仅要求按顺序输出，则输出：  
A[table[0]] , A[table[1]], …… ,A[table[N-1]]   
N个数字的排列由若干个独立的环组成。  
