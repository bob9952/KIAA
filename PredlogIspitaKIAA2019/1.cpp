#include <bits/stdc++.h>

using namespace std;

struct Point{

	double x, y;
	
	Point(){};

	Point(double x_, double y_){
		x = x_;
		y = y_;
	}

};

int orientation(Point &a, Point &b, Point &c)
{

	//int val = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x-p1.x);
    // p1p2 x p1p3
    double val = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
    if(fabs(val) < 0.01)
    {
        return 0;
    }
	
    if(val > 0) //counterclockwise
		return 2;
	else //clockwise
        return 1;
}

bool konveksan(vector<Point> &points)
{
    //Point p1 = points[0];
    //Point p2 = points[1];
    //Point p3 = points[2];

    //pronadjem prvu orj koja nije 0
    int o;
    int index = -1;
    for(int i = 0; i < 3; i++)
    {
        o = orientation(points[i], points[i+1], points[i+2]);
    //    cout << i << " " << "orj: " << o << endl;
        if(o != 0)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
        return true;
    int new_o;
    
    for(int i = index+1; i < 3; i++)
    {
        new_o = orientation(points[i], points[i+1], points[i+2]);
        //cout << new_o << endl;
        if(o != new_o && new_o != 0)
            return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	double x, y;
	vector<Point> points(5);
	Point *point;

	for(int i = 0; i < 5; i++)
    {
		cin >> x >> y;
		point = new Point(x, y);
		points[i] = *point;
	}

	if(konveksan(points))
		cout << "DA" << endl;
	else
		cout << "NE" << endl;

	return 0;
}
