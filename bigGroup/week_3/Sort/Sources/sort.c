#include"sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//主菜单
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t第三周大组作业排序算法\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.创建文件\t\t|\n");
	printf("|\t2.读取文件\t\t|\n");
	printf("|\t3.测试不同大数据量用时\t|\n");
	printf("|\t4.测试大量小数据量用时\t|\n"); 
	printf("|\t5.对文件数据排序\t|\n");
	printf("|\t6.测试颜色排序\t\t|\n");
	printf("|\t7.寻找第k大的数      \t|\n");
	printf("|\t8.寻找第k小的数\t\t|\n");  
	printf("|\t9.退出系统\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 

//大数据测试菜单
void big_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.10000个\t\t|\n");
	printf("|\t2.50000个\t\t|\n");
	printf("|\t3.200000个\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要测试的数量：\t\n"); 
}

//颜色排序菜单
void color_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.使用测试数组\t\t|\n");
	printf("|\t2.自主随机（不确保正确）\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要的操作：\t\n"); 
}

//排序算法菜单
void sort_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.插入排序\t\t|\n");
	printf("|\t2.归并排序\t\t|\n");
	printf("|\t3.快速排序\t\t|\n");
	printf("|\t4.计数排序\t\t|\n");
	printf("|\t5.基数计数排序\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要的算法：\t\n");
} 


//插入排序
void insertSort(int *a,int n){
	int i, j, k;
	for(i = 0; i < n; i++){
		if(a[i] < a[i-1]){
			k = a[i];
			for(j = i - 1; j>=0 && a[j] > k ; j--){
				//前面排好的数往后移 
				a[j+1] = a[j];
			}
			a[j+1] = k; //把值插入进去 
		}
	}
} 

//归并排序
void MergeSort(int *a,int begin,int end,int *temp){
	int mid = 0; 
	if(begin < end){
		mid = (begin+end)/2;//取中间 
		
		MergeSort(a,begin,mid,temp);//一左 
		
		MergeSort(a,mid+1,end,temp);//一右 
		
		MergeArray(a,begin,mid,end,temp);
		
	}
}

//归并排序，合并数组
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
	temp = (int*)malloc((end-begin+1)*sizeof(int));//创建一个一样大小的数组 
	int i = begin;//第一个数组 
	int j = mid+1;//第二个数组 
	int k;	
	for(k = 0; i <= mid && j <= end; ) {
		if(a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else if(a[i] > a[j] ){
			temp[k++] = a[j++];
		}
	}
	//剩余数字依次填入 
	while(i <= mid) {
		temp[k++] = a[i++];
	}
	while(j <= end) {
		temp[k++] = a[j++];
	}
	//赋值回原数据 
	for(i = 0; i < end-begin+1; i++) {
		a[begin+i] = temp[i];
	}
	//释放资源 
	free(temp);
}

//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end){
	//递归条件 
	if(begin < end){
		int ret = Partition(a,begin,end); //找出驱轴位置 
		QuickSort_Recursion(a,begin,ret-1); //左边 
		QuickSort_Recursion(a,ret+1,end); //右边 
	}
}

//快速排序（枢轴存放）
int Partition(int *a, int begin, int end){
	int temp = a[begin];
	while(begin < end){
		while(begin < end && a[end] >= temp){
			--end;
		}
		a[begin] = a[end];
		while(begin < end && a[begin] <= temp){
			++begin;
		}
		a[end] = a[begin];
	}
	a[begin] = temp;//把驱轴放回数组
	return begin; 
}

//计数排序
void CountSort(int *a, int size , int max){
	if(size == 2){
		printf("数组长度不足2，无法排序\n");
		return ; 
	}
	//获取最小值 
	int min = Min(a,size);
	
	int b[max-min+1];//创建一个数组长度
	memset(b,0,sizeof(b));//初始化该数组
	
	int i,j,k;
	//对b数组进行计数
	for(i=0;i<size;i++){
		b[a[i]-min]++;
	} 
	//返回值并且排好序 
	for(i=0,j=0;j<max-min+1;j++){
		for(k=0;k<b[j];k++){
			a[i++] = j+min;
		}
	}
	
}

