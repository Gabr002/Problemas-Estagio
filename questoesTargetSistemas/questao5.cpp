#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "Exemplo de string";
    int length = str.length();

    // Inverte os caracteres da string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    // Imprime a string invertida
    cout << "String invertida: " << str << endl;

    return 0;
}