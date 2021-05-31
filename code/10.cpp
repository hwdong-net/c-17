#include <iostream>
using namespace std;


//==============����ģ��====================

#if 0
//--------��2��Ԫ�ص����ֵ����ͬ�����赥����д����------
int Max(int a, int b) {
    return a > b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}
int main() {
    cout << Max(3, 5) << endl;         
    cout << Max(3.5, 4.5) << endl;  
    cout << Max(6, 4) << endl;
}


#endif



#if 0
//--------��2��Ԫ�ص����ֵ��ֻҪ��дһ��ģ�庯��------
template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}
int main() {
    cout << Max<int>(3, 5) << endl;          //ģ�����Ͳ���TΪint
    cout << Max<double>(3.5, 4.5) << endl;  //ģ�����Ͳ���TΪdouble
    cout << Max<int>(6, 4) << endl;
}

#endif

#if 0
//---------ģ������ƶ�----------
//���ݵ��ú���ģ�崫�ݵ�ʵ�ʺ���������ע������ģ��������Զ��ƶϳ�ģ����������͡�
//����Ҫ��ʽָ��ģ�����Ͳ���

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    cout << Max(3, 5) << endl;     //����ʵ�ʲ���3,5��int���ͣ�
//�ƶϳ���Ҫʵ����Max<int>����
    cout << Max(3.5, 4.5) << endl;  //����ʵ�ʲ���3.5, 4.5��double���ͣ�
//�ƶϳ���Ҫʵ����Max<double>����
    cout << Max(6, 4) << endl;     //����ǰ���Ѿ�ʵ������Max<int>����
}



#endif

//---------10.1.3 ģ��ר�Ż�----------
#if 0

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

#if 0
//���int*���Ͷ�ģ�����ר�Ż�
template <>
int* Max<int*>(int* a, int* b) {
    return  *a > *b ? a : b;
}
#endif

/*
* int* Max(int * a, int* b) {
	return a > b ? a : b;
}
*/
int main() {
    int x = 10, y = 20;
    int* p = &x, * q = &y;
    std::cout << *Max(p, q) << '\n';
}
#endif

//--------����ģ�������--------------
//���Զ���ͺ���ģ����ͬ���ĺ�����ģ�壬

#if 0
template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}
int* Max(int* a, int* b) {
    return *a > *b ? a : b;
}

template <typename T>
T Max(T arr[], int n) {
    T ret{ arr[0] };
    for (int i = 1; i != n; i++)
        if (arr[i] > ret) ret = arr[i];
    return ret;
}

template <typename T>
T* Max(T* a, T* b) {
    return *a > *b ? a : b;
}

//����ͨ�ĺ�������һ���������������ģ�������������ȷ����ƥ���ʵ����������
//����ͨ���������ָ�����͵�ģ�嶼�ܾ�ȷƥ��*Max(&x, &y)ʱ����ͨ�������ȡ�
//��int* Max(int * a, int* b)������template <typename T>T* Max(T* a, T* b)��
int main() {
    int x{ 10 }, y{ 20 };
    cout << Max(x, y) << '\n';      // template <typename T>T Max(T a, T b)
    cout << *Max(&x, &y) << '\n';  // int* Max(int * a, int* b)
    double ds[]{ 3.1,0.2,4.6,7.8 };
    cout << Max(ds, std::size(ds)) << '\n';  // template <typename T> T Max(T arr[], int n)
}

#endif

//-----------10.1.5 ģ��ķ��������ƶ�------------
#if 0
/*  ����������ʲô��
template <typename T1, typename T2>
? add(T1 a, T2 b) {
    return a + b;
}
*/

//β��������(trailing return type)�﷨��
//���ں���ǩ������->decltype(exp)���ƶ�ģ�庯���ķ������ͣ�
//����ǩ��ǰ��auto�ؼ��֣�
#if 1
template <typename T1, typename T2>
auto add(T1 a, T2 b)->decltype(a + b) {
    return a + b;
}

