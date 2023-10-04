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

// Глобальные переменные для подсчета количества пластинок, сотрудников и заказов
int numRecords, numEmployees, numOrders;

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

    // Метод для вывода информации о виниловой пластинке
    void outputVinylRecord();
    // Метод для получения стоимости виниловой пластинки
    float getPrice();
    // Метод для получения названия виниловой пластинки
    const string getAlbumName();
    // Метод для получения исполнителя виниловой пластинки
    const string getArtist();
    // Метод для получения количества виниловой пластинки
    int getQuantity();
};

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string* album, string* artist, int* year, string* genre, float* price, int* quantity)
{
    cin.ignore();

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

    cout << endl;
}

// Определение метода для вывода информации о виниловой пластинке
void VinylRecord::outputVinylRecord()
{
    cout << "Название альбома: " << albumName << endl;
    cout << "Исполнитель: " << artist << endl;
    cout << "Год выпуска: " << year << endl;
    cout << "Жанр: " << genre << endl;
    cout << "Цена: " << price << endl;
    cout << "Количество в наличии: " << quantity << endl;
    cout << endl;
}

// Определение метода для получения стоимости виниловой пластинке
float VinylRecord::getPrice()
{
    return price;
}

// Определение метода для получения названия виниловой пластинки
const string VinylRecord::getAlbumName()
{
    return albumName;
}

// Определение метода для получения исполнителя виниловой пластинки
const string VinylRecord::getArtist()
{
    return artist;
}

// Определение для получения количества виниловой пластинки
int VinylRecord::getQuantity()
{
    return quantity;
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

    // Методы для получения имени и фамилии человека
    const string getFirstName();
    const string getLastName();
};

// Определение метода для получения имени человека
const string Human::getFirstName()
{
    return firstName;
}

// Определение метода для получения фамилии человека
const string Human::getLastName()
{
    return lastName;
}

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

    // Метод для вывода информации о клиенте
    void outputCustomer();
};

// Функция для ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "Введите имя клиента: ";
    cin >> *firstName;

    cout << "Введите фамилию клиента: ";
    cin >> *lastName;

    cout << "Введите количества денег клиента: ";
    cin >> *money;

    cout << "Введите адрес доставки клиента: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, *address);

    cout << endl;
}

// Определение метода для вывода информации о клиенте
void Customer::outputCustomer()
{
    cout << person.getFirstName() << " " << person.getLastName() << endl;
}

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

    // Метод для вывода информации о сотруднике
    void outputEmployee();

    // Метод для получения имени сотрудника
    const string getFirstName();

    // Метод для получения фамилии сотрудника
    const string getLastName();

    // Метод для получения должности сотрудника
    const string getPosition();
};

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) {

    cout << "Введите имя сотрудника: ";
    cin >> *firstName;

    cout << "Введите фамилию сотрудника: ";
    cin >> *lastName;

    cout << "Введите должность сотрудника: ";
    cin.ignore();
    getline(cin, *position);

    cout << "Введите зарплату сотрудника: ";
    cin >> *salary;

    cout << endl;
}

// Определение метода для вывода информации о сотруднике
void Employee::outputEmployee()
{
    cout << "Имя сотрудника: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Должность: " << position << endl;
    cout << "Зарплата: " << salary << endl;
    cout << endl;
}

// Определение метода для получения имени сотрудника
const string Employee::getFirstName()
{
    return person.getFirstName();
}

// Определение метода для получения фамилии сотрудника
const string Employee::getLastName()
{
    return person.getLastName();
}

// Определение метода для получения должности сотрудника
const string Employee::getPosition()
{
    return position;
}

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

    // Метод для вывода информации о заказе
    void outputOrder();
};

// Определение метода для вывода информации о заказе
void Order::outputOrder()
{
    cout << "Номер заказа: " << orderNumber << endl;
    cout << "Дата заказа: " << orderDate << endl;
    cout << "Сотрудник магазина: " << employee.getFirstName() << " " << employee.getLastName() << " (" << employee.getPosition() << ")" << endl;
    cout << "Клиент: ";
    customer.outputCustomer();
    cout << "Заказанная пластинка: " << orderedRecord.getAlbumName() << " - " << quantityOrdered << " шт." << endl;
    cout << "Общая стоимость заказа: " << totalCost << endl;
    cout << endl;

}

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
    Store(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray) : storeName(name), storeAddress(address) {
        // Инициализация массивов в конструкторе
        for (int i = 0; i < numRecords; ++i) {
            vinylRecordsInStore[i] = vinylRecordsArray[i];
        }

        for (int i = 0; i < numEmployees; ++i) {
            employeesInStore[i] = employeeArray[i];
        }
    }
    // Деструктор
    ~Store() {}

    // Метод для вывода информации о магазине
    void outputStore();
};

