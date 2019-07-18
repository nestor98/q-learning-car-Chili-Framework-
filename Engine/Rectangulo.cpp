#include "Rectangulo.h"

Rectangulo::Rectangulo(Graphics& gfx, Grid& grid, const int x, const int y, const int tamx_, const int tamy_, const int r_, const int g_, const int b_) 
	: 
	Forma(x, y, gfx, grid, r_, g_, b_), tamx(tamx_), tamy(tamy_) {}


Rectangulo::Rectangulo(const int x1, const int y1, const int x2, const int y2, Graphics& gfx, Grid& grid, const int r_, const int g_, const int b_)
	: Rectangulo(gfx, grid, (x1+x2)/2, (y1+y2)/2, abs(x1-x2), abs(y1-y2), r_, g_, b_) 
{} 

bool Rectangulo::colision(const Forma& otra) const
{
	return false;
}

void Rectangulo::dibujar() const {
	m_gfx.dibujarRect(pos.x(), pos.y(), tamx, tamy, r, g, b);
}

void Rectangulo::mis_cuadrantes(std::vector<int>& cuads) const
{
	int tamxmed = tamx / 2;
	int tamymed = tamy / 2;
	Punto arribaIzq(pos.x() - tamxmed, pos.y() - tamymed);
	Punto abajoDer(pos.x() + tamxmed, pos.y() + tamymed);
	int cuad1 = m_grid.cuadranteDePos(arribaIzq);
	int cuad2 = m_grid.cuadranteDePos(abajoDer);
    arribaIzq.asignar(m_grid.coordenadas(cuad1));
	for (int i = cuad1; i < cuad2; i++) {
		cuads.push_back(i);
		//Saltar cuando este fuera del rectangulo
		/*   .  .  .  .  .  
			 .  x  .  .  . 
			 .  .  .  .  .
			 .  .  .  x  .
			 .  .  .  .  .
		*/
	}

}
