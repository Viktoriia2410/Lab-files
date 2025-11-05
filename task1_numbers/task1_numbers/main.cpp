#include <windows.h>      // для SetConsoleCP/OutputCP (українська консоль)

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>       // для std::max/std::min (якщо потрібно)
using namespace std;

int main() {
    // Підтримка кирилиці в консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ifstream file("number.txt");
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу number.txt!" << endl;
        return 1;
    }

    double num;
    double sum = 0.0;
    double minVal = numeric_limits<double>::infinity();
    double maxVal = -numeric_limits<double>::infinity();
    int count = 0;

    while (file >> num) {
        sum += num;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
        count++;
    }
    file.close();

    if (count > 0) {
        cout << "📄 Результати обчислення:" << endl;
        cout << "Кількість чисел: " << count << endl;
        cout << "Середнє значення: " << sum / count << endl;
        cout << "Мінімальне: " << minVal << endl;
        cout << "Максимальне: " << maxVal << endl;
    }
    else {
        cout << "Файл порожній або містить некоректні дані." << endl;
    }

    return 0;
}