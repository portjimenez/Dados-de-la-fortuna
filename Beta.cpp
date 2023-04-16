#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int dibujar_dado(int valord){
    int valor = valord;
    if (valor == 1) {
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        return valor;
    } else if (valor == 2) {
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|       |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        return valor;
    } else if (valor == 3) {
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|   *   |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+" << endl;
        return valor;
    } else if (valor == 4) {
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        return valor;
    } else if (valor == 5) {
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        return valor;
    } else if(valor == 6){
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        return valor;
    }
}

int lanzar_dado() {
    int valor = rand() % 6 + 1;
    return valor;
}

int animacion(int &dado1, int &dado2) {
	//funcion para medir el tiempo
    auto start_time = chrono::steady_clock::now();// guardamos el tiempo actual
    const int duration_in_seconds = 10; //duracion de la animacion de los dados de 10seg
    
    srand(time(NULL));
    
    while (true) {
    	system("cls");
        dado1 = lanzar_dado();
        dado2 = lanzar_dado();
        
        dibujar_dado(dado1);
        dibujar_dado(dado2);
        
        //Tiempo que muestra cada lado del dado
        this_thread::sleep_for(chrono::milliseconds(10));
        
        auto current_time = chrono::steady_clock::now();// funcion para obtener el tiempo actual
        auto elapsed_time = chrono::duration_cast<chrono::seconds>(current_time - start_time); //funcion para calcular en tiempo transcurrido
        
        if (elapsed_time.count() >= duration_in_seconds) {//condicion para evaluer el tiempo deseado con el tiempo transcurrido
            break;
        }
    }
}

int main() {
    cout << "Bienvenido al juego de los dados!" << endl;
    srand(time(NULL));
    bool jugar_nuevamente = true;
    while (jugar_nuevamente) {
        int dado1, dado2;
        cout << "Presiona Enter para lanzar los dados...";
        cin.ignore();
        //consume los valores que los dados nos dan
        animacion(dado1, dado2);
        cout << "El primer dado es: " << dado1 << endl;
        cout << "El segundo dado es: " << dado2 << endl;
        //suma de las cantidades que los dados imprime en pantalla
        cout << "La suma de los dados es: " << dado1 + dado2 << endl;
        cout << "Quieres jugar de nuevo... (s/n) ";
        char respuesta;
        cin >> respuesta;
        jugar_nuevamente = (respuesta == 's' || respuesta == 'S');
    }
    return 0;
}