//基数计数排序 
void RadixCountSort(int *a,int size){
	int i ;
	int j = 1;
	int max = Max(a,size);
	int *temp = (int *)malloc(size * sizeof(int));//暂存数组 
	//循环最大值的位数次数 
	while(max / j > 0){
		//设置一个计数数组
		int count[10] = {0};
		
		for(i=0;i<size;i++){
			count[a[i] / j % 10]++; //取每个数的位数上个值0，1，2... 
		} 
		//把每个计数的数据累加起来，方便数据按位置存放 
		for(i=1;i<10;i++){
			count[i] = count[i] + count[i-1];
		}
		//从后往前放
		for(i = size-1 ;i >= 0; i--){
			temp[count[a[i]/j % 10]-1] = a[i];
			count[a[i]/j % 10]--;
		} 
		for(i = 0; i <size ;i++){
			a[i] = temp[i];
		}
		//个，十，百... 
		j = j *10;
	}
	
}

//获取数组中最大值
int Max(int *a, int length){
	int i;
	int max = a[0];
	for(i=0; i<length; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
} 

//获取数组中最大值
int Min(int *a, int length){
	int i;
	int min = a[0];
	for(i=0; i<length; i++){
		if(a[i] < min){
			min = a[i];
		}
	}
	return min;
} 


//还没搞好 
//颜色排序
void ColorSort(int *a,int size){
	int *p0 = a;
	int *p1 = a;
	int *p2 = a + size - 1;
	int temp;
	
	while(1){
		if(*p1 == 1){
			if(p1 == p2) break;
			p1++;
		}
		//先判断p1是否为2 
		if(*p1 == 2){
			if(p1 == p2) break;
			temp = *p2;
			*p2 = *p1;
			*p1 = temp;
			p2--; //交换数值并让p2向前移动一个位置 
			//再判断p1是否为0 
			if(*p1 == 0){
				if(p1 == p2) break;
				temp = *p0;
				*p0 = *p1;
				*p1 = temp;
				p0++; //交换数值并让p0向后移动一个位置 
			}
			p1++; 
		}
		//先判断p1是否为0
		if(*p1 == 0){
			if(p1 == p2) break;
			temp = *p0;
			*p0 = *p1;
			*p1 = temp;
			p0++;
			if(*p1 == 2){
				if(p1 == p2) break;
				temp = *p2;
				*p2 = *p1;
				*p1 = temp;
				p2--;
				}
			p1++;	
		}
		 if(p1 == p2){
		 	return;
		 }
	}
}


//输出数组
void Lprintf(int *a,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
} 


//创建文件保存数据
void saveFile(int *a, int size ,const char *filename){
	FILE *file;
	file = fopen(filename,"w");
	if(file == NULL){
		printf("创建文件失败\n");
		return ;
	}
	int i;
	for(i=0; i<size; i++){
		fprintf(file, "%d\t", a[i]);
	}
	printf("保存成功\n");
	//关闭文件
	fclose(file); 
}

//读取文件数据
void readFile(int *a, int size, const char *filename){
	FILE *file;
	file = fopen(filename,"r");
	if(file == NULL){
		printf("读取文件失败\n");
		return ;
	}
	int i;
	for(i=0;i<size;i++){
		fscanf(file ,"%d",&a[i]);
	}
	printf("读取成功\n");
	fclose(file);
} 

//寻找第k数
void FindNumber(int *a, int size){
	printf("啥也不不会\n");
} 



int main(){
	//用于测试大数据 
	int n;
	int i,j;
	int n1;
	//用于1，2，5 
	int scope;
	//用于测试小数据 
	int num;
	int times;
	//存放随机数 
	int randomNum;
	//设置随机数种子
	srand(time(0));
	//用于颜色排序的数组 
	//int *colorarr[];
	//记录时间 
	clock_t start; 
	clock_t end;
	clock_t totalTime;
	//承载数组 
	int *temp;
	//用于5 
	int *arr1 = (int *)malloc(scope*sizeof(int));
	int max5;
	//用于7，8 
	int k;
	//判断文件
	int flag1 = 0;
	int flag2 = 0; 
	int flag3 = 0;
	while(1){
		//主菜单 
		welcome();
		char s = getch();
		switch(s){
			case '1': //创建文件保存一个数组
			system("cls");
			printf("输入你想创建的数组的大小：\n");
			printf("第一次先个位数，然后不超过15最好吧，否则程序闪退\n");
			scanf("%d",&scope);
			int *arr = (int *)malloc(scope*sizeof(int));
			for(i=0;i<scope;i++){
				arr[i] = rand();
			}
			saveFile(arr, scope ,"testdemo.txt");	
			flag1 = 1;
			system("pause");
			system("cls");
			break;
			case'2': //读取文件
			system("cls");
			if(flag1 == 0){
				printf("还没有创建文件\n");
				system("pause");
				system("cls");
				break;
			}
			readFile(arr1, scope, "testdemo.txt");
			Lprintf(arr1,scope);
			printf("\n");
			flag2 = 1;
			flag3 = 1;
			system("pause");
			system("cls");
			break;
			case '3': 
			//大数据测试 
			system("cls");
			big_welcome();
			char s3 = getch();
			switch(s3){
				case '1':{
				system("cls");
				//10000
				n = 10000;
				int *a = (int *)malloc(n*sizeof(int));
				int *b = (int *)malloc(n*sizeof(int));
				int *c = (int *)malloc(n*sizeof(int));
				int *d = (int *)malloc(n*sizeof(int));
				int *e = (int *)malloc(n*sizeof(int));
				for(i = 0; i < n; i++){
					a[i] = b[i] = c[i] = d[i] = e[i] = rand();//确保每个排序测试的数组内容一样 
				}
				printf("以下是10000个数据的测试结果:\n");
				//插入排序 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("插入排序:%d ms\n", end-start);
				//归并排序 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("归并排序:%d ms\n", end-start);
				//快速排序(递归版)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("快速排序:%d ms\n", end-start);
				//计数排序 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("计数排序:%d ms\n", end-start);
				//基数计数排序 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("基数计数排序:%d ms\n", end-start);
				
				//printf("10000\n");
				system("pause");
				system("cls");
				break;
				}
				case '2':{
				system("cls");
				 //50000
				n = 50000;
				int *a = (int *)malloc(n*sizeof(int));
				int *b = (int *)malloc(n*sizeof(int));
				int *c = (int *)malloc(n*sizeof(int));
				int *d = (int *)malloc(n*sizeof(int));
				int *e = (int *)malloc(n*sizeof(int));
				for(i = 0; i < n; i++){
					a[i] = b[i] = c[i] = d[i] = e[i] = rand();//确保每个排序测试的数组内容一样 
				}
				printf("以下是50000个数据的测试结果:\n");
				//插入排序 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("插入排序:%d ms\n", end-start);
				//归并排序 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("归并排序:%d ms\n", end-start);
				//快速排序(递归版)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("快速排序:%d ms\n", end-start);
				//计数排序 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("计数排序:%d ms\n", end-start);
				//基数计数排序 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("基数计数排序:%d ms\n", end-start);
				//printf("50000\n");
				system("pause");
				system("cls");
				break;
				}
				case '3':{
				system("cls");
				//200000
				n = 200000;
				int *a = (int *)malloc(n*sizeof(int));
				int *b = (int *)malloc(n*sizeof(int));
				int *c = (int *)malloc(n*sizeof(int));
				int *d = (int *)malloc(n*sizeof(int));
				int *e = (int *)malloc(n*sizeof(int));
				
				for(i = 0; i < n; i++){
					a[i] = b[i] = c[i] = d[i] = e[i]= rand();//确保每个排序测试的数组内容一样 
				}
				printf("以下是200000个数据的测试结果:\n");
				//插入排序 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("插入排序:%d ms\n", end-start);
				free(a);
				//归并排序 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("归并排序:%d ms\n", end-start);
				free(b);
				//快速排序(递归版)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("快速排序:%d ms\n", end-start);
				free(c);
				//计数排序 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("计数排序:%d ms\n", end-start);
				//基数计数排序 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("基数计数排序:%d ms\n", end-start);
				//printf("200000\n");
				system("pause");
				system("cls");
				break;
				}
			}
			break;
			
			case '4': //大量小数据的测试
			system("cls");
			printf("想要多少个数据：(如100)\n");
			scanf("%d",&num);
			printf("排序多少次:(如100，100000)\n");
			scanf("%d",&times);
			//动态数组 
			int *a = (int *)malloc(num*sizeof(int));
			int *b = (int *)malloc(num*sizeof(int));
			int *c = (int *)malloc(num*sizeof(int));
			int *d = (int *)malloc(num*sizeof(int));
			int *e = (int *)malloc(num*sizeof(int));
			
			//插入排序
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					a[i] = rand(); 
				}
				start = clock();
				insertSort(a,num);
				end = clock();
				totalTime += (end - start);
			}
			printf("插入排序:%d ms\n", totalTime);	
			
			//归并排序 	
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					b[i] = rand(); 
				}
				start = clock();
				MergeSort(b,0,num-1,temp);
				end = clock();
				totalTime += (end - start);
			}
			printf("归并排序:%d ms\n", totalTime);	
				
			//快速排序(递归版)	
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					c[i] = rand(); 
				}	
				start = clock();
				QuickSort_Recursion(c, 0, num-1);
				end = clock() ;
				totalTime += (end - start);
			}
				printf("快速排序:%d ms\n", totalTime);
				
				//计数排序
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					d[i] = rand(); 
				}
				int max = Max(d,num);
				start = clock();
				CountSort(d, num ,max);
				end = clock() ;
				totalTime += (end - start);
			}
				printf("计数排序:%d ms\n", totalTime);
				
				//基数计数排序 
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					e[i] = rand(); 
				}
				start = clock();
				RadixCountSort(e,num);
				end = clock();
				totalTime += (end - start);
			}
				printf("基数计数排序:%d ms\n", totalTime);
			
			system("pause");
			system("cls");
			break;
		
			case '5': //对文件的数组进行排序
			system("cls");
			if(flag2 == 0){
				printf("还没有读取文件或者创建文件\n");
				system("pause");
				system("cls");
				break;
			}
			if(flag3 == 0){
				printf("已完成排序，可以重新读取一遍文件，再进行此操作\n");
				system("pause");
				system("cls");
				break;
			}
			system("cls");
			printf("注意：\n一次只能选择一种排序算法！！！\n");
			printf("若还需要使用其他的，就重新读取文件即可~~~\n");
			printf("然后再到此地选择其中之一排序算法~~~\n");
