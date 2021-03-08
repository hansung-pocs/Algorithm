#include <iostream>
#include <list>

class Tree {
	int no;
public:
	std::list<Tree *> child;
	void setNo(int no)
	{
		this->no = no;
	}
	int getNo()
	{
		return no;
	}
	void addChild(Tree * child)
	{
		this->child.push_back(child);
	}
	Tree * find(int no)
	{
		for (Tree * element : child)
		{
			if (element->getNo() == no)
				return element;
			else
			{
				Tree * query = element->find(no);
				if (query) return query;
			}
		}
		return nullptr;
	}
	bool haveChild()
	{
		if (child.empty()) return false;

		bool isEmpty = true;
		for (Tree * element : child)
		{
			if (element->getNo() != -2)
			{
				isEmpty = false;
				break;
			}
		}
		return !isEmpty;
		
	}
	void remove()
	{
		no = -2;
	}
};

int totalCount(Tree * tree)
{
	std::list<Tree *> queue;
	int count = 0;

	queue.push_back(tree);

	while (!queue.empty())
	{
		int currentCount = queue.size();
		std::list<Tree *>::iterator itr = queue.begin();
		for (int i=0;i<currentCount;++itr,++i)
		{
			if ((*itr)->haveChild())
			{
				for (Tree * e : (*itr)->child)
				{
					if(e->getNo()!=-2)
						queue.push_back(e);
				}
			}
			else
			{
				if ((*itr)->getNo() != -1)
					++count;
			}
		}
		for (int i = 0; i < currentCount; ++i)
			queue.pop_front();
	}
	return count;
}

int main()
{
	int n;
	std::cin >> n;

	Tree rootNode;
	rootNode.setNo(-1);
	Tree ** elements = new Tree* [n];
	for (int i = 0; i < n; ++i)
	{
		elements[i] = new Tree;
		elements[i]->setNo(i);
	}

	for (int i = 0; i < n; ++i)
	{
		int parentNode;
		std::cin >> parentNode;
		if (parentNode == -1)
			rootNode.addChild(elements[i]);
		else
			elements[parentNode]->addChild(elements[i]);
	}

	int deleteTarget;
	std::cin >> deleteTarget;

	elements[deleteTarget]->remove(); 

	std::cout << totalCount(&rootNode);




	return 0;
}