#if 0
//Dog��������һ�������Animal�����
//һ��Dog����Animal���������ԣ�������Dog���е����ԣ����繷ϲ���ٹ�ͷ��й�ͷ��
//�����ࣺ�����ظ�

class Animal
{
	//...
	void run() {/*...*/}
};
class Dog
{
	//...
	void run() {/*...*/ }
	void eat_bone() {/*...*/ }
};
#endif

#if 0
//Dog��̳�Animal�࣬Animail���Ϊ���࣬Dog���Ϊ������
class Animal
{
	//...
	void run() {/*...*/ }
};
class Dog:public Animal
{
	//...
	//void run() {/*...*/ }
	void eat_bone() {/*...*/ }
};
#endif

#if 0
//������Ķ���:
class �������� : public ������
{
	//�������Ա(���ݳ�Ա�ͳ�Ա����)
};
#endif


#if 0
//Sprite����ʾ��Ϸ�����еľ���Ĺ���
#include <iostream>
using std::cout;
class Sprite {
	double pos[2]{}, vel[2]{ 1.,1. };    //λ��pos���ٶ�vel
public:
	Sprite(double* p = 0, double* v = 0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1]; }  //�����ٶȸ���λ��
	void draw() {
		cout << "��(" << pos[0] << ',' << pos[1] << ")λ�û��ƾ���\n";
	}
};

//Ball(��)��һ������ľ���
class Ball : public Sprite {
	double radius{ 1. };
public:
#if 0
	Ball(double x, double y, double vx, double vy, double r)
	{
		pos[0] = x;
	}
#endif
};

//Paddle(����)��һ������ľ���
class Paddle : public Sprite {
	double width,height;
public:
	Paddle(double w, double h) :width(w), height(h) {}	
};

int main() {
	Ball ball;
	ball.update();
	ball.draw();
	Paddle paddle1(2,5), paddle2(2,5);
	paddle1.update(); paddle2.update();
	paddle1.draw(); paddle2.draw();
}
#endif

#if 0
class Ball : public Sprite {
	double radius{ 1. };
public:
	void draw() {		
		cout << "���ư뾶" << radius << "��Բ����("
			<< pos[0] << ',' << pos[1] << ")��Բ\n";
	}
};
#endif

#if 0
#include <iostream>
using std::cout;
class Sprite {
protected://������Ա
	double pos[2]{}, vel[2]{ 1.,1. };    //λ��pos���ٶ�vel
public:
	Sprite(double* p = 0, double* v = 0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1]; }  //�����ٶȸ���λ��
	void draw() {
		cout << "��(" << pos[0] << ',' << pos[1] << ")λ�û��ƾ���\n";
	}
};

class Ball : public Sprite {
	double radius{ 1. };
public:
	void draw() {
		cout << "���ư뾶" << radius << "��Բ����("
			<< pos[0] << ',' << pos[1] << ")��Բ\n";
	}
};
// ��������ʻ����hide��Ա���û���������
class Paddle : public Sprite {
	double width, height;
public:
	Paddle(double w, double h) :width(w), height(h) {}
	void draw() {
		Sprite::draw();
		cout << "���ƿ��Ϊ" << width << ',' << height << "������\n";
	}
};
int main() {
	Ball ball;
	ball.update();
	ball.draw();
	Paddle paddle1(2, 5), paddle2(2, 5);
	paddle1.update(); paddle2.update();
	paddle1.draw(); paddle2.draw();
}

#endif

#if 0
//------------�̳з�ʽ--------------
//һ����ͨ��private��protected��public�ؼ������γ�Ա�����Ƴ�Ա�����Ŀɼ��ԡ�
//�ؼ���private��protected��publicҲ�������ڶ���������ӻ���ļ̳з�ʽ�������ƻ����Ա��������Ŀɼ��ԡ�
class B {
};
class D1 : public B{
	//...
};
class D2 : protected B {
	//...
};
class D3 : private B {
	//...
};

//�� class����һ��������ʱ�����û��ָ��������ʽ����Ĭ���� private�̳з�ʽ��
class D :  B    //�ȼ���class D : private B 
{
	//...
};

//�����Ա���������еķ��ʿɼ���
#endif

