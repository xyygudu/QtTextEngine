#pragma once

struct GESize
{
	int width;
	int height;
	GESize() : width(0), height(0) {}
	GESize(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	bool operator==(const GESize& other) const
	{
		return (width == other.width && height == other.height);
	}
};

struct GESizeF
{
	float width;
	float height;
	GESizeF() : width(0), height(0) {}
	GESizeF(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	bool operator==(const GESizeF& other) const
	{
		return (width == other.width && height == other.height);
	}
};

struct GEPoint
{
	int x;
	int y;
	GEPoint() : x(0), y(0) {}
	GEPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(const GEPoint& other) const
	{
		return (x == other.x && y == other.y);
	}
};

struct GEPointF
{
	float x;
	float y;
	GEPointF() : x(0), y(0) {}
	GEPointF(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(const GEPointF& other) const
	{
		return (x == other.x && y == other.y);
	}
};

struct GERect
{
	int x;
	int y;
	int width;
	int height;
	GERect() : x(0), y(0), width(0), height(0) {}
	GERect(int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	bool operator==(const GERect& other) const
	{
		return (x == other.x && y == other.y && width == other.width && height == other.height);
	}
};

struct GERectF
{
	float x;
	float y;
	float width;
	float height;
	GERectF() : x(0), y(0), width(0), height(0) {}
	GERectF(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	bool operator==(const GERectF& other) const
	{
		return (x == other.x && y == other.y && width == other.width && height == other.height);
	}
};

enum AlignMode
{
	LEFT, RIGHT, CENTER, JUSTIFY 
};

enum Layout
{
	HORIZONTAL, VERTICAL
};