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
private slots:
   void chgDisk(int index); // получаем индекс выбранного диска
   void goMainPath();       // Для UNIX-подобных ОС верхним уровнем является
                            // путь /
private:
   QStandardItemModel *model;
   QString curretnPath;
protected:
};

#endif // FSEXPLOREWIDGET_H
