#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    // Українська мова в консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS];

    ifstream file("matrix.txt");

    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл matrix.txt!" << endl;
        return 1;
    }

    cout << "Матриця з файлу:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            file >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    file.close();

    cout << "\nРезультати обчислень:" << endl;
    int totalSum = 0;

    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += matrix[i][j];
        }
        totalSum += rowSum;
        cout << "Сума рядка " << i + 1 << ": " << rowSum << endl;
    }

    cout << "Загальна сума елементів матриці: " << totalSum << endl;

    return 0;
}