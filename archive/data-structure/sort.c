/*
	����N���������ͷ�Χ�ڵģ�������Ҫ�������С���������Ľ����

	����ּ�ڲ��Ը��ֲ�ͬ�������㷨�ڸ�����������µı��֡�������������ص����£�
	����0��ֻ��1��Ԫ�أ�
	����1��11������ͬ�����������Ի�����ȷ�ԣ�
	����2��103�����������
	����3��104�����������
	����4��105�����������
	����5��105��˳��������
	����6��105������������
	����7��105�����������������
	����8��105�������������ÿ�����ֲ�����1000��
	
	�����ʽ��
	�����һ�и���������N��<= 105�������һ�и���N���������ͷ�Χ�ڵģ�����������Կո�ָ���

	�����ʽ��
	��һ���������С���������Ľ�������ּ���1���ո�ָ�����ĩ�����ж���ո�

	����������
	11
	4 981 10 -17 0 -20 29 50 8 43 -5
	���������
	-20 -17 -5 0 4 8 10 29 43 50 981
*/ 
#include <stdio.h>
#include <stdlib.h>
#define ElementType int

void Swap ( ElementType *x, ElementType *y ); // Swap

void Bubble_Sort ( ElementType A[], int N );
void Insertion_Sort ( ElementType A[], int N );
void Shell_Sort ( ElementType A[], int N );
void Selection_Sort ( ElementType A[], int N );
// Heap_Sort
void Heap_Sort ( ElementType A[], int N );
void PercDown (ElementType A[], int i , int N); // BuildHeap 
// Merge_Sort
// �ݹ��㷨 
void Merge ( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd ); // ���ģ��������еĹ鲢 ������ 
void MSort ( ElementType A[], ElementType TmpA[], int L, int RightEnd ); // ���� 
void Merge_Sort ( ElementType A[], int N ); // ͳһ�����ӿ�
// �ǵݹ��㷨
void Merge1 ( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd ); // ���ģ��������еĹ鲢  �������� 
void Merge_Pass ( ElementType A[], ElementType TmpA[], int N, int length );
void Merge_Sort1 ( ElementType A[], int N ); 
 
int main ( void )
{
	int N, i;
	scanf ("%d", &N);
	
	int A[N];
	
	for (i = 0; i < N; i++)
		scanf ("%d", A+i);
		
	Merge_Sort1 (A, N);
	
	for (i = 0; i < N; i++)
	{
		if (i)
			printf (" %d", A[i]);
		else
			printf ("%d", A[i]);
	}
	
	return 0;
} 

void Swap ( ElementType *x, ElementType *y )
{
	ElementType Tmp;
	
	Tmp = *x;
	*x = *y;
	*y = Tmp;
	
	return;
}

// Bubble_Sort
void Bubble_Sort ( ElementType A[], int N )
{  
	int P, i, flag;
	
	for (P = N-1; P >= 0; P--)
	{// ÿ��ѭ��ΪMax�ҵ�λ�� 
		flag = 0;
		for (i = 0; i < P; i++)
		{
			if (A[i] > A[i+1])
			{
				Swap (&A[i], &A[i+1]);
				flag = 1;
			}
		}
		if (flag == 0) // ����û��Swap����˵����������ɣ�����ѭ�� 
			break;
	}
	
	return;
}

// Insertion_Sort
void Insertion_Sort ( ElementType A[], int N )
{
	int P, i;
	ElementType Tmp;
	
	for (P = 1; P < N; P++)
	{
		Tmp = A[P];
		for (i = P; i > 0 && Tmp < A[i-1]; i--)
		{
			A[i] = A[i-1];
		}
		A[i] = Tmp;
	}
	
	return;
}

// Shell_Sort 
void Shell_Sort ( ElementType A[], int N )
{
	int D, P, i;
	ElementType Tmp;
	
	for (D = N/2; D > 0; D /= 2) // ϣ���������� 
	{
		for (P = D; P < N; P++) // �������� 
		{ // P++��ԭ��Ϊ���ΪD�ĸ������������� 
			Tmp = A[P];
			for (i = P; i >= D && Tmp < A[i-D]; i -=D)
			{
				A[i] = A[i-D];
			} 
			A[i] = Tmp;
		}
	}
	
	return;
}

// Selection_Sort
void Selection_Sort ( ElementType A[], int N )
{ // ÿ��ѭ���ҵ���СԪ 
	int i, j, temp;
	
	for (i = 0; i < N-1; i++)
	{
		for (temp = j = i; j < N; j++)
		{
			if (A[temp] > A[j])
				temp = j;
		}
		Swap (&A[i], &A[temp]);
	}
	return; 
}

