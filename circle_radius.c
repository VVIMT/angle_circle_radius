#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265

double	circle_radius(double X1, double X2, double X3, double Y1, double Y2, double Y3);
int		angle(double X1, double X2, double X3, double Y1, double Y2, double Y3);

int		main()
{
	double X1 = 5;
	double X2 = -1;
	double X3 = 4;
	double Y1 = -2;
	double Y2 = 2;
	double Y3 = 3;
	double ang = angle(X1, X2, X3, Y1, Y2, Y3);

	if (ang >= 90 && ang != 180)
		circle_radius(X1, X2, X3, Y1, Y2, Y3);
	return (0);
}

int		angle(double X1, double X2, double X3, double Y1, double Y2, double Y3)
{
	double a;
	double b;
	double c;

	a = sqrt(pow(X3 - X2, 2) + pow(Y3 - Y2, 2));
	b = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
	c = sqrt(pow(X3 - X1, 2) + pow(Y3 - Y1, 2));
	printf("%f\n", acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b))/PI * 180);
	return (acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b))/PI * 180);
}

double	circle_radius(double X1, double X2, double X3, double Y1, double Y2, double Y3)
{
	double Xc = 0;
	double Yc = 0;
	double Rc = 0;

	if ((X1 == X2 && Y1 == Y2)
	|| (X1 == X3 && Y1 == Y3)
	|| (X2 == X3 && Y2 == Y3))
	{
		write(2, "Input error\n", 12);
		return (0);
	}
	if (Y2-Y1 != 0 && Y3-Y2 != 0 && ((X3-X2)/(Y3-Y2)-(X2-X1)/(Y2-Y1)) != 0)
	{
		Xc = (pow(X3, 2)-pow(X2, 2)+pow(Y3, 2)-pow(Y2, 2))/(2*(Y3-Y2));
		Xc = Xc-((pow(X2, 2)-pow(X1, 2)+pow(Y2, 2)-pow(Y1, 2))/(2*(Y2-Y1)));
		Xc = Xc/((X3-X2)/(Y3-Y2)-(X2-X1)/(Y2-Y1));
	}
	if (Y3-Y2 == 0)
		Xc = (X3+X2)/2;
	else if (Y2-Y1 == 0)
		Xc = (X2+X1)/2;
	if (Y2-Y1 != 0)
		Yc = -(X2-X1)/(Y2-Y1)*Xc+(pow(X2, 2)-pow(X1, 2)+pow(Y2, 2)-pow(Y1, 2))/(2*(Y2-Y1));
	else
		Yc = -(X2-X1)/(Y3-Y2)*Xc+(pow(X2, 2)-pow(X1, 2)+pow(Y3, 2)-pow(Y2, 2))/(2*(Y3-Y2));
	Rc = sqrt(pow(X1-Xc, 2)+pow(Y1-Yc, 2));
	printf("Xc = %f Yc = %f and Rc = %f\n", Xc, Yc, Rc);
	return (Rc);
}
