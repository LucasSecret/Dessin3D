#include "ppm.h"
#include "Point.h"


#define T 80


void displayPoint(Point point, Ppm& image)
{
	char fileName[] = "res.ppm";
	image.setpixel(point.getXaxis(), point.getYaxis(), point.getColor());
	image.write(fileName);
}

int main()
{
	Ppm im(256, 256);


	Point pt1(0, 0, 0, ROUGE), pt2(T, 0, 0, ROUGE), pt3(T, 0, T, ROUGE), pt4(0, 0, T, ROUGE);
	Point pt5(0, T, T, ROUGE), pt6(0, T, 0, ROUGE), pt7(T, T, 0, ROUGE), pt8(T, T, T, ROUGE);
/*
	Facette fdessous(pt1, pt2, pt3, pt4, BLEU);
	Facette fface(pt8, pt5, pt4, pt3, ROUGE);
	Facette fgauche(pt5, pt6, pt1, pt4, VERT);
	Facette farriere(pt6, pt7, pt2, pt1, JAUNE);
	Facette fdroit(pt7, pt8, pt3, pt2, CYAN);
	Facette fdessus(pt5, pt8, pt7, pt6, ROSE);


	Cube C(fdessous, fface, fgauche, farriere, fdroit, fdessus);

	C.translation(100, 100, 0);
	C.rotation(20., -30., 0.);
	//C.afficherFilDeFer(im);

	C.remplissage(im);

	Cercle cer(10);
	cer.translation(50, 50, 0);
	cer.afficher(im);
*/

	

	return 0;
}