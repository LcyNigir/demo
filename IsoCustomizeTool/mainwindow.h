#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DApplication>
#include <DMainWindow>
#include <DTitlebar>
#include <DListView>
#include <DFrame>

#include "appconfiguration.h"
#include "midinstall.h"
#include "postcleaning.h"
#include "prepare.h"
#include "selectiso.h"
#include "selectkernel.h"
#include "structure.h"
#include "output.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void initWidget();

signals:

public slots:
    void changeWidget(int);
    void listViewItemClicked(const QModelIndex &index);
    void slotActionHelp();

private:
    DTitlebar *m_titlebar;
    DListView *m_listView;
    QStackedWidget *m_pStackedWidget;
    QStandardItemModel *m_standarModel;
    QHash<QString, QWidget *> m_ItemWiget;

    SelectIso *m_selectIso;
    Structure *m_structure;
    AppConfiguration *m_appConfig;
    Prepare *m_prepare;
    MidInstall *m_midInstall;
    PostCleaning *m_postClean;
    SelectKernel *m_selectKernel;
    Output *m_outputFile;

};

#endif // MAINWINDOW_H
