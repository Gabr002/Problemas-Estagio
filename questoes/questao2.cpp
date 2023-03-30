#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, numPertencente;
    
    cout << "Digite um numero maximo para a sequencia: ";
    cin >> num; // Total de numeros para a sequencia de fibonacci
    
    cout << "Número que será testado se pertence ou não a seqFibonacci: ";
    cin >> numPertencente; // Número que será testado se pertence ou não a seqFibonacci.
    
    int vetFib[num]; // Declarei o vetor da seq. fibonacci
    
    vetFib[0] = 0; // 1° posicao recebe 0.
    vetFib[1] = 1; // 2° posicao recebe 1.
    
    int somaAntecessores;
    
    vetFib[2] = 1; // 3° posicao recebe a soma dos numeros antecessores.
    
    for(int i = 2; i <= num; i++){ 
        
        somaAntecessores = vetFib[i-1] + vetFib[i]; // Variavel guarda a somaAntecessores
        vetFib[i+1] = somaAntecessores; // Valor atribuida a proxima pos.
        
    }
    
    cout << endl;
    
    for(int i = 0; i < num; i++){
        
        if(vetFib[i] == numPertencente){
            std::cout << "O numero " << numPertencente << " pertence a sequencia de fibonacci e ele está na posicao " << i+1 << '.' << std::endl;
            break;
        }
        else if(i == num-1){
            std::cout << "O numero " << numPertencente << " não pertence a sequencia de fibonacci!" << endl;
        }
    }
    
    return  0;
}
