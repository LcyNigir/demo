#include "mainwindow.h"
#include <QDebug>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent) :
    DMainWindow(parent),
    m_selectIso(new SelectIso),
    m_structure(new Structure),
    m_appConfig(new AppConfiguration),
    m_prepare(new Prepare),
    m_midInstall(new MidInstall),
    m_postClean(new PostCleaning),
    m_selectKernel(new SelectKernel),
    m_outputFile(new Output)
{
    auto flags = windowFlags() & ~Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    m_titlebar = this->titlebar();
    m_titlebar->setIcon(QIcon::fromTheme("iso_image5"));

    initWidget();

    m_pStackedWidget = new QStackedWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_listView, 1);
    mainLayout->addWidget(m_pStackedWidget, 2);


    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);
    widget->setLayout(mainLayout);



    m_pStackedWidget->addWidget(m_selectIso);//0
    m_pStackedWidget->addWidget(m_structure);
    m_pStackedWidget->addWidget(m_appConfig);
    m_pStackedWidget->addWidget(m_prepare);
    m_pStackedWidget->addWidget(m_midInstall);
    m_pStackedWidget->addWidget(m_postClean);
    m_pStackedWidget->addWidget(m_selectKernel);
    m_pStackedWidget->addWidget(m_outputFile);//7

//    connect(m_listView, &DListView::clicked, this, &MainWindow::slotListViewItemClicked, Qt::QueuedConnection);

    connect(m_selectIso, &SelectIso::sendSignal, this, &MainWindow::changeWidget);
    connect(m_structure, &Structure::sendSignal, this, &MainWindow::changeWidget);
    connect(m_appConfig, &AppConfiguration::sendSignal, this, &MainWindow::changeWidget);
    connect(m_prepare, &Prepare::sendSignal, this, &MainWindow::changeWidget);
    connect(m_midInstall, &MidInstall::sendSignal, this, &MainWindow::changeWidget);
    connect(m_postClean, &PostCleaning::sendSignal, this, &MainWindow::changeWidget);
    connect(m_selectKernel, &SelectKernel::sendSignal, this, &MainWindow::changeWidget);


}

void MainWindow::initWidget()
{
    m_listView = new DListView(this);
    m_standarModel = new QStandardItemModel(this);
    DStandardItem *itemOne = new DStandardItem(QIcon::fromTheme("NO_inactive1"), "选择ISO");
    m_standarModel->appendRow(itemOne);


    DStandardItem *itemTwo = new DStandardItem(QIcon::fromTheme("NO_inactive2"), "选择框架");
    itemTwo->setEnabled(false);
    m_standarModel->appendRow(itemTwo);
    m_ItemWiget.insert("选择框架", m_structure);

    DStandardItem *itemThree = new DStandardItem(QIcon::fromTheme("NO_inactive3"), "程序配置");
    itemThree->setEnabled(false);
    m_standarModel->appendRow(itemThree);
    m_ItemWiget.insert("程序配置", m_appConfig);

    DStandardItem *itemFour = new DStandardItem(QIcon::fromTheme("NO_inactive4"), "前期准备");
    itemFour->setEnabled(false);
    m_standarModel->appendRow(itemFour);
    m_ItemWiget.insert("前期准备", m_prepare);

    DStandardItem *itemFive = new DStandardItem(QIcon::fromTheme("NO_inactive5"), "中期安装");
    itemFive->setEnabled(false);
    m_standarModel->appendRow(itemFive);
    m_ItemWiget.insert("中期安装", m_midInstall);

    DStandardItem *itemSix = new DStandardItem(QIcon::fromTheme("NO_inactive6"), "后期清理");
    itemSix->setEnabled(false);
    m_standarModel->appendRow(itemSix);
    m_ItemWiget.insert("后期清理", m_structure);

    DStandardItem *itemSeven = new DStandardItem(QIcon::fromTheme("NO_inactive7"), "选择Kernel");
    itemSeven->setEnabled(false);
    m_standarModel->appendRow(itemSeven);
    m_ItemWiget.insert("选择Kernel", m_selectKernel);

    DStandardItem *itemEight = new DStandardItem(QIcon::fromTheme("NO_inactive8"), "输出");
    itemEight->setEnabled(false);
    m_standarModel->appendRow(itemEight);
    m_ItemWiget.insert("输出", m_outputFile);


    m_listView->setModel(m_standarModel);
}

void MainWindow::changeWidget(int a)
{
    m_pStackedWidget->setCurrentIndex(a + 1);
}


