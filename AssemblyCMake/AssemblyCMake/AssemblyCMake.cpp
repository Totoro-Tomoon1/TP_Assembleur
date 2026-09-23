// AssemblyCMake.cpp : définit le point d'entrée de l'application.
//

#include "AssemblyCMake.h"
#include "Chrono.h"

extern "C" int64_t asm_add(int64_t a, int64_t b);
extern "C" int64_t asm_find(int64_t* tab, int64_t size, int64_t value);

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

int main()
{
	int64_t size = 6;
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

	cout << "C++ : " << time << endl;

	return 0;
}
