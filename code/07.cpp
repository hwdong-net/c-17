/*��ͳ�Ĺ���ʽ��̣�
���� (����)����һЩ�洢���ݵ��ڴ�飬������ (����)����Щ���ݽ��д���
*/

/*
 �������������̣��������ɲ�ͬ������������໥Э����ɵġ�
 ����֮��ͨ������/������Ϣ��Э����ɸ�������
 ����Щ���󹹳ɵĳ���Ҳ��Ϊ������ʽϵͳ��.
*/

//------------��class��struct�ؼ��ֶ���һ����----
//����������һ���������͡�

#if 0
#include <string>
using std::string;
struct student {
	string name;
	double score;
};

//C++�б���Ҳ��Ϊ���󣬶������ࣨ���ͣ��ľ���ʵ��
//��: student stu
//ͨ����Ա���������.���������ĳ�Ա
//�磺stu.score

int main() {
	student stu; //����һ�����ʵ��-����
	stu.name = "LiPing"; //��Ա���������.���������ĳ�Ա
	stu.score = 78.5;

	//����������һ�������Զ��������͵����飬�洢һ�������
	student students[3];
	students[0].name ="LiPing";
	students[0].score = 60.5;
}
#endif

#if 0
//T�������ͣ���T* ��Tָ������
#include <string>
using std::string;
struct student {
	string name;
	double score;
};
int main() {
	student stu;	
	student* p = &stu;

	(*p).name = "LiPing";   //*p����pָ��ı���stu
	p->score = 78;                //pָ��������ĳ�Աscore
	student students[3];
	p = students + 2;         //ָ���3��student����
	p->name = "Wang Wei";	
}
#endif

#if 0
//T�������ͣ���T* ��Tָ������
//T* ָ��ָ��̬�����һ����������
//��ͬint *��ָ��int���ͱ�����ָ������
//ͬ�������ü�ӷ�������� ->������������*����ָ��ָ��ı���

#include <string>
using std::string;
struct student {
	string name;
	double score;
};
int main() {
	student* p = new student;
	p->name = "Wang";
	delete p;                     //����Ҫ���ڴ��Ҫ��ʱ�ͷ�
	p = new student[3];   //pָ��̬�����3��student���ڴ�����ʼ��ַ
	p[1].score = 67;
	(*(p + 1)).score = 67;
	p->score = 78;
	delete[] p;
}
#endif

#if 0
//---��ĳ�Ա����----
// ������������ĺ��������Է��ʴ����ࣨ���󣩵�����
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print() { cout << name << " " << score << '\n'; }
};
int main() {
	student stu;
	stu.name = "LiPing"; //��Ա���������.���������ĳ�Ա	
	stu.score = 78.5;
	stu.print();
}
#endif 

#if 0
//������������ �����Ա����
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print();
};

void student::print() { 
	cout << name << " " << score << '\n';
}
int main() {
	student stu;
	stu.name = "LiPing"; //��Ա���������.���������ĳ�Ա	
	stu.print();
}
#endif 


# if 0
//----------this ָ��-----
//��ģ��Ǿ�̬����Ա��������һ��this����������
//��ָ���������������Ǹ�����
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print() { cout << name << " "<< score << '\n'; }
};
//void print(student *this){/*...*/}
int main() {
	student stu, stu2;
	stu.name = "Li"; stu.score = 67.8;
	stu2.name = "Wang"; stu2.score = 77.5;
	stu.print(); //  print(&stu)
	stu2.print();
}
#endif 

#if 0
#include <iostream>
#include <string>
using std::string;
using std::cout;

struct student {
	string name;
	double score;
	void print() {
		cout << this->name << "\t" << this->score<<std::endl;
	}
};

int main() { 
	student stu, stu2;
	stu.name = "Li"; stu.score = 78.6;
	stu2.name = "Wang"; stu2.score = 98.2;
	student* p = &stu;
	p->print();
	(*p).print();
	p = &stu2;
	p->print();
	(*p).print();
	
}
#endif 

