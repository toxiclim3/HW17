#include <iostream>
#include <stdio.h>

using namespace std;

/*Завдання 2. что то там посчитать символы буквы и тд*/



int makeFiles(FILE*& file1, FILE*& file2)
{
    fopen_s(&file1, "str1.txt", "a");
    fopen_s(&file2, "str2.txt", "a");

    fclose(file1);
    fclose(file2);

    return 1;
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

    /*if (makeFiles(file1, file2) == 1)
    {
        return 1;
    };*/


    const int gSize = 255;
    char tempChar;

    int size;

    if ((fopen_s(&file1, file1path, "r") != NULL) || (fopen_s(&file2, file2path, "w") != NULL))
        cout << "The file cannot be opened";
    else
    {
        int spChars = 0, chars = 0, vowels = 0, consonants = 0, digits = 0, spaces = 0, outsideASCII = 0;
        while ((tempChar = fgetc(file1)) != EOF)
        {

            int tempInt = 0;

            if (tempChar == 32)
            {
                spaces++;
            }
            else if (tempChar <= 32)
            {
                spChars++;
            }
            else if ((tempChar > 32 && tempChar <= 47) || (tempChar >= 58 && tempChar <= 64) || (tempChar >= 91 && tempChar <= 96) || (tempChar >= 123 && tempChar <= 126))
            {
                chars++;
            }
            else if (tempChar >= 48 && tempChar <= 57)
            {
                digits++;
            }
            
            else if ((tempChar >= 65 && tempChar <= 90) || (tempChar >= 97 && tempChar <= 122))
            {
                if ((tempChar >= 97 && tempChar <= 122))
                {
                    tempInt = tempChar - 32;
                }
                else
                {
                    tempInt = tempChar;
                }
                if ((tempInt == 65) || (tempInt == 69) || (tempInt == 73) || (tempInt == 79) || (tempInt == 85))
                {
                    vowels++;
                }
                else
                {
                    consonants++;
                }
            }
            else
            {
                outsideASCII++;
            }




        }
        fprintf_s(file2, "The first file has %i special invisible characters, %i regular special characters, %i vowels, %i consonants, %i digits, %i spaces, %i characters outside the ASCII table", spChars, chars, vowels, consonants, digits, spaces, outsideASCII);

        closeFiles(file1, file2);
    }

}