#else
//��decltype(auto)���ƶϺ����ķ������ͣ�
template <typename T1, typename T2>
decltype(auto) add(T1 a, T2 b) {
    return a + b;
}
#endif

int main() {
    auto ret = add(3, 4.5);
    cout << typeid(ret).name() << endl;
    cout << add(3, 4.5)<<endl;
}
#endif

//----------10.1.6 ������ģ�����----------
//ģ������ﻹ�����з�����ģ�������
//ģʽʵ����ʱ���ݸ�������ģ�����������ͨ��ֵ��������������
#if 0
template <typename T, int lower, int upper>
T average(const T arr[])
{
    T ret{ arr[lower] };
    for (auto i = lower + 1; i <= upper; i++)
        ret += arr[i];
    return ret;
}

int main() {
    int arr[]{ 1,2,3,4,5 };
    std::cout << average<int, 0, 4>(arr) << '\n';
    std::cout << average<int, 1, 3>(arr) << '\n';
    double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
    std::cout << average<double, 1, 3>(arr2) << '\n';

#if 0
    //������ģ�����Ҫ���ݳ���ֵ�����Ǳ���
    int i = 1, j = 3;
    std::cout << average<double, i,j>(arr2) << '\n'; 
#endif
}

#endif

//���Խ�����ģ�������ģ������������������������ĺ�����ʵ���Զ��ƶϡ�
#if 0
template <int lower, int upper, typename T>
T average(const T arr[])
{
    T ret{ arr[lower] };
    for (auto i = lower + 1; i <= upper; i++)
        ret += arr[i];
    return ret;
}
int main() {
    int arr[]{ 1,2,3,4,5 };
    std::cout << average<0, 4>(arr) << '\t';
    std::cout << average<1, 3>(arr) << '\t';
    double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
    std::cout << average<1, 3>(arr2) << '\t';
}

#endif 

//C++17�л�������auto˵��������ģ�������
//�Ӷ�����ģ��ʵ���Զ��ƶϷ�����ģ����������͡�
#if 0
template <auto value> void f() { }
int main() {
    f<10>();
}
#endif

//--------��C++17�п�����auto����������ģ�������ʹ��ģ�嶨����Ӽ򵥣�-----
#if 0
#if 0
//�����constexpr����ģ�弰��ʵ�������룺
template <typename T, T value> constexpr T TConstant = value;
constexpr auto const MySuperConst = TConstant<int, 100>;
#else
//��auto����������ģ�����
template <auto value> constexpr auto TConstant = value;
constexpr auto const MySuperConst = TConstant<100>;
#endif 

#endif 

//---------10.1.7 ģ��ģ�����--------------
//ģ���������Ҳ������һ��ģ�壬����ģ�������Ϊģ��ģ�������
//ʵ����ģ��ʱ�����ݵĲ���һ���������ͻ��߾���ֵ���������һ��ģ�壬
#if 0
template <template<class> class X, class A>
void f(const X<A>& value) {
    /*...*/
}
#endif

//------------10.1.8 ģ�������Ĭ��ֵ-------
//���庯��ģ��ʱ�����Ը�����ģ�������������ģ�������ģ��ģ���������Ĭ��ֵ��
// 
#if 0
//������������ģ�����T��������ģ�����e��������һ��Ĭ��ֵ��

template <typename T = int, int e = 2>
T power(const T x) {
    T ret{ x };
    for (auto i = 1; i < e; i++)
        ret *= x;
    return ret;
}

int main() {
    std::cout << power(3) << '\t';
    std::cout << power(3.5) << '\t';
    std::cout << power<double, 3>(3.5) << '\t';
}
#endif 

