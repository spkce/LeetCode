/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/



#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* out;
			ListNode* p = NULL;
			int carry = 0;
			int sum,a,b;
			while (l1 != NULL || l2 != NULL)
			{
				a = (l1 != NULL)? l1->val : 0;
				b = (l2 != NULL)? l2->val : 0;
				sum = a + b + carry;
				carry = sum / 10;
				if (p == NULL)
				{
					p = new ListNode(sum % 10);
					out = p;
				}
				else
				{
					p->next = new ListNode(sum % 10);
					p = p->next;
				}
				if (l1 != NULL)
				{
					l1 = l1->next;
				}
				if (l2 != NULL)
				{
					l2 = l2->next;
				}
			}
			if (carry != 0)
			{
				p->next = new ListNode(carry);
			}
		return out;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	ListNode* p;
	ListNode* l1 = new ListNode(2);
	p = new ListNode(4);
	l1->next = p;
	p->next = new ListNode(3);


	ListNode* l2 = new ListNode(5);
	p = new ListNode(6);
	l2->next = p;
	p->next = new ListNode(4);

	Solution s;
	p = s.addTwoNumbers(l1,l2);

	while (p != NULL)
	{
		cout<<p->val;
		p = p->next;
	}
	return 0;
}
