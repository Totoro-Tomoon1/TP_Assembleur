// AssemblyCMake.cpp : définit le point d'entrée de l'application.
//

#include "AssemblyCMake.h"
#include "Chrono.h"

extern "C" int64_t asm_add(int64_t a, int64_t b);
extern "C" int64_t asm_find(int64_t* tab, int64_t size, int64_t value);
extern "C" int64_t asm_calc(int64_t type, int64_t value1, int64_t value2);
extern "C" double asm_calc_f(int64_t type, double value1, double value2);

using namespace std;

int Find(int64_t* tab, int64_t size, int64_t value)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == value)
			return i + 1;
	}

	return -1;
}

//only int
//0 : +
//1 : -
//2 : x
//3 : /
//4 : 

int main()
{
	while (true)
	{
		cout << "Int : 0, float : 1 : ";
		bool isFloat;
		cin >> isFloat;

		if (!isFloat)
		{
			cout << "Selectionner l'operation (0 : +, 1 : -, 2 : x, 3 : /) : ";
			int type;
			cin >> type;
			int64_t value1;
			cout << endl << "Premiere valeur : ";
			cin >> value1;
			int64_t value2;
			cout << endl << "Deuxieme valeur : ";
			cin >> value2;

			cout << endl << "Resultat : " << asm_calc(type, value1, value2);
		}
		else
		{
			cout << "Selectionner l'operation (0 : +, 1 : -, 2 : x, 3 : /) : ";
			int type;
			cin >> type;
			double value1;
			cout << endl << "Premiere valeur : ";
			cin >> value1;
			double value2;
			cout << endl << "Deuxieme valeur : ";
			cin >> value2;

			cout << endl << "Resultat : " << asm_calc_f(type, value1, value2);
		}
		

		cout << endl << "Continuer ? (Oui : 0, Non : 1) : ";
		bool cont;
		cin >> cont;

		if (cont != false)
			return 0;

		system("CLS");

	}

	/*int64_t size = 6;
	int64_t tab[6] = { 0, 0, 0, 4, 0, 0 };
	int64_t value = 4;

	Chrono chrono;
	chrono.Start();

	cout << asm_find(tab,6, 4) << endl;

	float time = chrono.CurrentTime();

	cout << "Time assembleur : " << time << endl;

	chrono.Restart();

	cout << Find(tab, 6, 4) << endl;

	time = chrono.CurrentTime();

	cout << "C++ : " << time << endl;*/

	return 0;
}
