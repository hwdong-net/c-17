//========Ϊʲô��Ҫ������==========.include <iostream>
using namespace std;
//---------���Լ��--
#if 0
int main() {
    int m{ 72 }, n{ 27 };
    cout << m << "��" << n;
    while (n != 0) {
        auto r = m % n;
        m = n; n = r;
    }
    cout << " �����Լ��Ϊ"
        << m << endl;

    m = 36, n = 24;
    cout << m << "��" << n;
    while (n != 0) {
        auto r = m % n;
        m = n; n = r;
    }
    cout << " �����Լ��Ϊ"
        << m << endl;
}
#endif

//------�����Ķ��塢��������ʽ����----
//------�����ĵ��á�ʵ�ʲ���----------

# if 0
#include <iostream>

//GCD�Ǻ�������Բ�����ڵ��ǲ�������2������m,n����Ϊ����ʽ������
//������ǰ���void�ؼ��֣�˵���������������ֵ
void GCD(int m, int n) {   
    while (n != 0) {
        int r = m % n;
        m = n; n = r;
    }
    std::cout << m << "��" << n << "�����Լ���ǣ� " << m << std::endl;
}

int main() {
    int x = 72, y = 27;
    GCD(x, y); //���ú�������GCD�Ĵ��룬��x,y��ֵ���ݸ�
             //�����ú���GCD��2���β���m,n    
    x = 36; y = 24;
    GCD(x, y);
}
#endif

//---------return���أ������---------------
# if 0
#include <iostream>
int GCD(int m, int n) {
    //int m = 72,n = 27;
    while (n != 0) {
        int r = m % n;
        m = n; n = r;
    }
    return m; //����int���͵Ľ����ֵ��m    
}

int main() {
    int x = 72, y = 27;
    int gcd = GCD(x, y); //�ú���GCD�ķ��ؽ����ʼ��int���ͱ���gcd
    std::cout << x << "��" << x << "�����Լ���ǣ� " << gcd << std::endl;

    x = 36; y = 24;
    gcd = GCD(x, y);
    std::cout << x << "��" << y << "�����Լ���ǣ� " << gcd << std::endl;
}
#endif


#if 0
//������ÿ���β��ö��Ÿ���������˵��ÿ���βε�����
//�ββ���ͬ����Ҳ������ֲ�����ͬ�������ض���
void f();
void f1(void);

//void f2(int v1, v2);
void f3(int v) {
    int v;
}
#endif

//---------return�����ؽ��----------------
//һ�����������ж��return��䣬��������return��ִ�н���
#if 0
#include <iostream>
auto g() {
    int i; std::cin >> i;
    if (i > 0) return 1;        //��������������1
    else if (i < 0) return -1;   //��������������-1
    else return 0;              //��������������0
}
int main() {
    auto ret = g();
    std::cout<<typeid(ret).name();
    return 0;
}
#endif

//���returnֵ�����ͱ�����ͬ����ת��Ϊͬһ������
#if 0
#include <iostream>
auto g2() {
    int i; std::cin >> i;
    if (i > 0) return 3.14;        
    else if (i < 0) return -1;   
    else return 0;              
}
int main() {
    g2();
    return 0;
}
#endif

//���ܷ��طǾ�̬�ֲ����������û�ָ��
#if 0
int* fp() {
    int var;
    //...
    return &var;
}
int& fr() {
    int var;
    //...
    return var;
}

#include <iostream>
int main() {
    int *p = fp();
    *p = 45;
    std::cout << *p << std::endl;

    int& q = fr();
    q = 45;
    std::cout << q << std::endl;
}
#endif


