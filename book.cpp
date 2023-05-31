#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Array {
    int* arr;
    int size;
public:
    explicit Array(int usize = 5) : arr{ new int[usize] }, size{ usize }
    {
        randomize(10, 20);
        cout << "Конструктор с параметром\n";
    }
    ~Array()
    {
        if (arr)
        {
            delete[]arr;
        }
        cout << "Деструктор\n";
    }

    void randomize(int a, int b) //10 20
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = a + rand() % (b - a + 1); //10-29
        }
    }
    void setElem(int ind, int x)
    {
        arr[ind] = x;
    }
    int getElem(int ind) const
    {
        return arr[ind];
    }
    int getSize() const {
        return size;
    }
};

class Book {
    char* autor;
    char* name;

    double marks;

    int year;
    int papers;
public:
    explicit Book(const char* aut, const char* uname, double mark, int paper, int years) {
        autor = new char[strlen(aut) + 1];
        strcpy(autor, aut);

        name = new char[strlen(uname) + 1];
        strcpy(name, uname);

        marks = mark;
        papers = paper;

        year = years;

    }
    void sortMarker(const Book* b, int size, const char* Uauthor) {
        cout << "SortMark:\n";
        char* a;
        a = new char[strlen(Uauthor) + 1];
        strcpy(a, Uauthor);
        for (int i = 0; i < size; i++) {
            strlwr(b[i].autor);

        }
        strlwr(a);
        for (int i = 0; i < size; i++) {
            if (strstr(b[i].autor, a)) {
                cout << "Книга: " << b[i].name << "\n";
            }
        }cout << endl;

        delete[] a;
    }

    void sortRate(const Book* b,int size,double rate = 4) {
        cout << "SortRate:\n";
        for (int i = 0; i < size; i++) {
            if (b[i].marks > rate) {
                cout << "Книга: " << b[i].name << "\n";
            }
        }cout << endl;
    }

    void sortYear(const Book* b, int size, int year) {
        cout << "SortYear:\n";
        for (int i = 0; i < size; i++) {
            if (b[i].year > year) {
                cout << "Книга: " << b[i].name << "\n";
            }
        }cout << endl;
    }

};
void print(const Array& obj)
{
    for (int i = 0; i < obj.getSize(); i++)
    {
        cout << obj.getElem(i) << " ";
    }
    cout << endl;
}
void main() {

    setlocale(0, "");
    srand(time(NULL));

    Book b[5] = { Book{"Михаил Булгаков","Мастер и Маргарита",6.3,32,1928},
                  Book{"Федор Михайлович Достоевский","Преступление и наказание",5.7,574,1866},
                  Book{"Михаил Булгаков","Собачье сердце",9.8,85,1925},
                  Book{"Михаил Лермонтов","Герой нашего времени",6.5,232,1840},
                  Book{"Джон Рональд Руэл Толкин","Властелин колец",8.2,600,1954} 
    };

    b->sortMarker(b, 5, "БуЛгаКов");
    b->sortRate(b, 5);
    b->sortYear(b,5,1920);
}
