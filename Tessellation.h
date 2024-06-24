#pragma once

#include <QPainter>

class Tessellation {
public:
	virtual ~Tessellation() {}
	virtual void operator()(QPainter &p, size_t width, size_t height) = 0;
};
