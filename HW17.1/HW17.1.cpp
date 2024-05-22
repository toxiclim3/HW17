#include <iostream>
#include <stdio.h>

using namespace std;

/*Завдання 1. Дано два текстові файли. З'ясувати, чи збігаються їхні рядки. 
Якщо ні, то вивести рядок, який не збігається, з кожного файлу.*/



void makeFiles(FILE* &file1,FILE* &file2)
{
	fopen_s(&file1,"str1.txt", "a");
	fopen_s(&file2,"str2.txt", "a");

	fclose(file1);
	fclose(file2);
}

void closeFiles(FILE*& file1, FILE*& file2)
{
	if (fclose(file1) == EOF)
		cout << "The file 1 has NOT been closed \n";
	else
		cout << "The file 1 has been closed \n";

	if (fclose(file2) == EOF)
		cout << "The file 2 has NOT been closed \n";
	else
		cout << "The file 2 has been closed \n";
}

int main()
{
	FILE* file1;
	FILE* file2;
	
	const char* file1path = "str1.txt";
	const char* file2path = "str2.txt";
	//makeFiles(file1, file2);

	//err  = fopen_s(&file1,file1path, "r");
	//err2 = fopen_s(&file2,file2path, "r");

	char* line1;
	char* line2;

	const int gSize = 255;
	char* tempChar = new char[255];

	int size;
	
	if ((fopen_s(&file1, file1path, "r") != NULL) || (fopen_s(&file2, file2path, "r") != NULL))
		cout << "The file cannot be opened";
	else
	{
		int curLine = 0;
		while (!feof(file1) && !feof(file2))
		{
		
			fscanf_s(file1, "%s", tempChar, gSize);

			size = strlen(tempChar);
			line1 = new char[size + 1];
			strcpy_s(line1, size + 1, tempChar);

			fscanf_s(file2, "%s", tempChar, gSize);

			size = strlen(tempChar);
			line2 = new char[size + 1];
			strcpy_s(line2, size + 1, tempChar);

			if (strcmp(line1, line2) != 0)
			{
				cout << "difference at line " << curLine << endl;
				cout << "File 1:" << line1 << endl;
				cout << "File 2:" << line2 << endl;
			}

			delete[] line1;
			delete[] line2;

			curLine++;
		}

		closeFiles(file1, file2);
	}
	
	delete[] tempChar;
}
