#pragma once
#define Len 30
#define LenDate 11
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ���������

struct Author {
    char* name;
    char* date;
    char* country;
};

struct Client {
    char* name;
    char* date;
    char* address;
};

struct Book {
    char* name;
    Author author;
    int year;
};

struct Operation {
    char* move;
    char* date;
    Book book;
    Client human;
};

struct Library {
    Book* book;
    Client* readers;
    Operation* operations;
    char* address;
};

// ��������������� �������

char vvod(char min, char max) { // ��������������� �������� �� ������������ �����, ���� ��� ������� ENTER
    char x;
    do {
        x = _getch();
    } while (x < min || x > max);
    return x;
}

void wait() {
    while (getchar() != '\n');
}

// �������� �������

Author AuthorInput() {
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* country = (char*)calloc(Len, sizeof(char));

    puts("������� ��� ������");
    gets_s(name, Len);
    puts("������� ���� �������� ������ � ������� DD.MM.YYYY");
    gets_s(date, LenDate);
    puts("������� ������ ������������� ������");
    gets_s(country, Len);
}

Client ClientInput() {
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("������� ��� ��������");
    gets_s(name, Len);
    puts("������� ���� �������� ��������");
    gets_s(date, LenDate);
    puts("������� ����� ���������� ��������");
    gets_s(address, Len);
}

Book BookInput() {
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("������� �������� �����");
    gets_s(name, Len);
    puts("������� ��� ������� �����");
    scanf("%d", &year);
}

Operation OperationInput() {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));

    puts("������� ��� ����������� ��������");
    gets_s(move, Len);
    puts("������� ���� ���������� ��������");
    gets_s(date, LenDate);
}

Library LibraryInp() {
    char* address = (char*)calloc(Len, sizeof(char));

    gets_s(address, Len);
}