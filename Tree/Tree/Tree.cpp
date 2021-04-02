#include <iostream>
#include "C:\Users\Господин\Downloads\Stack.h"
#include "C:\Users\Господин\Downloads\Queue.h"
using namespace std;

struct Link {
	int val;
	
	Link* l;
	Link* r;

	Link(int _a = 0, Link* _l = NULL, Link* _r = NULL) : val(_a), l(_l), r(_r) {};
};

void TLR(Link* curr) {
	if (curr == NULL)
		return;
	cout << curr->val << " ";
	TLR(curr->l);
	TLR(curr->r);
}

void LTR(Link* curr) {
	if (curr == NULL)
		return;
	LTR(curr->l);
	cout << curr->val << " ";
	LTR(curr->r);
}

void TLR_itr_1(Link* root) {
	Link* curr;
	Stack<Link*> st;
	curr = root;
	while (true) {
		if (curr != NULL)
		{
			cout << curr->val << " ";
			st.push(curr);
			curr = curr->l;
		}
		else
		if (st.isEmpty()) {
			break;
		}
		else {
			curr = st.pop();
			curr = curr->r;
		}
	}
}

void TLR_itr_2(Link* root) {
	Link* curr;
	Queue<Link*> q;
	if(root!=NULL)
		q.push(root);
	while (!q.isEmpty()) {
		curr = q.pop();
		cout << curr->val << " ";
		if (curr->l != NULL)
			q.push(curr->l);
		if (curr->r != NULL)
			q.push(curr->r);
	}
}

class Iterator {
	Link* curr;
	Queue<Link*> q;
public:
	Iterator(Link* root)
	{
		if (root != NULL) q.push(root);
	}
	bool hasNext() { return !q.isEmpty(); }
	int next() {
		curr = q.pop();
		if (curr->l != NULL)
			q.push(curr->l);
		if (curr->r != NULL)
			q.push(curr->r);
		return curr->val;
	}
};

void LTR_itr_2(Link* root) {
	Stack<Link*> st;

	Link* curr = root;

	while (curr != NULL || !st.isEmpty())
	{
		while (curr != NULL)
		{
			st.push(curr);
			curr = curr->l;
		}

		curr = st.pop();
		cout << curr->val << " ";
		curr = curr->r;
	}
}

int main() {
	Link* l6 = new Link(6);
	Link* l5 = new Link(5);
	Link* l4 = new Link(4, NULL, l6);
	Link* l3 = new Link(3, l4, l5);
	Link* l2 = new Link(2);
	Link* l1 = new Link(1, l2, l3);

	Link* root = l1;

	TLR(root);
	cout << endl;

	LTR(root);
	cout << endl;

	TLR_itr_1(root);
	cout << endl;

	TLR_itr_2(root);
	cout << endl;

	Iterator itr(root);
	while (itr.hasNext())
	{
		cout << itr.next() << " ";
	}
	cout << endl;

	LTR_itr_2(root);
	cout << endl;

	return 0;
}