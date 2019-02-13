#include <iostream>
#include "extremum.h"
using namespace std;
class metod_Dihotomii: public extremum
{	private:
		double aa,bb,NN,xx,cc,tt,F1,F2;
	public:
	void	search(double d)
	{
		if (d!=0)
		{
			aa = a;
			bb = b;
			NN = 0;
			cc = c;
			tt = t;
			do 
			{
				xx = (aa + bb) / 2;
				F1 = function(xx - tt);
				F2 = function(xx + tt);
				if ( cc*F1 < cc*F2 )
				{
					bb = xx;
				}
				else 
				{
					aa = xx;
				}
				//cout << "N= " << NN << "  x = " << xx << endl;
				NN++;
			}
			while ( (bb-aa) > tt );
			x = (aa+bb) / 2;
			y = function(x);
		}
	};
};
int main()
{	
	setlocale(LC_ALL, "Russian");
	double b = 0;
	bool k = false;
	metod_Dihotomii a;
	do
	{
		a.vvod();
		b = a.metod(b);
		a.search(b);
		k = a.vyvod(k);
	cout << endl;
	}
	while (k!=1);
	system ("pause");
return 0;}

#include <iostream>
using namespace std;
class extremum
{
protected:
	double	a,b,a1,b1,c,c1,f,x,y,t,N,k;
	
	char	s[5],s2[5],s1[5];
	bool	correctly, correctly1, correctly2, correctly3, correctly4;
public:
	double	function(double x);
	void	vvod();
	double	metod(double d);
	void	virtual search(double d);
	double	vyvod(double k);
};

#include <iostream>
#include "extremum.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
using namespace std;
double extremum::function(double x)
	{
		return ((x-4)*(x-4)+2);
	};
void extremum::vvod()
{
	srand(time(0));
	cout << "	/////////////////////////" << endl;
	cout << "	//// Метод Дихотомии ////" << endl;
	cout << "	/////////////////////////" << endl;
	do
		{
			cout << "<< Введите точность определения экстремума: " << endl;
			cin >> s;
			t = atof( s );
			if ((t == NULL)||(t<=0)||(t>=1)||(t<0.000000000023125))
			{
				cout << endl << "<< Ошибка. Пожалуйста введите коректные данные точности." << endl;
				cout << "<< Справка: точность определяется числом в интервале от 0 до 1." << endl;
				cout << "<< Пример: 0,00" << rand()%1+9 << endl << endl;
				correctly = false;
			}
			else 
			{
				cout << endl << "<< Точность определена: " << t << endl << endl;
				correctly = true;
			}
		}
	while (correctly == false);
	do 
		{
			cout << "<< Введите интервал, в котором будет вестись поиск экстремума." << endl;
			do
			{
				cout << endl << "<< Начало интервала:" << endl;
				if (scanf("%lf",&a)!=1)
				{
					scanf("%*s");
					cout << endl << "<< Ошибка. Пожалуйста введите коректно начало интервала." << endl;
					cout << "<< Пример: " << rand()%-5+5 << endl;
					correctly2 = false;
				}
				else
				{
					correctly2 = true;
				}
			}
			while(correctly2 != true);
			do
			{
				cout << endl << "<< Конец интервала:" << endl;
				if (scanf("%lf",&b)!=1)
				{
					scanf("%*s");
					cout << endl << "<< Ошибка. Пожалуйста введите коректно конец интервала." << endl;
					cout << "<< Пример: " << rand()%-5+20 << endl;
					correctly2 = false;
				}
				else
				{
					correctly2 = true;
				}
			}
			while(correctly2 != true);
			if ((a >= b)||((fabs(a)*fabs(b)*(1/t))/1000000000 > (378*4*1000000000000)))
			{
				cout << endl << "<< Ошибка. Пожалуйста введите коректно данные для интервала." << endl;
				cout << "<< Пример: " << rand()%1+5 << " и " << rand()%5+20 << endl << endl;
				correctly1 = false;
			}
			else
			{
				cout << endl << "<< Интервал определен: от " << a << " до " << b << endl;
				correctly1 = true;
			}
		}
	while(correctly1 != true);
	do
		{
			cout << endl << "<< Выберите тип экстремума, который необходимо найти. Введите или 0, или 1." << endl;
			cout << "<< Минимум - 0, Максимум - 1" << endl;
			if (scanf("%lf",&c)!=1)
			{
				scanf("%*s");
				cout << endl << "<< Ошибка." << endl;
				correctly3 = false;
			}
			else
			{
				if (c!=1)
				{
					if (c!=0)
					{
						cout << endl << "<< Ошибка." << endl;
						correctly3 = false;
					}
					else
					{
						correctly3 = true;
					}
				}
				else
				{
					correctly3 = true;
				}
			}
		}
	while(correctly3 != true);
};

double extremum::metod(double d)
{
	if (c==0)
	{
		c = 1;
		return (c);
	}
	else 
	{
		c = -1;
		return (c);
	}	
};
void extremum::search(double d)
{};
double extremum::vyvod(double k)
{
	if ((( x + t ) > b )||(( x - t ) < a ))
	{
		cout << endl << "Экстремум не найден" << endl;
	}
	else 
	{
		ofstream fout;
		cout << endl << "Координаты экстремума x = " << x << "  y = " << y << " с погрешностью +/- " << t << endl;
		fout.open("F:\\координаты.txt", ios::app);
		fout << "Координата по оси ОХ = " << x << endl;
		fout << "Координата по оси ОУ = " << y << endl;
		fout << "С погрешностью +/- " << t << endl << endl;
		fout.close();
	}
	do
		{
			cout << endl << "<< Хотите продолжить работу? Да - 0 / Нет - 1" << endl;
			if (scanf("%lf",&k)!=1)
			{
				scanf("%*s");
				cout << endl << "<< Ошибка." << endl;
				correctly4 = false;
			}
			else
			{
				if (k!=1)
				{
					if (k!=0)
					{
						cout << endl << "<< Ошибка." << endl;
						correctly4 = false;
					}
					else
					{
						correctly4 = true;
					}
				}
				else
				{
					correctly4 = true;
				}
			}
		}
	while(correctly4 != true);
	return (k);
};
