#include <iostream>
#include <string>
#include <windows.h> // для підтримки українських символів у консолі
using namespace std;

// Структура оцінки
struct Grades {
    int algebra;
    int geometry;
    int informatics;
};

// Структура студент
struct Student {
    string name;
    int curs;
    Grades grades;
};

// Функція для введення даних студента
Student InputStudentData() {
    Student student;
    cout << "Введіть ім'я студента: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Введіть курс: ";
    cin >> student.curs;

    cout << "Введіть оцінку з алгебри: ";
    cin >> student.grades.algebra;

    cout << "Введіть оцінку з геометрії: ";
    cin >> student.grades.geometry;

    cout << "Введіть оцінку з інформатики: ";
    cin >> student.grades.informatics;

    return student;
}

// Функція для виведення студентів з оцінками від 75 до 100
void PrintGrades(Student students[], int n) {
    cout << "\nСписок студентів з оцінками від 75 до 100:\n";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if ((students[i].grades.algebra >= 75 && students[i].grades.algebra <= 100) &&
            (students[i].grades.geometry >= 75 && students[i].grades.geometry <= 100) &&
            (students[i].grades.informatics >= 75 && students[i].grades.informatics <= 100)) {
            cout << students[i].name << " (курс " << students[i].curs << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентів, що відповідають умові.\n";
    }
}

int main() {
    // Додаємо підтримку українських літер у консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;
    cin.ignore();

    Student students[100];

    for (int i = 0; i < n; i++) {
        cout << "\nСтудент #" << i + 1 << ":\n";
        students[i] = InputStudentData();
    }

    PrintGrades(students, n);

    return 0;
}