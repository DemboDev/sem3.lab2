#pragma once
#define Len 30
#define LenDate 11
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Структуры

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

// Вспомогательные функции

char vvod(char min, char max) { // автоматизировал проверку на допустимость ввода, ввод без нажатия ENTER
    char x;
    do {
        x = _getch();
    } while (x < min || x > max);
    return x;
}

void wait() {
    while (getchar() != '\n');
}

// Основные функции

Author AuthorInput() {
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* country = (char*)calloc(Len, sizeof(char));

    puts("Введите имя автора");
    gets_s(name, Len);
    puts("Введите дату рождения автора в формате DD.MM.YYYY");
    gets_s(date, LenDate);
    puts("Введите страну происхождения автора");
    gets_s(country, Len);
}

Client ClientInput() {
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите имя читателя");
    gets_s(name, Len);
    puts("Введите дату рождения читателя");
    gets_s(date, LenDate);
    puts("Введите адрес проживания читателя");
    gets_s(address, Len);
}

Book BookInput() {
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("Введите название книги");
    gets_s(name, Len);
    puts("Введите год издания книги");
    scanf("%d", &year);
}

Operation OperationInput() {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));

    puts("Введите тип совершённой операции");
    gets_s(move, Len);
    puts("Введите дату совершения операции");
    gets_s(date, LenDate);
}

Library LibraryInp() {
    char* address = (char*)calloc(Len, sizeof(char));

    gets_s(address, Len);
}