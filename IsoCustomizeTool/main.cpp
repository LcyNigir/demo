#include "mainwindow.h"
#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
//    a.setTheme("light");
//    a.setOrganizationName("deepin");
    a.setApplicationName("ISO定制工具");
//    a.setApplicationVersion("1.0");
//    a.setProductIcon(QIcon(":/images/logo.svg"));
//    a.setProductName("Dtk Application");
//    a.setApplicationDescription("This is a dtk template application.");

    MainWindow w;
    w.setMinimumSize(800, 600);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
