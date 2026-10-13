#include <iostream>


#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    // Affiche correctement les accents dans la console Windows.
    SetConsoleOutputCP(CP_UTF8);
#endif


    return 0;
}