#if 0
//----------�����Ĵ�С------------
//һ�������ռ�ݵ��ڴ��ŵ��������ݳ�Ա��
//��������Ĵ�С�����ϵ��ڻ��Դ����������ݳ�Առ���ڴ�֮�͡�
//Ϊʲô�Դ����������ݳ�Ա֮���أ�������Ϊ�������ڴ�����Ҫ�����ŵ�

#include <iostream>
class X {
	int a, b, c;
	double d;
};
int main() {
	X x;
	std::cout << sizeof(3) << '\t' << sizeof(double) << '\n';
	std::cout << sizeof(x) << '\t' << sizeof(X) << '\n';
}
#endif


//==============���캯��==============
//���������ʱ�����Զ��������ĳ�����캯��
//û�ж��幹�캯��������������Զ�����һ��
//�����б�ͺ����嶼Ϊ�յ�Ĭ�Ϲ��캯���� 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	void print() {
		std::cout << year << "-" << month << "-" << day << '\n'; 
	}
};
int main() {
	Date day, day1;  //day��day1����Ĭ�Ϲ��캯��
	day.print();
	day1.print();
}
#endif

#if 0
//---------��Ĭ�ϣ����캯��-------------
//���캯������������������ͬ��û�з�������
//Ĭ�Ϲ��캯�����������������������Ĭ��ֵ
#include <iostream>
class Date{
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() { 
		std::cout << "����Date����" << std::endl; 
		print(); 
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;   //���������ʱ�Զ�����ƥ��Ĺ��캯��
}
#endif 

#if 0
//---------���캯��-------------
//��������˹��캯������������Ͳ���������Ĭ�Ϲ��캯��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "����Date����" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	//Date day(2018, 8, 18),	       //���������ʱ�Զ�����ƥ��Ĺ��캯��
	//	day2{ 2019,6,1 };

	//Date day;    //��û�к��ʵ�Ĭ�Ϲ��캯������
	Date day(2010, 1,3);  //��û�����غ������� 4 ������
}
#endif 



#if 0
//---------��Ĭ�ϣ����캯��-------------
//����ͨ����һ������ĳ�Ա�������������캯�����Ĳ���
//Ҳ������Ĭ��ֵ,������Ĭ�ϲ���һ�ɿ��ҵĹ���.
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1(2011), day2{ 2019,6 },
		day3{ 2019,13,8 };
	day2.print();
}

#endif 

#if 0
//---------default����Ĭ�Ϲ��캯��-------------
//����ͨ��default�ؼ�����֪ͨ����������Ĭ�Ϲ��캯��
//���ܶ�����Ĭ�Ϲ��캯�����ض��壡
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() = default;//Date() {}
	Date(int y , int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;
}

#endif 

#if 0
//���Զ��������캯��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//Date() {}
	Date() = default;
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "����Date����" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018, 8, 18),	       //���������ʱ�Զ�����ƥ��Ĺ��캯��
		day2;
}
#endif

#if 0
//-------��ʼ����Ա�б�-----------
// �ں��������ʼ�������ĳ�Ա��
//��Ȼ�������ݳ�Ա��Date�ж���Ĵ���year��month��day�Ĵ������γ�ʼ����
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
//	Date(int y = 2000, int m = 1, int d = 1) 
//	:year{ y }, month(m), day(d){		}	
	Date(int y = 2000, int m = 1, int d = 1) 
		: day(d), month(m), year{ y }{
		//year = y; month = m; day = d;
		std::cout << "����һ��date����\n";
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 };	
	day.print();
	//Date day2{ day };
	//day2.print();
}
#endif 

#if 1
//ΪʲôҪ��ʼ����Ա�б�
//��Ϊ��Щ��Ա����non-static const�����ñ�������Ĭ�Ϲ��캯�������
//�޷��ڹ��캯�������ʼ��

#if 0
#include <iostream>
class X {
	const int a;
public:
	X(int x):a(x) {
		
	}  //Initializer list must be used
	int get() { return a; }
};

int main() {
	X x(10);
	std::cout << x.get();
	return 0;
}
#endif 

