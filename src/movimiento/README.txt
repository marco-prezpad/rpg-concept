Movimiento de Personaje con WASD(SFML)
----------------------------------------------

Implementa un sistema simple de movimiento para un personaje usando W, A, S y D. 

CONTROLES:
- W: Mover arriba
- S: Mover abajo
- A: Mover a la izquierda
- D: Mover a la derecha

ARCHIVOS DEL PROYECTO:
- main.cc         -> Contiene el bucle principal del juego y la ventana
- movimiento.h     -> Declaración de la clase del personaje
- movimiento.cc    -> Lógica del movimiento y dibujo del personaje

REQUISITOS:
- Compilador de C++ (como g++)
- SFML instalado en el sistema:
    -Linux: 
        ·sudo apt install libsfml-dev
    -Windows(En Visual Studio):
	·Descargar los archivos de https://www.sfml-dev.org/download.php.
	·Incluir los headers y enlazar las bibliotecas (.lib o .a).
	·Copiar los .dll en la misma carpeta del .exe.

COMPILACIÓN:
g++ main.cc personaje.cc -o movimiento -lsfml-graphics -lsfml-window -lsfml-system

CÓMO EJECUTAR:
-Linux:
    ./movimiento
-Windows:   
    movimiento.exe

DESCRIPCIÓN:
Este código es una prueba que sirve como base para el movimiento del personaje.
Se crea una ventana de 800x600 píxeles.
En ella se dibuja un cuadrado verde que representa al personaje.
Mientras se mantengan pulsadas las teclas WASD, el personaje se moverá en la dirección correspondiente.
