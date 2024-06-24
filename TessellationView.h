#pragma once

#include <memory>

#include <QWidget>
#include <QKeyEvent>

#include "Tessellation.h"

class TessellationView : public QWidget {
	Q_OBJECT
public:
	TessellationView(QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;

private:
	Tessellation *m_tess = nullptr;
};