#if 0
using namespace std;
class X {
	const int &r;
public:
	X(int &b) :r(b) {//Initializer list must be used
		//r = b;
	}  
	int get() { return r; }
};

int main() {
	int i = 20;
	X x(i);
	cout << x.get() << endl;
	i = 30;
	cout << x.get() << endl;
	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;

class A {
	int i;
public:
	A(int);
};

A::A(int arg) {
	i = arg;
	cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B contains object of A
class B {
	A a;
public:
	B(int);
};

B::B(int x) :a(x) {  //Initializer list must be used
	
	cout << "B's Constructor called";
}

int main() {
	B obj(10);
	return 0;
}
#endif 
#endif 



#if 0
//-------�������캯��----------
//���Ѵ��ڵ�ͬ�����Ը�������ʼ����
//���û�ж��忽�����캯�������������Զ�����һ��Ĭ�Ͽ������캯����
#include <iostream>
using std::cout;
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();
}


#endif

#if 0
//���Զ����Լ��Ŀ������캯��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){
		std::cout << "�������캯��\n";
	}
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();	
}
#endif 

#if 0
//--------�������캯���Ĳ�������������---------
#if 0
class X {	
public:
	X() = default;
	X(X s) {}
};
int main() {
	X x;
	X y(x); //
}  
#else
class X {
public:
	X() = default;
	X( const X &x) {}
	//X& operator=(const X& object) { return *this; }
};
int main() {
	const X a;
	X b;
	X y(a),y2(b);
}
#endif

#endif 


#if 0
//---------Ĭ�ϣ���ֵ�����operator=---------------
//Ĭ������£����Խ�һ�������ֵ������һ�������
//���õ��ǣ���Ĭ�ϣ���ֵ�����operator=

#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day3;
	day3 = day; // day3.operator=(day)
	day.print();
	day3.print();

}
#endif 

#if 0
//---------��ֵ�����operator=---------------
// ��ֵ����������Ĳ����Ϳ������캯��һ���ģ���const��������
//�����ص��Ǳ���ֵ���������� *this
//�磺
class X {
	X& operator=(const X& object) {
		//...
		return *this;
  }
};
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& operator=(const Date& date) {
		std::cout << "��ֵ�����\n";
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this; //���ر���ֵ�������������
	}
};
//a=b=c

#if 0
//---------��ֵ�����operator=-�ҽ����--------------
int main() {
	Date day{ 2018,1,1 }, day3;
	day3 = day; // day3.operator=(day)
	day.print();
	day3.print();
}
#else
int main() {
	Date day(2018, 1, 1);
	Date day2(2020,4,8), day3;
	day3 = day2 = day; //��ִ��day2 = day�������day2����ִ��day3 = day2
					 //day2 = dayʵ����day2.operator=(day)
	//day3.operator=(day2.operator=(day))
	day.print();
	day2.print();
	day3.print();
}
#endif
#endif 


#if 0
//--------��ʽ����ת��------------
//---����1�������Ĺ��캯������������ʽ����ת��----
#include <iostream>
class A {
public:
	A(int x) { std::cout << "��" << x << "�������"; }
};

#if 0
int  main() {
	A a(1), b{ 2 }, c = 3;  //����A���3������a,b,c
	a = 4;    //����a= A(4);��4��ֵ��A�����
	          //�Ƚ�4ת��ΪA�����A(4)���ٸ�ֵ��
}
#else
void f(A a) {}
int main() {
	f(2); //����f(A(2)): ����ͨ�����캯��A(int)
	          //ת����A���Ͷ����ٶ�a��ʼ��
}
#endif

#endif 

