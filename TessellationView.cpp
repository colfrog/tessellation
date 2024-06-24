#include "TessellationView.h"
#include "Sierpinski.h"

TessellationView::TessellationView(QWidget *parent) : QWidget(parent) {}

void TessellationView::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QColor bg(0x22, 0x22, 0x22);
	QColor fg(0x23, 0xff, 0x4f);

	painter.setBrush(bg);
	painter.setPen(bg);
	painter.drawRect(0, 0, width(), height());

	if (m_tess == nullptr)
		return;

	Tessellation &tess = *m_tess;

	painter.setBrush(fg);
	painter.setPen(fg);
	tess(painter, width(), height());
}

void TessellationView::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
	case Qt::Key_Escape:
		exit(0);
		break;
	case Qt::Key_S:
		if (m_tess != nullptr)
			delete m_tess;

		m_tess = new Sierpinski();
		break;
	}

	update();
}
