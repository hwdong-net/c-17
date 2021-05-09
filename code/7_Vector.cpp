#include <iostream>
#if 0
class IntArray {
	int* data{ nullptr };      //ָ�����ָ��̬������ڴ��
	int size{ 0 };            //dataָ��Ķ�̬����Ĵ�С
public:
	IntArray(int s) :size(s) {
		data = new int[s];    //����һ�鶯̬�ڴ棬��ַ������data��
		if (data)  size = s;
		std::cout << "������һ����С��" << s << "��IntArray����\n";
	}
	~IntArray() {
		std::cout << "��������\n";
		if (data) delete[] data;  //�ͷ�dataָ��Ķ�̬�ڴ�
	}
	void put(int i, int x) {
		if (i >= 0 && i < size) data[i] = x;
	}
	int get(int i) {
		if (i >= 0 && i < size) return data[i];
		else return 0;
	}
};

#include <vector>
int main(){
	//int ages[5];//��̬����
	
	std::vector<int> ages;
	ages.push_back(3);
	ages.push_back(45);
	ages.size();
}
#endif
/*
struct student {
	string name;
	double score;
};
using ElemType = student;   //��������Ԫ������ElemType��char����
*/
using ElemType = char;   //��������Ԫ������ElemType��char����

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

#include <iostream>
void print(const Vector& v) {   //������Ա��е�����Ԫ��
	ElemType ele;
	//����ÿһ���±�i:0,1,��,size()-1
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, ele);   //ͨ��e�����±�i����Ԫ��ֵ 
		std::cout << ele << '\t';
	}
	std::cout << std::endl;
}

int main() {
	Vector v(2);           //����������2�Ŀ����Ա�
	v.push_back('a');     //���Ա�������һ��Ԫ�ء�a��
	v.push_back('b');     //���Ա�������һ��Ԫ�ء�b��
	v.push_back('c');
	v.insert(1, 'd');    //�±�1������һ��Ԫ�ء�d��
	print(v);
	ElemType e;
	v.get(1, e);         //��ѯ�±�1����Ԫ��ֵ
	std::cout << e << '\n';
	v.set(1, 'f');       //�޸��±�1����Ԫ��ֵΪ��f��
	print(v);
	v.erase(2);          //ɾ���±�2����Ԫ��
	print(v);
	v.pop_back();       //ɾ�����һ��Ԫ��
	print(v);
}