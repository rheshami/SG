#include "Rectangle2D.h"
#include <stdio.h>


Rectangle2D::Rectangle2D(Point start, float width, float height)
	:m_bottomLeft(start)
	,m_width(width)
	,m_height(height)
{
	setRectangle();
}


bool Rectangle2D::isInRectangle(const Point& point) const
{
	return (point.X >= m_bottomLeft.X &&
		point.X <= m_bottomRight.X &&
		point.Y >= m_bottomLeft.Y &&
		point.Y <= m_topLeft.Y);
}

bool Rectangle2D::isColliding(const Rectangle2D& rectangle) const
{
	return (isInRectangle(rectangle.m_bottomLeft) ||
			isInRectangle(rectangle.m_bottomRight) ||
			isInRectangle(rectangle.m_topLeft) ||
			isInRectangle(rectangle.m_topRight));
}



// private funtions
void Rectangle2D::setRectangle()
{
	m_bottomRight.X = m_bottomLeft.X + m_width;
	m_bottomRight.Y = m_bottomLeft.Y;

	m_topLeft.X = m_bottomLeft.X;
	m_topLeft.Y = m_bottomLeft.Y + m_height;

	m_topRight.X = m_bottomRight.X;
	m_topRight.Y = m_topLeft.Y;

}