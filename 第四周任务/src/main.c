#include<stdio.h>
#include<stdlib.h>
#include"../inc/qgsort.h"
#include"./qgsort.c"

void menu(){
	printf("					|---      **********      ---|\n");
	printf("					 1.��������\n");
	printf("					 2.�鲢����\n");
	printf("					 3.��������\n");
	printf("					 4.��������\n");
	printf("					 5.������������\n");
	printf("					 6.��ɫ����(ֻ֧������0��1��2~)\n");
	printf("					 7.�������е�n��/С������\n");
	printf("					 8.�˳�\n");
	printf("					|---      **********      ---|\n");
	printf("					 ��������������з�����");
}

void main(){
	int *p,t,number;
	char *c;
	p=(int*)malloc(sizeof(int));
	c=(char*)malloc(sizeof(char));
	menu();
	while(1){
		int i;
	scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>10){          //�����û���� 
    printf("					 �����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    if(number==8) break;
    printf("					 ����������ĳ��ȣ�");
    scanf("%d",&t); 
    while(t<1||t>1000){          //�����û���� 
    printf("					 PS�����ݳ��Ȼ�Ӱ��������������~");
   
    printf("\n");
     printf("					 ����������������������ĳ��ȣ�"); 
    fflush(stdin);
    scanf("%d",&t);
    }
        printf("					 ����֮���ÿո����Ӵ~\n");
    printf("					 ��������������ݣ�");

    while(1){
    	for(i=0;i<t;i++){
    	scanf("%d",p+i);	
    	if(*(p+i)<0) break;
		}
		if(i<t) {
			printf("					 ������󣬲����������������������Ӵ~\n");
			printf("					 ����������:");	
		}
		else break;
	}
	
	if(number==1){
		
	insertSort(p,t);
	}
	
	if(number==2){
		int *q;
//		q=(int*)malloc(sizeof(int));
		q=p;
		MergeSort(p,0,t-1,q);
	}
	
	if(number==3){
		QuickSort_Recursion(p, 0, t-1);
	}
	
	
	if(number==4){
		int max=0;
		for(i=0;i<t;i++) {
			if(*(p+i)>max) max=*(p+i);
		} 
		CountSort(p, t , max);
	} 
	
	if(number==5){
		RadixCountSort(p,t);
	}
	
	if(number==6){
		ColorSort(p,t);
	}
	
	if(number==7){
		int k;
		char c;
		printf("					 a.�ҵ�n�������\n");
		printf("					 b.�ҵ�nС������\n");
		printf("					 ��������Ҫʵ�ֵĹ��ܣ�");
		fflush(stdin);
		scanf("%c",&c); 
		
    while(c!='a'&&c!='b'){          //�����û���� 
    printf("					 ������������ǰ�벻Ҫ�ӿո��������ĸ�ޣ����������룺");  
    scanf("%c",&c);
    }
    printf("					 ������n��ֵ��"); 
		scanf("%d",&k);                //������ѡ������� 
    while(k<1||k>t){          //�����û���� 
    printf("					 ���������������ڳ��ȷ�Χ�ڵ����ݣ�"); 
    fflush(stdin);
    scanf("%d",&k);
    }
    	Findnthnumber(p, t);
    	if(c=='b') 
    printf("					 ��nС��ֵΪ��%d\n",*(p+k-1));
	if(c=='a') printf("					 ��n���ֵΪ��%d\n",*(p+t-k));
	} 
    
	
	if(number!=7){
	for(i=0;i<t;i++){
	if(i==0) 
    	printf("					 %d ",*(p+i));	
    	if(i<t-1&&i>0) printf("%d ",*(p+i));
    	if(i==t-1) printf("%d\n",*(p+i));
	}	
	} 
	
	
	printf("					 ����س�����ִ�й��ܡ�"); 
	getchar();
	getchar();
	getchar();
	system("CLS");
	menu(); 
	 }
    
    
    
    
   	
    

}


