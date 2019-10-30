#include<iostream>

using namespace std;

class complex
{

	private:

		int real;
		int imag;

	public:

		complex(int a = 0, int b = 0)
		{
			real = a;
			imag = b;
		}

		friend complex operator + (complex&,complex&);
		friend complex operator - (complex&,complex&);
		friend istream & operator >> (istream &t, complex &res);
		friend ostream & operator << (ostream &t, complex &res);
};


complex operator + (complex &c1,complex &c2)
{
	complex result;
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
}

complex operator - (complex &c1,complex &c2)
{
	complex result;
	result.real = c1.real - c2.real;
	result.imag = c1.imag - c2.imag;
	return result;
}

 istream & operator >> (istream &t, complex &res)
 {
 	//complex res;
 	cout << "Enter the real part: ";
 	t >> res.real;

 	cout << "Enter the imaginary part: ";
 	t >> res.imag;

 	return t;
 }

 ostream & operator << (ostream &t, complex &res)
 {
 	if(res.imag < 0) t << res.real << "- i" << -1*res.imag;
 	else t << res.real << "+ i" << res.imag;

 	return t;
 }


int main()
{
	complex c1;
	cin >> c1;
	cout << c1;
	return 0;
}
