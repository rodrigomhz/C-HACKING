# Lectura de Memoria de un Proceso Externo

## Descripción

Este proyecto tiene como objetivo explicar cómo realizar la lectura de memoria de un proceso externo con fines de hacking utilizando C++. El ejemplo práctico está basado en el juego **Counter Strike 1.6**, y el enfoque se realiza sobre un sistema de 32 bits en lugar de 64 bits, lo cual es esencial para trabajar con procesos de esta índole.

## Requisitos

- **Sistema operativo**: Windows
- **Lenguaje**: C++
- **Librerías necesarias**:
  - `Windows.h` - Para interactuar con las funciones de la API de Windows.
  - `iostream` - Para entrada y salida estándar.
  - `conio.h` - Para usar la función `getch()`.
  - `string` - Para manipulación de cadenas de texto.

## Conceptos Clave

### 1. **Obtención del PID**
Para leer la memoria de un proceso, primero necesitamos obtener su identificador de proceso (PID). En este ejemplo, utilizamos el juego **Counter Strike 1.6** y lo ponemos en ventana para obtener el nombre de la ventana, lo cual nos permite obtener el PID.

### 2. **Comandos utilizados**
- **FindWindow**: Para encontrar la ventana del proceso utilizando su nombre.
- **GetWindowThreadProcessId**: Para obtener el PID del proceso asociado a la ventana encontrada.
  
### 3. **Apertura del Proceso**
Una vez obtenido el PID, se abre el proceso con la función **OpenProcess**, donde asignamos los privilegios necesarios para poder leer y escribir en la memoria del proceso.

### 4. **Lectura de Memoria**
La función clave para la lectura de la memoria es **ReadProcessMemory**, que nos permite acceder al contenido de la memoria de un proceso dado su PID y una dirección de memoria específica. En este caso, se lee una dirección de memoria dinámica que contiene el nombre del jugador dentro del juego.

