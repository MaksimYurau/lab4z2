#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream input_file("E:\input.txt");
    std::ofstream output_file("E:\output.txt");

    // Подготовка входного файла
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < 100; ++i) {
        int number = std::rand() % 101 - 50;
        input_file << number << std::endl;
    }

    input_file.close();

    // Чтение входного файла, преобразование и запись выходного файла
    std::ifstream input("E:\input.txt");
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

    std::ofstream output("E:\output.txt");

    for (int number : numbers) {
        if (number % 2 == 0) {
            output << number * first_negative << std::endl;
        }
    }

    output.close();

    return 0;
}
