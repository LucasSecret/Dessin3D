
#include "ppm.h"





////////////////////////////////////////////////
//diff(a,b): retourne la distance entre a et b//
////////////////////////////////////////////////
inline SHORT diff(SHORT a, SHORT b)
{
	return a > b ? a - b : b - a;
}



//////////////////////////////////////////////////////////////////
//Ppm(w,h): constructeur affectant la memoire pour une image w*h//
//////////////////////////////////////////////////////////////////
Ppm::Ppm(ULONG w, ULONG h)
{
	width = w;
	height = h;
	length = 3 * w * h;
	level = 255;
	pixel = new BYTE[length];
	for (LONG i = 0; i < length; i++)
		pixel[i] = 0;
}



////////////////////////////////////////////////////////////////
//destructeur de Ppm: libere la memoire occupee par les pixels//
////////////////////////////////////////////////////////////////
Ppm::~Ppm(void)
{
	if (pixel)
		delete[] pixel;
}


/////////////////////////////////////////////////////////////////////
//write(nom): ecrit les donnees dans le fichier 'nom' (Ppm binaire)//
/////////////////////////////////////////////////////////////////////
void Ppm::write(CHAR* nom)
{
	ofstream out(nom, ios::binary);

	//tester si le fichier est ouvert
	out.seekp(0, ios::end);
	if (out.tellp() < 0)
	{
		out.close();
		throw("erreur d'ouverture de fichier");
	}

	//ecriture de l'en-tête
	out << "P6\n" << width << " " << height << "\n" << level << "\n";

	//ecriture des valeurs des pixels
	out.write((char*)pixel, length);
	out.close();

	return;
}


///////////////////////////////////////////////////////////////////////////
//line(I1,J1,I2,J2): trace le segment entre les points (I1,J1) et (I2,J2)//
//           la methode utilisee est l'algorithme de Bresenham           //
///////////////////////////////////////////////////////////////////////////
void Ppm::line(SHORT I1, SHORT J1, SHORT I2, SHORT J2, ULONG color)
{
	SHORT dI, dJ, incrI, incrJ, currentI, currentJ, dPi, dPj, dPij, P;




	dI = diff(I1, I2);
	dJ = diff(J1, J2);
	currentI = I1;
	currentJ = J1;
	incrI = (I2 > I1 ? 1 : -1);
	incrJ = (J2 > J1 ? 1 : -1);

	if (dJ >= dI)	//|tan(theta)|<=1
	{
		dPj = dI << 1;
		dPij = dPj - (dJ << 1);
		P = dPj - dJ;

		for (; dJ >= 0; dJ--)
		{
			setpixel(currentI, currentJ, color);
			if (P > 0)
			{
				currentI += incrI;
				currentJ += incrJ;
				P += dPij;
			}
			else
			{
				currentJ += incrJ;
				P += dPj;
			}
		}
	}
	else		//|tan(theta)|>1
	{
		dPi = dJ << 1;
		dPij = dPi - (dI << 1);
		P = dPi - dI;

		for (; dI >= 0; dI--)
		{
			setpixel(currentI, currentJ, color);
			if (P > 0)
			{
				currentJ += incrJ;
				currentI += incrI;
				P += dPij;
			}
			else
			{
				currentI += incrI;
				P += dPi;
			}
		}
	}

	return;
}


