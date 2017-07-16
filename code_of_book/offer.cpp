#if 0
/*
	�����������׿�������ݽṹ
*/
#include<iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
///////////////////////////////////////
void AddToTail(ListNode **pHead,int value);
void RemoveNode(ListNode **pHead,int value);

///////////////////////////////////////
int main()
{
	ListNode *pHead = NULL;
	AddToTail(&pHead,1);
	return 0;
}

void AddToTail(ListNode **pHead,int value)	//��ӽ��
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL)
		*pHead = pNew;
	else
	{
		ListNode *pNode = *pHead;

		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode **pHead,int value)	//�Ƴ�ĳ�����
{
	if(*pHead == NULL || *pHead == NULL)
		return;
	
	ListNode* pToBeDeleted = NULL;
	if( (*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
		if(pToBeDeleted != NULL)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
		}
	}
}

#endif
#if 0

/*
	��Ŀ:����һ�������ͷ���,��β��ͷ��������ӡ��ÿ������ֵ
	�����㶨��Ϊ:
	struct ListNode
	{
		int key;
		ListNode *next;
	};
	���������,�ܶ��˵ĵ�һ��Ӧ�Ǵ�ͷ��β����Ƚϼ�,�������Ǻ���Ȼ���뵽�����������ӽ���ָ�뷴ת����,�ı�����ķ���,Ȼ��Ϳ��Դ�ͷ��β�����.���÷�����ı�ԭ������Ľṹ.�Ƿ������ڴ�ӡ�����ʱ���޸�����Ľṹ,���ȡ�������Թٵ�Ҫ��,��������Ե�ʱ������Ҫѯ�����Թٵ�Ҫ��
	ͨ����ӡֻ��һ��ֻ������,���ǲ�ϣ����ӡʱ�޸�����,�������Թ�ҲҪ�������Ŀ���ܸı�����Ľṹ.
	�����������뵽�Ľ���������϶���Ҫ��������.������˳���Ǵ�ͷ��β��˳��,�������˳��ȷʵ��β��ͷ��Ҳ����˵��һ���������Ľ�����һ�����,�����һ���������Ľ���һ�����������ǵ��͵�"����ȳ�",���ǿ�����ջʵ�����ֽṹ,ÿ����һ������ʱ�򣬰Ѹý���ֵ�Ž�һ��ջ��,�����������������,�ٴ�ջ����ʼ����������ֵ,��ʱ����Ľ���˳���Ѿ���ת������,z����˼·ʵ�ֵĴ�������:
*/


void PrintListReversing_Iteratively(ListNode *pHead)
{
	stack<ListNode*> nodes;

	ListNode *pNode = pHead;

	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		cout<<pNode->value<<" ";
		nodes.pop();
	}
	cout<<endl;
}

/*
	��Ȼ�뵽����ջ��ʵ���������,���ݹ鱾�����һ��ջ�ṹ,���Ǻ���Ȼ�����뵽���õݹ���ʵ�֡�Ҫʵ�ַ������������,����û���ʵ�һ������ʱ��,�ȵݹ����������Ľ��,������ý�㱾��,����������������ͷ�������
*/

void PrintListReversing_Recursively(ListNode *pHead)
{
	if(pHead != NULL)
	{
		if(pHead->next != NULL)
		{
			PrintListReversing_Recursively(pHead->next);
		}
		cout<<pHead->value<<" ";
	}
}

/*
	����Ļ��ڵݹ�Ĵ��뿴�����ܼ��,���и�����:������ǳ�����ʱ��,�ͻᵼ�º������õĲ㼶����,�Ӷ��п��ܵ��º�������ջ���.��ʽ����ջʵ�ֵĴ����ȶ���ҪǿһЩ.
*/
#endif