#if 0
//Ȼ���������е��࣬������������ת�������һЩ���⡣
#include <iostream>
class Circle {
	double radius{ 0. };
public:
	 Circle(double r) :radius(r) {}
	auto area() { return 3.1415 * radius * radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};

int main() {
	Circle c(2), c2(5);
	std::cout << "c��c2������ǣ�" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2�������c��\n";
	else
		std::cout << "c2�������cС\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2�������50��\n";
	else
		std::cout << "c2�������50С\n";
}

#endif 


#if 0
//--------explicit---------------
//��explicit˵�����캯����ֹ��������ת��
#include <iostream>
class Circle {
	double radius{ 0. };
public:
	explicit Circle(double r) :radius(r) {}
	auto area() { return 3.1415 * radius * radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};

int main() {
	Circle c(2), c2(5);
	std::cout << "c��c2������ǣ�" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2�������c��\n";
	else
		std::cout << "c2�������cС\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2�������50��\n";
	else
		std::cout << "c2�������50С\n";
}
#endif 

#if 0
//-----------ί�й��캯��-------------
//ί�й��캯��:һ�����캯���ڳ�ʼ���б��ֵ��������Ĺ��캯��.
//���Ա����ظ��Ĵ���
//ί�й��캯��ֻ���ڳ�ʼ����Ա�б���������ں���������ñ�ί�й��캯����
//��Ա����������ί�й��캯���ĳ�ʼ���б����ʼ�����������ں��������ʼ����Ա������
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
		std::cout << "Ĭ�Ϲ��캯����\n";
	}
	//ί��Date(int y=2000,int m=1,int d=1)���캯��  
	Date(int* p) :Date(p[0], p[1], p[2]) {	
		std::cout << "ί�й��캯����\n";
	}
	//Date(int* p) :Date(p[0], p[1], p[2]), day{ 20 } {	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	int date[]{ 2018,9,6 };
	Date d(date); d.print();
}
#endif

#if 0
//-------delete----------
//����ϣ����ֹĳ�����캯����ֵ�������
//�����ֹ����������Ĭ�ϵĿ������캯����ֵ�������
//����ͨ��delete�ؼ�����ʽ�ؽ���˵��
class A {
public:
	A(int) {/*...*/ }
	A(double) = delete;
	A& operator=(const A& o) = delete;
	A(const A& o) = delete;
};
int main() {
	A a(1);
	A a1(3.14);  //�� A(double)����ֹ��
	A a2(a);     //��A(const A& o) ����ֹ��
	a2 = a1;     //��A& operator=(const A& o) ����ֹ��
}
//�������������Ҳ�ǽ�ֹ�������ģ�
//��Ϊ��������ļ��̺��������Ļֻ��һ����������������ͻ����ˡ�
#endif



#if 0
//-------����������----------
//һ��û�й��캯�����߶�����Ĭ�Ϲ��캯�����࣬�ſ��Զ���������Ķ�������顣
#include <iostream>
class X {	
public:
	void set_x(int i) { x = i; }
	void print() { std::cout << x; }
private:
	int x{ 0 };
};

int main() {
	X x;
	x.print(); std::cout << '\n';
	X arr[3];              //X����������
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
	for (auto i = 0; i != 3; i++) 
		arr[i].set_x(2 * i + 1);
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
}
#endif 

#if 0
//-------����������----------
//��Ĭ�Ϲ��캯�����࣬�ſ��Զ�������������
class X {
	int x{ 0 };
public:	
};
int main() {
	X arr[3];    //X�б��������ɵ�Ĭ�Ϲ��캯�����ɶ���X���͵����飡
	X* p = new X[3];
}
#endif 

#if 0
//-------����������----------
//û��Ĭ�Ϲ��캯�����࣬���ܶ�������������
class X {
int x{ 0 };
public:
	X(int i) :x(i) {}
};
int main() {
	X arr[3];    //Xû��Ĭ�Ϲ��캯������˲��ܶ���X���͵����飡
}
#endif 

#if 0
//-------���ʿ���--------------
//private��public�ؼ���˵����ĳ�Ա�Ƿ���Ա�������
#include <iostream>
class X {
	int x;
public:
	void set_x(int i) { x = i; }
	int get_x() { return x; }
};

int main() {
	X x;
	x.x = 5;
	x.set_x(5);
	std::cout << x.get_x();
}

#endif

