#pragma once
#define Len 30
#define LenDate 10
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

Author AuthorInit(char* name, char* date, char* country) {
    Author buf;
    if (strlen(name) == 0 || strlen(country) == 0) {
        exit(-1);
    }
    else if (strlen(date) != 10) {
        puts("� ����� ����� ��������");
        exit(-1);
        }
        else {
            if (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9') {
                puts("� ���� ������ �� �������, ������, ��� ��� �������, � �����");
                exit(-1);
            }
            else {
                buf.name = name;
                buf.date = date;
                buf.country = country;
            }
        }
    return buf;
}

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

    Author buf = AuthorInit(name, date, country);
    return buf;
}

void PrintAuthor(Author author) {
    puts(author.name);
    puts(author.date);
    puts(author.country);
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
    Client buf;
    return buf;
}

Book BookInput() {
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("������� �������� �����");
    gets_s(name, Len);
    puts("������� ��� ������� �����");
    scanf("%d", &year);
    Book buf;
    return buf;
}

Operation OperationInput() {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));

    puts("������� ��� ����������� ��������");
    gets_s(move, Len);
    puts("������� ���� ���������� ��������");
    gets_s(date, LenDate);
    Operation buf;
    return buf;
}

Library LibraryInp() {
    char* address = (char*)calloc(Len, sizeof(char));

    gets_s(address, Len);
    Library buf;
    return buf;
}