#if 0
//�ͺ�����Ĭ�ϲ��������ڷ�Ĭ�ϲ������治ͬ��
//Ĭ��ģ����������ڷ�Ĭ��ģ�������ǰ�棬
template <typename T = int, int e>
T power(const T x) {
    T ret{ x };
    for (auto i = 1; i < e; i++)
        ret *= x;
    return ret;
}
//�ٿ�һ�����ӣ�
template <typename T = int, int e = 2>
T fun() {
    T  ret{ 0 };
    for (auto i = 1; i < e; i++)
        ret += 3.14;
    return ret;
}

int main() {
    std::cout << fun() << '\t';
    std::cout << fun<double>() << '\t';
    //std::cout << fun<3>() << '\t';  //��3ʵ����T
    std::cout << fun<double, 3>() << '\t';
}
#endif 

//-------------10.1.9�ɱ�ģ�����----------------
/*
* std::initializer_list�ɶ���ɱ���Ŀ���βΣ�
�����ݸ��βεĿɱ���Ŀ������ʵ�����Ͷ�������ͬ��
��ͨ������ɱ�ģ�������ģ�壬
���Ը��ɱ�ģ�������Ӧ���βδ��ݲ�ͬ���Ͳ�ͬ��Ŀ��ʵ�Ρ�
*/

#if 0
template <typename... Args>
void fun(Args... args) {/*...*/ }
//��Range for���·��ʴ��ݸ�args��ÿ��ʵ���Ǵ���ģ�
template <typename... Args>
void print(Args...args) {
    for (auto arg : args)
        std::cout << arg;
}
#endif 

#if 0
//�ú���ģ��д�ɵݹ麯��ģ����ʽ
/*
* �ݹ���ʽ�ĺ���ģ�彫�ɱ�������2���֣�
��һ���β���һ����ͨ�ĵ���ֵ�Ĳ�����
���ڶ�����һ���ɱ�ģ����������е�rest...��ʾ���Ÿ����Ŀɱ������
*/

#if 0
template <typename T>
void print(T t) {                       //�����Σ�ֻ��һ�������β�
    std::cout << t << '\t';
}
template <typename T, typename... Rest>
void print(T t, Rest...rest) {              //�ݹ����Σ��ж�������β�
    std::cout << t << "\t";	print(rest...);
}

int main() {
    print("Li");           //���õ���print(T t)
    print(2, "Li");          //���õ���print(T t, Rest...rest)
    print(2, "Li", 80.5);      //���õ���print(T t, Rest...rest)
}
#endif


#if 1
//�����sum����ģ�����ڶ�һ��ɱ�ģ�������͡�
#include <iostream>
auto sum() { return 0; }

template<typename T1, typename... T>
auto sum(T1 s, T... ts) { return s + sum(ts...); }

int main() {
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
}
#endif 

#endif


#if 0
//-----�۵����ʽ------------
/*
* �۵����ʽ��Fold expressions����һ���µ������������ɱ�����ķ�����
����һ�����������op���Դ���Ŀɱ������pack�������䳣����ʽ���£�
( pack op ... )             //(1)
( ... op pack )             //(2)
( pack op ... op init )       //(3)
( init op ... op pack )       //(4)
�汾(1)�����۵�����չ���ɣ�(a1 op (a2 op (a3 ... (aN-1 op aN))))��ʽ��
�汾(2)�����۵���չ���ɣ�((((a1 op a2) op a3) ... ) op aN)��ʽ��
�汾(3)��(4)������(1)��(2)��ֻ��������һ����ʼֵ��
*/

#if 0
template <typename... T>
auto sum(T... s) {
    return (... + s);
}
int main() {
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
}
#endif

#if 0
//�û��ڶ��������,���۵����ʽ�ɽ�ǰ���print����ģ��д��������ʽ��
template<typename ...Args>
void print(Args ...args) {
    ((std::cout << args << '\t'), ...) << "\n";
}
int main() {
    print("Li");           
    print(2, "Li");         
    print(2, "Li", 80.5);    
}
#endif

//��Ȼ�������еĴ���Ҳ������һ��Lambda����������Ĺ�����
#if 1
template<typename ... Args>
void print(Args ... args) {
    ([](const auto& x) { std::cout << x << "\t"; }(args), ...);
    std::cout << "\n";
}
int main() {
    print("Li");
    print(2, "Li");
    print(2, "Li", 80.5);
}
#endif