#if 0
//-------���ʿ���--------------
//private,public,protected
#include <iostream>
class Date {
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	Date(int* p) :Date(p[0], p[1], p[2]) { //ί��Date(int y=2000,int m=1,int d=1)���캯��    
	}
	//get��������������������
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

	//set�������޸�����������
	void setYear(int y) { if (y > 0) year = y; }
	void setMonth(int m) { if (m > 0) month = m; }
	void setDay(int d) { if (d > 0) day = d; }
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
private:
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
int main() {
	Date day;
	day.month = 4;
	day.setYear(2018);
	std::cout << day.getMonth() << '\n';
}
#endif

#if 0
//------const����:�����޸ĵĶ���---------
int main() {
	int i;
	const int ci = 1;
	ci = 3;             //�������޸�const����(����)
	const int* p = &i;    //p��ָ��const int���������󡱵�ָ�����
	*p = 3;            //�������޸�pָ��ĳ�����(const����)
	const int& r = i;     //r��const int�������󡱵�����
	r = 3;              //�������޸�r���õĳ�����(const����)
}
#endif

#if  0
//------const����:�����޸ĵĶ���---------
#include <iostream>
class Date {
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	void setYear(const int year) { this->year = year; }
	int getYear() { return year; }
};
int main() {
	const Date day;
	day.setYear(2008);            //������ȥ�޸�const����day
	std::cout << day.getYear();      //��getYear��Ȼ�����޸�day			
									 //����������ô֪�����᲻���޸�day�������أ�
}
#endif

#if  0
//--------const��Ա����:�����޸����ݳ�Ա�ĺ���---------
#include <iostream>
class Date {
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	void setYear(const int year) { this->year = year; }
	int getYear()const { return year; }
};
int main() {
	const Date day;
//	day.setYear(2008);            //������ȥ�޸�const����day
	std::cout << day.getYear();      //��getYear��Ȼ�����޸�day			
									 //����������ô֪�����᲻���޸�day�������أ�
}
#endif 

#if  0
//-----------����const-----------
//const�����е�const�ؼ����Ǻ���ǩ����һ���֣�
// Ҳ����˵�����������ؽ�������������ͬ�������ġ�
class X {
	void f() {/*...*/ }
	void f()const {/*...*/ }
};

//����ͨ��const�����const�����ָ������õ��������const����
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;                 //OK
	std::cout << day.year() << std::endl;   //OK
	const Date day2;
	day2.year() = 2008;                //��������Ǻ���ģ���Ϊ�����޸�const������
	std::cout << day2.year() << std::endl;  //������󡣲�����Ϊʲô���ܲ�ѯconst������Ϣ��    
}

#endif

#if 0
//�������������const��������һ�����ص�const������
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
	const int& year() const { return _year; }
	const int& month() const { return _month; }
	const int& day() const { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;    //û���⣬���õ��Ƿ�const������int& year()
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	//day2.year() = 2008;  //��������Ǻ���ģ���Ϊ�����޸�const����
	std::cout << day2.year() << std::endl; //OK,û�б������    
}

#endif 

#if 0
//mutable
//��mutable��Ա���ǿ��Ա��޸ĵģ���ʹ��const����
#include <iostream>
class X {
	mutable int count{ 0 }; //count��mutable����
	int ival{ 0 };
public:
	int val()const {
		count++;       //mutable��Ա���ǿ��Ա��޸�
		return ival;
	}
	int get_count()const { return count; }
};

int main() {
	X x;
	std::cout << x.val() << '\n';
	std::cout <<x.get_count();
}
#endif

#if 0
//��һ�����������ʱ�������һ����Ϊ����������destructor���������Ա������
class X {
public:
	~X() {  }  //��~X()=default
};
#endif


#if 0
//��һ�����������ʱ�������һ����Ϊ����������destructor���������Ա������
#include <iostream>
class X{
public:
	X(){ std::cout << "���캯����������Դ\n"; }
	//~X()=default
	~X() {
		std::cout << "����������������/�ͷŶ���ռ�õ���Դ\n";
	}
}; 

int main() {
	X x;
}

#endif


#if 0
//IntArray���ʾһ���̶���С������Ԫ����int�Ķ�̬���顣
#include <iostream>
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