#if 0
/*
	��ת�������С�ַ�
	��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ,���ǳ�֮Ϊ�������ת.����һ����������������һ����ת�������ת�������СԪ�ء���������{3,4,5,1,2}Ϊ{1,2,3,4,5}�����������СֵΪ1
	�������ֱ�۵Ľⷨ������,��ͷ��β��������һ��,���Ǿ����ҵ���������С��Ԫ��,����˼·��ʱ�临�Ӷ�����ΪO(n),�������˼·��û�������������ת���������,�϶��ﲻ�����Թٵ�Ҫ��
	����ע�⵽��ת֮�������ʵ���Ͽ��Ի���Ϊ��������������飬����ǰ����������Ԫ�ض����ڻ��ߵ��ں����������Ԫ��.���ǻ�ע�⵽��С��Ԫ�ظպ���������������ķֽ���,����������������ǿ������ö��ֲ��ҷ���ʵ��O(logn)�Ĳ���,���������������һ���̶����������,������ǿ��������ö��ַ���˼·�����������С��Ԫ��.
	�Ͷ��ֲ��ҷ�һ��,������������ָ��ֱ�ָ������ĵ�һ��Ԫ�غ����һ��Ԫ�ء�������Ŀ����ת�Ĺ���,��һ��Ԫ��Ӧ���Ǵ��ڻ��ߵ������һ��Ԫ�صġ�
	�������ǿ����ҵ������м��Ԫ�أ�������м�Ԫ��λ��ǰ��ĵ��������飬��ô��Ӧ�ô��ڻ��ߵ��ڵ�һ��ָ��ָ���Ԫ��.��ʱ��������С��Ԫ��Ӧ��λ�ڸ��м�Ԫ�صĺ��档���ǿ��԰ѵ�һ��ָ��ָ����м�Ԫ��,����������С���ҵķ�Χ.�ƶ�֮��ĵ�һ��ָ����Ȼλ��ǰ��ĵ���������.
	ͬ������м�Ԫ��λ�ں���ĵ���������,��ô��Ӧ��С�ڻ��ߵ��ڵڶ���ָ��ָ���Ԫ��.��ʱ����������С��Ԫ��Ӧ��λ�ڸ��м�Ԫ�ص�ǰ�档���ǿ��԰ѵڶ���ָ��ָ����м�Ԫ�أ�����Ҳ����СѰ�ҵķ�Χ���ƶ�֮��ĵڶ���ָ����Ȼλ�ں���ĵ������鵱�С�
	�������ƶ���һ��ָ�뻹�ǵڶ���ָ�룬���ҷ�Χ������С��ԭ����һ�롣�������������ø���֮�������ָ�룬�ظ���һ�ֵĲ��ҡ�
	���յ�һ��ָ���ָ��ǰ����������һ��Ԫ�أ��ڶ���ָ���ָ�����������ĵ�һ��Ԫ�أ�Ҳ�����������ջ�ָ���������ڵ�Ԫ�ء������ѭ��������������

*/

//ʵ�ֵĴ�������:

int Min(int *numbers,int length)
{
	if(numbers == NULL || length <= 0)
		return 0;
	
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2)/2;
		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid <= numbers[index2]])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

/*
	ǰ�������ᵽ����ת�����У������ǰѵ�����������ǰ������ɸ����ְᵽ����ĺ���,��˵�һ���������Ǵ��ڻ��ߵ������һ�����֡������涨����һ������:��������������ǰ���0��Ԫ�ذᵽ����棬���������鱾������Ȼ�������һ����ת�����ǵĴ�����Ҫ֧�������������ʱ����ĵ�һ�����־�����С�����֣�����ֱ�ӷ��ء������������Ĵ����У���indexMid��ʼ��Ϊindex1��ԭ��һ�����������е�һ������С�����һ�����֣�����������������ģ�ֱ�ӷ��ص�һ�����֡�
*/
/*
	����Ĵ����Ƿ����������,�����ǣ����������������ʱ�򣬿��Է���һ�£�
{1,0,1,1,1}   {1,1,1,0,1}
	����������£���һ�����֣����һ�����֣��м����֣�����ͬ�ģ������޷��ж��м��������λ��ǰ��������黹��λ�ں���������顣Ҳ���޷��ƶ�����ָ������С���ҵķ�Χ����ʱ����ֻ����˳����ҵķ�����ʵ�֡�

*/

//���Խ������Ϊ:

int Min(int *numbers,int length)
{
	if(numbers == NULL || length <= 0)
		return 0;
	
	int index1 = 0;
	int index2 = length -1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1+index2)/2;

		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInoeder(numbers,index1,index2);

		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinInoeder(int *numbers,int index1,int index2)
{
	int result = numbers[index1];

	for(int i = index1+1; i <= index2; ++i)
	{
		if(result > numbers[i])
			result = numbers[i];
	}
	return result;
}

#endif