#endif 

//--------10.1.10 constexpr if-----------
/*
* constexprʹ�ñ��ʽ�����ڱ����ڼ���㣬�Ӷ������������ڼ�ļ��㿪����
�����if��ϣ�ʹ�ÿ����ڱ���ʱ���ݳ������ʽ����������if���ķ�֧��
if constexpr (cond)
   ���1; // ��� cond��false�����������
else
   ���2; // ��� cond��true�����������
*/

#if 0
//fibonacci(쳲�����) ���е�C++ģ��ʵ�֡�
template<int  n>
constexpr int fibonacci() { return fibonacci<n - 1>() + fibonacci<n - 2>(); }
template<>
constexpr int fibonacci<1>() { return 1; }
template<>
constexpr int fibonacci<0>() { return 0; }

int main() {
    cout << fibonacci<6>()<< endl;
}

#endif

#if 0
//��C++17�У������constexpr ifʵ����ֻ��Ҫдһ��������ͨ�ݹ麯����ģ�塣
template<int n>
constexpr int fibonacci() {
    if constexpr (n >= 2)
        return fibonacci<n - 1>() + fibonacci<n - 2>();
    else
        return n;
}

int main() {
    cout << fibonacci<6>() << endl;
}

#endif

//=========10.2 ��ģ��=============

#if 0
//-----C++��׼���vector��ģ����һ��ģ�廯��˳���-------
#include <iostream>
#include <vector>   //vector��ģ���ͷ�ļ�
using namespace std;
int main() {
    vector<int> ivec;            //���������Զ���������Ԫ����
//int���͵�vector�����������飩��
    vector<double> dvec;        //���������Զ���������Ԫ����
//double���͵�vector�����������飩��
    vector<int> ivec2 = { 3,5,7,4,6 };   //��ͳһ��ʼ��{ }��ivec2��ʼ��.
//ivec2��������vector<int>
    ivec = ivec2;        // ivec��ivec2��ͬ����vector<int>�ı��������󣩣������໥��ֵ
 //   dvec = ivec2;        // ��dvec��ivec2�ǲ�ͬ���͵Ķ��󣬲����໥��ֵ��

    for (auto e : ivec2)            //range for�ɱ�������ivec2��ÿ��Ԫ��
        cout << e << '\n';
    cout << endl;

    ivec.push_back(10);   //��ivec�������������һ������10
    ivec.push_back(9);    //��ivec�������������һ������9
    ivec.push_back(8);    //��ivec�������������һ������8
    for (auto e : ivec)   cout << e << '\n';
    cout << endl;

    for (int i = 0; i != 5; i++)
        dvec.push_back(2*i + 1);
    for (int i = 0; i != dvec.size(); i++)   //dvec.size()����ʵ��Ԫ�صĸ���
        cout << dvec[i] << '\n';
    cout << endl;
}

#endif

#if 0
#include <string>
using std::string;
class student {
    string name_;
    double score_;
public:
    student(string n, double s) :name_(n), score_(s) {}
    string name() { return name_; }
    double score() { return score_; }
    void set_name(string n) { name_ = n; }
    void set_score(double s) { score_ = s; }
};
//ͬ������ֱ���ڳ�����ʵ����һ������Ԫ��������student��vector��
#include <iostream>
using namespace std;
int main() {
    vector<student> students;       //��vectorʵ����һ���ࣺvector<student>
    student stu;
    cout << "����ѧ����Ϣ��name, score\n";
    while (cin >> stu.name) {
        if (cin >> score && score >= 0)
            students.push_back(stu);
        else break;
        cout << "����ѧ����Ϣ��name, score\n";
    }
    cout << "�������ѧ������Ϣ\n";
    for (auto e : students)
        cout << e.name() << '\t' << e.score() << endl;

    return 0;
}
#if 0
int main() {
    student students[100];  //100��student�ľ�̬����ռ�
    int num_student = 0;   //ʵ��ѧ������
    return 0;
}
#endif 
#endif

