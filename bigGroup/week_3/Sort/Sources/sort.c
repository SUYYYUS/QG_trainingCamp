#include"sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//���˵�
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t�����ܴ�����ҵ�����㷨\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.�����ļ�\t\t|\n");
	printf("|\t2.��ȡ�ļ�\t\t|\n");
	printf("|\t3.���Բ�ͬ����������ʱ\t|\n");
	printf("|\t4.���Դ���С��������ʱ\t|\n"); 
	printf("|\t5.���ļ���������\t|\n");
	printf("|\t6.������ɫ����\t\t|\n");
	printf("|\t7.Ѱ�ҵ�k�����      \t|\n");
	printf("|\t8.Ѱ�ҵ�kС����\t\t|\n");  
	printf("|\t9.�˳�ϵͳ\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
} 

//�����ݲ��Բ˵�
void big_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.10000��\t\t|\n");
	printf("|\t2.50000��\t\t|\n");
	printf("|\t3.200000��\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫ���Ե�������\t\n"); 
}

//��ɫ����˵�
void color_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.ʹ�ò�������\t\t|\n");
	printf("|\t2.�����������ȷ����ȷ��\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫ�Ĳ�����\t\n"); 
}

//�����㷨�˵�
void sort_welcome(){
	printf("*-------------------------------*\n");
	printf("|\t1.��������\t\t|\n");
	printf("|\t2.�鲢����\t\t|\n");
	printf("|\t3.��������\t\t|\n");
	printf("|\t4.��������\t\t|\n");
	printf("|\t5.������������\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫ���㷨��\t\n");
} 


//��������
void insertSort(int *a,int n){
	int i, j, k;
	for(i = 0; i < n; i++){
		if(a[i] < a[i-1]){
			k = a[i];
			for(j = i - 1; j>=0 && a[j] > k ; j--){
				//ǰ���źõ��������� 
				a[j+1] = a[j];
			}
			a[j+1] = k; //��ֵ�����ȥ 
		}
	}
} 

//�鲢����
void MergeSort(int *a,int begin,int end,int *temp){
	int mid = 0; 
	if(begin < end){
		mid = (begin+end)/2;//ȡ�м� 
		
		MergeSort(a,begin,mid,temp);//һ�� 
		
		MergeSort(a,mid+1,end,temp);//һ�� 
		
		MergeArray(a,begin,mid,end,temp);
		
	}
}

//�鲢���򣬺ϲ�����
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
	temp = (int*)malloc((end-begin+1)*sizeof(int));//����һ��һ����С������ 
	int i = begin;//��һ������ 
	int j = mid+1;//�ڶ������� 
	int k;	
	for(k = 0; i <= mid && j <= end; ) {
		if(a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else if(a[i] > a[j] ){
			temp[k++] = a[j++];
		}
	}
	//ʣ�������������� 
	while(i <= mid) {
		temp[k++] = a[i++];
	}
	while(j <= end) {
		temp[k++] = a[j++];
	}
	//��ֵ��ԭ���� 
	for(i = 0; i < end-begin+1; i++) {
		a[begin+i] = temp[i];
	}
	//�ͷ���Դ 
	free(temp);
}

//�������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end){
	//�ݹ����� 
	if(begin < end){
		int ret = Partition(a,begin,end); //�ҳ�����λ�� 
		QuickSort_Recursion(a,begin,ret-1); //��� 
		QuickSort_Recursion(a,ret+1,end); //�ұ� 
	}
}

//�������������ţ�
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
	a[begin] = temp;//������Ż�����
	return begin; 
}

//��������
void CountSort(int *a, int size , int max){
	if(size == 2){
		printf("���鳤�Ȳ���2���޷�����\n");
		return ; 
	}
	//��ȡ��Сֵ 
	int min = Min(a,size);
	
	int b[max-min+1];//����һ�����鳤��
	memset(b,0,sizeof(b));//��ʼ��������
	
	int i,j,k;
	//��b������м���
	for(i=0;i<size;i++){
		b[a[i]-min]++;
	} 
	//����ֵ�����ź��� 
	for(i=0,j=0;j<max-min+1;j++){
		for(k=0;k<b[j];k++){
			a[i++] = j+min;
		}
	}
	
}

