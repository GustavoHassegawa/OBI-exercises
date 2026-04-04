#include <iostream>

using namespace std;

int main(int argv, char* argc[]) {
    int idade_monica, idade_filho_1, idade_filho_2, idade_filho_3, idade_mais_velho;

    cin >> idade_monica;
    cin >> idade_filho_1;
    cin >> idade_filho_2;

    if (idade_filho_1 > idade_filho_2)
        idade_mais_velho = idade_filho_1;
    else
        idade_mais_velho = idade_filho_2;

    idade_filho_3 = idade_monica - idade_filho_1 - idade_filho_2;

    if (idade_filho_3 > idade_mais_velho)
        idade_mais_velho = idade_filho_3;

    cout << idade_mais_velho;
    
    return 0;
} 