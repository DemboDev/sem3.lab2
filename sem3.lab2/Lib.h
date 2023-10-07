#pragma once
#define Len 30
#define LenDate 10
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

Author AuthorInit(char* name, char* date, char* country) { // инициализация автора
    Author buf;
    if (strlen(name) == 0 || strlen(country) == 0) {
        exit(-1);
    }
    else if (strlen(date) != LenDate) {
        puts("Я тупой прост немножко");
        exit(-1);
        }
        else {
            if (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9') {
                puts("У тебя ошибка во времени, братан, так что извиняй, я пошёл");
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

Author AuthorInput() { // ввод автора
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* country = (char*)calloc(Len, sizeof(char));

    puts("Введите имя автора");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату рождения автора в формате DD.MM.YYYY");
            gets_s(date, 200);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("Введите страну происхождения автора");
    gets_s(country, Len);

    Author buf = AuthorInit(name, date, country);
    return buf;
} 

void PrintAuthor(Author author) { // вывод информации об авторе
    puts(author.name);
    puts(author.date);
    puts(author.country);
}

Client ClientInit(char* name, char* date, char* address) {
    Client buf;

    if (strlen(name) == 0 || strlen(date) != LenDate || strlen(address) == 0) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.date = date;
        buf.address = address;
    }
    return buf;
}

Client ClientInput() { // ввод клиента (читателя)
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите имя читателя");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату рождения читателя в формате DD.MM.YYYY");
            gets_s(date, 200);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("Введите адрес проживания читателя");
    gets_s(address, Len);

    Client buf = ClientInit(name, date, address);
    return buf;
}

Book BookInit(char* name, Author author, int year) {
    Book buf;

    if (strlen(name) == 0 || year <= 1000) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.author = author;
        buf.year = year;
    }
    return buf;
}

Book BookInput(Author author) {
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("Введите название книги");
    gets_s(name, Len);
    puts("Введите год издания книги");
    do {
        scanf("%d", &year);
        if (year < 1000) {
            puts("А теперь нормально");
        }
    } while (year < 1000);

    Book buf = BookInit(name, author, year);
    return buf;
}

Operation OperationInput() {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));

    puts("Введите тип совершённой операции");
    gets_s(move, Len);
    puts("Введите дату совершения операции");
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