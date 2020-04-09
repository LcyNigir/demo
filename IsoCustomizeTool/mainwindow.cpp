#include "mainwindow.h"
#include <QDebug>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent),
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

    DMenu *pDMenu = new DMenu;
    QAction *helpAction(new QAction(tr("Help"), this));
    pDMenu->addAction(helpAction);
    titlebar()->setMenu(pDMenu);
    connect(helpAction, &QAction::triggered, this,  &MainWindow::slotActionHelp);

    initWidget();//初始化


    DFrame *leftFrame = new DFrame();  //底部边框
    DFrame *rightFrame = new DFrame();
    m_pStackedWidget = new QStackedWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout;  //主布局
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;

    leftFrame->setLayout(leftLayout);  //设置leftFrame布局为垂直布局
    leftLayout->addWidget(m_listView);

    rightFrame->setLayout(rightLayout);
    rightLayout->addWidget(m_pStackedWidget);


    mainLayout->addWidget(leftFrame, 1);
    mainLayout->addWidget(rightFrame, 3);


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


    connect(m_selectIso, &SelectIso::sendSignal, this, &MainWindow::changeWidget);
    connect(m_structure, &Structure::sendSignal, this, &MainWindow::changeWidget);
    connect(m_appConfig, &AppConfiguration::sendSignal, this, &MainWindow::changeWidget);
    connect(m_prepare, &Prepare::sendSignal, this, &MainWindow::changeWidget);
    connect(m_midInstall, &MidInstall::sendSignal, this, &MainWindow::changeWidget);
    connect(m_postClean, &PostCleaning::sendSignal, this, &MainWindow::changeWidget);
    connect(m_selectKernel, &SelectKernel::sendSignal, this, &MainWindow::changeWidget);
    connect(m_outputFile, &Output::sendCloseSignal, [ = ]() {
        this->close();
    });

}

void MainWindow::initWidget()
{
    m_listView = new DListView(this);
    m_standarModel = new QStandardItemModel(this);
    DStandardItem *item1 = new DStandardItem(QIcon::fromTheme("NO_inactive1"), "选择ISO");
    m_standarModel->appendRow(item1);
    m_ItemWiget.insert("选择ISO", m_selectIso);

    DStandardItem *item2 = new DStandardItem(QIcon::fromTheme("NO_inactive2"), "选择框架");
    item2->setEnabled(false);
    m_standarModel->appendRow(item2);
    m_ItemWiget.insert("选择框架", m_structure);

    DStandardItem *item3 = new DStandardItem(QIcon::fromTheme("NO_inactive3"), "程序配置");
    item3->setEnabled(false);
    m_standarModel->appendRow(item3);
    m_ItemWiget.insert("程序配置", m_appConfig);

    DStandardItem *item4 = new DStandardItem(QIcon::fromTheme("NO_inactive4"), "前期准备");
    item4->setEnabled(false);
    m_standarModel->appendRow(item4);
    m_ItemWiget.insert("前期准备", m_prepare);

    DStandardItem *item5 = new DStandardItem(QIcon::fromTheme("NO_inactive5"), "中期安装");
    item5->setEnabled(false);
    m_standarModel->appendRow(item5);
    m_ItemWiget.insert("中期安装", m_midInstall);

    DStandardItem *item6 = new DStandardItem(QIcon::fromTheme("NO_inactive6"), "后期清理");
    item6->setEnabled(false);
    m_standarModel->appendRow(item6);
    m_ItemWiget.insert("后期清理", m_structure);

    DStandardItem *item7 = new DStandardItem(QIcon::fromTheme("NO_inactive7"), "选择Kernel");
    item7->setEnabled(false);
    m_standarModel->appendRow(item7);
    m_ItemWiget.insert("选择Kernel", m_selectKernel);

    DStandardItem *item8 = new DStandardItem(QIcon::fromTheme("NO_inactive8"), "输出");
    item8->setEnabled(false);
    m_standarModel->appendRow(item8);
    m_ItemWiget.insert("输出", m_outputFile);

    m_listView->setModel(m_standarModel);

    connect(m_listView, &DListView::clicked, this, &MainWindow::listViewItemClicked, Qt::QueuedConnection);
}

void MainWindow::changeWidget(int a)
{
    QStandardItemModel *itemModel = m_standarModel;
    itemModel->item(a)->setCheckState(Qt::Checked);  //设置状态
    itemModel->item(a + 1, 0)->setEnabled(true);     //激活
    m_listView->setCurrentIndex(itemModel->indexFromItem(itemModel->item(a + 1, 0)));  //切换左边widget

    m_pStackedWidget->setCurrentIndex(a + 1); //切换右边widget
}

void MainWindow::listViewItemClicked(const QModelIndex &index)
{
    QStandardItemModel *itemModel = m_standarModel;
    QString itemName = index.data().toString();
//    qDebug() << itemName;
    if (itemModel->item(index.row(), 0)->isEnabled()) {
        m_pStackedWidget->setCurrentWidget(m_ItemWiget.value(itemName));
    }
}

void MainWindow::slotActionHelp()
{
    qDebug() << "help...help...help...help";
}


