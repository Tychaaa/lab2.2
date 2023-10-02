#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECORDS 10
#define MAX_EMPLOYEE 20
#define MAX_ORDER 10

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Класс для объекта "Виниловая пластинка"
class VinylRecord {
private:

    string albumName;   // Название альбома
    string artist;      // Исполнитель
    int year;           // Год выпуска
    string genre;       // Жанр
    float price;        // Цена
    int quantity;       // Количество в наличии

public:

    // Контруктор без параметров
    VinylRecord() : albumName(""), artist(""), year(0), genre(""), price(0), quantity(0) {}
    // Контруктор с параметрами
    VinylRecord(string album, string artist, int year, string genre, float price, int quantity)
        : albumName(album), artist(artist), year(year), genre(genre), price(price), quantity(quantity) {}
    // Деструктор
    ~VinylRecord() {}

};

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string* album, string* artist, int* year, string* genre, float* price, int* quantity)
{
    cout << "Введите название альбома: ";
    getline(cin, *album);

    cout << "Введите исполнителя: ";
    getline(cin, *artist);

    cout << "Введите год выпуска: ";
    cin >> *year;
    cin.ignore();

    cout << "Введите жанр: ";
    getline(cin, *genre);

    cout << "Введите цену: ";
    cin >> *price;

    cout << "Введите количество в наличии: ";
    cin >> *quantity;
}

// Класс для объекта "Человек"
class Human {
private:

    string firstName;   // Имя
    string lastName;    // Фамилия

public:

    // Конструктор без параметров
    Human() : firstName(""), lastName("") {}
    // Контруктор с параметрами
    Human(string first, string last) : firstName(first), lastName(last) {}
    // Деструктор
    ~Human() {}
};

// Класс для объекта "Клиент"
class Customer {
private:

    Human person;       // Используем класс Human для представления клиента
    float money;        // Кол/во денег
    string address;     // Адрес доставки

public:

    // Конструктор без параметров
    Customer() : money(0), address("") {}
    // Контруктор с параметрами
    Customer(string first, string last, float money, string addr)
        : person(first, last), money(money), address(addr) {}
    // Деструктор
    ~Customer() {}
};

// Класс для объекта "Сотрудник магазина"
class Employee {
private:

    Human person;       // Используем класс Human для представления сотрудника
    string position;    // Должность
    float salary;       // Зарплата

public:

    // Контруктор без параметров
    Employee() : position(""), salary(0) {}
    // Контруктор с параметрами
    Employee(string first, string last, string pos, float sal)
        : person(first, last), position(pos), salary(sal) {}
    // Деструктор
    ~Employee() {}
};

// Класс для объекта "Заказ"
class Order {
private:

    int orderNumber;    // Номер заказа
    string orderDate;   // Дата заказа
    Employee employee;  // Сотрудник магазина
    Customer customer;  // Клиент
    VinylRecord orderedRecord; // Заказанная виниловая пластинка
    int quantityOrdered;       // Кол/во заказанных виниловых пластинок
    float totalCost;    // Общая стоимость заказа

public:

    // Контруктор без параметров
    Order() : orderNumber(0), orderDate(""), quantityOrdered(0), totalCost(0) {}
    // Контруктор с параметрами
    Order(int number, string date, Employee emp, Customer cust, VinylRecord record, int quantity, float cost)
        : orderNumber(number), orderDate(date), employee(emp), customer(cust), orderedRecord(record), quantityOrdered(quantity), totalCost(cost) {}
    // Деструктор
    ~Order() {}
};

// Класс для объекта "Магазин"
class Store {
private:

    string storeName;    // Название магазина
    string storeAddress; // Адрес магазина
    VinylRecord vinylRecordsInStore[MAX_RECORDS]; // Список имеющихся в магазине виниловых пластинок
    Employee employeesInStore[MAX_EMPLOYEE];      // Список сотрудников магазина

public:

    // Контруктор без параметров
    Store() : storeName(""), storeAddress("") {}
    // Контруктор с параметрами
    Store(string name, string address) : storeName(name), storeAddress(address) {
        // Инициализация массивов в конструкторе
        for (int i = 0; i < MAX_RECORDS; ++i) {
            vinylRecordsInStore[i] = VinylRecord(); // Используем конструктор по умолчанию VinylRecord
        }

        for (int i = 0; i < MAX_EMPLOYEE; ++i) {
            employeesInStore[i] = Employee(); // Используем конструктор по умолчанию Employee
        }
    }
    // Деструктор
    ~Store() {}
};

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t~~Программа №2 по реализации АТД на языке C и C++~~\n";
    cout << endl;

    // Объявление переменных для хранения данных о виниловой пластинке
    string album, artist, genre;
    int year, quantity;
    float price;

    // Вызов функции для ввода данных о виниловой пластинке
    inputVinylRecord(&album, &artist, &year, &genre, &price, &quantity);

    // Создание объекта класса VinylRecord на основе введенных данных
    VinylRecord record1(album, artist, year, genre, price, quantity);

    return 0;
}