//������������ 
void RadixCountSort(int *a,int size){
	int i ;
	int j = 1;
	int max = Max(a,size);
	int *temp = (int *)malloc(size * sizeof(int));//�ݴ����� 
	//ѭ�����ֵ��λ������ 
	while(max / j > 0){
		//����һ����������
		int count[10] = {0};
		
		for(i=0;i<size;i++){
			count[a[i] / j % 10]++; //ȡÿ������λ���ϸ�ֵ0��1��2... 
		} 
		//��ÿ�������������ۼ��������������ݰ�λ�ô�� 
		for(i=1;i<10;i++){
			count[i] = count[i] + count[i-1];
		}
		//�Ӻ���ǰ��
		for(i = size-1 ;i >= 0; i--){
			temp[count[a[i]/j % 10]-1] = a[i];
			count[a[i]/j % 10]--;
		} 
		for(i = 0; i <size ;i++){
			a[i] = temp[i];
		}
		//����ʮ����... 
		j = j *10;
	}
	
}

//��ȡ���������ֵ
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

//��ȡ���������ֵ
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


//��û��� 
//��ɫ����
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
		//���ж�p1�Ƿ�Ϊ2 
		if(*p1 == 2){
			if(p1 == p2) break;
			temp = *p2;
			*p2 = *p1;
			*p1 = temp;
			p2--; //������ֵ����p2��ǰ�ƶ�һ��λ�� 
			//���ж�p1�Ƿ�Ϊ0 
			if(*p1 == 0){
				if(p1 == p2) break;
				temp = *p0;
				*p0 = *p1;
				*p1 = temp;
				p0++; //������ֵ����p0����ƶ�һ��λ�� 
			}
			p1++; 
		}
		//���ж�p1�Ƿ�Ϊ0
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


//�������
void Lprintf(int *a,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
} 


//�����ļ���������
void saveFile(int *a, int size ,const char *filename){
	FILE *file;
	file = fopen(filename,"w");
	if(file == NULL){
		printf("�����ļ�ʧ��\n");
		return ;
	}
	int i;
	for(i=0; i<size; i++){
		fprintf(file, "%d\t", a[i]);
	}
	printf("����ɹ�\n");
	//�ر��ļ�
	fclose(file); 
}

//��ȡ�ļ�����
void readFile(int *a, int size, const char *filename){
	FILE *file;
	file = fopen(filename,"r");
	if(file == NULL){
		printf("��ȡ�ļ�ʧ��\n");
		return ;
	}
	int i;
	for(i=0;i<size;i++){
		fscanf(file ,"%d",&a[i]);
	}
	printf("��ȡ�ɹ�\n");
	fclose(file);
} 

//Ѱ�ҵ�k��
void FindNumber(int *a, int size){
	printf("ɶҲ������\n");
} 



