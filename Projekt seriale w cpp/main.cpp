//    © 2018 Damian Tabaczynski All Rights Reserved

//Aby kod poprawnie działał prosze w visualu w zakładce właściwości->C/C++->preprocesor-> wstawić zapis _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include "Serial.h"
#include "Media.h"
#include <fstream>
#include "Movie.h"
#include "Stream.h"
#include "Console.h"
#include "Collection.h"

int main()
{
	Console Why_no_code_in_main_because_I_can;

	try
	{
		Why_no_code_in_main_because_I_can.main_manu();
	}
	catch (const char*msg)
	{
		cout << endl << msg << endl << endl;
		system("pause");
	}
	
	catch (...) {
		cout << "Przepraszamy nieznany blad :(((" << endl;
		system("pause");
	}
}
