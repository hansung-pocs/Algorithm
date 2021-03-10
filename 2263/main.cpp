#include <iostream>
#include <vector>

using namespace std;

void toPreOrder(
	vector<int> & inOrder,
	int iBegin, int iEnd,
	vector<int> & postOrder,
	int pBegin, int pEnd
)
{
	if (pEnd - pBegin <= 0) return;
	int base = postOrder[pEnd];
	int mid = iBegin;
	while (inOrder[mid] != base)
		++mid;
	toPreOrder(inOrder, iBegin, mid - 1, postOrder, pBegin, mid - iBegin + pBegin - 1);
	toPreOrder(inOrder, mid + 1, iEnd, postOrder, mid - iBegin + pBegin, pEnd - 1);

	vector<int> newInOrder, newPostOrder;

	newPostOrder.push_back(postOrder[pEnd]);
	for (int i = pBegin; i <= pEnd - 1; ++i)
		newPostOrder.push_back(postOrder[i]);
	for (int i = pBegin; i <= pEnd; ++i)
		postOrder[i] = newPostOrder[i - pBegin];
}

int main()
{
	int n, x;
	vector<int> inOrder, postOrder;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		inOrder.push_back(x);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		postOrder.push_back(x);
	}
	toPreOrder(inOrder, 0, n - 1, postOrder, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", postOrder[i]);
	}
	return 0;
}
