
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class joey
{
	T first, second;
public:
	joey(T a, T b)
	{	first = a;
		second = b;	}
	T bigger();

};

template <class T>
T joey<T>::bigger()
{	//to see which number is bigger
	return (first > second ? first : second);
}

template <class T>
class chap
{
public:
	chap(T x){
		cout << x << " is not a character" << endl;
	}
};

template<>
class chap<char>{
public:
	chap(char x)
	{
		cout << x << " is a character" << endl;
	}
};

template <class F, class S>
F smaller(F a, S b)
{	return (a > b ? a : b);}


int main()
{
	joey <int> chapo(702, 85);
	cout << chapo.bigger() << endl;
	
	chap<int> obj1(7);
	chap<double> obj2(2.14159);
	chap<char> obj3('J');
	
	try{
		int momage = 30;
		int sonage = 34;

		if (sonage > momage)
		{
			throw 100;
		}
	}
	catch (int x)
	{
		cout << "Son cant be older than mom. Error " << x << endl;
	}
	
	int x;
	double y;
	cout << "Enter 2 numbers ";
	cin >> x >> y;
	double z = smaller(x, y);
	cout << z << endl;

	system("pause");
	return 0;
}