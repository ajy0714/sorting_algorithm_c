﻿#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int num=0, cursor=0;
int i, j, n;
int temp=NULL;
const int ITEMSIZE = 1000;
clock_t start, end;


void selection_sort(int ran_num1[],int num)
{
	int last=num-1;//개수-1 -> ran_num은 0을 시작으로 하는 배열이기 때문

	for(i=0;i<last;last--)//큰 수를 찾아서 맨 뒤로 보내는 과정
	{
		int theLargest=NULL;
		for(n=0;n<last||n==last;n++)//제일 큰 수를 찾는 과정
		{
			if(theLargest<ran_num1[n])
			{
				theLargest=ran_num1[n];
				cursor=n;
			}
		}
		temp=theLargest;
		ran_num1[cursor]=ran_num1[last];
		ran_num1[last]=temp;
	}
}

void bubble_sort(int ran_num2[],int num)
{
	for(i=0;i<num-1;i++)//정렬하는 횟수 계산
	{
		for(j=0;j<num-1;j++)//탐색
		{
			if(ran_num2[j]>ran_num2[j+1])
			{
				temp=ran_num2[j];
				ran_num2[j]=ran_num2[j+1];
				ran_num2[j+1]=temp;
			}
		}
	}
}

void insertion_sort(int ran_num3[],int num)
{	
	for(i=1;i<num;i++)
	{
		temp=ran_num3[i];//i는 정렬 안 된 배열들 중에서 첫번째를 의미함.
		j=i-1;//j는 정렬된 배열들 중에서 마지막을 의미함
		while(ran_num3[j]>temp)//조건을 추가해서, 전체적인 스캔 필요 없이 완전히 정렬되어 있으면 반복문을 돌지 않게하는 방법도 생각해볼 것.(이거 시험 문제였던 것 같은데?)
		{
			ran_num3[j+1]=ran_num3[j];//조건 비교한 뒤 만족하면 칸을 뒤로 밀음
			j--;	
		}
		ran_num3[j+1]=temp;//정렬이 되어있으면 temp에 있는 값은 그 자리로 다시 복사됨(=들어감)
	}
}

void merge_sort(int ran_num4[], int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(ran_num4,p,q);
		merge_sort(ran_num4,q+1,r);
		merge(ran_num4,p,q,r);
	}
}

void merge(int ran_num4[],int p,int q,int r)//      https://gist.github.com/yujuwon/5810996#file-gistfile1-c 참고해서 할 
{
	int i=p;int j=q+1;
	int m; int k=p;
	int temp2[ITEMSIZE];
	while(i<=q && j<=r)
	{
		if(ran_num4[i]<=ran_num4[j])
			temp2[k++]=ran_num4[i++];	
		else
			temp2[k++]=ran_num4[j++];
	}

	if(i>q)//배열의 오른쪽이 남아있는 경우

	{
		for(m=j;m<=r;m++,k++)	
		{
			temp2[k]=ran_num4[m];
		}		

	}
	else
	{
		for(m=i;m<=q;m++,k++)
		{
			temp2[k]=ran_num4[m];
		}
	}

	for(m=0;m<=r;m++)
	{
		ran_num4[m]=temp2[m];
	}
}

void quick_sort(int ran_num4[],int p,int r)//퀵 정렬은 4부분으로 나뉨. 기준보다 작은, 기준보다 큰, 아직 정렬되지 않은, 기준
{
	if(p<r)
	{
		q=partition(ran_num4,p,r);
		quick_sort(ran_num4,p,q-1);
		quick_sort(ran_num4,q+1,r);
	}
}
/*
void partition(int ran_num4,int p,int r)
{
	int base=ran_num4[r];//base는 기준을 의미함. 배열의 맨 마지막
	i=p-1;//p는 정렬할 배열의 맨 앞 부분, i는 기준보다 작은 값들 중 정렬된 마지막 값의 번호, j는 커서,  
	for(j=p;j<r;j++)
	{
		if(ran_num4[j])		
	}

	return i+1;
}*/
/*   void heap_sort()
   {

   }
 */


void print_array(int array[])//정렬이 잘 되었다고 확인하는 용도
{
	for(i=0;i<num;i++)
		printf("%d ",array[i]);
}


int main(void)
{
	printf("입력하고자 하는 난수의 개수를 입력하시오 : ");
	scanf("%d",&num);

	int *ran_num=(int*)malloc(sizeof(int)*num);//동적할당
	srand(time(NULL));
	printf("\n정렬하기 전 : ");	
	for(i=0;i<num;i++)
	{
		ran_num[i]=rand()%1000 + 0;
		printf("%d ",ran_num[i]);
	}//0부터 999까지 랜덤 정수를 ran_num에 대입 및 제대로 들어갔는지 확인출력


	int *ran_num1=(int*)malloc(sizeof(int)*num);
	memcpy(ran_num1,ran_num,sizeof(ran_num)*num);
	start=clock();
	selection_sort(ran_num1,num);//선택 정렬
	end=clock();
	printf("\n\n선택정렬 : ");	print_array(ran_num1);
	printf("소요시간 : %lf",(double)end-start);
	free(ran_num1);

	int *ran_num2=(int*)malloc(sizeof(int)*num);
	memcpy(ran_num2,ran_num,sizeof(ran_num)*num);
	start=clock();
	bubble_sort(ran_num2,num);//버블 정렬
	end=clock();
	printf("\n버블정렬 : ");	print_array(ran_num2);
	printf("소요시간 : %lf",(double)end-start);
	free(ran_num2);

	int *ran_num3=(int*)malloc(sizeof(int)*num);
	memcpy(ran_num3,ran_num,sizeof(ran_num)*num);
	start=clock();
	insertion_sort(ran_num3,num);//삽입 정렬
	end=clock();
	printf("\n삽입정렬 : ");	print_array(ran_num3);
	printf("소요시간 : %lf",(double)end-start);
	free(ran_num3);

	int *ran_num4=(int*)malloc(sizeof(int)*num);
	memcpy(ran_num4,ran_num,sizeof(ran_num)*num);
	start=clock();
	merge_sort(ran_num4,0,num-1);//병합 정렬
	end=clock();	
	printf("\n병합정렬 : ");	print_array(ran_num4);
	printf("소요시간 : %lf",(double)end-start);
	free(ran_num4);

/*	int *ran_num5=(int*)malloc(sizeof(int)*num);
	memcpy(ran_num5,ran_num,sizeof(ran_num)*num);
	start=clock();
	quick_sort(ran_num5,0,num-1);//퀵 정렬
	end=clock();
	printf("\n퀵 정렬 : ");		printf_array(ran_num5);
	printf("소요시간 : %lf",(double)end-start);
	free(ran_num5);*/
	//	heap_sort(ran_num,num);//힙 정렬*/
	return 0;
}
