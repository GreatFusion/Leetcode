#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	bool isValidInput(ListNode *head)
	{
		if (!head)
			return false;
		else
			return true;
	}
public:
	bool hasCycle(ListNode *head) {
		if (!isValidInput(head))
			return false;

		ListNode *show = head,*fast = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			show = show->next;
			if (fast == show)
				return true;
		}
		return false;
	}
};


int main(int argc,char *argv[])
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	node1->next = node2;
	Solution s;
	s.hasCycle(node1);
	return 0;
}