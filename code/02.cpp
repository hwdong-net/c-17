/*=============�����Ķ���===================
-------- Ϊʲô��Ҫ������-----------
// ��������Ӳ����
// ��ߴ���ɶ���
// �����м��� ��f(x) = 5x^3-2x^2+4x+6 = 0
// �����ظ�����
*/

#if 0
// 1. ���������ʽ��
// ��������  ������ [��ʼ��ʽ]
// ����ͬʱ������ͬ���͵ı���������֮���ö��Ÿ���
#include <iostream>
using namespace std;
int main() {
	int adfs3_,b=3;
	std::cout << adfs3_ << " " << b<<endl;
	return 0;
}
#endif 

#if 0
// 2. �����ĳ�ʼ���� =, (),{}
#include <iostream>
int main() {
	int a;
	int b{};
	int c{ 2 };
	int d = 2 ;
	int e(2);
	std::cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}
#endif 

#if 0
// 3. �б��ʼ��{}:�������¡���Ϣ��ʧ�� �ĳ�ʼ��
#include <iostream>
int main() {
	int a;
	int b{};
	int c{ 2.6 };
	int d = 2.6;
	int e(2.6);
	std::cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}
#endif

#if 0
// 4. auto
// �����г�ʼ���ı���ʱ��������auto�ƶ����������͡�

#include <iostream>
int  main() {
	auto b = true; //bool
	auto ch{ 'x' }; //char
	auto i = 123;  //int
	auto j = 123L;  //long
	auto d{ 1.2 };  //double
	auto z = d + i;

	std::cout << b << " " << ch << " " << i << " " << j << " "
		<< d << " " << z << '\n';
	return 0;
}
#endif


#if 0
// 5. typeid
// typeid�������ѯ�õ�һ���������ͻ������������Ϣ
#include <iostream>
int  main() {
	auto b = true;
	auto ch{ 'x' };
	auto i = 123;
	auto j = 123L;
	auto d{ 1.2 };
	auto z = d + i;

	std::cout << b << " " << ch << " " << i << " " << j << " "
		<< d << " " << z << '\n';

	std::cout << typeid(b).name() << " " << typeid(ch).name() << " "
		<< typeid(int).name() << " " << typeid(j).name() << " "
		<< typeid(d).name() << " " << typeid(z).name() << '\n';
	return 0;
}
#endif

#if 0
// 6. decltype
// ��decltype(exp)�õ�һ�����ʽ��ֵ�����ͣ������������������һ��������
 
#include <iostream>
int  main() {
	decltype(3 + 4.5) c{ 2.4 };
	std::cout << typeid(c).name() << '\n';

	return 0;
}
#endif


#if 0
// 7.��ֵ�����=
// �����ø�ֵ������޸ĸñ�����ֵ���ñ����ڴ��ֵ����
// ��ʼ��=  vs     ��ֵ =
#include <iostream>
using namespace std;
int main() {
	int a = 2;
	a = 5;
	std::cout << a << std::endl;
}
#endif



#if 0
// 8. const 
// ��const�ؼ�������һ�����������󣩣�������ʾ�����Ĳ����޸��ԡ�
// ��ˣ�const��������ʼ��

#include <iostream>
int  main() {
	const int i=3;   //δ��ʼ��
	//const int j;   //δ��ʼ��
	//i = 6;  //��
	std::cout << i << '\n';
	return 0;
}
#endif


/*==============��������===============
C++���Ա����Ѿ������˻������ͣ���int��char��double��
�͸������ͣ����顢ָ�롢���ã�����Щ�������ͳ�Ϊ�������͡�
*/

#if 0
// 1 ���;������ܶԱ�������ʲô��������
#include <iostream>
using namespace std;
int main() {
	int x = 3.5, y(4);	
//	double x = 3.5, y(4);
	std::cout << x % y; //% 6%5
}
#endif

#if 0
// 2.���;����˱���ռ���ڴ�Ĵ�С
#include <iostream>
int main() {
	int i = 3;
	char ch = 'A';
	double radius = 2.56;
	bool ok = false;

	std::cout << "int����ռ���ڴ棺 " << sizeof(int) << "�ֽ�" << std::endl;
	std::cout << "iռ���ڴ棺 " << sizeof(i) << "�ֽ�" << std::endl;
	std::cout << "chռ���ڴ棺 " << sizeof(ch) << "�ֽ�" << std::endl;
	std::cout << "radiusռ���ڴ棺 " << sizeof(radius) << "�ֽ�" << std::endl;
	std::cout << "okռ���ڴ棺 " << sizeof(ok) << "�ֽ�" << std::endl;
}
#endif


#if 0
// 3.���;�����ֵ�ķ�Χ
// ������
//  numeric_limits��ͷ�ļ�limits
//numeric_limits��ģ���ṩ��һ�ֱ�׼���ķ�ʽ����ѯ�������͵ĸ�������
#include <limits>
#include <iostream>

