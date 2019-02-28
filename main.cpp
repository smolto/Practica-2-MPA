#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Insercion(int *, int);

int main(){
    int ticks;
    int n = 0;
    int *v;
    int semilla, ini, fin, centinela;

    cout << "Semilla para generar aleatorios: ";
    cin >> semilla;
    cout << "Introduce tamanyo del vector: ";
    cin >> n;
    cout << "Posiciones INICIAL y FINAL del vector para mostrar\n";
    cout << "INICIAL: ";
    cin >> ini;
    cout << "FINAL: ";
    cin >> fin;
    cout << "Mostrar tiempo de ejecucion (1:Si, 0:No): ";
    cin >> centinela;

    srand(semilla);
    v = new int [n+1];

    for (int i = 1; i <= n; i++){
        v[i] = rand()%n;
    }

    cout << "ALGORITMO DE INSERCION\n";
    cout << "CASO CUALQUIERA\n";
    cout << "---------------\n";
    cout << "Vector a ordenar: ";
    for (int i = ini;i <= fin; i++){
        cout << v[i] << " ";
    }
    if (centinela == 1)
        ticks = clock();
    Insercion(v,n);
    cout << "\nVector ordenado: ";
    for (int i = ini;i <= fin; i++){
        cout << v[i] << " ";
    }
    if(centinela == 1){
        cout << " \nTiempo (ms): " << ticks / CLOCKS_PER_SEC;
    }
    return 0;
}

void Insercion(int *v, int n){
    int i,j,x;

    for(i = 2;i <= n; i++){
        x = v[i];
        j = i - 1;
        while(j > 0 && v[j] > x){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j+1] = x;
    }
}
