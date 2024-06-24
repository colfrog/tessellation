#include "Sierpinski.h"

class SierpinskiTiles : public Sierpinski {
public:
	virtual void operator()(QPainter &p, size_t width, size_t height);
};
