/*
Лабораторная работа №4.
Потоки ввода-вывода.
Задание 2.
Следующее задание требуется решить с привлечением текстовых
файлов. Нужно написать функцию, с помощью которой подготовить входной
файл, записав в него 100 случайных целых чисел в диапазоне от -50 до +50 по
одному на строке. Сформировать выходной файл, преобразовав числа входного
файла. 
9. Записать выходной файл, умножить каждое четное число на первое
отрицательное число файла.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(0, "Ru");

    std::string input_filename, output_filename;

    std::cout << "Введите путь к входному файлу (например, input.txt): ";
    std::cin >> input_filename;

    std::cout << "Введите путь к выходному файлу (например, output.txt): ";
    std::cin >> output_filename;

    // std::ofstream input_file("E:\input.txt");
    std::ofstream input_file(input_filename);

    // std::ofstream output_file("E:\output.txt");
    // std::ofstream output_file(output_filename);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < 100; ++i) {
        int number = std::rand() % 101 - 50;
        input_file << number << std::endl;
    }

    input_file.close();

    std::ifstream input(input_filename);
    std::vector<int> numbers;
    int first_negative = 0;

    while (!input.eof()) {
        int number;
        input >> number;
        numbers.push_back(number);

        if (number < 0 && first_negative == 0) {
            first_negative = number;
        }
    }

    input.close();

    std::ofstream output(output_filename);

    for (int number : numbers) {
        if (number % 2 == 0) {
            output << number * first_negative << std::endl;
        }
    }

    output.close();

    std::cout << std::endl;
    std::cout << "Исходный файл. " << output_filename << std::endl;
    std::cout << "Преобразование завершено. Результат записан в " << output_filename << std::endl << std::endl;

    system("pause");
    return 0;
}
