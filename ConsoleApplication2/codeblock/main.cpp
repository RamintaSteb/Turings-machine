#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string B[100]; // busena
	char K[100]; // kintamasis
	char P[100]; // pakeicia
	char J[100]; //juda
	string N[100]; // nauja busena
	//skaitymas
	int a, kiek, kuris;
	string eil;
	string file;
	//------------------------------------------------------
	cout << "Kurio failo duomenis norite naudoti?" << endl;
	cin >> file;
	while (file != "0")
	{
		ifstream F((file+".txt").c_str());
		F >> kuris;
		kuris--;//nes skaiciuojam nuo 0
		F >> eil;
		kiek = 0;
		while (!F.eof()) // nuskaito
		{
			F >> B[kiek];
			F >> K[kiek];
			F >> P[kiek];
			F >> J[kiek];
			F >> N[kiek];
			kiek++;
		}
		F.close();
		kiek--;
		//------------------------------------------------------
		string busena = "0";
        for (int i = 0; i < kiek; i++)
        {
            if (!kbhit())
            {
                if (B[i] == busena && K[i] == eil[kuris])
                {
                    eil[kuris] = P[i];
                    if (J[i] == 'R') kuris++;
                    else kuris--;
                    busena = N[i];
                    cout << eil << endl;
                    i = -1;
                }
            }
        }
		//------------------------------------------------------
		cout << "Kurio failo duomenis norite naudoti?" << endl;
		cin >> file;
	}
	cout << "Programa baigia darba" << endl;
	system("PAUSE");
    return 0;
}
