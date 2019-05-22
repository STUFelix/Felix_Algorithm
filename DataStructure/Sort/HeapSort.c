/*本函数完成在数值R[low]到R[high]的范围内对在位置low上的结点进行堆结构调整*/
void Sift(int R[], int low, int high) {//这里关键字的存储设定为从数组下标1开始
	int i = low;
	int j = 2 * i;	//R[j]是R[i]的左儿子
	int temp = R[i];
	while (j<=high)
	{
		if (j < high && R[j] < R[j + 1]) {
			j++;	//选取R[j]为儿子中数值最大的
		}
		if (temp < R[j]) {
			R[i] = R[j];	//将R[j]调整到双亲结点的位置上
			i = j;			//修改i和j的值，继续往下调整
			j = 2 * i;
		}
		else {
			break;		//没有变换，调整结束
		}
	}
	R[i] = temp;		//被调整结点的值放入最终位置
}

void heapSort(int R[], int n) {
	int i;
	int temp;
	for (i = n / 2; i >= 1; i--) {		//非叶子结点为n/2个（完全二叉树）
		Sift(R, i, n);		//建立初始堆
	}
	for (i = n; i >= 2; --i) {
		/*以下3句换出了根结点中的关键字，将其放入最终位置*/
		temp = R[1];
		R[i] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1);//在减少了1个关键字的无序序列中进行调整
	}

}
