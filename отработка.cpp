#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // ������ ������, ������� ����� ������������
    string line;
    cout << "������� ������ ��� ���������: ";
    getline(cin, line);

    // ������ ����������� ����� ������� � ����� ������
    string sep;
    cout << "������� ����������� ������: ";
    getline(cin, sep);

    // �������� �� ������ ������ 
    if (!line.empty()) {

        // ����� ��������� � �������� ������� ������ ������� �����.
        int start = 0;
        int end = line.find(sep);

        // ������ ������ ������, � ������� ����� ��������� ����� � �� ������
        string new_line = "";

        // ����� ����, � ������� ����� �������� ��� �����
        while (start != -1) {

            // ��������� � new_line ������ + ����� ������
            string word = line.substr(start, end - start); // ��������� ���� ����� �� �����������
            new_line += word + to_string(word.length()); // ��������� � new_line �����+�����

            // ��������� ����������� ����� �������, ���� �� ����������
            if (end != -1) {
                new_line += sep;
            }

            // ��������� ��������� � �������� ������� �����
            start = (end == -1) ? end : end + sep.length();
            end = line.find(sep, start);
        }

        // ������� �� ����� ���������� ������
        cout << endl << "����� ������: " << new_line << endl;
    }
    else
        cout << endl << "������ �� �������� ���� � �� ����� ���� ����������" << endl;

    return 0;
}