//��̬�ֲ������ͷǾ�̬�ֲ�����
#if 0
#if 1
int main() {
    while (true) {
        auto i{ 0 }; //i��һ���Ǿ�̬�ֲ�����
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#else

#include <iostream>
int main() {
    while (true) {
        static auto i{ 0 }; //i��һ����̬�ֲ�����
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif
#endif 

#if 0
#include <iostream>
void  f() {
    static auto i{ 0 };   //i�Ǿ�̬�ֲ�����
    int j{ 0 };          //j�ǷǾ�̬�ֲ�����
    i++;  j++;
    std::cout << i << '\t' << j << '\n';
}

int main() {
    f();
    f();
}
#endif 

#if 0
#if 0
#include <iostream>
int main() {
    while (true) {
        auto i{ 0 }; //i��һ���Ǿ�̬�ֲ�����
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif
#include <iostream>
int main() {
    while (true) {
        static auto i{ 0 }; //i��һ����̬�ֲ�����
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif

#if 0
//1. ֵ�βΣ������β�
#include <iostream>
void f(int var, int& ref) {
    var++;
    ref++;
    std::cout << var << '\t' << ref << std::endl;
}
int main() {
    auto x = 1, y = 1;
    f(x, y);
    std::cout << x << '\t' << y << std::endl;
}
#endif

#if 0
//2.Ĭ���β�
int pow(int x, int n = 2) {
    auto ret{ 1 };
    for (auto i{ 0 }; i < n; i++)
        ret *= x;
    return ret;
}


void f(int a, int b = 2, int c = 4) {

}

int main() {
    f();
    cout << pow(3) << '\t'
        << pow(3, 4) << endl;
}
#endif


//3.�����β�
#if 0
//�������β�д�����������,ʵ����һ��ָ�����
void printArr(int a[], int n) { //int *
    //for(auto e:a)
    //	cout << e << '\t';

    for (auto i{ 0 }; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}

int main() {
    int arr[]{ 1,2,3,4,5 };
    printArr(arr, 5);
}
#endif

//----������range for����ָ��ָ�������----
#if 0
#include <iostream>
void PrintArr(int arr[], int n) {  
    for (auto e:arr)
        std::cout << e << '\t';
}
int main() {
    int a[]{ 7,2,4,19 };
    PrintArr(a, 4);
}

#endif

//���ò���������һ������
//��ʱ������range for�����������
#if 0
#include <iostream>
//arr���õ���int[4]���͵����飬
//�����õ�����4��intԪ�ص�����
void SquareArr(int(&arr)[4]) {   
    for (auto& e : arr)  //arr��Ȼ��һ���������飬�Ϳ�����Range forѭ��
        e *= e;
}
int main() {
    int a[]{ 7,2,4,19 };
    SquareArr(a);
    for (auto e : a)
        std::cout << e << '\t';
}
#endif

#if 0
#include <iostream>
void h(int arr[][4], int n) {
    //pָ��һ��int[4]�����ָ��,��ָ��һ�ж�Ӧ���Ǹ�����
    //p++��ָ����һ��int[4]����
    for (auto p = arr; p != arr + n; p++) {
        for (auto e : *p)  //*p��������int[4]�����Կ�����Range for
            std::cout << e << '\t';
        std::cout << '\n';
    }
}
int main() {
    int a[][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    h(a, 3); //���봫��a�Ĵ�С
}

#endif


//-------const���β�----------
/*
void f(const int x, const int y);
void g(const int *p, const int n);
void h(int *const q, const int n);
void k(const int &r);
*/
//���ܽ�һ��const�����ָ��(������)
// ����һ����const��ָ�루���ã��βΣ�
// const int *���ܴ���int*
//���������ǿ��Ե�

#if 0
void f(int *x) {
}
void g(int& x) {
}
int main() {
    const int i{3};
 //   f(&i);
    g(i);
}
#endif

//-------�ɱ���Ŀ���β�---------
//C���� ...
//C++: ��C++��׼���std::initializer_list<T>����
// ���庯�����β�
#if 0
#include <iostream>
//scores��std::initializer_list<double>���͵ı���
double average(std::initializer_list<double> scores) {
    auto n{ 0 };
    double all{ 0 };
    for (auto score : scores) {
        all += score; n++;
    }
    if (n > 0)	return all /= n;
    return 0;
}

int main() {
    std::cout << average({  }) << '\n';
    std::cout << average({ 60. }) << '\n';
    std::cout << average({ 50.,80 }) << '\n';
    std::cout << average({ 90,50.,80 }) << '\n';
}
#endif

//=============�ݹ麯��===============
#if 0
#include <iostream>
int fact(int n) {
    if (n == 1)  // ���n����1����ֱ�ӷ���ֵ1
        return 1;
    return n * fact(n - 1);	//fact(n)����n��fact(n-1)�ĳ˻�
}
int main() {
    std::cout << fact(4) << '\n';     //����� 24
}
/*
�ݹ���һ��Ƕ�׵Ĺ��̣���fact(4)�ĵݹ����������£�
fact(4)
 4 * fact(3)
 4 * (3 * fact(2))
 4 * (3 * (2 * fact(1)))
 4 * (3 * (2 * 1 ))
 4 * (3 * 2)
 4 * 6
 24
*/
#endif

#if 0
//쳲���������
#include <iostream>
int fib(int n) {
    if (n < 2)                  //������
        return 1;
    else                       //�ݹ�����
        return fib(n - 1) + fib(n - 2);
}
int main() {
    for (int i{ 1 }; i != 8; i++)
        std::cout << fib(i) << '\t';
}

#endif



#if 0
#include <iostream>
int gcd(int m, int n) {
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}
int main() {
    std::cout << gcd(72, 27) << '\t' << gcd(24, 36) << '\t';
}
#endif

#if 0
auto binarySearch(int a[], const int L, const int H, int value) {
    if (L > H)           //������
        return -1;
    auto Middle = (L + H) / 2;
    if (a[Middle] == value) // 1���м�Ԫ��ֱ�ӱȽ�
        return Middle;
    else 	if (value < a[Middle])
        return binarySearch(a, L, Middle - 1, value);    // 2) ���������
    else
        return binarySearch(a, Middle + 1, H, value);  // 3) ���������
}

#include <iostream>
int main() {
    int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
    std::cout << binarySearch(arr, 0, 11, 25) << '\t';
    std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif


#if 0
#include <iostream>
// һ�����ӣ�ֱ���ƶ�
void moveDisk(int i, const char x, const char y) {
    std::cout << "moving disk" << i << " from " << x << " to " << y << '\n';
}

// ����������, ��ʼ��, ��ת��, Ŀ����
void move(int n, const char a, const char b, const char c) {
    if (n < 1) return;
    move(n - 1, a, c, b);  // n - 1�����Ӵ�A��������C���Ƶ�B��
    moveDisk(n, a, c);
    move(n - 1, b, a, c);   // n - 1�����Ӵ�B��������A���Ƶ�C��
}
int main() {
    move(3, 'A', 'B', 'C');
}

#endif

#if 0
using T = int;   //T������Ԫ�ص�����
int partition(T arr[], const int start, const int end) {
    auto pivotvalue{ arr[start] };
    auto L = start + 1, R = end;

    auto done{ false };
    while (!done) {
        while (L <= R and arr[L] <= pivotvalue) L = L + 1;
        while (arr[R] >= pivotvalue and R >= L) R = R - 1;
        if (R < L)	done = true;
        else {	//����L,R��ֵ
            auto temp{ arr[L] };
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }
    //����R��start��ֵ������׼Ԫ���Ƶ���׼λ��R
    auto temp{ arr[R] };
    arr[R] = arr[start];
    arr[start] = temp;
    return R;
}



// qsort�Ƕ�[start, end]�����Ԫ�ؽ��п����������
void qsort(T arr[], const int start, const int  end) {
    if (start >= end) return;
    // partition��[start, end]֮�������һ�λ���Ϊ2���֣�����pivot�ǻ�׼��λ��
    auto pivot = partition(arr, start, end); //�ȶ�ԭ����һ�λ���
    qsort(arr, start, pivot - 1);    //��[start, pivot - 1]֮������е���qsort����������̣�
    qsort(arr, pivot + 1, end);     //��[pivot + 1, end]֮������е���qsort����������̣�	
}

void quickSort(T arr[], const int n) { //��n��Ԫ�ص�����arr�Ŀ�������
    qsort(arr, 0, n - 1); //���ö�һ����������������qsort
}

#include <iostream>
int main() {
    int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
    quickSort(a, 8);
    for (auto i{ 0 }; i != 8; i++)
        std::cout << a[i] << '\t';
    std::cout << '\n';
}

#endif



//=======�������������ؽ���===========
/*C++ͬһ�������ܿɶ�����ͬ����ͬǩ���ĺ�����
��֮Ϊ�������ء�

�����������β��б����˺�����ǩ����
��ֻҪ������ǩ����ͬ�����ǲ�ͬ�ĺ�����
*/

#if 0
int f() {/*...*/ }
int f(int) {/*...*/ }
int f(int, int) {/*...*/ }
double f(double) {/*...*/ }
#endif

#if 0
//ͬһ�������еĶ����ͬǩ���ĺ�������֮Ϊ�ض��塣
int f(int) {/*...*/ }
double f(int) {/*...*/ }
#endif

#if 0
//�ββ�ͬ���β��Ƿ�const�޹�
void f(int) {}
void f(const int) {}

void g(int*) {}      //int�����ָ��
void g(int* const) {}    //int����ĳ�ָ��
int main() {
    int i{ 0 };
    f(i);
    g(&i);
}

//��ˣ�����������޸��βΣ�Ӧ���β�����Ϊconst����
#endif

#if 0
//�������2��ͬ������f()����g()�����β��ǲ�ͬ�ģ�
void f(int&) {}        //int���������
void f(const int&) {}    //const int��Ӧ������

void g(int*);         //int�����ָ��
void g(const int*);    //const int �����ָ�룬ָ�벻��const
int main() {
    int i{ 0 };
    f(i);
    g(&i);
}
#endif

#if 0
//���ж��ͬ������ʱ������������ʵ����ѡ��һ������ʵĺ�����
//���ѡ��������غ����Ĺ��̳�Ϊ���ؽ�����

void f()
void f(int)
void f(int, int)
void f(double, double = 3.14)

int main() {
    f(5.6);
    f(3, 5.6);
}
#endif


#if 0
/*
* �����ؽ���ʱ��ʵ�ζ��βεĳ�ʼ������ͨ�����ĳ�ʼ����һ���ġ�
�磬������const��non-const�����ָ�������ȥ��ʼ��const����
��ָ������ã�
��������������const�����ָ�������ȥ��ʼ��
non-constָ������á�
*/

//��ϰ�������ĳ�ʼ��

#if 0
int main() {
    const int ci = 3; //const���������non-const�����ʼ��
    int i = ci;       //non-const���������const�����ʼ��
    const int j = i;  //const���������non-const�����ʼ��
    const int& cri = i; // const��������ÿ���const��non-constֵ��ʼ��������������
    const int& cr3 = 3; // const��������ÿ���const��non-constֵ��ʼ��������������
    const int& crj = j; // const��������ÿ���const��non-constֵ��ʼ��������������
    int& r = ci;        //non-const��������ã���ͨ���ã�������const�����ʼ��
    int& r = 3;        //non-const��������ã���ͨ���ã�������const�����ʼ��������������

    const int* cp = &i; // ok: const�����ָ�����const��non-const��ָ��(��ַ)��ʼ��
    const int* cpj = &j; // ok: const�����ָ�����const��non-const��ָ��(��ַ)��ʼ��
    const int* cp3 = &3; //��������û�е�ַ
    int* p = &i;       //��ָͨ�루non-const�����ָ�룩����non-const��ָ��(��ַ)��ʼ��
    int* p2 = cp;   // error: ��ָͨ�벻����const�����ָ���ʼ����p2��cp���Ͳ�ƥ��
    int* pj = &j;   // error: ��ָͨ�벻����const�����ָ���ʼ����pj��&j���Ͳ�ƥ��
}
#else


//���ں������漰const��ָ������õ��βεĳ�ʼ��Ҳ��һ���ģ��磺
void fun(int*) {/*...*/ }
void fun(int&) {/*...*/ }
void g(const int&) {/*...*/ }

int main() {
    int i = 0;
    const int ci = i;
    unsigned  ui = 0;
    fun(&i); // ����fun(int *)
    fun(&ci); // ��: ���ܽ�const int��ָ��ת��Ϊint *
    fun(i); // ����fun(int &)
    fun(ci); // ��: ���ܽ���ͨ����int &�󶨵�һ��const����ci
    fun(18); // ��: ���ܽ���ͨ����int &�󶨵�һ��������
    fun(ui); // ��: ���Ͳ�ƥ�䣬ui��unsigned
    g(37);   // OK: cosnt int�����ÿ�������������ʼ��
}
#endif

#endif 



#if 0
inline int add(const int x, const int y) {
    return x + y;
}
int main() {
    add(3, 4);
}
#endif

//constexpr�ؼ��ֿ�����������һ������������
//��ʾ�������������ֵ�Ǳ���ʱ�������ġ�
//Ҳ����˵����������ֵ�Ǳ���ʱ����ȷ����ֵ�Ҳ���ı䡣

#if 0
constexpr auto pi{ 3.14 };
constexpr int I;
#endif 

#if 0
//constexpr�������Է��س������ʽ
constexpr auto size1(int x) {
    int i{ 9 };	return i;
}

int main() {
    const auto b{ 4 };          //����ʱ��������Ϊ4�ǳ������ʽ
    const auto e{ size1(b) };    //����ʱ��������b�ǳ������ʽ������size1(b)�ǳ������ʽ

    auto a{ 3 };
    const auto d{ size1(a) };     //����ʱ��������a�Ǳ���������size1(a)���ǳ������ʽ

    int arr[e];
    int brr[d];
}
#endif

#if 0
const auto size() {	      //����һ��const���󣬲��ǳ������ʽ
    int i{ 9 };	return i;
}
constexpr auto size1(int x) {   //constexpr�������Է��س������ʽ
    int i{ 9 };	return i;
}
auto a{ 3 };
const auto b{ 4 };          //����ʱ��������Ϊ4�ǳ������ʽ
const auto c{ size() };       //����ʱ��������Ϊsize()����ֵ����ʱ����ȷ��
const auto d{ size1(a) };     //����ʱ��������a�Ǳ���������size1(a)���ǳ������ʽ
const auto e{ size1(b) };    //����ʱ��������b�ǳ������ʽ������size1(b)�ǳ������ʽ
char arr[a], arr1[b], arr2[c], arr3[d], arr4[e];  //�����С�����ǳ������ʽ

#endif 

#if 1
using color = char; //��ͬ�ַ�ģ��������ɫ

color* framebuffer{ nullptr };          //֡������
int framebuffer_width, framebuffer_height;

color clear_color{ ' ' };                //������ɫ  

//API����
bool initWindow(int width, int height);  //��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
void clearWindow();               //��մ�������
void destoryWindow();             //���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void show();                      //��ʾ֡��������ͼ��
void setPixel(const int x, const int y, color c = ' ');            //�������ص���ɫ
color getPixel(const int x, const int y);                       //�������ص���ɫ
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

void setPixel(const int x, const int y, color c) {
    framebuffer[y * framebuffer_width + x] = c;
}
color getPixel(const int x, const int y) {
    return framebuffer[y * framebuffer_width + x];
}

#include <iostream>

//��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
bool initWindow(int width, int height) {
    framebuffer = new color[width * height];
    if (!framebuffer) return false;
    framebuffer_width = width;
    framebuffer_height = height;
    clearWindow();
    return true;
}

//��������ɫclear_color��մ�������
void clearWindow() {
    for (int y = 0; y < framebuffer_height; y++)
        for (int x = 0; x < framebuffer_width; x++)
            framebuffer[y * framebuffer_width + x] = clear_color;

}

//���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void destoryWindow() {
    delete[] framebuffer;
    framebuffer = nullptr;
}

//��ʾ֡��������ͼ��
void show() {
    for (int y = 0; y < framebuffer_height; y++) {
        for (int x = 0; x < framebuffer_width; x++)
            std::cout << framebuffer[y * framebuffer_width + x];
        std::cout << '\n';
    }
}

#if 0
int main() {
    if (!initWindow(25, 15)) {
        return 1;
    }
    set_clear_color('-');
    clearWindow();
    int x{ 10 }, y{ 10 };
    setPixel(x, y, '*');
    setPixel(x - 1, y + 1, '*'); setPixel(x, y + 1, ' '); setPixel(x + 1, y + 1, '*');
    setPixel(x - 2, y + 2, '*'); setPixel(x - 1, y + 2, ' '); setPixel(x, y + 2, '*'); setPixel(x + 1, y + 2, ' '); setPixel(x + 2, y + 2, '*');
    show();
}
#endif

#if 0
#include <cmath>
//#define SINEHEIGHT  20
//#define DEGREESTEP  5
void draw_sin_curve(const int SINEHEIGHT = 20, const int DEGREESTEP = 5) {
    for (int degree = 0; degree < 361; degree = degree + DEGREESTEP) {
        auto x = floor((degree / DEGREESTEP) + 0.5) + 1;
        auto y = floor(sin(degree * 3.141 / 180) * (SINEHEIGHT / 2) + 0.5)
            + SINEHEIGHT / 2 + 1;

        setPixel(x, y, '*');
    }
    auto x = 1;
    auto y = SINEHEIGHT / 2 + 1;
    setPixel(x, y, '*');
}
int main() {
    if (!initWindow(70, 30)) {
        return 1;
    }
    draw_sin_curve();
    show();
}
#endif


#if 0
inline void min_max(double s[], const int n, double& min, double& max) {
    if (n <= 0) return;
    min = s[0]; max = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] < min) min = s[i];
        if (s[i] > max) max = s[i];
    }
}

inline void plot(double x[], double y[], const int n, const int win_w, const int win_h,
    const int offset = 2, const bool upset = true) {
    auto plot_w{ win_w - 2 * offset }, plot_h{ win_h - 2 * offset };
    //��x[],y[]�����е����ֵ����Сֵ
    double x_min, x_max, y_min, y_max, x_dist, y_dist;
    min_max(x, n, x_min, x_max);
    min_max(y, n, y_min, y_max);
    x_dist = x_max - x_min;
    y_dist = y_max - y_min;
    auto scale_x = new double[n], scale_y = new double[n];
    if (!scale_x || !scale_y) return;
    //��������ͼplot������
    for (int i = 0; i < n; i++) {
        scale_x[i] = plot_w * (x[i] - x_min) / x_dist;
        scale_y[i] = plot_h * (y[i] - y_min) / y_dist;
    }
    //���Ƶ㼯
    if (upset)
        for (int i = 0; i < n; i++)
            setPixel(scale_x[i] + offset, win_h - (scale_y[i] + offset), '*');
    else
        for (int i = 0; i < n; i++)
            setPixel(scale_x[i] + offset, scale_y[i] + offset, '*');
    delete[] scale_x;
    delete[] scale_y;
    show();
}

int main() {
    const int w = 100, h = 40;
    if (!initWindow(w, h)) {
        return 1;
    }
    double x[] = { 2014, 1600, 2400, 1416, 3000, 3670, 4500 };//�������
    double y[] = { 400, 330, 369, 232, 540, 620, 800 };//���ݼ۸�
    plot(x, y, 7, w, h);
    return 0;
}

#endif 

#endif