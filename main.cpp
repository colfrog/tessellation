#include <QApplication>

#include "TessellationView.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	TessellationView view;
	view.show();
	return app.exec();
}
