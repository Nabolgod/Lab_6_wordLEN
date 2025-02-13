#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Вводим строку, которую будем обрабатывать
    string line;
    cout << "Введите строку для обработки: ";
    getline(cin, line);

    // Вводим разделитель между словами в нашей строке
    string sep;
    cout << "Введите разделитель строки: ";
    getline(cin, sep);

    // Проверка на пустую строку 
    if (!line.empty()) {

        // Задаём начальную и конечную позицию нашего первого слова.
        int start = 0;
        int end = line.find(sep);

        // Создаём пустую строку, в которую будем добавлять слова с из длиной
        string new_line = "";

        // Задаём цикл, в котором будем обходить все слова
        while (start != -1) {

            // Добавляем в new_line строку + длина строки
            string word = line.substr(start, end - start); // сохраняем наше слово до разделителя
            if (!word.empty()) // проверка на то, что слово не "пустое"
                new_line += word + to_string(word.length()); // добавляем в new_line слово+длина

            // Добавляем разделитель между словами, если он существует
            if (end != -1) {
                new_line += sep;
            }

            // Обновляем начальную и конечную позицию слова
            start = (end == -1) ? end : end + sep.length();
            end = line.find(sep, start);
        }

        // Выводим на экран обновлённую строку
        cout << endl << "Новая строка: " << new_line << endl;
    }
    else
        cout << endl << "Строка не содержит слов и не может быть обработана" << endl;

    return 0;
}
