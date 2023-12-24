#include <iostream>
#include <ctime>

int Practice1() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    std::cout <<
        "ПРАКТИЧЕСККАЯ РАБОТА №1\n\n"

        "ДДЕЙСТВИЯ:\n"
        "1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: "
        "int, short int, long int, float, double, long double, char и bool.\n"
        "2) Вывести на экран двоичное представление в памяти (все разряды) целого числа.\n"
        "3) Вывести на экран двоичное представление в памяти (все разряды) числа типа float.\n"
        "4) Вывести на экран двоичное представление в памяти (все разряды) числа типа double.\n";
    int taskNumb;
    for (int stop = 0; stop < 1; stop) {
        std::cout << "Введите номер действия: ";
        std::cin >> taskNumb;

        switch (taskNumb) {
        case 1:
            std::cout <<
                "Выделенное кол-во памяти(в байтах) на разные типы данных:\n"
                "int: " << sizeof(int) << "\n" <<
                "short int: " << sizeof(short int) << "\n" <<
                "long int: " << sizeof(long int) << "\n" <<
                "float: " << sizeof(float) << "\n" <<
                "double: " << sizeof(double) << "\n" <<
                "long double: " << sizeof(long double) << "\n" <<
                "char: " << sizeof(char) << "\n" <<
                "bool: " << sizeof(bool) << "\n\n";
            break;

        case 2: {
            int intVar;
            std::cout << "Введите целое число: ";
            std::cin >> intVar;
            std::cout << "Двоичное представление числа " << intVar << " в памяти: ";
            int order = sizeof(int) * 8;
            unsigned mask = 1 << (order - 1);

            for (int i = 0; i < order; ++i) {
                std::cout << ((intVar & mask) ? 1 : 0);
                mask >>= 1;
                if (!i || !((i + 1) % 8)) {
                    std::cout << " ";
                }
            }
            std::cout << "\n\n";
            break;
        }

        case 3: {
            union {
                int tool1;
                float flVar;
            };
            unsigned int order = 32;
            std::cout << "Введите вещественное число: ";
            std::cin >> flVar;
            unsigned mask = 1 << (order - 1);
            std::cout << "Двоичное представление числа " << flVar << " в памяти: ";
            for (int i = 1; i <= order; i++) {
                std::cout << (tool1 & mask ? '1' : '0');
                mask >>= 1;
                if (i == 1)
                    std::cout << ' ';
                if (i == 9)
                    std::cout << ' ';
            }
            std::cout << "\n\n";
            break;
        }
        case 4: {
            union {
                int arr[2];
                double dbVar;
            };
            unsigned int order = 32;
            std::cout << "Введите вещественное число: ";
            std::cin >> dbVar;
            unsigned mask = 1 << (order - 1);
            std::cout << "Двоичное представление числа " << dbVar << " в памяти: ";
            for (int i = 1; i <= order; i++) {
                std::cout << (arr[1] & mask ? '1' : '0');
                mask >>= 1;
                if (i == 1)
                    std::cout << ' ';
                if (i == 9)
                    std::cout << ' ';
            }
            std::cout << " ";

            mask = 1 << (order - 1);
            for (int i = 1; i <= order; i++) {
                std::cout << (arr[0] & mask ? '1' : '0');
                mask >>= 1;
                if (i == 1)
                    std::cout << ' ';
                if (i == 9)
                    std::cout << ' ';
            }
            std::cout << "\n\n";
            break;
        }
        case 0:
            stop = 1;
            break;
        }
    }
    return 0;
}