//-------10.2.2 ��ģ��Vector-------------
#if 0
template <typename T>            //����ģ�����T���ڷ�������Ԫ�ص�����
class Vector {
private:
    T* data{ nullptr };             // T*����ָ��ָ������Ԫ��������T�Ķ�̬�ڴ�飨��̬���飩
    size_t capacity{ 0 };            //��̬�ռ�Ĵ�С
    size_t n{ 0 };                  // ʵ�ʵ�����Ԫ�ظ���
public:
    explicit Vector<T>(int cap = 5);
    ~Vector<T>();

    T& operator[](size_t index);                    // �±������
    const T& operator[](size_t index) const;          // const�汾���±������

    Vector<T>(const Vector<T>& array);           // �������캯��
    Vector<T>& operator=(const Vector<T>& rhs);   // ��ֵ�����

    bool push_back(const T& e);
    size_t size() const { return n; } // ����ʵ������Ԫ�صĸ���
};

//1.	���캯��ģ��Constructor Templates
template <typename T>             //�����ⶨ���Ա����ģ�壬�������ģ��ͷ
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, n{ 0 }
{
    if (data) { capacity = cap; }
}
//2.	��������ģ��Destructor Templates
template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

//3.	�������캯��ģ��
template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity } {
    if (!data)  return;
    n = vec.n;
       for (size_t i{}; i < n; ++i)  //����ÿ������Ԫ��
            data[i] = vec.data[i];
}
//4.	�±������[]ģ��
template <typename T>
T& Vector<T>::operator[](size_t index) { // �±������
    if (index >= n) throw "�±�Ƿ�";
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const { // �±������-const
    if (index >= n) throw "�±�Ƿ�";
    return data[index];
}


#if 0 
//const��non-const���±����������ģ�����һ���Ĵ��룬
// ʵ�ʱ����Ӧ�����������ִ����ظ���
//��ônon - const�汾���±��������ô����const�汾���±�����������أ�
//�ܲ���ֱ��д��������ʽ����
template <typename T>
T & Vector<T>::operator[](size_t index) // �±������
{
    return (*this)[index];
}
/*
* ��Ϊ�����non-const�汾�ģ����this��non-constָ�룬
//*this��non-const�����ã�ͨ��������õ��õ��±������������Ȼ�������������
//��ˣ��Ͳ�����������ѭ����
*/
//��ȷ��������ǿ������ת��
//return const_cast<T&> ( static_cast<const Vector<T>&>(*this)[index] );
//const_cast<>ȥ�������const��,��const_cast<>��const����ת��Ϊnon-const����

C++17�ṩ��һ����������std::as_const���Խ�һ��non - const����
//ǿ��ת��Ϊһ��const����
//�����������static_cast<>��ʹ������Ӽ��һЩ��
return const_cast<T&> (std::as_const(*this)[index]);

//std::as_const������ͷ�ļ�<utility>�У�

#include <utility>
template <typename T>
T& Vector<T>::operator[](size_t index) {// �±������
    return const_cast<T&> (std::as_const(*this)[index]);
}

#endif 

//5.	��ֵ�����ģ��The Assignment Operator Template
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
    {
        T* temp = new T[rhs.capacity];   //������Ҳ�����ͬ����С�Ŀռ�
        if (temp) {
            delete[] data;             // �ͷ�ԭ�����ڴ�ռ�
            data = temp;
            // �����Ҳ�����������
            n = rhs.n;
            capacity = rhs.capacity;
            for (size_t i{}; i < n; ++i)
                data[i] = rhs.data[i];
        }
    }
    return *this; // �������������
}

/*
* ��ֵ����������ڲ��ǺͿ������캯������ͬ���Ĵ��룬
//���� �����ظ�����DRY������ԭ��Ӧ�ñ����ظ����롣
�Ƿ���������е��ÿ������캯���أ�
*/

