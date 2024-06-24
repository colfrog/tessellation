#pragma once

#include "Tessellation.h"

#include <QPoint>

class Sierpinski : public Tessellation {
public:
	virtual void operator()(QPainter &p, size_t width, size_t height);
protected:
	struct Triangle {
		QPoint p1, p2, p3;
	};

	void draw_sierpinski(QPainter &p, const Triangle &t, uint32_t min_len = 24) const;
	void draw_triangle(QPainter &p, const Triangle &t) const;
};
