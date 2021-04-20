#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/qgsort.h" 

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
	int i,c,j,k;
	for(i=1;i<n;i++){
		k=*(a+i);
		for(j=i-1;j>=0&&(k<=*(a+j));j--){
			*(a+j+1)=*(a+j);
		}
		*(a+j+1)=k;
	}	
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i,j=0,k=0;
	int *hh;
	int t=(end-begin)/2;
	hh=(int*)malloc(sizeof(int));
	for(i=0;i<=t;i++) *(hh+i)=*(temp+i);
	for(i=0;i<=end-begin;i++){
	
	if(end!=1&&end%2==0){
	if(j<t+1&&k<t){
		if(*(a+j)<*(hh+k)) {
			*(temp+i)=*(a+j);
			j++;
			}
			
		
		else{
			*(temp+i)=*(hh+k);
			k++;	
			}
	}
	else{
		if(k>=t) *(temp+i)=*(a+j++);
		else *(temp+i)=*(hh+k++);
	}
	
		
	}
	else{
	if(j<=t&&k<=t){
		if(*(a+j)<*(hh+k)) {
			*(temp+i)=*(a+j);
			j++;
			}
			
		
		else{
			*(temp+i)=*(hh+k);
			k=k+1;	
			}
	}
	else{
		if(k>t) *(temp+i)=*(a+j++);
		else *(temp+i)=*(hh+k++);
	}	
	}		
		}
		
	}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	temp=a+begin;
	
	if(begin!=end){
		if((end-begin)%2==0){
		int k=(end-begin)/2,i;
		int b[k+1],c[k];
		int *d,*e;
		d=e=(int*)malloc(sizeof(int));
		for(i=0;i<=k;i++) b[i]=*(temp+i);
		d=b;
		for(i=0;i<k;i++) c[i]=*(temp+i+k+1);
		e=c;
		MergeSort(b,0,k,d);
		MergeSort(c,0,k-1,e);	
		MergeArray(b,0,0,end-begin,c);
		for(i=0;i<=end-begin;i++) *(temp+i)=*(c+i);
//		printf("%d\n",*(c+i));
//for(i=0;i<=end-begin;i++) *(a+i)=*(c+i);
		}
		else{
		int k=(end-begin)/2+1,i;
//		int b[k],c[k];
		int f[k],g[k];
		int *d,*e,*h;
		d=e=(int*)malloc(sizeof(int));	
		for(i=0;i<k;i++){
//			b[i]=*(temp+i);
//			c[i]=*(temp+i+k);
		f[i]=*(temp+i);
		g[i]=*(temp+i+k);
		} 
//		d=b;
//		e=c;
		d=f;
		e=g;	
//		MergeSort(b,0,k-1,d);
//		MergeSort(c,0,k-1,e); 
//		MergeArray(b,0,0,end-begin,c);
		MergeSort(f,0,k-1,d);
		MergeSort(g,0,k-1,e); 
		h=g;
		MergeArray(f,0,0,end-begin,h);
		for(i=0;i<=end-begin;i++) *(temp+i)=*(h+i);
//		for(i=0;i<=end-begin;i++) printf("%d\n",*(c+i));
//for(i=0;i<=end-begin;i++) *(a+i)=*(c+i);
		}
			
	}
	
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
 //begin只能是0，要在调用函数前将p设置为第一个结点的位置，同时end要设置为数组长度-1 
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin!=end&&end>0){
	int *front,*tail;
	int *aa,*bb,i,t,k;
	aa=(int*)malloc(sizeof(int));
	bb=(int*)malloc(sizeof(int));
	front=a+begin+1;
	tail=a+end;
	while(front!=tail){
		while(*front<=*a&&front!=tail) front++;
		while(*tail>=*a&&tail!=front) tail--;
		if(front!=tail) {
			t=*front;
			*front=*tail;
			*tail=t;
		}
	}
	if(*a>*front){
		t=*a;
		*a=*front;
		*front=t;
	}
	else {
	t=*a;
	for(i=1;i<front-a;i++){
		*(a+i-1)=*(a+i);
	}
	*(a+i-1)=t;
	}
	if(t==*front){
	k=front-a;
	for(i=0;i<k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<=end;i++) *(bb+i-k-1)=*(a+i);
	}
	else{
	k=front-a-1;
	if(k>0){
	for(i=0;i<k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<=end;i++) *(bb+i-k-1)=*(a+i);	
	}
	if(k==0){
	for(i=0;i<=k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<=end;i++) *(bb+i-k-1)=*(a+i);
	}	
	}	
	QuickSort_Recursion(aa, 0, k-1);
	QuickSort_Recursion(bb, 0, end-k-1);
	for(i=0;i<k;i++) *(a+i)=*(aa+i);
	for(i=k+1;i<=end;i++) *(a+i)=*(bb+i-k-1);
	*(a+k)=t;
	}

}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){
	int i,j=0;
	int c[max+1];
	for(i=0;i<=max;i++) c[i]=0;
	for(i=0;i<size;i++){
		if(*(a+i)>=0&&(*(a+i)<=max)) c[*(a+i)]++;
	}
	for(i=0;i<size;i++) {
		while(c[j]==0&&j<=max) j++;
		if(j<=max){
		*(a+i)=j;
		c[j]--;
		}	
	}
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){
	int i,k=*a,j,flag,t,mid;
	int b[size];
	for(i=0;i<size;i++) {
		b[i]=*(a+i);
	}
	for(i=0;i<size;i++){
		if(*(a+i)>k) 	k=*(a+i);
	}
	if(k>=1000&&k<10000) {
		int ge[size],shi[size],bai[size],qian[size];
		mid=0;	
		flag=size;
		for(i=0;i<size;i++)  ge[i]=b[i]-b[i]/10*10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(ge[i]>ge[i+1]){
			j=ge[i];
			ge[i]=ge[i+1];
			ge[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//十位比较 
		flag=size;
		for(i=0;i<size;i++)  shi[i]=(b[i]-b[i]/100*100)/10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(shi[i]>shi[i+1]){
			j=shi[i];
			shi[i]=shi[i+1];
			shi[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//百位比较 
		flag=size;
		for(i=0;i<size;i++)  bai[i]=(b[i]-b[i]/1000*1000)/100;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(bai[i]>bai[i+1]){
			j=bai[i];
			bai[i]=bai[i+1];
			bai[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//千位比较 
		flag=size;
		for(i=0;i<size;i++)  qian[i]=b[i]/1000;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(qian[i]>qian[i+1]){
			j=qian[i];
			qian[i]=qian[i+1];
			qian[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
	}
	
	
		if(k>=100&&k<1000) {
		int ge[size],shi[size],bai[size];
		mid=0;	
		flag=size;
		for(i=0;i<size;i++)  ge[i]=b[i]-b[i]/10*10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(ge[i]>ge[i+1]){
			j=ge[i];
			ge[i]=ge[i+1];
			ge[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//十位比较 
		flag=size;
		for(i=0;i<size;i++)  shi[i]=(b[i]-b[i]/100*100)/10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(shi[i]>shi[i+1]){
			j=shi[i];
			shi[i]=shi[i+1];
			shi[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//百位比较 
		flag=size;
		for(i=0;i<size;i++)  bai[i]=(b[i]-b[i]/1000*1000)/100;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(bai[i]>bai[i+1]){
			j=bai[i];
			bai[i]=bai[i+1];
			bai[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}}

		if(k>=10&&k<100) {
		int ge[size],shi[size];
		mid=0;	
		flag=size;
		for(i=0;i<size;i++)  ge[i]=b[i]-b[i]/10*10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(ge[i]>ge[i+1]){
			j=ge[i];
			ge[i]=ge[i+1];
			ge[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		//十位比较 
		flag=size;
		for(i=0;i<size;i++)  shi[i]=(b[i]-b[i]/100*100)/10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(shi[i]>shi[i+1]){
			j=shi[i];
			shi[i]=shi[i+1];
			shi[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		
	}
	
	
	if(k>=0&&k<10) {
		int ge[size];
		mid=0;	
		flag=size;
		for(i=0;i<size;i++)  ge[i]=b[i]-b[i]/10*10;
		for(t=0;flag!=0;t++){
			for(i=0;i<flag-1;i++) {
			if(ge[i]>ge[i+1]){
			j=ge[i];
			ge[i]=ge[i+1];
			ge[i+1]=j;
			j=b[i];
			b[i]=b[i+1];
			b[i+1]=j;
			mid=i+1;	
			}
			}
		if(mid==flag) 	break;
		flag=mid;
		}
		
	}
	for(i=0;i<size;i++)
	*(a+i)=b[i];
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	int *b,*c,*d,i=0,t=0,j=0,k=0,flag=0,aa;     //i,j,k分别对应b[],c[],d[],用来防止越界 
	b=a,c=a,d=a+size-1;
	for(;i<size-k;){
		if(j+k>size-1){
			if(*(a+i+1)==0) 
			flag=1;	
			if(*(a+i)>*(a+i+1)){
			t=*(a+i);
			*(a+i)=*(a+i+1);
			*(a+i+1)=t;
			i++;	
			}
			else i++;
			if(flag==1) {
				i=aa;
				flag=0;
			}
		}
		else{
		while(*b!=1&&i<size&&*b!=2) {
		b++;
		i++;
		}
		while((*c==1&&j<size)||b-c>=0){
			j++;
			c++;
		} 
		while(*d==2&&d-c>0){
			d--;
			k++;
		} 
		if(d-c==0){
			c++;j++;
		}
		if(*c>*d&&d-c>0){
		t=*c;
		*c=*d;
		*d=t;
		d--;
		k++;	
		}
		if(*c<*b) {
			t=*b;
			*b=*c;
			*c=t;
			c++;
			j++;
		}
		aa=i;	
		}
	
		
	}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
 //还需要在后面加一个 
void Findnthnumber(int *a, int size){
 	if(size>1){
	int *front,*tail;
	int *aa,*bb,i,t,k;
	aa=(int*)malloc(sizeof(int));
	bb=(int*)malloc(sizeof(int));
	front=a+1;
	tail=a+size-1;
	while(front!=tail){
		while(*front<=*a&&front!=tail) front++;
		while(*tail>=*a&&tail!=front) tail--;
		if(front!=tail) {
			t=*front;
			*front=*tail;
			*tail=t;
		}
	}
	if(*a>*front){
		t=*a;
		*a=*front;
		*front=t;
	}
	else {
	t=*a;
	for(i=1;i<front-a;i++){
		*(a+i-1)=*(a+i);
	}
	*(a+i-1)=t;
	}
	if(t==*front){
	k=front-a;
	for(i=0;i<k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<size;i++) *(bb+i-k-1)=*(a+i);
	}
	else{
	k=front-a-1;
	if(k>0){
	for(i=0;i<k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<size;i++) *(bb+i-k-1)=*(a+i);	
	}
	if(k==0){
	for(i=0;i<=k;i++) *(aa+i)=*(a+i);
	for(i=k+1;i<size;i++) *(bb+i-k-1)=*(a+i);
	}	
	}	
	QuickSort_Recursion(aa, 0, k-1);
	QuickSort_Recursion(bb, 0, size-k-2);
	for(i=0;i<k;i++) *(a+i)=*(aa+i);
	for(i=k+1;i<size;i++) *(a+i)=*(bb+i-k-1);
	*(a+k)=t;
	}
 }
