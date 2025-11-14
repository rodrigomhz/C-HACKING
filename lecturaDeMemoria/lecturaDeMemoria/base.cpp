#include <Windows.h> //Encabezado necesario para usar las funciones de la API de Windows
#include <iostream> //Encabezado necesario para usar las funciones de entrada y salida
#include <conio.h> //Encabezado necesario para usar la función getch() (dicha función permite capturar una tecla sin necesidad de presionar Enter)
#include <string> //Encabezado necesario para usar la clase string

uintptr_t NICK = 0x051433F7; //Variable asiciada a nuestra dirección de memoria

using namespace std;

HWND hwnd; //variable de tipo ventana
DWORD pid; //Donde guardaremos el PID
HANDLE hp; // Es el control del proceso, es basicamente el alma del programa

int main() {
	//Encontrar nombre de la ventana
	hwnd = FindWindow(0, L"Counter-Strike"); // Debemos de poner la F, para que acepte caracteres UNICODE o WHITE CHAR
	//Obtener el PID
	GetWindowThreadProcessId(hwnd, &pid); //El & debido a que se asignará el PID automaticamente, por lo que debemos escribir dentro de la variable
	cout << "El PID del proceso es: " << pid << endl;

	hp = OpenProcess(PROCESS_ALL_ACCESS, true, pid);// Privilegios, Real o No, ID

	char buffer_txt[256]; //Lugar donde almacenaremos el contenido de la dirección de memoria

	ReadProcessMemory(hp, (LPBYTE)(NICK), &buffer_txt, sizeof(buffer_txt), 0); // Esta función lo que hace es leer el proceso.
	cout << "Mi nombre es: " << buffer_txt << endl;
}