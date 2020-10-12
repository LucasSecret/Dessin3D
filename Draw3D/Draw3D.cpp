#include "ppm.h"
#include "Point.h"
#include "Circle.h"
#include "Segment.h"
#include "Face.h"

#define T 80


void addPointToImage(Point point, Ppm& image)
{
	image.setpixel(point.getXaxis(), point.getYaxis(), point.getColor());
}

void addShapeOnImage(vector<Point> pointList, Ppm& image)
{
	for (int i = 0; i < pointList.size(); i++)
		addPointToImage(pointList[i], image);
}

void createImage(Ppm& image)
{
	char fileName[] = "res.ppm";
	image.write(fileName);

	cout << "Computed.";
}

int main()
{
	Ppm image(256, 256);

	/*
	Point pt1(0, 0, 0, ROUGE), pt2(T, 0, 0, ROUGE), pt3(T, 0, T, ROUGE), pt4(0, 0, T, ROUGE);
	Point pt5(0, T, T, ROUGE), pt6(0, T, 0, ROUGE), pt7(T, T, 0, ROUGE), pt8(T, T, T, ROUGE);

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

	cer.afficher(im);
*/

	Segment segment(Point(128, 64), Point(128, 192), BLUE);
	Segment segment2(Point(64, 128), Point(192, 128), BLUE);

	segment.displayOn(image);
	segment2.displayOn(image);

	vector<Segment> segments;
	segments.push_back(Segment(Point(64, 64), Point(192, 64), YELLOW));
	segments.push_back(Segment(Point(192, 64), Point(192, 192), YELLOW));
	segments.push_back(Segment(Point(192, 192), Point(64, 192), YELLOW));
	segments.push_back(Segment(Point(64, 192), Point(64, 64), YELLOW));

	SquareFace face(segments, YELLOW);
	face.displayEdgesOn(image);

	Circle circle(128, 128, 0, 64, GREEN);
	addShapeOnImage(circle.getPoints(), image);


	segments.clear();

	SquareFace faceFull(Point(150, 32, 0), 20, RED);
	SquareFace edges(Point(150, 32, 0), 20, WHITE);

	faceFull.rotate(0, 0, 45);
	edges.rotate(0, 0, 45);

	edges.displayEdgesOn(image);
	faceFull.displayFullFaceOn(image);
	

	
	createImage(image);



	return 0;
}