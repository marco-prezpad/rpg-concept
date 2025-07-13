#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

class Movimiento {
 private:
   int x, y; // Coordenadas del personaje
 
 public:
   Movimiento();           // Constructor por defecto
   void mover(char tecla); // Mover según tecla
   int getX() const;       // Obtener coordenada X
   int getY() const;       // Obtener coordenada Y
};

#endif