#if 0
//���������Ҳ��һ������Ļ������
//Dog��һ��Animal
//���Խ�һ����������󵱳�һ���������ʹ��
#include <iostream>
class B {
	int b{ 0 };
public:
	B(int b = 0) :b(b) {}
	void print() { std::cout << "B:" << b; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(double d = 0) :d(d) {}
	void print() {
		std::cout << "D:";
		B::print(); std::cout << '\t' << d;
	}
};

int main() {
	B b{ 1 };
	D d{ 3.14 };
	b.print();  std::cout << '\n';
	d.print();  std::cout << '\n';
	b = d;
	b.print();  std::cout << '\n';
}
#endif


#if 0
//����ָ���������ָ��
//���⡰�����и�ĸ��õķ������û���ָ��ָ����������󣬻���˵��������ָ�븳ֵ������ָ�������
#include <iostream>
class B {
	int b{ 0 };
public:
	B(int b = 0) :b(b) {}
	void print() { std::cout << "B:" << b; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(double d = 0) :d(d) {}
	void print() {
		std::cout << "D:";
		B::print(); std::cout << '\t' << d;
	}
};

#if 1
int main() {
	B b{ 1 };
	D d{ 3.14 };
	B* p = &b;            //����ָ��pָ��������b
	p->print(); std::cout << '\n';
	p = &d;               //����ָ��pָ�����������d
	p->print(); std::cout << '\n';
}
#endif

#if 0
//����ָ��ǿ������ת��Ϊ������ָ��
int main() {
	B b{ 1 };
	D d{ 3.14 };
	B* p = &b;            //����ָ��pָ��������b
	p->print(); std::cout << '\n';
	p = &d;               //����ָ��pָ�����������d
	((D*)p)->print(); std::cout << '\n';
	(static_cast<D*>(p))->print(); std::cout << '\n';	
}
#endif
#endif 

#if 0
//----------������Ĺ��캯��---------
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B�๹�캯��\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D() { cout << "D�๹�캯��\n"; }
};
int main() {
	D d;
}
//�ȵ��û��๹�캯���������������Ļ��ಿ��
//�ٵ��������๹�캯������ʼ�������ಿ��
#endif

#if 0
//--------���������������----------
//������һ������ʱ��ȴ�Ƿ�������У�
//����ִ���������Լ�������������Ȼ�������ϲ�Ļ��������������ֱ�����ϲ���������������
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B�๹�캯��\n"; }
	~B() { cout << "B����������\n"; }

};
class D :public B {
	double d{ 2.5 };
public:
	D() { cout << "D�๹�캯��\n"; }
	~D() { cout << "D����������\n"; }
};
int main() {
	D d;
}
#endif 

#if 0
//---------��������ĳ�ʼ����Ա�б�����û�����������캯��-----------
//������Ĺ��캯�����õ��ǻ���Ĭ�ϵĹ��캯����
//Ҳ������������ĳ�ʼ����Ա�б�����û�����������캯����
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B��Ĭ�Ϲ��캯��\n"; }
	B(int b) :b(b) { cout << "B�๹�캯��\n"; }
	~B() { cout << "B����������\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D() :B(2) { cout << "D��Ĭ�Ϲ��캯��\n"; }  //�ڳ�ʼ����Ա�б�����û��๹�캯��
	~D() { cout << "D����������\n"; }
};
int main() {
	D d;
}


#endif 

#if 0
//------ ���û��๹�캯�������ṩ��Ӧ�Ĳ���----------
//�����ڳ�ʼ����Ա�б�����ʽ���û��๹�캯�����ṩ����Ĳ�����
//��ˣ����๹�캯����Ҫ�Ĳ���ͨ��Ӧ����������Ĺ��캯�����β��б��г��֡�
#include <iostream>
#include <string>
using std::cout;
using std::string;
class B {
	int b{ 0 };
	string name{};
public:
	B(int b, string n) :b(b), name(n) {
		cout << "B�๹�캯��\n"; }
	~B() { cout << "B����������\n"; }

};
class D :public B {
	double d{ 2.5 };
public:
	D():B(2,"hello") { cout << "D��Ĭ�Ϲ��캯��\n"; }
	D(double d, int i, string s) :B(i, s), d(d) {}
	~D() { cout << "D����������\n"; }
};
int main() {
	D d;
}

// D(double d,int b,string n):B(b,n),d(d) {
//     cout << "D�๹�캯��\n"; }
// D():B(2,"name"),d(d) { cout << "D��Ĭ�Ϲ��캯��\n"; }
#endif

