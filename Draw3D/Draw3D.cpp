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

	Segment segment(Point(100, 50), Point(100, 150), BLUE);
	Segment segment2(Point(50, 100), Point(150, 100), BLUE);

	segment.displayOn(image);
	segment2.displayOn(image);

	vector<Segment> segments;
	segments.push_back(Segment(Point(50, 50), Point(150, 50), YELLOW));
	segments.push_back(Segment(Point(150, 50), Point(150, 150), YELLOW));
	segments.push_back(Segment(Point(150, 150), Point(50, 150), YELLOW));
	segments.push_back(Segment(Point(50, 150), Point(50, 50), YELLOW));

	SquareFace face(segments);
	face.displayEdgesOn(image);

	Circle circle(100, 100, 0, 50, GREEN);
	addShapeOnImage(circle.getPoints(), image);


	segments.clear();
	segments.push_back(Segment(Point(10, 10), Point(50, 10), YELLOW));
	segments.push_back(Segment(Point(50, 10), Point(50, 50), YELLOW));
	segments.push_back(Segment(Point(50, 50), Point(10, 50), YELLOW));
	segments.push_back(Segment(Point(10, 50), Point(10, 10), YELLOW));

	SquareFace faceFull(segments, RED);
	faceFull.displayFullFaceOn(image);

	
	createImage(image);



	return 0;
}