int main(){
	//���ڲ��Դ����� 
	int n;
	int i,j;
	int n1;
	//����1��2��5 
	int scope;
	//���ڲ���С���� 
	int num;
	int times;
	//�������� 
	int randomNum;
	//�������������
	srand(time(0));
	//������ɫ��������� 
	//int *colorarr[];
	//��¼ʱ�� 
	clock_t start; 
	clock_t end;
	clock_t totalTime;
	//�������� 
	int *temp;
	//����5 
	int *arr1 = (int *)malloc(scope*sizeof(int));
	int max5;
	//����7��8 
	int k;
	//�ж��ļ�
	int flag1 = 0;
	int flag2 = 0; 
	int flag3 = 0;
	while(1){
		//���˵� 
		welcome();
		char s = getch();
		switch(s){
			case '1': //�����ļ�����һ������
			system("cls");
			printf("�������봴��������Ĵ�С��\n");
			printf("��һ���ȸ�λ����Ȼ�󲻳���15��ðɣ������������\n");
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
			case'2': //��ȡ�ļ�
			system("cls");
			if(flag1 == 0){
				printf("��û�д����ļ�\n");
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
			//�����ݲ��� 
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
					a[i] = b[i] = c[i] = d[i] = e[i] = rand();//ȷ��ÿ��������Ե���������һ�� 
				}
				printf("������10000�����ݵĲ��Խ��:\n");
				//�������� 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//�鲢���� 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("�鲢����:%d ms\n", end-start);
				//��������(�ݹ��)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//�������� 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//������������ 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("������������:%d ms\n", end-start);
				
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
					a[i] = b[i] = c[i] = d[i] = e[i] = rand();//ȷ��ÿ��������Ե���������һ�� 
				}
				printf("������50000�����ݵĲ��Խ��:\n");
				//�������� 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//�鲢���� 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("�鲢����:%d ms\n", end-start);
				//��������(�ݹ��)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//�������� 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//������������ 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("������������:%d ms\n", end-start);
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
					a[i] = b[i] = c[i] = d[i] = e[i]= rand();//ȷ��ÿ��������Ե���������һ�� 
				}
				printf("������200000�����ݵĲ��Խ��:\n");
				//�������� 
				start = clock();
				insertSort(a,n);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				free(a);
				//�鲢���� 
				start = clock();
				MergeSort(b,0,n-1,temp);
				end = clock() ;
				printf("�鲢����:%d ms\n", end-start);
				free(b);
				//��������(�ݹ��)
				start = clock();
				QuickSort_Recursion(c, 0, n-1);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				free(c);
				//�������� 
				int max = Max(d,n);
				start = clock();
				CountSort(d, n ,max);
				end = clock() ;
				printf("��������:%d ms\n", end-start);
				//������������ 
				start = clock();
				RadixCountSort(e,n);
				end = clock() ;
				printf("������������:%d ms\n", end-start);
				//printf("200000\n");
				system("pause");
				system("cls");
				break;
				}
			}
			break;
			
			case '4': //����С���ݵĲ���
			system("cls");
			printf("��Ҫ���ٸ����ݣ�(��100)\n");
			scanf("%d",&num);
			printf("������ٴ�:(��100��100000)\n");
			scanf("%d",&times);
			//��̬���� 
			int *a = (int *)malloc(num*sizeof(int));
			int *b = (int *)malloc(num*sizeof(int));
			int *c = (int *)malloc(num*sizeof(int));
			int *d = (int *)malloc(num*sizeof(int));
			int *e = (int *)malloc(num*sizeof(int));
			
			//��������
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					a[i] = rand(); 
				}
				start = clock();
				insertSort(a,num);
				end = clock();
				totalTime += (end - start);
			}
			printf("��������:%d ms\n", totalTime);	
			
			//�鲢���� 	
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					b[i] = rand(); 
				}
				start = clock();
				MergeSort(b,0,num-1,temp);
				end = clock();
				totalTime += (end - start);
			}
			printf("�鲢����:%d ms\n", totalTime);	
				
			//��������(�ݹ��)	
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					c[i] = rand(); 
				}	
				start = clock();
				QuickSort_Recursion(c, 0, num-1);
				end = clock() ;
				totalTime += (end - start);
			}
				printf("��������:%d ms\n", totalTime);
				
				//��������
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
				printf("��������:%d ms\n", totalTime);
				
				//������������ 
			for(j = 0;j<times;j++){
				for(i = 0; i < num; i++){
					e[i] = rand(); 
				}
				start = clock();
				RadixCountSort(e,num);
				end = clock();
				totalTime += (end - start);
			}
				printf("������������:%d ms\n", totalTime);
			
			system("pause");
			system("cls");
			break;
		
			case '5': //���ļ��������������
			system("cls");
			if(flag2 == 0){
				printf("��û�ж�ȡ�ļ����ߴ����ļ�\n");
				system("pause");
				system("cls");
				break;
			}
			if(flag3 == 0){
				printf("��������򣬿������¶�ȡһ���ļ����ٽ��д˲���\n");
				system("pause");
				system("cls");
				break;
			}
			system("cls");
			printf("ע�⣺\nһ��ֻ��ѡ��һ�������㷨������\n");
			printf("������Ҫʹ�������ģ������¶�ȡ�ļ�����~~~\n");
			printf("Ȼ���ٵ��˵�ѡ������֮һ�����㷨~~~\n");
