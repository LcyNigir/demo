#include "mainwindow.h"
#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DLog>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();  //翻译
//    a.setTheme("light");
//    a.setOrganizationName("deepin");
    a.setApplicationName("ISO定制工具");
//    a.setApplicationVersion("1.0");
//    a.setProductIcon(QIcon(":/images/logo.svg"));
//    a.setProductName("Dtk Application");
//    a.setApplicationDescription("This is a dtk template application.");
//    Dtk::Core::DLogManager::registerConsoleAppender();  //log日志追踪


    MainWindow w;
    w.setMinimumSize(800, 600);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
