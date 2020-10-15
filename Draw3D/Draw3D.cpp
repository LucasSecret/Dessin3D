#include "ppm.h"
#include "Point.h"
#include "Circle.h"
#include "Segment.h"
#include "Face.h"
#include "Cube.h"


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


void makeBeautifullSquaresOnCenterOf(Ppm& image, int centerSquareSize)
{
	SquareFace faceFull(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, RED); //Little Square 1
	SquareFace edges(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, WHITE);
	SquareFace faceFull_1(faceFull);
	SquareFace edges_1(edges);

	faceFull.rotate(0, 0, 22.5); //Rotate
	edges.rotate(0, 0, 22.5);
	faceFull_1.rotate(0, 0, -22.5);
	edges_1.rotate(0, 0, -22.5);

	edges.displayEdgesOn(image); //Display
	faceFull.displayFullFaceOn(image);
	edges_1.displayEdgesOn(image);
	faceFull_1.displayFullFaceOn(image);

	SquareFace faceFull2(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, YELLOW);//Little Square 2
	SquareFace edges2(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, WHITE);

	faceFull2.rotate(0, 0, 45);
	edges2.rotate(0, 0, 45);

	edges2.displayEdgesOn(image);
	faceFull2.displayFullFaceOn(image);

	SquareFace faceFull3(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, GREEN);//Little Square 3
	SquareFace edges3(Point(128 - centerSquareSize / 2, 128 - centerSquareSize / 2, 0), centerSquareSize, WHITE);

	faceFull3.rotate(0, 0, 90);
	edges3.rotate(0, 0, 90);

	edges3.displayEdgesOn(image);
	faceFull3.displayFullFaceOn(image);
}

void make3DCubes(Ppm& image)
{
	int size = 30;
	int angleY = -30;
	int angleX = 20;
	Point pt1(55, 55, 0), pt2(55 + size, 55, 0),  pt3(55 + size, 55 + size, 0), pt4(55, 55 + size, 0);
	Point pt5(55, 55, size), pt6(55+size, 55, size), pt7(55+size, 55 + size, size), pt8(55, 55 + size, size);

	SquareFace backFace(pt5, pt6, pt7, pt8, PINK);
	SquareFace downFace(pt4, pt8, pt7, pt3, CYAN);
	SquareFace rightFace(pt2, pt6, pt7, pt3, GREEN);
	SquareFace leftFace(pt1, pt5, pt8, pt4, BLUE);
	SquareFace topFace(pt1, pt2, pt6, pt5, GREEN);
	SquareFace frontFace(pt1, pt2, pt3, pt4, YELLOW);

	Cube cube(frontFace, downFace, backFace, leftFace, rightFace, topFace);
	cube.rotate(angleX, angleY, 0);
	cube.translate(0, 0, 0);
	cube.displayFullOn(image);


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
	//Cross
	/*
	Segment segment(Point(128, 64), Point(128, 192), BLUE);
	Segment segment2(Point(64, 128), Point(192, 128), BLUE);

	segment.displayOn(image);
	segment2.displayOn(image);
	


	vector<Segment> segments; //Big Edge Square Segments
	segments.push_back(Segment(Point(64, 64), Point(192, 64), YELLOW));
	segments.push_back(Segment(Point(192, 64), Point(192, 192), YELLOW));
	segments.push_back(Segment(Point(192, 192), Point(64, 192), YELLOW));
	segments.push_back(Segment(Point(64, 192), Point(64, 64), YELLOW));

	SquareFace face(segments, YELLOW); //Big Edge Square 
	face.displayEdgesOn(image);
	segments.clear();
	*/
	Circle circle(128, 128, 0, 64, GREEN); //Big Circle
	circle.displayOn(image);

	//makeBeautifullSquaresOnCenterOf(image, 30);
	make3DCubes(image);
	createImage(image);

	return 0;
}