#if  0
//------ע�⣺������Ŀ������캯�����û����Ĭ�Ϲ��캯�������ǿ������캯��--
#include <iostream>
using std::cout;
class B {
public:
	B() { cout << "B��Ĭ�Ϲ��캯��\n"; }
	B(const B& b) { cout << "B�࿽�����캯��\n"; }
};
class D :public B {
public:
	D() { cout << "D��Ĭ�Ϲ��캯��\n"; }
	D(const D& d) { cout << "D�࿽�����캯��\n"; }
};
int main() {
	D d, d2(d);
}
#endif

#if 0
//����취���������࿽�����캯���ĳ�ʼ����Ա�б�����û���Ŀ������캯����
#if 0
#include <iostream>
using std::cout;
class B {
public:
	B() { cout << "B��Ĭ�Ϲ��캯��\n"; }
	B(const B& b) { cout << "B�࿽�����캯��\n"; }
};
class D :public B {
public:
	D() { cout << "D��Ĭ�Ϲ��캯��\n"; }
	D(const D& d) :B{ d }  //�ڳ�ʼ����Ա�б�����û���Ŀ������캯��
	{
		cout << "D�࿽�����캯��\n";
	}
};
int main() {
	D d, d2(d);
}

#else

//����Ĵ������B��D����һЩ��Ա������
//������Ŀ������캯���ĳ�ʼ����Ա�б���ͬ�������˻���Ŀ������캯����
#include <iostream>
#include <string>
using std::cout;
using std::string;
class B {
	int b{ 0 };
	string name{};
public:
	B(const B& b) :b(b.b), name(b.name) { cout << "B�࿽�����캯��\n"; }
	B(int b, string n) :b(b), name(n) { cout << "B�๹�캯��\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(const D& d) :d(d.d), B(d) { cout << "D�࿽�����캯��\n"; }
	D(double d, int b, string n) :B(b, n), d(d) { cout << "D�๹�캯��\n"; }

};
int main() {
	D d(3.0, 2, "helo");
	std::cout << '\n';
	D d2(d);
	std::cout << '\n';
}

#endif 
#endif 

#if 0
//-------��̳�-------
//�Ӷ��ֱ�ӻ��ඨ��һ�������࣬����˵һ������Լ̳ж�����࣬
//���ּ̳з�ʽ��Ϊ��̳У�Multiple Inheritance����

class A {
	/*...*/
};
class B {
	/*...*/
};
class C {
	/*...*/
};
class D : public A, protected B, private C {
	//��D��ĳ�Ա
};
//D�ֱ���public��protected��private�Ȳ�ͬ�̳з�ʽ�̳��˻���A��B��C�����ԡ�


#include <iostream>
class Shape {
public:
	void draw() { std::cout << "����һ����״\n"; }
};
class Color {
	int color{ 0 };
public:
	int get_color() { return color; }
};
class Circle :public Shape, public Color {
public:
	void draw() { std::cout << "����Բ\n"; }
};

int main() {
	Circle c;
	std::cout << c.get_color() << '\n';
	c.draw();
}

#endif 

#if 0
//--------��̳еĶ���������-----------
//���һ��������Ĳ�ͬ���������ͬ�������ݳ�Ա��ͬ��ǩ���ĺ�����Ա��
//��ͨ���������������������Աʱ�����ܻ�������������⡣
#include <iostream>
class USBDevice {
private:
	long m_id;
public:
	USBDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};

class NetworkDevice {
private:
	long m_id;
public:
	NetworkDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
	WirelessAdapter(long usbId, long networkId)
		: USBDevice(usbId), NetworkDevice(networkId) {	}
};
int main() {
	WirelessAdapter  wa(5442, 181742);
	std::cout << wa.getID(); // ������һ��getID()��
	return 0;
}

//��ν����
#endif

#if 0
//------------�����----------

#include <iostream>
#include <string>
using namespace std;
class Person { //��
protected:
	string name{ "noname" };
};

#if 0
//��̳�ʱ����һ��������������ж�ݼ�ӻ������
class PartyMember : public Person { //��Ա
protected:
	string party{ "RP" };
};

class Teacher : public Person { //��ʦ
protected:
	string title{ "TA" }; //ְ��
	string profession{ "CS" };// רҵ
};

class TeacherPM :public Teacher, PartyMember {  //��ʦ��Ա
};

int main() {
	Person p;
	PartyMember pm;
	Teacher t;
	TeacherPM tpm;
	string s{ "hello" };
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;
}

#else
//Ϊ�˱������ּ�ӻ���������������г��ֶ��������
// �����ڶ���������ʱ�������̳еĻ���Ϊ�����
class PartyMember : virtual public Person { //��Ա
protected:
	string party{ "RP" };
};
class Teacher : virtual public Person { //��ʦ
protected:
	string title{ "RP" }; //ְ��
	string profession{ "CS" };// רҵ
};
class TeacherPM :public Teacher, PartyMember {  //��ʦ��Ա
};
int main() {
	Person p;
	PartyMember pm;
	Teacher t;
	TeacherPM tpm;
	string s{ "hello" };
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;
}

#endif
#endif


#if 0
//-------���������Ҳ�ǻ�������-----
// �����������ֵ��������󣬻�������и����⡱
#include <string>
#include <iostream>
using namespace std;

class Person { //��
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\t'; }
};
class Student :public Person { //ѧ��
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};
int main() {
	Person p{ "Li Ping" };
	Student s{ "Zhang wei",60 };
	p = s;            //�����������Ը�ֵ��������󣬵��������и�
	cout << p.score;    //��p��Person����û��score����
	s = p;            //�����ܽ�Person����ֵ��Student����
}

#endif

#if  0
//---------ָ�����������ת��-----------
//������ָ���������ת��Ϊ����ָ��
#include <string>
#include <iostream>
using namespace std;

class Person { //��
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\t'; }
};
class Student :public Person { //ѧ��
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};


#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;          //���������s�ĵ�ַ(ָ��)��ֵ������ָ�����
	Person& r = s;     //�������ñ��������������������
	pp->print();
	r.print();
}