//			printf("�Դ�����\n");
			sort_welcome();
			char s5 = getch();
			switch(s5){
				case '1': //�����㷨
				system("cls");
				start = clock();
				insertSort(arr1,scope);
				end = clock();
				printf("�����\n");
				Lprintf(arr1,scope);
				printf("��ʱ��%d ms\n",end - start);
				break;
				case '2': //�鲢�㷨
				system("cls");
				start = clock();
				MergeSort(arr1,0,scope-1,temp); 
				end = clock();
				printf("�����\n");
				Lprintf(arr1,scope);
				printf("��ʱ��%d ms\n",end - start);
				break;
				case '3': //�������� 
				system("cls");
				start = clock();
				QuickSort_Recursion(arr1, 0, scope-1);
				end = clock();
				printf("�����\n");
				Lprintf(arr1,scope);
				printf("��ʱ��%d ms\n",end - start);
				break;
				case '4': //�������� 
				system("cls");
				max5 = Max(arr1,scope);
				start = clock();
				CountSort(arr1, scope , max5); 
				end = clock();
				printf("�����\n");
				Lprintf(arr1,scope);
				printf("��ʱ��%d ms\n",end - start);
				break;
				case '5': //������������ 
				system("cls");
				start = clock();
				RadixCountSort(arr1,scope); 
				end = clock();
				printf("�����\n");
				Lprintf(arr1,scope);
				printf("��ʱ��%d ms\n",end - start);
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
						printf("��������:\n");
						Lprintf(testColor,24);
						ColorSort(testColor,24); //������ɫ����
						printf("�����Ϊ��\n"); 
						Lprintf(testColor,24);
						system("pause");
						system("cls");
						break;
				}
			case '2':{
			//��ɫ����
			printf("������Ҫ�����鳤�ȣ�\n");
			scanf("%d",&n1);
			int* colorarr = (int *)malloc(n1*sizeof(int));
			for(i=0;i<n1;i++){
				randomNum = rand() % 3; //0-2����
				colorarr[i] = randomNum; 
			}
			printf("������ɵ�����Ϊ��\n");
			Lprintf(colorarr,n1);
			int flag = 0;
			for(i = 0; i<n1 ;i++){
				if(colorarr[i] == 1){
				flag = 1;
				}
				}
			if(flag == 0){
			printf("������ȱ��1����������\n");
			system("pause");
			system("cls");
			break;
			}else{
				ColorSort(colorarr,n1); //������ɫ����
			printf("�����Ϊ��\n"); 
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
		
		case '7': //Ѱ�ҵ�k�����
		system("cls");
		if(flag2 == 0){
				printf("��û�ж�ȡ�ļ����ߴ����ļ�\n");
				system("pause");
				system("cls");
				break;
			}
			while(1){
				printf("��Ҫ�ҵڼ������:\n");
				scanf("%d",&k);
				if( k> scope){
					printf("������Χ������������\n");}
					else{
						break;
					}
			}
		
		QuickSort_Recursion(arr1, 0, scope-1);
		printf("��%d�����Ϊ:%d\n",k,arr1[scope-k]);
		 system("pause");
			system("cls");
			break;
			case '8': //Ѱ�ҵ�kС���� 
			system("cls");
		if(flag2 == 0){
				printf("��û�ж�ȡ�ļ����ߴ����ļ�\n");
				system("pause");
				system("cls");
				break;
			}
			while(1){
				printf("��Ҫ�ҵڼ�С����:\n");
				scanf("%d",&k);
				if( k> scope){
					printf("������Χ������������\n");}
					else{
						break;
					}
			}
		QuickSort_Recursion(arr1, 0, scope-1);
		printf("��%dС����Ϊ:%d\n",k,arr1[k-1]);
		 system("pause");
			system("cls");
			break;
			case '9': //�˳�ϵͳ
		printf("�ڴ��´��ټ�\n");
		return ;
			default: //�������
		printf("���������룺\n");
		system("pause");
		system("cls");
		break;
		}
		 
	}
	
	//int a[] = {222004,222143,243554,275275,297874,214531,221132,4,232994};
	//int *temp; //��������ָ��temp
	//int length = sizeof(a) / sizeof(int);
	//int max = Max(a,length); //���������ֵ 
	
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