int main() {
	std::cout << "������������";
	int s; std::cin >> s;

	IntArray arr(s);      //����IntArray���󣬻�Ϊs.data��Ա����һ�鶯̬�ڴ�

	std::cout << "���������䣺";
	for (auto i = 0; i < s; i++) {
		int age;
		std::cin >> age;
		arr.put(i, age);
	}
	std::cout << "����������ǣ�\n";
	for (auto i = 0; i < s; i++)
		std::cout << arr.get(i) << '\t';
	std::cout << '\n';       //�������󣬽�����arr�����IntArray��
//���������ͷ�arr.dataָ��Ķ�̬�ڴ�
}
#endif 

#if  0
//static�ؼ������εĳ�Ա��Ϊ��̬��Ա��
//��̬��Ա���������������ĳ�����󡣾�̬��Ա�����������ж�����ġ�

# if 0
class X {
private:
	static int count;   //count����X�ľ�̬��Ա��������ʾ��X�Ķ���ĸ���
public:
	static int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};
int X::count = 0;       //�� int X::count{0};

#else 
//��X�����еľ�̬��Ա����count���������������Ƕ��壬��ˣ����ඨ���в��ܶ�����ʼ����
class X {
private:
	static  int count{0};   //count����X�ľ�̬��Ա��������ʾ��X�Ķ���ĸ���
public:
	static int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};
#endif
//��̬��Ա���������������ⶨ�壬��Ϊ��������ĳ������


#include <iostream>
int main() {
	//X x,y;
	std::cout<<X::get_count();
	//std::cout << X::count;
}
#endif

#if  0
//��C++17��ͨ���ؼ���inline����һ����̬������ʹ�þ�̬��Ա�������붨��ͳһ������
class X {
private:
	 static inline int count{ 0 };   //count����X�ľ�̬��Ա��������ʾ��X�Ķ���ĸ���
public:
	int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};
int main() {
	X x;
}
#endif 

#if 0
//��̬const��Ա����
class Circle {
public:
	static inline const double PI{ 3.1415926 };
	//static void init() { radius = 0; }
	Circle(double r) :radius(r) {}
	auto area() { return PI * this->radius * radius; }
private:
	double radius{ 0. };
};

#include <iostream>
int  main() {
	Circle c(2.5);
	std::cout <<sizeof(c)<<" "<< c.area() << " " <<c.PI<<" "<<Circle::PI;
}

#endif

#if 0
//��̬��Ա����(static member function)
//����������ĳ�Ա���������ܷ��ʷǾ�̬��Ա
class X {
public:
	static inline int count{};   //count����X�ľ�̬��Ա��������ʾ��X�Ķ���ĸ���
public:
	static int get_count() { return count; };    //��̬��Ա����
	X() { count++; }         //������һ���µ�X����,count����1
	~X() { count--; }         //������һ���µ�X����,count����1
};
//�;�̬��Ա������ͬ���ǣ���̬��Ա�����Ķ��������ȫ�����������ڣ���ȻҲ���Զ����������⡣
//��̬��Ա�����;�̬��Ա�����������������࣬ͨ�������Ϳ��Ե��þ�̬��Ա������
//����ͨ��Ա��������ͨ���������ܵ��á�
#include <iostream>
int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\t' << arr[1].get_count() << '\t'
		<< X::get_count() << '\n';
}

#endif

#if 0
//���������͵ľ�̬��Ա����
#include <iostream>
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:
    const static Date default_date;
	
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
//�����������ⶨ������
const Date Date::default_date{ 2010,1,1 };

int main() {
	Date arr[3];
	Date d(2018, 6, 8);
	Date arr2[5];

}
#endif

#if  0
//Ҳ���Խ�������ɷ�const���͵ľ�̬��Ա���Ա�����޸���
#include <iostream>
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:
	static Date default_date;
	static void set_default(const Date& d) {
		default_date.year = d.year;
		default_date.month = d.month;
		default_date.day = d.day;
	}
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
//Ȼ���������⣬��������
Date Date::default_date{ 2010,1,1 };
//���ھͿ����޸������̬��Ա�����ˣ�
int main() {
	Date arr[3];
	Date d(2018, 6, 8);
	d.set_default(d);     //  ��Date::set_default(d)
	Date arr2[5];
}
#endif