//			printf("以此类推\n");
			sort_welcome();
			char s5 = getch();
			switch(s5){
				case '1': //插入算法
				system("cls");
				start = clock();
				insertSort(arr1,scope);
				end = clock();
				printf("排序后：\n");
				Lprintf(arr1,scope);
				printf("用时：%d ms\n",end - start);
				break;
				case '2': //归并算法
				system("cls");
				start = clock();
				MergeSort(arr1,0,scope-1,temp); 
				end = clock();
				printf("排序后：\n");
				Lprintf(arr1,scope);
				printf("用时：%d ms\n",end - start);
				break;
				case '3': //快速排序 
				system("cls");
				start = clock();
				QuickSort_Recursion(arr1, 0, scope-1);
				end = clock();
				printf("排序后：\n");
				Lprintf(arr1,scope);
				printf("用时：%d ms\n",end - start);
				break;
				case '4': //计数排序 
				system("cls");
				max5 = Max(arr1,scope);
				start = clock();
				CountSort(arr1, scope , max5); 
				end = clock();
				printf("排序后：\n");
				Lprintf(arr1,scope);
				printf("用时：%d ms\n",end - start);
				break;
				case '5': //基数计数排序 
				system("cls");
				start = clock();
				RadixCountSort(arr1,scope); 
				end = clock();
				printf("排序后：\n");
				Lprintf(arr1,scope);
				printf("用时：%d ms\n",end - start);
				break;
			}
			flag3 = 0;
			system("pause");
			system("cls");
			break;
			case '6': {
				system("cls");
				color_welcome();
				char s6 = getch();
				switch(s6){
					case '1':{
						int testColor[] = {1,2,0,0 ,1 ,0 ,2 ,1, 1 , 2, 1,1, 0 ,1, 0, 1,0 , 0 , 2 ,2 ,1 ,0 ,1 ,1};
						printf("测试数组:\n");
						Lprintf(testColor,24);
						ColorSort(testColor,24); //进行颜色排序
						printf("排序后为：\n"); 
						Lprintf(testColor,24);
						system("pause");
						system("cls");
						break;
				}
			case '2':{
			//颜色排序
			printf("输入想要的数组长度：\n");
			scanf("%d",&n1);
			int* colorarr = (int *)malloc(n1*sizeof(int));
			for(i=0;i<n1;i++){
				randomNum = rand() % 3; //0-2的数
				colorarr[i] = randomNum; 
			}
			printf("随机生成的数组为：\n");
			Lprintf(colorarr,n1);
			int flag = 0;
			for(i = 0; i<n1 ;i++){
				if(colorarr[i] == 1){
				flag = 1;
				}
				}
			if(flag == 0){
			printf("数组中缺少1，不能排序\n");
			system("pause");
			system("cls");
			break;
			}else{
				ColorSort(colorarr,n1); //进行颜色排序
			printf("排序后为：\n"); 
			Lprintf(colorarr,n1);
			system("pause");
			system("cls");
			break;
			}
			}	
							
		}
			system("cls");
			break;
		}
		
		case '7': //寻找第k大的数
		system("cls");
		if(flag2 == 0){
				printf("还没有读取文件或者创建文件\n");
				system("pause");
				system("cls");
				break;
			}
			while(1){
				printf("想要找第几大的数:\n");
				scanf("%d",&k);
				if( k> scope){
					printf("超出范围，请重新输入\n");}
					else{
						break;
					}
			}
		
		QuickSort_Recursion(arr1, 0, scope-1);
		printf("第%d大的数为:%d\n",k,arr1[scope-k]);
		 system("pause");
			system("cls");
			break;
			case '8': //寻找第k小的数 
			system("cls");
		if(flag2 == 0){
				printf("还没有读取文件或者创建文件\n");
				system("pause");
				system("cls");
				break;
			}
			while(1){
				printf("想要找第几小的数:\n");
				scanf("%d",&k);
				if( k> scope){
					printf("超出范围，请重新输入\n");}
					else{
						break;
					}
			}
		QuickSort_Recursion(arr1, 0, scope-1);
		printf("第%d小的数为:%d\n",k,arr1[k-1]);
		 system("pause");
			system("cls");
			break;
			case '9': //退出系统
		printf("期待下次再见\n");
		return ;
			default: //输入错误
		printf("请重新输入：\n");
		system("pause");
		system("cls");
		break;
		}
		 
	}
	
	//int a[] = {222004,222143,243554,275275,297874,214531,221132,4,232994};
	//int *temp; //承载数组指针temp
	//int length = sizeof(a) / sizeof(int);
	//int max = Max(a,length); //数组中最大值 
	
	//for(i=0; i<9; i++){
	//	printf("%d->",a[i]);
	//}
	//printf("=============\n");
	
	//for(i=0; i<9; i++){
	//	printf("%d->",a[i]);
	//}
	//printf("=============\n");
	//int b[] = {1,2,0,2,1,0,1,2,0,1};
	//int lengthb = sizeof(b) / sizeof(int);
	//for(i=0; i<lengthb; i++){
	//	printf("%d->",b[i]);
	//}
//	printf("\n\n\n");
//	ColorSort(b,lengthb);
//	for(i=0; i<lengthb; i++){
//		printf("%d->",b[i]);
//	}
	return 0;
}
