#include "ArrayBranchTree.h"

static int LEFT(int pos)
{
	return pos*2 + 1;
}

static int RIGHT(int pos)
{
	return pos*2 + 2;
}

static void swap(vector<int>& vec, int first, int second)
{
	int tmp = vec[first];
	vec[first] = vec[second];
	vec[second] = tmp;
}

void ArrayBranchTree::maxHeapity( vector<int>& vec
								 , int index
								 , int legth)
{
	int left = LEFT(index);
	int right = RIGHT(index);
	int larget(index);

	if (left  <=  legth && vec[left] > vec[index])
		larget = left;
	
	if (right <= legth && vec[right] > vec[larget])
		larget = right;

	if (larget != index){
		swap(vec, larget, index);
		maxHeapity(vec, larget, legth);
	}
}

//ԭ�� (n-1)/2,��n-1��Ԫ�ض��Ǹ�
void ArrayBranchTree::buildMaxHeapity( vector<int>& vec )
{
	int length = vec.size();
	for (int i = (length-1)/2; i >= 0; --i)
	{
		int legth = (vec.size()-1);
		maxHeapity(vec, i, legth);
	}
}


ArrayBranchTree::ArrayBranchTree(void)
{
}

ArrayBranchTree::~ArrayBranchTree(void)
{
}


