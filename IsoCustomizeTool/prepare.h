#ifndef PREPARE_H
#define PREPARE_H


#include <DApplication>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DFontSizeManager>
#include <DLabel>
#include <DPushButton>
#include <DMessageManager>

#include <QWidget>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class Prepare : public QWidget
{
    Q_OBJECT
public:
    explicit Prepare(QWidget *parent = nullptr);

signals:
    void sendSignal(int a);

public slots:
private:
    DFloatingMessage *floatMessage;
    QVector<DFloatingMessage *> m_floatingMessage;
};

#endif // PREPARE_H