// Определение метода для вывода информации о магазине
void Store::outputStore()
{
    cout << "Информация о магазине:" << endl;
    cout << "Название: " << storeName << endl;
    cout << "Адрес: " << storeAddress << endl;
    cout << endl;

    cout << "Информация о виниловых пластинках в магазине:" << endl;
    cout << endl;
    for (int i = 0; i < numRecords; ++i) {
        cout << "Виниловая пластинка #" << i + 1 << ":" << endl;
        vinylRecordsInStore[i].outputVinylRecord();
    }

    cout << "Информация о сотрудниках магазина:" << endl;
    cout << endl;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        employeesInStore[i].outputEmployee();
    }
}

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t~~Программа №2 по реализации АТД на языке C и C++~~" << endl;;
    cout << endl;

    // Объявление переменных для хранения данных о магазине
    string name, address;

    cout << "Введите название магазина: ";
    getline(cin, name);

    cout << "Введите адрес магазина: ";
    getline(cin, address);

    cout << "Введите количество имеющихся виниловых пластинок: ";
    cin >> numRecords;

    cout << endl;

    // Динамический массив объектов класса VinylRecord
    VinylRecord* vinylRecordsArray = new VinylRecord[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        // Объявление переменных для хранения данных о виниловой пластинке
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "Виниловая пластинка #" << i + 1 << endl;
        // Ввод данных о виниловой пластинке
        inputVinylRecord(&album, &artist, &year, &genre, &price, &quantity);

        // Создание объекта и добавление его в массив
        vinylRecordsArray[i] = VinylRecord(album, artist, year, genre, price, quantity);
    }

    cout << "Введите количество сотрудников магазина: ";
    cin >> numEmployees;

    cout << endl;

    // Динамический массив объектов класса Employee
    Employee* employeeArray = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        // Объявление переменных для хранения данных о сотруднике
        string firstName, lastName, position;
        float salary;

        cout << "Сотрудник #" << i + 1 << ":" << endl;
        // Ввод данных о сотруднике
        inputEmployee(&firstName, &lastName, &position, &salary);

        // Создание объекта и добавление его в массив
        employeeArray[i] = Employee(firstName, lastName, position, salary);
    }

    // Создаем магазин
    Store store1(name, address, vinylRecordsArray, employeeArray);

    cout << "----------------------------------------" << endl;
    cout << endl;

    // Выводим информацию о магазине
    store1.outputStore();

    cout << "----------------------------------------" << endl;
    cout << endl;

    cout << "Введите количество заказов: ";
    cin >> numOrders;

    // Создаем массив указателей на объекты Order (массив динамических объектов)
    Order** ordersArray = new Order * [numOrders];

    // Ввод данных для каждого заказа
    for (int i = 0; i < numOrders; ++i) {
        cout << endl << "Заказ #" << i + 1 << ":" << endl;

        // Объявление переменных для хранения данных о заказе
        int orderNumber;
        string orderDate;

        // Ввод номера заказа и даты заказа
        cout << "Введите номер заказа: ";
        cin >> orderNumber;
        cin.ignore();

        cout << "Введите дату заказа: ";
        getline(cin, orderDate);

        // Показываем возможные варианты сотрудников для выбора
        int employeeIndex;
        bool isValidChoice = false;
        
        cout << "Выберите сотрудника, обслуживающего заказ:" << endl;

        for (int i = 0; i < numEmployees; i++) {
            cout << i + 1 << ". " << employeeArray[i].getFirstName() << " " << employeeArray[i].getLastName() << endl;
        }

        do {
            int choice;
            cin >> choice;

            if (choice >= 1 && choice <= numEmployees) {
                employeeIndex = choice - 1;
                isValidChoice = true; // Устанавливаем флаг, если выбор сотрудника корректен
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        } while (!isValidChoice); // Повторяем цикл, пока выбор не станет корректным

        // Объявление переменных для хранения данных о клиенте
        string clientFirstName, clientLastName, clientAddress;
        float clientMoney;

        // Ввод данных о клиенте
        cout << "Введите информацию о клиенте, оформляющем заказ:" << endl;
        inputCustomer(&clientFirstName, &clientLastName, &clientMoney, &clientAddress);

        // Показываем возможные варианты виниловых пластинок для выбора
        int vinylIndex;
        isValidChoice = false;

        cout << "Выберите виниловую пластинку для заказа:" << endl;

        for (int i = 0; i < numRecords; i++) {
            cout << i + 1 << ". " << vinylRecordsArray[i].getAlbumName() << " - " << vinylRecordsArray[i].getArtist() << " (" << vinylRecordsArray[i].getQuantity() << " шт." << ")" << endl;
        }

        do {
            int choice;
            cin >> choice;

            if (choice >= 1 && choice <= numRecords) {
                vinylIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        } while (!isValidChoice);


        // Ввод количества заказанных виниловых пластинок
        int quantityOrdered;
        cout << "Введите количество заказанных виниловых пластинок: ";
        cin >> quantityOrdered;

        // Рассчет общей стоимости заказа
        float totalCost = vinylRecordsArray[vinylIndex].getPrice() * quantityOrdered;

        // Создание объекта заказа и добавление его в массив указателей на заказы
        ordersArray[i] = new Order(orderNumber, orderDate, employeeArray[employeeIndex], Customer(clientFirstName, clientLastName, clientMoney, clientAddress), vinylRecordsArray[vinylIndex], quantityOrdered, totalCost);
    }

    cout << endl;
    cout << "----------------------------------------" << endl;

    // Отображение информации о заказах
    for (int i = 0; i < numOrders; ++i) {
        cout << endl << "Информация о заказе #" << i + 1 << ":" << endl;
        ordersArray[i]->outputOrder();
    }

    cout << "----------------------------------------" << endl;

    // Освобождаем память, выделенную для каждого заказа
    for (int i = 0; i < numOrders; ++i) {
        delete ordersArray[i];
    }

    // Освобождаем память, выделенную для массивов
    delete[] vinylRecordsArray;
    delete[] employeeArray;
    delete[] ordersArray;

    return 0;
}
