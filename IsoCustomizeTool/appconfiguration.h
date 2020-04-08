#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H

#include <DApplication>
#include <DLabel>
#include <DPushButton>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DMessageManager>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class AppConfiguration : public QWidget
{
    Q_OBJECT
public:
    explicit AppConfiguration(QWidget *parent = nullptr);

signals:
    void sendSignal(int a);

public slots:
private:
    DFloatingMessage *floatMessage;
    QVector<DFloatingMessage *> m_floatingMessage;
};

#endif // APPCONFIGURATION_H