#else

//��ͨ�����ǵ��õ�print()������Ȼ�ǻ���������������print()������
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;          //���������s�ĵ�ַ(ָ��)��ֵ������ָ�����
	Person& r = s;     //�������ñ��������������������
	pp->print();
	r.print();

	Student* ps = static_cast<Student*>(pp);     //��Person*ǿ��ת��ΪStudent*
	ps->print();
	ps = static_cast<Student*>(&p);             //��Person*ǿ��ת��ΪStudent*
	ps->print();
}
#endif

#endif 

#if 0
//---------static_cast<>ֻ������������͵�ǿ������ת��-------------
//static_cast<>ֻ������������ͣ�����м̳к�������ϵ��ָ�루�����ã�����֮���ǿ������ת����
//2����ͬ����ָ�루�����ã���D* ��X* ֮���ǲ�����static_cast<>ǿ������ת���ģ�
#include <iostream>
struct B {
	int m = 0;
	void print() const { std::cout << "Hi, this is B!\n"; }
};
struct D : B {
	void print() const { std::cout << "Hi, this is D!\n"; }
};
class X {};
int main() {
	int n = static_cast<int>(3.14);     //��������֮���static_cast
	D d;
	B& br = d;      // ��������ת�������������ÿ����Զ�����ת��Ϊ��������
				 //Ҳ������static_cast<>�� B& br = static_cast<B&>d;
	br.print();
	D& dr = static_cast<D&>(br);    // ��������ת��(downcast)
	dr.print();

	D* dp = new D;
	B* bp = dp;       // ��������ת����������ָ������Զ�����ת��Ϊ����ָ��
				   // Ҳ������static_cast<>�� B*bp = static_cast<B*>d;
	D* dp2 = static_cast<D*>(bp); // this works
	X* xp = static_cast<X*>(dp);    // ��������޷��ӡ�D *��ת��Ϊ��X *��

	void* p = dp; //�κ�ָ�붼����ת��Ϊvoid*
	D* dp3 = static_cast<D*>(p);  //��void*ǿ��ת��ΪD*��
	return 0;
}

#endif 


//==============9.4 ��̬(Polymorphism)==================


#if 0
#include <string>
#include <iostream>
using namespace std;
class Person { //��
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\n'; }
};
class Student :public Person { //ѧ��
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};

//-----------���������Ҳ�ǻ������----------------
#if 0
int main() {
	Person p{ "Li Ping" };
	Student s{ "Zhang wei",60 };
	p = s;            //�����������Ը�ֵ��������󣬵��������и�
	cout << p.score;    //��p��Person����û��score����
	s = p;            //�����ܽ�Persion����ֵ��Student����
}
#endif 

