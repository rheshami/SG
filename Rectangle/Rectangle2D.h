#pragma once

struct Point
{
	float X = 0.0f;
	float Y = 0.0f;

};

class Rectangle2D
{
public:	
	Rectangle2D(Point start, float width, float height );
	~Rectangle2D();

	bool isInRectangle(const Point& point) const;
	bool isColliding(const Rectangle2D& rectangle) const;


private: 
	void setRectangle();
	
private:
	Point m_bottomRight;
	Point m_bottomLeft;
	Point m_topRight;
	Point m_topLeft;
	float m_width;
	float m_height;
};