// Task conditions
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = nullptr;
	ListNode* it = nullptr;
	int remains = 0;

	while (l1 || l2) {
		int a = l1 ? l1->val : 0;
		int b = l2 ? l2->val : 0;
		int sum = a + b + remains;
		
		remains = sum / 10;
		sum = sum % 10;

		if (!it) {
			it = new ListNode(sum);
			head = it;
		} else {
			it->next = new ListNode(sum);
			it = it->next;
		}

		it->val = sum;

		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;
	}

	if (remains > 0) {
		it->next = new ListNode(remains);
	}

	return head;
}