//-------- ����ָ�루���ã�����������ת��------
#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;        //���������s�ĵ�ַ(ָ��)��ֵ������ָ�����
	Person& r = s;  //�������ñ��������������������
	pp->print();
	r.print();
}
#endif

#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;        //���������s�ĵ�ַ(ָ��)��ֵ������ָ�����
	Person& r = s;  //�������ñ��������������������
	pp->print();
	r.print();
	Student* ps = static_cast<Student*>(pp);     //��Person*ǿ��ת��ΪStudent*
	ps->print();
	ps = static_cast<Student*>(&p);             //��Person*ǿ��ת��ΪStudent*
	ps->print();
}
#endif 

#endif 


//-----------�麯���Ͷ�̬----------------

#if 0
#include <string>
#include <iostream>
using namespace std;

//��ǰ���Person��print()��������Ϊ�麯����
class Person { //��
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print() { cout << name << '\t'; }
	virtual ~Person() { cout << "Person����������\n"; }
};

//ֻҪ�ڻ������ùؼ���virtual�������麯����
// ������������麯��ǰ�ɼӿɲ���virtual�ؼ��֣�������������麯����
class Teacher :public Person { //ѧ��	
public:
	string title{ "��ʦ" }; //ְ��
	Teacher(string n, string t) :Person(n), title(t) {}
	void print() { Person::print(); cout << title << '\n'; }
	virtual ~Teacher() { cout << "Teacher����������\n"; }
	
};

class Student :public Person { //ѧ��
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
	virtual  ~Student() { cout << "Student����������\n"; }
};

#if  1
int main() {
	Person p{ "Li Ping" }, *pp = &p; //ppָ����Person����
	Student s{ "Zhang wei",60 };
	Teacher t{ "��ǿ","����" };
	pp->print();         //���õ���Person��print()
	cout << '\n';
	pp = &s;           //ppָ����Student����
	pp->print();        //���õ���Student��print()
	cout << '\n';
	pp = &t;          //ppָ����Teacher����
	pp->print();	   //���õ���Teacher��print()
	cout << '\n';
	Person& r = s; //�������ñ��������������������
	r.print();
}

#endif

#if 0
int main() {
	Person* arr[5];
	int n = 0;
	arr[0] = new Teacher("Li Ping", "��ʦ");
	arr[1] = new Teacher("��ΰ", "����");
	arr[2] = new Student("�� ��", 70.5);
	n = 3;
	for (auto i = 0; i != n; i++)
		arr[i]->print();
	
	for (auto i = 0; i != n; i++) 
		delete arr[i];

}
#endif

#endif 

#if 0
//--------dynamic_cast----
// dynamic_cast<>��Ҫ���ھ��ж�̬�ԵĲ�μ̳нṹ����֮���ָ�루�����ã������ϡ����ºͲ���ת����
//�����ڳ��������ڼ����ָ�루�����ã�ָ�򣨻����ã��Ķ����ʵ������ȷ��
// �Ƿ��ܰ�ȫ�ؽ���ָ�루�����ã����͵�ת�������ʽ�ǣ�
/*
	dynamic_cast<Type*>(p)
	dynamic_cast<Type&>(r)
*/
//��������ʱ����ָ��p��������r��ת��Ϊ����Type* ����Type& ����
//������ܽ�������ת��������ָ�룬���ؿ�ָ�룬�������ã����׳�һ���쳣�����󣩡�


//dynamic_cast<>��Ҫ���ڽ�һ������ָ�루�����ã�ת��Ϊһ���������ָ�루�����ã�������������ת����downcasting����
//��������ת����upcasting������ʹ��Ҳ���Բ�ʹ��dynamic_cast��
#if 1
#include <iostream>
using std::cout;
struct Base {
	virtual ~Base() {}
};

struct Derived : Base {
	virtual void name() {}
};
int main() {
	Base* b1 = new Base;
	if (Derived * d = dynamic_cast<Derived*>(b1)) {
		std::cout << "downcast from b1 to d successful\n";
		d->name(); // safe to call
	}

	Base* b2 = new Derived;
	if (Derived * d = dynamic_cast<Derived*>(b2)) {
		std::cout << "downcast from b2 to d successful\n";
		d->name(); // safe to call
	}

	delete b1;
	delete b2;
}

