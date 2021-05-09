#include <string>
class Book {
public:
	std::string name, author, publisher;
	double price;
};

using ElemType = Book; //ElemType����ΪBook����
class Vector {
	ElemType* data{ nullptr };   //�ռ���ʼ��ַ
	int  capacity{ 0 }, n{ 0 };   //�ռ�������ʵ��Ԫ�ظ�������ʼ��Ϊ0
public:
	Vector(const int cap = 5)   //����������cap��һ�����Ա�
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType& e); //��i������Ԫ��
	bool erase(const int i);            //ɾ��iԪ��
	bool push_back(const ElemType& e); //���������һ��Ԫ��
	bool pop_back();  //ɾ��������Ԫ��
	//bool insert_front(const ElemType e);
	//bool pop_front();
	//bool find(const ElemType e);

	bool get(const int i, ElemType& e)const; //��ȡiԪ��
	bool set(const int i, const ElemType e);//�޸�iԪ��
	int size() const { return n; }  //��ѯ��
private:
	bool add_capacity();             //��������
};

bool Vector::add_capacity() {
	ElemType* temp = new ElemType[2 * capacity];   //����2����С�ĸ���ռ�
	if (!temp) return false;                         //�����ڴ�ʧ��
	for (auto i = 0; i < n; i++) {                     //��ԭ�ռ�data���ݿ������¿ռ�temp
		temp[i] = data[i];
	}
	delete[] data;                               //�ͷ�ԭ���ռ��ڴ�
	data = temp;                                //dataָ���µĿռ�temp
	capacity *= 2;                              //�޸�����
	return true;
}

//(a0,a1,..., e,  ai,...   an-1)
bool Vector::insert(const int i, const ElemType& e) {
	if (i < 0 || i > n) return false;          //����λ�úϷ���
	if (n == capacity && !add_capacity())   //��������������
		return false;
	for (auto j = n; j > i; j--)             //��n-1��i��Ԫ�ض�����ƶ�һ��λ��
		data[j] = data[j - 1];           //j-1�Ƶ�jλ����
	data[i] = e;
	n++;                            //��Ҫ�����޸ı�
	return true;
}

bool Vector::erase(const int i) {
	if (i < 0 || i >= n) return false;    //λ��i�Ϸ���
	 //i+1��n-1Ԫ��������ǰ�ƶ�һ��λ��
	for (auto j = i; j < n - 1; j++)
		data[j] = data[j + 1];       //j+1�Ƶ�jλ����
	n--;                         // ��Ҫ���ˣ���������ȥ1��
	return false;
}

bool Vector::push_back(const ElemType& e) {
	if (n == capacity && !add_capacity())    //�ռ���������
		return false;
	data[n] = e;
	n++;
	//data[n++] = e;                      //e�����±�nλ�ã�Ȼ��n++
	return true;
}
bool Vector::pop_back() {
	if (n == 0) return false;          //�ձ�
	n--;                         //n��ȥ1���൱��ɾ���˱�βԪ��
	return true;
}

bool Vector::get(const int i, ElemType& e)const {
	if (i >= 0 && i < n) {  //�±��Ƿ�Ϸ���
		e = data[i]; return true;
	}
	return false;
}
//�޸�iԪ�ص�ֵ
bool Vector::set(const int i, const ElemType e) {
	if (i >= 0 && i < n) {  //�±��Ƿ�Ϸ���
		data[i] = e; return true;
	}
	return false;
}


//----------ͼ�����------------------
#include <iostream>
//����һ������Ԫ�صĸ�������
void input(ElemType& e) {
	std::cout << "������ͼ�����Ϣ������ ���� ������ �۸�:\n";
	std::cin >> e.name >> e.author >> e.publisher >> e.price;
}
//��ӡһ��ͼ����Ϣ
void print(const ElemType& e) {
	std::cout << e.name << e.author << e.publisher << e.price << '\n';
}
//��ӡVector����v�е�����ͼ����Ϣ
void print(const Vector& v) {
	ElemType e;
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, e);
		print(e);//�����ͼ����Ϣ
	}
	std::cout << std::endl;
}
//������ʾ����
void help() {
	std::cout << "����������:i(����)��e(ɾ��)��a(׷��)��b(ɾ�����Ԫ��)��\n";
	std::cout << "s(��ɾ��ĳ���Ԫ��)��g(��ѯĳ���Ԫ��)��p(��ӡ)\n";
}
int main() {
	Vector books;
	ElemType e;
	char cmd;
	help();
	while (std::cin >> cmd) {
		if (cmd == 27)break;
		else if (cmd == 'I' || cmd == 'i') {//����һ��ͼ��
			std::cout << "����������λ�ã���0��ʼ����";
			int i; std::cin >> i;
			input(e);
			books.insert(i, e);
		}
		else if (cmd == 'e' || cmd == 'E') {//ɾ��һ��ͼ��
			std::cout << "������ɾ����λ�ã���0��ʼ����";
			int i; std::cin >> i;
			books.erase(i);
		}
		else if (cmd == 'a' || cmd == 'A') {//��������һ��ͼ��
			input(e);
			books.push_back(e);
		}
		else if (cmd == 'b' || cmd == 'B') {//ɾ�����һ��ͼ��
			input(e);
			books.pop_back();
		}
		else if (cmd == 's' || cmd == 'S') {//�޸�ĳ��ŵ�ͼ��
			std::cout << "������Ҫ�޸ĵ�ͼ���λ�ã���0��ʼ����";
			int i; std::cin >> i;
			input(e);
			books.set(i, e);
		}
		else if (cmd == 'g' || cmd == 'G') {//��ѯĳ��ŵ�ͼ��
			std::cout << "������Ҫ��ѯ��ͼ���λ�ã���0��ʼ����";
			int i; std::cin >> i;
			books.get(i, e);
			print(e);
		}
		else if (cmd == 'p' || cmd == 'P') {//��ʾ����ͼ��
			print(books);
		}
		help();

	}
}
