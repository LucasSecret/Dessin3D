///////////////////////////////////////////////////////////
//   header inclus dans tous les fichiers sources//
///////////////////////////////////////////////////////////

#pragma once
#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

////////////////////////////////////
//Redefinition des types d'entiers//
////////////////////////////////////
typedef unsigned char BYTE;
typedef unsigned long ULONG;
typedef unsigned short USHORT;
typedef long LONG;
typedef short SHORT;
typedef char CHAR;





//////////////////////////////////////////////////////////////////
//              Definition de la classe Ppm                     //
//Represente un fichier image au format Ppm (Portable Pixel Map)//
//////////////////////////////////////////////////////////////////
class Ppm
{
public:
	SHORT width;		//largeur
	SHORT height;		//hauteur
	LONG length;		//nombre d'octets de 'pixel' (3*largeur*hauteur)
	ULONG level;		//niveau de R,G,B maximal (255)
	BYTE* pixel;		//tableau des pixels

	Ppm(ULONG, ULONG);
	~Ppm(void);
	void write(CHAR*);

	//affecte la couleur 'color' au pixel de coordonnees (I,J)
	void setpixel(SHORT J, SHORT I, ULONG color)
	{
		//cout << "I:" << I << "     J:" << J << endl;
		assert((I >= 0) && (I < height) && (J >= 0) && (J < width));

		LONG ind = 3 * (I * width + J);
		pixel[ind++] = 255 & (color >> 16);	//R
		pixel[ind++] = 255 & (color >> 8);	//G
		pixel[ind] = 255 & color;			//B
		return;
	};

	//retourne la couleur 'color' du pixel de coordonnees (I,J)
	ULONG getpixel(SHORT I, SHORT J)
	{
		ULONG couleur;
		BYTE R, G, B;
		assert((I >= 0) && (I < height) && (J >= 0) && (J < width));

		LONG ind = 3 * (I * width + J);

		R = pixel[ind++];	//R
		G = pixel[ind++];	//G
		B = pixel[ind];		//B

		couleur = 0;
		couleur = couleur | (R << 16);
		couleur = couleur | (G << 8);
		couleur = couleur | B;

		return couleur;
	};

	SHORT getWidth();
	SHORT getHeight();


	//trace une ligne à partir de deux points
	void line(SHORT, SHORT, SHORT, SHORT, ULONG color);

};





