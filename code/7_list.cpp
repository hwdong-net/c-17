#if 0
using ElemType = char;      //��������Ԫ�ص�������ElemType
struct LNode {             //struct�������ĳ�ԱĬ���ǹ�����
	ElemType data;
	LNode* next{ nullptr };  //next��ָ����һ��Ԫ�ؽ���ָ�����
};
#endif

using ElemType = char;      //��������Ԫ�ص�������ElemType
class List {
	struct LNode {    //struct�������ĳ�ԱĬ���ǹ�����
		ElemType data;
		LNode* next{ nullptr }; //next��ָ����һ��Ԫ�ؽ���ָ�����
	};
	LNode* head;         //ָ��ͷ����ָ�����
public:
	//��ʼ��һ�������κ�����ֻ��ͷ���Ŀյ�����
	List() :head{ new LNode{} } {}

	bool insert(const int i, const ElemType& e); //��i������Ԫ��
	bool erase(const int i);            //ɾ��iԪ��
	LNode* locate(const int i)const;

	bool push_back(const ElemType& e); //���������һ��Ԫ��
	bool pop_back();  //ɾ��������Ԫ��

	bool push_front(const ElemType& e); //����Ԫ�س�Ϊ��һ��Ԫ�أ��׽�㣩
	bool pop_front();  //ɾ���׽��

	bool get(const int i, ElemType& e)const; //��ȡiԪ��
	bool set(const int i, const ElemType e);//�޸�iԪ��	
	int size() const;  //��ѯ��
};

bool List::push_front(const ElemType& e) {
	LNode* p = new LNode;     //����һ���µĽ��
	if (!p) return false;          //�����ڴ�ʧ��!
	p->data = e;               //�������ݷ���pָ����½���data��Ա��
	p->next = head->next;       //p��nextָ��ָ��ԭ�����׽��
	head->next = p;            //head��nextָ��pָ����½�㣬���½���Ϊ�׽�㡣
}

bool List::pop_front() {
	if (!head->next) return false;   //�ձ�
	LNode* p = head->next;      //pָ��Ҫɾ�����׽��
	head->next = p->next;        //head��nextָ��p�ĺ�һ����㣬�������׽��
	delete p;                   //ɾ��ԭ�����׽��
	return true;
}
int List::size()const {
	LNode* p{ head }; auto i{ 0 };  //pָ��ͷ��㣬������iΪ0
	p = p->next;               //pָ���׽�㣬
	while (p) {                 //p���ǿ�ָ�룬��ʾ����һ�����
		i++;                  //����������1
		p = p->next;           //pָ����һ�����
	}
	return i;
}
List::LNode* List::locate(const int i)const {
	if (i < 0) return nullptr;//����λ�ò��Ϸ�
	LNode* p{ head }; auto j{ 0 };//pָ��ͷ��㣬������iβ0
	while (p && j < i) {
		p = p->next;  //pָ����һ�����
		j++;
	}
	return p;
}

bool List::erase(const int i) {     //ɾ��iԪ��
	LNode* p = locate(i - 1);          //��λi-1�Ž��	
	if (p) {                        //���pָ��ĵ�i-1�Ž�����
		LNode* q = p->next;       //q����Ҫɾ���Ľ���ַ
		p->next = q->next;         //ʹp��nextָ������q���
		delete q;                 // ɾ��qָ����Ǹ����
		return true;
	}
	return false;                   //i�����˱�
}

bool List::insert(const int i, const ElemType& e) {
	LNode* p = locate(i - 1);             //��λi-1�Ž��	
	if (p) {                          //pָ��ĵ�i-1�Ž�����
		LNode* q = new LNode;       //qָ�������½���ڴ��
		if (!q) return false;
		q->data = e;
		q->next = p->next;            //��p�ĺ�̽��ҵ�q�ĺ���
		p->next = q;                 //��qָ��Ľ��ҵ�p�ĺ���
		return true;
	}
	return false;
}
bool List::get(const int i, ElemType& e)const {
	LNode* p = locate(i);//��λi�Ž��	
	if (p) {
		e = p->data; return true;
	}
	return false;
}
bool List::set(const int i, const ElemType e) {
	LNode* p = locate(i);//��λi�Ž��	
	if (p) {
		p->data = e; return true;
	}
	return false;
}

#include <iostream>
void print(const List& v) {
	ElemType e;
	for (auto i = 1; i <= v.size(); i++) {
		v.get(i, e);
		std::cout << e << '\t';
	}
	std::cout << std::endl;
}

int main() {
	List v;
	v.push_front('a');
	v.push_front('b');
	v.push_front('c');
	print(v);
	v.insert(1, 'd');
	print(v);
	ElemType e;
	v.get(1, e);
	std::cout << e << '\n';
	v.set(1, 'f');
	print(v);
	v.erase(2);
	print(v);
	v.pop_front();
	print(v);
}