#if 0
//�������ùؼ���friend����ĳ���ⲿ�������ⲿ������������Ԫ��
//������ⲿ�������ⲿ���ǿ���ֱ�ӷ���������private��Ա��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
	friend void print(const Date& day); //�ⲿ����print��Date�����Ԫ
};
void print(const Date& day) { //print���Է���Date����day��˽�г�Ա
	 std::cout << day.year << "-" << day.month << "-" << day.day << '\n';    
}
void print2(const Date& day) {//print2���ܷ���Date����day��˽�г�Ա
	 std::cout << day.year<< "-" << day.month << "-" << day.day << '\n';    
}

#endif

#if 0
//����ͨ�����������Ϊ������inline������������߳���Ч��һ����
//��ĳ�Ա����Ҳ������������inline����Ա������
//���һ����ĳ�Ա����������������ʵ�ֵģ���������Զ��ͳ�Ϊ��������Ա������
//���һ����ĳ�Ա����������ʵ�ֵģ�������������ں���������ǰ�ӹؼ���inline��
// �������⺯������ǰ���ܼ�inline��
class X {
public:
	inline void f();
};
void X::f() {
	/*...*/
}
//��������������f()��������Ա�����������⺯������ǰ�������йؼ���inline��
#endif

#if 0
#define  _CRT_SECURE_NO_WARNINGS
//�ض��忽�����캯���͸�ֵ�����
//��ֹ������Դ���µ����⡰������١��ͷ�ͬһ����Դ��

#include <iostream>
#include <cstring>   //strlen()
class String {
	char* data{ nullptr };
	int size_{ 0 };
public:
	String() = default;
	String(const char* s) {
		auto len = strlen(s);
		data = new char[len + 1];  //����һ��洢�ַ��Ķ�̬�ڴ��
		if (!data) return;
		strcpy(data, s);         //�����ַ������ݴ�s��dataָ��Ŀռ�
		size_ = len;
	}
	~String() {
		delete[] data;
	}
	auto size() { return size_; }
};

int main() {
	String s("hello world");
	String s2(s);    //���ÿ������캯������s�������¶���s2��

	String  s3;
	s3 = s;
}

#endif

#if 0
//����İ취�����¶��忽�����캯���͸�ֵ�������
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>   //strlen()

#include <iostream>
#include <cstring>   //strlen()
class String {
	char* data{ nullptr };
	int size_{ 0 };
public:
	String() = default;
	String(const char* s) {
		auto len = strlen(s);
		data = new char[len + 1];  //����һ��洢�ַ��Ķ�̬�ڴ��
		if (!data) return;
		strcpy(data, s);         //�����ַ������ݴ�s��dataָ��Ŀռ�
		size_ = len;
	}
	auto size() { return size_; }

	String(const String& s);
	String& operator=(const String& s);
};


String::String(const String& s) {
	std::cout << "�������캯��:\n";  //������������Ƿ����ú���
	if (s.data == 0)return;
	if (this != &s) {
		data = new char[s.size_ + 1]; //����һ���Լ�ר�õ��ڴ濨
		if (!data) return;
		size_ = s.size_;
		strcpy(data, s.data); //�����ַ�������
	}
}

String& String::operator=(const String& s) {
	if (this != &s) {
		std::cout << "��ֵ�����:\n";  //������������Ƿ����ú���
		if (s.data == 0) return *this;
		data = new char[s.size_ + 1]; //����һ���Լ�ר�õ��ڴ濨
		if (!data) return *this; 
		size_ = s.size_;
		strcpy(data, s.data); //�����ַ�������
	}
	return *this;
}

int main() {
	String s("hello world");
	String s2(s);    //���ÿ������캯������s�������¶���s2��

	String  s3;
	s3 = s;
}
#endif