int main(){
	std::cout << "type\tlowest()\tmin()\t\tmax()\n\n"
		<< "bool\t"
		<< std::numeric_limits<bool>::lowest() << "\t\t"
		<< std::numeric_limits<bool>::min() << "\t\t"
		<< std::numeric_limits<bool>::max() << '\n'
		<< "uchar\t"
		<< +std::numeric_limits<unsigned char>::lowest() << "\t\t"
		<< +std::numeric_limits<unsigned char>::min() << "\t\t"
		<< +std::numeric_limits<unsigned char>::max() << '\n'
		<< "int\t"
		<< std::numeric_limits<int>::lowest() << '\t'
		<< std::numeric_limits<int>::min() << '\t'
		<< std::numeric_limits<int>::max() << '\n'
		<< "float\t"
		<< std::numeric_limits<float>::lowest() << '\t'
		<< std::numeric_limits<float>::min() << '\t'
		<< std::numeric_limits<float>::max() << '\n'
		<< "double\t"
		<< std::numeric_limits<double>::lowest() << '\t'
		<< std::numeric_limits<double>::min() << '\t'
		<< std::numeric_limits<double>::max() << '\n';
}
#endif

/*==============������===============
ֱ��д��ֵ�ĳ�����2��3.14����X������hello world���ȶ���Ϊ������
ÿ��������Ҳ���ж�Ӧ����������
*/

#if 0
/*  1. ����������
���Ա�ʾΪʮ���ơ��˽��ơ�ʮ�����ơ������ƵȲ�ͬ��ʽ��
��0��ͷ���ǰ˽��ƣ���0x��0X��ͷ����ʮ�����ƣ���0b��0B��ͷ���Ƕ����ơ�
*/
#include <iostream>
using namespace std;
int main() {
	cout << typeid(18).name() << ' '
		<< typeid(022).name() << ' '
		<< typeid(0x12).name() << ' '
		<< typeid(0b100010010).name() << '\n';
}
#endif


#if 0
/*  2. �����������ĺ�׺��ʾ
* Ϊ�˱�ʾ��int����������ͣ�����������������
��ӱ�ʾ��ͬ���͵ĺ�׺����ĸu��U��ʾ��unsigned���ͣ�
����ĸl��L��ʾlong���ͣ�ll��LL��ʾlong long���͡�
*/
#include <iostream>
using namespace std;
int main() {
	cout << typeid(18u).name() << '\n'
		<< typeid(022L).name() << '\n'
		<< typeid(18LL).name() << '\n'
		<< typeid(0x12UL).name() << '\n'
		<< typeid(18ULL).name() << '\n';

}
#endif


#if 0
  //3.������������
/*�������С���㣬���ú�׺f��F��ʾfloat��
��l��L��ʾlong double�������͡�
*/
#include <iostream>
using namespace std;
int main() {
	cout << 2E3 << '\t' << 0.2e-3 << '\t'
		<< -0.1E-3L << '\t' << .3E2f << '\n';
}
#endif


#if 0
// 4. �ַ�������������
// ���Ҫ��ʾ��ͬ���͵��ַ����ͣ�������ǰ׺��
// u8ǰ׺ʵ�������ڱ�ʾUTF-8�ַ����ġ�
#include <iostream>
using namespace std;
int main() {
	cout << typeid(L'A').name() << '\n'
		<< typeid(u'A').name() << '\n'
		<< typeid(U'A').name() << '\n'
		<< typeid(u8'A').name() << '\n';
	cout << u8"��ã�liping" << '\n';
	cout << sizeof(L'A') << " " << sizeof(u'A') << " "
		<< sizeof(U'A') << " " << sizeof(u8'A') << "\n";
}
#endif


#if 0
// 5. ת���ַ�����
/*�÷�б��\��ʼ��ת���ַ����б�ʾĳ���ַ���
��\n��ʾ���з���\t��ʾ�Ʊ����\0��ʾ���ַ�(������)������
���е�ASCII�ַ��������÷�б��\����8λASCII��ʾ��

R "delimiter( raw_characters )delimiter"
*/

#include <iostream>
using namespace std;
int main() {
	cout << "hello\tworld" << '\n'
		
		<< "hello\0world" << '\n'
		<< '\115' << '\n'
	    << '\7' << '\n';  //����������
	cout << R"dfdsf( \n\0\t\7 )dfdsf" << '\n';
}
#endif


/*
* ========�����ݷ�==========
�����������ݷ��������ݵ������ʽ
iomanip��ios
*/
#if 0
#include <iostream>
using namespace std;
int main() {
	bool b{ true };
	std::cout << b << '\t';
	std::cout << boolalpha << b << std::endl;
}
#endif


#if 0
// std::dec��std::oct��std::hex
//��������������ʮ���ơ��˽��ơ�ʮ��������ʽ�����
#include <iostream>
using namespace std;
int main() {
	std::cout << std::hex << 18 << '\t' << 25 << '\n';
	std::cout << std::oct << 18 << '\t' << 25 << '\n';
	std::cout << std::dec << 18 << '\t' << 25 << '\n';
	return 0;
}
#endif