#if 0
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
    {
        Vector<T> ret(rhs)�� //�������캯������һ����ʱ����ret
            delete[] data;        // �ͷű������ڴ�
        data = ret.data;      //dataָ����ʱ�����data�ڴ�
        n = ret.n;
        capacity = ret.capacity;
    }
    return *this; // �������������
}

#endif 

#if 0
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
    {
        Vector<T> ret{ rhs };
        //����ret.data��dataָ��
        T* temp = ret.data;   //
        ret.data = data;
        data = temp;

        n = ret.n;
        capacity = ret.capacity;
    }
    return *this; // �������������
}

#endif

#if 0
//����2��dataָ�������ֵ����ʹ�ñ�׼��ĺ���std::swap()
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
    {
        Vector<T> ret{ rhs };
        std::swap(data, ret.data);
        std::swap(n, ret.n);
        std::swap(capacity, ret.capacity);
    }
    return *this; // �������������
}

#endif

//6.	push_back()

template <typename T>
bool Vector<T>::push_back(const T& e)
{
    if (capacity == n) // �ռ�����
    {
        T* temp = new T[2 * capacity];   //����2�����ڴ�ռ�
        if (!temp) return false;        //ʧ��
        capacity *= 2;                //���ÿռ�����
        //�����ݴӾɿռ俽������¿ռ�
        for (size_t i{}; i < n; ++i)
            temp[i] = data[i];

        delete[] data; // �ͷű������ڴ�
        data = temp;
    }
    //��������e�ӵ���������Ԫ�أ��±�0,1,��,size_-1���������
    data[n] = e;   n++;
    return true;
}

//7.	����Vector��ģ��
int main() {
    Vector<int> a;  // Vector<int>��Vector��ģ���ʵ�����࣬���е�����Ԫ��������int
    for (auto i = 0; i <= 6; i++)
        a.push_back(2 * i + 1);
    a[3] = 30;
    for (auto i = 0; i != a.size(); i++)
        std::cout << a[i] << '\t';
    std::cout << '\n';

    Vector<int> b;
    b = a;
    for (auto i = 0; i != a.size(); i++)
        std::cout << b[i] << '\t';
    return 0;
}

#endif 

//--------10.2.4 ��ģ���ģ������ƶ�------------
/*
* C++17����ģ��ͺ���ģ��һ�������Զ��ƶ�ģ��������͡�
��C++17�У���������ǿ��Դӳ�ʼ���б���
�ƶϳ�ģ��Vector<T>��ģ�����T�����͵ġ�

 Vector x{ 2., 4.3, 8.  };
��
  Vector y{ 2, 4.3, 8. };
���޷��ƶ�ģ����������ͣ���Ϊ2��int����������ֵ��double��

*/

#if 0
//std::tuple��һ���������ɲ�ͬ������ֵ��ģ���ࡣ
int main() {
    std::tuple t(1, 2, 3);              // �Զ��ƶ�3��ֵ�����Ͷ���int
    std::tuple<int, int, int> t2(1, 2, 3); //ָ��3��ֵ�����Ͷ���int
    std::tuple t3(1, 2., 3.f); // �Զ��ƶ�3��ֵ�����Ͷ���int��double��float

    //������get<i>����ģ����һ��tuple�����ĳ���±���i��Ԫ�ء�
    std::cout << typeid(std::get<0>(t3)).name() << "\n";
    std::cout << typeid(std::get<1>(t3)).name() << "\n";
    std::cout << typeid(std::get<2>(t3)).name() << "\n";

}
#endif

//--------10.2.5��ģ���ר�Ż�---------
#if  0
//�ͺ���ģ���ר�Ż�һ����Ҳ���Զ�����ģ���ר�Ż���
//��������ģ�������ָ��ר�����͵���ģ��ר�Ż���Ϊ��ȫר�Ż�
template <>
class Vector<const char*>
{
    // �����ض����� const char*����Vector...
};

