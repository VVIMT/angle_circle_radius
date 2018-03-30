#!/usr/bin/python
# -*-coding:utf-8 -*

import	math

def		angle(X1, X2, X3, Y1, Y2, Y3):
	a = 0
	b = 0
	c = 0

	a = math.sqrt(pow(X3 - X2, 2) + pow(Y3 - Y2, 2))
	b = math.sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2))
	c = math.sqrt(pow(X3 - X1, 2) + pow(Y3 - Y1, 2))
	return (math.acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b))/math.pi * 180)

def		circle_radius(X1, X2, X3, Y1, Y2, Y3):
	Xc = 0
	Yc = 0
	Rc = 0

	if ((X1 == X2 and Y1 == Y2) or (X1 == X3 and Y1 == Y3) or (X2 == X3 and Y2 == Y3)):
		write(2, "Input error\n", 12);
		return (0)
	if (Y2-Y1 != 0 and Y3-Y2 != 0 and ((X3-X2)/(Y3-Y2)-(X2-X1)/(Y2-Y1)) != 0):
		Xc = (pow(X3, 2)-pow(X2, 2)+pow(Y3, 2)-pow(Y2, 2))/(2*(Y3-Y2));
		Xc = Xc-((pow(X2, 2)-pow(X1, 2)+pow(Y2, 2)-pow(Y1, 2))/(2*(Y2-Y1)));
		Xc = Xc/((X3-X2)/(Y3-Y2)-(X2-X1)/(Y2-Y1));
	if (Y3-Y2 == 0):
		Xc = (X3+X2)/2
	elif (Y2-Y1 == 0):
		Xc = (X2+X1)/2
	if (Y2-Y1 != 0):
		Yc = -(X2-X1)/(Y2-Y1)*Xc+(pow(X2, 2)-pow(X1, 2)+pow(Y2, 2)-pow(Y1, 2))/(2*(Y2-Y1))
	else:
		Yc = -(X2-X1)/(Y3-Y2)*Xc+(pow(X2, 2)-pow(X1, 2)+pow(Y3, 2)-pow(Y2, 2))/(2*(Y3-Y2))
	Rc = math.sqrt(pow(X1-Xc, 2)+pow(Y1-Yc, 2))
	return (Rc)

if __name__ == "__main__":
	X1 = 5
	X2 = -1
	X3 = 4
	Y1 = -2
	Y2 = 2
	Y3 = 3
	ang = angle(X1, X2, X3, Y1, Y2, Y3)
	print(str(float(ang)) + "\n")
	if (ang >= 0 and ang != 180):
		print(str(float(circle_radius(X1, X2, X3, Y1, Y2, Y3))) + "\n")
