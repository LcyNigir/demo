#ifndef MIDINSTALL_H
#define MIDINSTALL_H

#include <DApplication>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DFontSizeManager>
#include <DLabel>
#include <DPushButton>

#include <QWidget>
#include <QHBoxLayout>
#include <DFloatingMessage>

DWIDGET_USE_NAMESPACE

class MidInstall : public QWidget
{
    Q_OBJECT
public:
    explicit MidInstall(QWidget *parent = nullptr);
    QIcon getIcon(QString list);

signals:
    void sendSignal(int a);

public slots:
private:
    DFloatingMessage *floatMessage;
    QVector<DFloatingMessage *> m_floatingMessage;
};

#endif // MIDINSTALL_H
