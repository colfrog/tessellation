#include "Sierpinski.h"

#include <cmath>

/*
 *   p3
 * p1  p2
 * same for t
 */

void Sierpinski::operator()(QPainter &p, size_t width, size_t height) {
	Triangle t;
	size_t a = height/sqrt(3);

	t.p1.rx() = width/2 - a;
	t.p1.ry() = height;

	t.p2.rx() = width/2 + a;
	t.p2.ry() = height;

	t.p3.rx() = width/2;
	t.p3.ry() = 0;

	draw_sierpinski(p, t);
}

void Sierpinski::draw_sierpinski(QPainter &p, const Triangle &t, uint32_t min_len) const {
	if (abs(t.p1.x() - t.p2.x()) <= min_len)
		return;

	Triangle t1, t2, t3;

	t1.p1 = t.p1;
	t1.p2.rx() = (t.p1.x() + t.p2.x())/2;
	t1.p2.ry() = t.p1.y();
	t1.p3.rx() = (t1.p1.x() + t1.p2.x())/2;
	t1.p3.ry() = (t.p1.y() + t.p3.y())/2;

	t2.p1 = t1.p2;
	t2.p2 = t.p2;
	t2.p3.rx() = (t2.p1.x() + t2.p2.x())/2;
	t2.p3.ry() = t1.p3.y();

	t3.p1 = t1.p3;
	t3.p2 = t2.p3;
	t3.p3 = t.p3;

	draw_triangle(p, t1);
	draw_triangle(p, t2);
	draw_triangle(p, t3);

	draw_sierpinski(p, t1, min_len);
	draw_sierpinski(p, t2, min_len);
	draw_sierpinski(p, t3, min_len);
}

void Sierpinski::draw_triangle(QPainter &p, const Triangle &t) const {
	p.drawLine(t.p1, t.p2);
	p.drawLine(t.p2, t.p3);
	p.drawLine(t.p3, t.p1);
}