// Heap_Sort
void Heap_Sort ( ElementType A[], int N )
{
	int i;
	
	for (i = N/2; i >= 0; i--)
		PercDown (A, i , N); 	// ÿ�ε��øú������ܻᴴ�������ѣ����ѵ�Ԫ�ظ�����1or2or3��ʼ��ֱ��N 
	for (i = N-1; i > 0; i--)
	{
		Swap (&A[0], &A[i]);
		PercDown (A, 0 , i);   // �˲����ǵ�һ��forѭ������������i = 0ʱ 
	}
	
	return;
}
// BuildHeap 
void PercDown (ElementType A[], int i , int N)
{
	int Parent, Child;
	ElementType Tmp;
	
	Tmp = A[i];
	for (Parent = i; Parent*2+1 < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if (Child != N-1 && A[Child] < A[Child+1])
			Child++;
		if (Tmp < A[Child])
			A[Parent] = A[Child];
		else
			break;
	} 
	A[Parent] = Tmp;
	
/*	��һ��Code
	int Tmp; 
	for (Parent = i, Tmp = Parent; Parent*2+1 < N; Parent = Child)
	{
		Child = 2 * Parent + 1; // ������0��ʼ 
		if (Child != N-1 && A[Child] < A[Child+1])
			Child++;
		if (A[Child] > A[Tmp])
		{
			Swap (A+Child, A+Tmp);   
			Tmp = Child;
		}
	} 

	ÿ�ε��øú������ܻᴴ�������ѣ����ѵ�Ԫ�ظ�����1or2or3��ʼ��ֱ��N 
	��ôÿ�ε��ã�ÿ���ӽڵ㶼��һ�����ѣ���˸����ѵĽ����������������ѵ�ɾ�� 
*/ 

	return;
} 

// Merge_Sort
// �ݹ��㷨 
// ���ģ��������еĹ鲢 ������ 
void Merge ( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ // L = �����ʼλ�ã� R = �ұ���ʼλ�ã� RightEnd = �ұ��յ�λ��    A[]��ԭʼ�Ĵ������� TmpA[]��ʱ���� 
  // �����������а��� 
	int NumElements = RightEnd - L + 1;
	int LeftEnd = R - 1;
	int Tmp = L;
	int i;
	// ���������ʽ�ļӷ� 
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	} 
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; //������TmpA����A 
	 
	return;	
}
// ���� 
void MSort ( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{
	int Center;
	
	if (L < RightEnd)
	{
		Center = (L + RightEnd) / 2;
		MSort (A, TmpA, L, Center);
		MSort (A, TmpA, Center+1, RightEnd);
		Merge (A, TmpA, L, Center+1, RightEnd);
	}
	
	return; 
}
// ͳһ�����ӿ�
void Merge_Sort ( ElementType A[], int N )
{
	ElementType *TmpA = (ElementType *)malloc (N * sizeof (ElementType));
	if (NULL == TmpA)
		exit (-1);
	else
	{
		MSort (A, TmpA, 0, N-1);
		free (TmpA);
	}
	
	return;
}

// �ǵݹ��㷨
// ���ģ��������еĹ鲢  �������� 
void Merge1 ( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{
	int NumElements = RightEnd - L + 1;
	int LeftEnd = R - 1;
	int Tmp = L;
	int i;
	
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] >= A[R])
			TmpA[Tmp++] = A[R++];
		else
			TmpA[Tmp++] = A[L++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	
	return;
}

void Merge_Pass ( ElementType A[], ElementType TmpA[], int N, int length )
{
	int i, j;
	
	for (i = 0; i <= N-2*length; i += 2*length) // Here N-2*length !! Reason�����²����� > length,��ɹ鲢�������������A�����²��ֵ���TmpA�� 
		Merge1 (A, TmpA, i, i+length, i+2*length-1); // ��Ԫ�ع鲢��TmpA����
	if (i+length < N) // �鲢���2������
		Merge1 (A, TmpA, i, i+length, N-1); 
	else // ���ֻʣ1������ 
		for (j = i; j < N; j++)
			TmpA[j] = A[j];

	return;
}

void Merge_Sort1 ( ElementType A[], int N )
{
	ElementType *TmpA = (ElementType *)malloc (N * sizeof (ElementType));
	int length = 1;
	
	if (NULL == TmpA)
		exit (-1);
	else
	{
		while (length < N)
		{
			Merge_Pass (A, TmpA, N, length); // ִ���ϴ�Merge_pass����Ѿ�������ϣ��´�Merge_pass���TmpA�е����ݵ���A�� 
			length *= 2;
			Merge_Pass (TmpA, A, N, length);
			length *= 2;
			// ѭ����2��Merge_pass��֤����ѭ��������A�� 
		}
		free (TmpA);
	}
	return;
}
