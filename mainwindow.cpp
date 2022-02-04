#include "mainwindow.h"
//#include "fsexplorewidget.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent),
     fsExplWdgt { new FSExploreWidget(this) }
{
//   FSExploreWidget *fsExplWdgt = new FSExploreWidget(this);
}


MainWindow::~MainWindow()
{
    delete fsExplWdgt;
}