//����ר�Ż�����ֻר�Ż�����ģ������������Ĳ���ר�Ż���Ȼ��һ����ģ�塣
template<typename T, int s = 10>
class X {
    //...
};

//���Զ����е�һ��ģ�����������ģ�����ָ����ר�Ż�Ϊconst char*��
//�õ������ר�Ż���ģ�壺
template<int s>
class X<const char*, s> {
    //��
};

//ע�⣺��ģ���е�ģ�����sҲ���������ר����ģ�������<>�������Ҫ˵�������͡�
//�����ר�Ż�������ģ�����ר�Ż�ΪT*ָ�����͡�
template<typename T, int s>
class X<T*, s> {
    //��
};

#endif

//---------10.2.6��ģ�����Ԫ-------------------
/*
* ����ͨ�����Ԫһ���������ùؼ���friend��
��ģ����ָ���ⲿ�������ࡢ������ģ��Ϊ����ģ�����Ԫ��
*/

#if 0
template<typename T>
class X {
    int a{ 0 };
    //...
    friend void fun();
    friend class A;
};

void fun() {
    X<int> x;
    X<double> y;
    std::cout << x.a << '\t' << y.a << '\n';
}

#endif 

#if 0
/*
* ��Ϊ��Ԫ�ĺ���ģ��g����ģ��Y��ͬһ��ģ��ͷ��
��ˣ�g��ʵ����g<int>ֻ����ͬ����ģ�������int������ģ��Y��ʵ��Y<int>����Ԫ��
������������ģ���������double����Yʵ������Y<double>������Ԫ��
*/

template<typename T>
class Point {
public:
    T x, y;
    Point(const T x, const T y) :x(x), y(y) {}
    //...
    friend Point<T>* g(Point<T>& e);
};
template<typename T>
Point<T>* g(Point<T>& e) {
    Point<T>* p = new Point<T>(e);
    return p;
}
int main() {
    Point<int> e(3, 4);
    auto p = g<int>(e);
    std::cout << p->x << "\t" << p->y << '\n';
    Point<double> x(3, 4);
    auto q = g<int>(x);  //��g<int>����Point<double>����Ԫ
    std::cout << q->x << "\t" << q->y << '\n';
}

#endif 

//---------10.2.7 ��ģ��std::initializer_list< >--------------
/*
* ����{}��ʼ���б�ȥ��ʼ��������������Ϊ��ֵ��������Ҳ�����ʱ��
���������Զ�����һ��std::initializer_list<>ʵ������Ķ������磺
   auto il = { 10, 20, 30 };

*/

#if 1
//Point���ж�����std::initializer_list<int>��Ϊ�����Ĺ��캯����
//��Ϳ��Խ���������ֵ�����Ų������б����

class Point {
    int x, y;
public:
    Point(int x0, int y0) :x{ x0 }, y{ y0 }{}
    Point(std::initializer_list<int> list) {
        auto it = list.begin();    //begin()����һ��ָʾlist
//��һ��Ԫ��λ�õĵ�����
        x = *it++;             //�Ƚ�itָ���Ԫ��ֵ*it��ֵ��x,
//Ȼ��it++��ʹ��itָ����һ��Ԫ��
        y = *it++;
    }
    void print() {
        std::cout << x << "," << y;
    }
};

//������Vector�Ĵ�std::initializer_list<>�����Ĺ��캯����
Vector(std::initializer_list<T> l) {
    data = new T[l.size()];
    if (!data) return;
    capacity = l.size(); n = l.size();
    auto i{ 0 };
    for (auto it = l.begin(); it != l.end(); it++, i++)
        data[i] = *it;
}

//ִ�����г���
int main() {
    Vector<Vector<int>> matrix{ {1,2,3,4},{5,6,7,8} };
    for (auto i = 0; i < matrix.size(); i++) {
        for (auto j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}


#endif 