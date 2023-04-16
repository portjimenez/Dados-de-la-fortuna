#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para dibujar un dado con el número de puntos especificado
void dibujar_dado(int puntos) {
    cout << "+-----+" << endl;
    cout << "|     |" << endl;
    cout << "|  ";

    // Dibuja los puntos del dado
    switch (puntos) {
        case 1:
            cout << "o";
            break;
        case 2:
            cout << "o  o";
            break;
        case 3:
            cout << "o o o";
            break;
        case 4:
            cout << "o o";
            cout << endl << "|  ";
            cout << "o o";
            break;
        case 5:
            cout << "o o";
            cout << endl << "|  o";
            cout << endl << "|  ";
            cout << "o o";
            break;
        case 6:
            cout << "o o";
            cout << endl << "|  o o";
            cout << endl << "|  o o";
            break;
    }

    cout << endl << "|     |" << endl;
    cout << "+-----+" << endl;
}

int main() {
    srand(time(NULL)); // Semilla aleatoria para la función rand()

    int dado1, dado2, suma, punto;
    bool juego_terminado = false;

    dado1 = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6 para el primer dado
    dado2 = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6 para el segundo dado
    suma = dado1 + dado2;

    cout << "Los dados han sido lanzados. La suma es " << suma << endl;
    dibujar_dado(dado1);
    dibujar_dado(dado2);

    // Determina el resultado del primer tiro
    if (suma == 7 || suma == 11) {
        cout << "¡Felicidades! Has ganado en el primer tiro." << endl;
        juego_terminado = true;
    }
    else if (suma == 2 || suma == 3 || suma == 12) {
        cout << "Lo siento, has perdido en el primer tiro." << endl;
        juego_terminado = true;
    }
    else {
        punto = suma;
        cout << "El punto es " << punto << endl;
    }

    // Continúa el juego si es necesario
    while (!juego_terminado) {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        suma = dado1 + dado2;

        cout << "Los dados han sido lanzados. La suma es " << suma << endl;
        dibujar_dado(dado1);
        dibujar_dado(dado2);

        if (suma == punto) {
            cout << "¡Felicidades! Has ganado al llegar a tu punto." << endl;
            juego_terminado = true;
        }
        else if (suma == 7) {
            cout << "Lo siento, has perdido al lanzar un 7 antes de llegar a tu punto." << endl;
            juego_terminado = true;
        }
    }

    return 0;
}

