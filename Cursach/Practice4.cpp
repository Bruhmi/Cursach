#include <iostream>
#include <cstring>
#include <fstream>
#include<array>


char puncts[] = { '!', '@', '#', '$', '%', '^', '&', '(',')', '-', '_', '"', '�', ';', ':', '?', '/', '.', ',' };

bool isPunc(char symbol) {
    for (int i = 0; i < 19; i++) {
        if (symbol == puncts[i]) {
            return true;
        }
    }
    return false;
}


int searchSubstring(char text[], char pattern[]) {
    int sizeText = strlen(text); int sizePattern = strlen(pattern);
    for (int i = 0; i <= sizeText - sizePattern; i++) {
        int j;
        for (j = 0; j < sizePattern - 1; j++) {
            if (text[i + j] != pattern[j + 1])
                break;
        }

        if (j == sizePattern - 1)
            return i;
    }
    return -1;
}

int Practice4() {
    system("chcp 1251");
    setlocale(LC_ALL, "ru");

    const int SIZE_STR = 10000;
    char str[SIZE_STR];
    char formattedStr[SIZE_STR] = "";

    std::cout <<
        "������������ ������ �4\n\n"
        "������� ������ (�� ������ " << SIZE_STR << " ��������):\n";
    std::cin.getline(str, SIZE_STR);

    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    for (i; i < strlen(str); i++) {
        if (str[i] != ' ') {
            strncat_s(formattedStr, str + i, 1);
        }
        else {
            if (str[i] == ' ' && str[i + 1] != ' ' && !isPunc(str[i + 1])) { //���� ������� ���, ����� ������ ����� ���������� ���������
                strncat_s(formattedStr, str + i, 1);
            }
        }
    }for (int i = 1; i < strlen(formattedStr); i++) {
        formattedStr[i] = tolower(formattedStr[i]);
    }


    std::cout <<
        "��������:\n"
        "1) ������� ����������������� ������.\n"
        "2) �������� ����� � ������ � �������� �������\n"
        "3) �������� ������ ����� �� ��������� �� ���� ������.\n"
        "4) ����� ���������� ��������";

    int task;
    for (int stop = 0; stop < 1; stop) {
        std::cout << "������� ����� ��������: ";
        std::cin >> task;

        switch (task) {
        case 1: {
            std::cout <<
                "����������������� ������:\n" <<
                formattedStr << "\n\n";
            break;
        }

        case 2: {
            int wordlen = 0;
            for (int i = strlen(formattedStr) - 1; i >= 0; i--) {
                if (formattedStr[i] != ' ') {
                    ++wordlen;
                }
                else {
                    for (int j = i; j <= i + wordlen; j++) {
                        std::cout << formattedStr[j];
                    }
                    std::cout << ' ';
                    wordlen = 0;
                }
            }
            break;
        }
        case 3: {
            for (int i = 1; i < strlen(formattedStr); i++) {
                if (formattedStr[i - 1] == ' ') {
                    formattedStr[i] = toupper(formattedStr[i]);
                }
            }
            std::cout << formattedStr << "\n\n";
            break;
        }

        case 4: {
            std::cout << "������� ������� ���������:\n";
            char pattern[SIZE_STR] = "";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(pattern, SIZE_STR);

            if (searchSubstring(formattedStr, pattern) < 0) {
                std::cout << "����� ��������� ���\n\n";
            }
            else {
                std::cout << "������ �������, � �������� ���������� ������: " << searchSubstring(formattedStr, pattern); "\n\n";
            }

            break;
        }
        case 0:
            stop = 1;
        }

    }

    return 0;
}