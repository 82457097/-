#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef struct LinkList {
	int data;
	struct LinkList* next;
}Node;

void InsertByHead(Node& list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list.next;
	list.next = newNode;
}

void CreateList(Node& list, int len) {
	int data;
	srand((unsigned)time(NULL));
	for(int i = 0; i < len; ++i) {
		data = rand() % 100;
		InsertByHead(list, data);
	}
	cout << "�ɹ���������Ϊ " << len << " ������" << endl; 
}

void GetData(Node &list, int index, int *data) {
	Node* p;
	int i = 1;
	p = list.next;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "�����ڸýڵ㣡" << endl;
		return; 
	} 
	*data = p->data;
	cout << "�����е�"  << index << "��Ԫ�ص�ֵΪ��" << *data << endl; 
}

void ListInsert(Node& list, int index, int data) {
	int i = 1;
	Node* newNode,*p;
	p = &list;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "�����ڵ�" << index << "��λ�ã�" <<endl;
		return; 
	}
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	cout << "�ɹ��������е�"  << index << "��λ�ò��룺" << data << endl;
}

void ListDelete(Node& list, int index, int *data) {
	Node* p,*delNode;
	p = &list;
	int i = 1;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "�����ڵ�" << index << "��λ�ã�" <<endl;
		return; 
	}
	delNode = p->next;
	*data = delNode->data;
	p->next = delNode->next;
	delNode->next = NULL;
	cout << "�ɹ�ɾ�������е�"  << index << "��Ԫ�أ�" << *data << endl;
}

void ClearList(Node& list) {
	Node* p,*temp;
	p = list.next;
	while(p) {
		temp = p->next;
		free(p);
		p = temp;
	} 
	list.next = NULL;
	cout << "�ɹ���������" << endl;
} 

int main() {
	Node list;
	list.next = NULL;
	CreateList(list, 10);
	int data;
	GetData(list, 5, &data); 
	ListInsert(list, 6, 1234); 
	ListDelete(list, 9, &data);
	
	Node* p = list.next;
	while(p) {
		cout << p->data << endl;
		p = p->next; 
	} 
	
	ClearList(list);
	
	getchar();
	return 0;
}
