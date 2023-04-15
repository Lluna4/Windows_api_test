#include "lib.h" 
int main()
{
    WIN32_FIND_DATAA buff;
    std::vector<char *> archivos;
    HANDLE primer_archivo;
    int index = 0;
    char *a = new char;
    bool cambio = false;
    const char *path = "C:\\Users\\carly\\source\\repos\\testcpp\\x64\\Debug\\+Instaladores\\*";

    primer_archivo = FindFirstFileA(path, &buff);
    if (primer_archivo == INVALID_HANDLE_VALUE)
    {
        std::cout << "Error, probablemente no hay carpetas en esta carpeta";
        return 1;
    }
    if (buff.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(buff.cFileName, ".") != 0 && strcmp(buff.cFileName, "..") != 0)
        archivos.push_back(_strdup(buff.cFileName));
    while (FindNextFileA(primer_archivo, &buff))
    {
        if (buff.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(buff.cFileName, ".") != 0 && strcmp(buff.cFileName, "..") != 0)
            archivos.push_back(_strdup(buff.cFileName));
    }
    for(unsigned int i = 0; i < archivos.size(); i++)
    {
        cambio = false;
        if (i < archivos.size() - 1 && archivos[i] && archivos[i+1])
        {   
            if (archivos[i][0] > archivos[i+1][0])
            {
                ft_swap(&archivos[i], &archivos[i+1]);
                cambio = true;
            }
        }
        else
        {
            if (cambio == true)
                i = 0;
            else
                break;
        }
    }
    for(unsigned int i = 0; i < archivos.size(); i++)
    {
        std::cout << ft_itoa(i) << "-" << archivos[i] << '\n';
    }
    std::cout << "Numero: ";
    std::cin >> a;
}

