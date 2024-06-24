#include "SierpinskiTiles.h"

#include <cmath>

void SierpinskiTiles::operator()(QPainter &p, size_t width, size_t height) {
	int th = height/8;
	int tw = 2*th/sqrt(3);
	std::cout << tw << ", " << th << ", " << sqrt(tw*tw + th*th) << std::endl;

	Sierpinski::Triangle base_triangle1{QPoint(0, 0), QPoint(tw, 0), QPoint(tw/2, th)};
	Sierpinski::Triangle base_triangle2{QPoint(tw/2, th), QPoint(tw + tw/2, th), QPoint(tw, 0)};
	std::cout << width/tw << ", " << height/th << std::endl;
	for (int i = -1; i < ((int) width)/tw + 1; i++) {
		std::cout << i << std::endl;
		for (int j = -1; j < ((int) height)/th + 1; j++) {
			Sierpinski::Triangle t1 = base_triangle1;
			Sierpinski::Triangle t2 = base_triangle2;
			QPoint offset = QPoint(i, j);
			offset.rx() *= tw;
			offset.ry() *= th;

			t1.p1 += offset;
			t1.p2 += offset;
			t1.p3 += offset;

			t2.p1 += offset;
			t2.p2 += offset;
			t2.p3 += offset;

			std::cout << t1 << " " << t2 << std::endl;
			draw_sierpinski(p, t1, 10);
			draw_sierpinski(p, t2, 10);
		}
	}
}