#else
#include <iostream> 
struct V {
	virtual void f() {};       //�����Ƕ�̬�Ĳ���ʹ������ʱ����dynamic_cast
};
struct A : virtual V {};
struct B : virtual V {
	B(V* v, A* a) {
		// ��������е�����ת��(������D�Ĺ��캯���ĵ���)
		dynamic_cast<B*>(v);   // û���⣺ v�������� V*, ��V��B�Ļ��࣬v����ת��ΪB*����
		dynamic_cast<B*>(a);   // ����Ԥ֪��undefined behavior: a��������A*��
		                       // ��A����B�Ļ���
	}
};
struct D : A, B {
	D() : B(static_cast<A*>(this), this) { }
};
int main() {
	D d;
	A& ra = d; // ��������ת��������������ת��Ϊ�������á�����ʹ��Ҳ���Բ�ʹ��dynamic_cast
	D& rd = dynamic_cast<D&>(ra); // ��������ת������������ת��Ϊ����������
	B& rb = dynamic_cast<B&>(ra); // ��������ת������A&ת��ΪB&
	A a;
	D& rda = dynamic_cast<D&>(a); //����ʱ������Ϊʵ�ʶ���a����D����
	B& rba = dynamic_cast<B&>(a); //����ʱ������Ϊʵ�ʶ���a����B����
}

#endif

#endif 


#if 0
//--------�����ⶨ���麯��-------------
/*
* ��inline������Ա����һ����
�����ⶨ����麯�������йؼ���virtual��
�ұ�����������ĺ�������ǰ��ӹؼ���virtual��
*/
#include <string>
#include <iostream>
using namespace std;
class Person { //��
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print();       //������ĺ�������ǰ��virtual�ؼ���
};
//������ĺ�������ǰ������virtual�ؼ���
void Person::print() { cout << name << '\n'; }  

#endif 


#if 0
//----------- �麯����ǩ���ͷ�������------------
/*
* ������ǩ����ָ���������β��б�ͺ��������η���const��
������ͻ�����麯����ǩ��������ͬ��
���⣬��������麯���ķ�������Ҫô��ͬҪô�Ǹ����ָ����������͡�
*/
#if 0
#include <iostream>
class B {
public:
	virtual B& f() { return *this; }
	virtual int g() { std::cout << "g\n"; return 0; }
};
class D :public B {
public:
	D& f() { return *this; }
	double g() { std::cout << "g\n"; return 0.; }
};
#endif

#if 1
//����D���g()��B���g()�ĺ���ǩ����ͬ�����ǾͲ���ͬһ���麯����
#include <iostream>
class B {
public:
	virtual B& f() { return *this; }
	virtual void  g(int) { std::cout << "g in B\n"; }
};
class D :public B {
public:
	D& f() { return *this; }
	void g() { std::cout << "g in D\n"; }
};

int main() {
	D d;
	B* p = &d;
	p->f();
	d.g();
	p->g(); //����ָ��p�����������g()�Ǵ���ģ���Ϊ�ú��������麯��
}

#endif

#endif 

#if 0
//-------override---------
// ����������麯��ǩ�������override�ؼ��֣�˵������һ���ӻ���̳��������麯����
// ��������������Ƿ�������麯�������û�оͻᱨ�����
//
class X {
public:
	virtual void  print() { }
};
class Y :public X {
public:
	virtual void  Print() override
	{}
};

#endif 


#if 1
//--------final ----------
/*
* �麯��ǩ�������final�ؼ��֡���ʾ�麯���ļ̳е���Ϊֹ��
* �������಻���ٶ����̳и��麯���ˡ�
*/

class Y :public X {
public:
	//final ��ʾY��������಻������print()�麯����
	virtual void print() override final 
	{ }
};

//�������ùؼ���final��һ���ඨ��Ϊfinal�ࣨ�����ࣩ��
// �������ٴ�����ඨ���κ������ࡣ
//final ��ʾ���ܴ�Y�ඨ�������࣬����˵�κ��಻�ܽ�Y��Ϊ���ࡣ
class Y final :public X {
public:
	virtual void  print() override { }
};

#endif 


#if 1
//---------����������-----------
//��������Ӧ�ö���Ϊ�麯��

#endif 