#ifndef FSEXPLOREWIDGET_H
#define FSEXPLOREWIDGET_H


#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QDebug> //
#include <QLineEdit> //
#include <QToolButton>//

//Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class FSExploreWidget : public QWidget
{
   Q_OBJECT
public:
   explicit FSExploreWidget(QWidget *parent = nullptr);
   void clearTree();
   QStandardItemModel *getCurrentModel()const
   {
       return model;

}
   void setNewModel(QStandardItemModel *newmodel);
   void rebuildModel(QString str);
private:
   QGridLayout *gridLay;
   QTreeView *tree;
   QPushButton *mainPath;
   QComboBox *disckSelBox;

   //*
   QLineEdit *lePath;
   QToolButton *tbGo;
//   QString currentPath;
   //*
private slots:
   void chgDisk(int index); // получаем индекс выбранного диска
   void goMainPath();       // Для UNIX-подобных ОС верхним уровнем является
                            // путь /
   void goPath();
private:
   QStandardItemModel *model;
   QString currentPath;

#if defined (__unix__)
   inline static const QString rootDir { "/" };
#elif
   QString rootDir;
#endif //unix

protected:
};

#endif // FSEXPLOREWIDGET_H