#if 0
/*���²��ݷ��ı両�����������ʽ
std::fixed���Թ̶�������ʽ���
std::scientific���Կ�ѧ��������ʽ���
std::hexfloat����ʮ�����Ƹ�����ʽ���
std::defaultfloat����Ĭ����ʽ���
*/
#include <iostream>
using namespace std;
int main() {
	std::cout << std::fixed << 100.01234567 <<"\t"<< 0.01234567 << '\n'
		<< std::scientific << 100.01 << "\t" << 0.01 << '\n'
		<< std::hexfloat << 100.01 << "\t" << 0.01 << '\n'
		<< std::defaultfloat << 100.01 << "\t" << 0.01 << '\n';
}
#endif

#if 0
/*
iomanip�Ĳ��ݷ�������Ҫ����һ����������setw(5)���ݷ���ʾ�����ռ�ݵĿ����5��
std::setw(n)���ı������Ŀ��
std:: setprecision(n)���ı両�����ľ���
std:: setfill(ch)���ı�����ַ�����setw��������ȴ������ֵ�Ŀ��ʱ��
    Ĭ�ϵ�����ַ��ǿո񣬿�����setfill(ch)�ı��������ַ���
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {	
	std::cout << std::setprecision(2) << 3.1415926 << '\n';
	std::cout << std::setw(10) << 3.1415926 << '\n';
	std::cout << std::setw(10) << std::setfill('-') << 3.1415926 << '\n';
}
#endif


/*
* ============����ת��=====================
* ��һ�����͵�ֵת��������һ�����͵�ֵ
*/

#if 0
/* 1. ��ʽ����ת��
��������Բ�ͬ���͵����ݽ�������ʱ��������ĳ�ʼ��ֵ���ͺͱ������Ͳ�һ��ʱ��
C++�������Ὣ�Զ�����ת��Ϊͬһ�����ͣ���Ϊ��ʽ����ת����
*/
#include <iostream>
using namespace std;
int main() {
	int i = 3.14;    //�ڶ�int�ͱ���i��ʼ��ʱ���Ὣ
				   // double��ֵ3.14ת��Ϊint��ֵ3���ٶ�i��ʼ��
	cout << i << endl;
	int  j = i * 2.5;  //i��ת��Ϊ�� 2.5ͬ���͵�doubleֵ 3.0��2��
	            // doubleֵ��˵Ľ����ת��Ϊint����ֵ���Ա���j��ʼ��
	cout << typeid(i * 2.5).name()<< endl;
	cout << j << endl;
}
#endif

#if 0
/* 1. ǿ������ת��
��ʱ��Ҫǿ�ƽ�һ������ֵת��Ϊ��һ������ֵ��
1)��ʱǿ������ת����  ��T�� var
double c = 2/(double)5;
2) static_cast<T>
double d = 2/ static_cast<double>5;

*/
#include <iostream>
using namespace std;
int main() {
	bool b = 42;  //int��ֵ42ת��Ϊboolֵtrue,�ٶ�b��ʼ����b��ֵ����true	
	int i = b; // b��ֵtrueת��Ϊint��ֵ1���ٳ�ʼ��int����i��
	std::cout << boolalpha << b << '\t' << i << std::endl;

	i = 3.14; //double��ֵ3.14ת��Ϊint��ֵ3���ٶԱ���i��ֵ��i��ֵ����3
	std::cout << i << std::endl;

	unsigned char c = -1; //unsigned char��ȡֵ��Χ��[0,255]
			  // -1����[0,255]������Ϊ  (-1+256) % 256 = 255
	signed char c2 = 256; //256����char��ȡֵ��Χ[-127,128]���������֪
	std::cout << (unsigned short)c << std::endl;
	std::cout << (short)c2 << std::endl;
	return 0;
}

#endif

#if 0
/*
 ���int��unsigned����ʱ��
����ȡģ��(������)����������ʽת��Ϊunsigned���͵�ֵ��
*/
#include <limits>
#include <iostream>
using namespace std;
int main() {	
	cout << std::numeric_limits<unsigned>::min() << "\t\t"
		<< std::numeric_limits<unsigned>::max() << '\n';

	unsigned u = 0;
	u = u - 1;              //���unsigned��32λ����: [0, 4294967295]
							//-1ת��Ϊ�� (-1+4294967296) % 4294967296
	std::cout << u << std::endl << std::endl;

	int i = -42;
	cout << i + i << endl;   //��� -84
	cout << u + i << endl;   //�����32λ�����������4294967264
						     //-42ת��Ϊ�� (-42+4294967296)%4294967296
	                         //            = 4294967254
}
#endif


#if 1
/*
 ---------���ͱ�������һ��������һ��������------
 */
#include <iostream>
 using FLOAT = double;//typedef double FLOAT

 int main(){
	 FLOAT radius{2.5}; //�൱��double radius{2.5};
	 std::cout << typeid(radius).name() << std::endl;
	 return 0;
 }

 /*
#define USING_COMPILER_B
#if defined USING_COMPILER_A
using Int32 = __int32;
using Int64 =  __int64;
#elif defined USING_COMPILER_B
using Int32 = int;
using Int64 = long long;
#endif
 */

#endif