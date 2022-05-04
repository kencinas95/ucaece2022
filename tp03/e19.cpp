#include <iostream>
#include <cstdlib>
#include <cstring>


bool is_palyndrome(const char*, const int);

int main(int argc, const char **argv)
{
    if (argc < 2) {
        return 1;
    }

    const char *word = argv[1];
    const int len = strlen(word);    

    std::cout << word;    
    std::cout << ": Is palyndrome? ";
    std::cout << (is_palyndrome(word, len) ? "Yes" : "No") << std::endl;

    return 0;
}

bool is_palyndrome(const char *string, const int lenght)
{
    for (int i = 0; i < (int)(lenght / 2); i++)
    {
        if (string[i] != string[lenght - (i + 1)])
        {        
            return false;
        }
    }
    return true;
}
