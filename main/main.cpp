#include<iostream>
#include<iomanip>
#include<random>


//пример передачи переменной по ссылке 
int add5(int &a)
{
    a+=5;
    return a;
}

// функция, для преобразования в нужную систему счисления
std::string binhex(int a, const int base)
{

    const char l[16] = { '0', '1', '2', '3','4','5','6','7','8','9','A','B','C', 'D','E','F' };
    std::string res = "00000000";
    for (int i = 7; i >= 0; --i)
    {
        res[i] = l[a % base];
        a /= base;
    }
    return res;
}

// Здесь с помощью арифметики указателей считываем переменную побайтово
void byte(unsigned long* a, int len, int base)
{

    for (int i = len - 1; i >= 0; --i)
    {
        std::cout << binhex((int)a[i], base) << "|";
    }
    std::cout << std::endl;
}
static int recursiveCalls = 0;

// Рекурсивная функция для поиска максимального элемента в массиве
int findMaxRecursive(const int* arr, int size) {
    ++recursiveCalls; // Увеличиваем счетчик вызовов
    // Когда размер массива достигает 1, функция завершает рекурсию 
    if (size == 1) {
       // std::cout << "Базовый случай: " << recursiveCalls << " вызовов" << std::endl;
        return arr[0];
    }

    int maxInRest = findMaxRecursive(arr + 1, size - 1);
    return (arr[0] > maxInRest) ? arr[0] : maxInRest;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    float b;
    int a, base;
    std::cout << "Введите целочисленное число: ";
    std::cin >> a;
    std::cout << "Введите, в какой системе счисления вы хотите вывести его побайтово: ";
    std::cin >> base;
    byte((unsigned long*)(&a), sizeof(a), base); // для того чтобы двигаться по нашему числу по одному байту, преобразовываем число к uint8_t
    std::cout << "Введите число с плавующей точкой: ";
    std::cin >> b;
    std::cout << "Введите, в какой системе счисления вы хотите вывести его побайтово: ";
    std::cin >> base;
    byte((unsigned long*)(&b), sizeof(b), base);
    std::cout << "\nЗадача 2\n";
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    int * mas = new int[n];
    for(int i = 0; i < n; ++i)
    {
        mas[i] = rand() % 1000;
    }
    std::cout << "Максимальный элемент: " << findMaxRecursive(mas, n);
    std::cout << "\nЗадача 3\nВведите n: ";
    std::cin >> n;
    add5(n);
    std::cout <<"n + 5 = " << n;

}