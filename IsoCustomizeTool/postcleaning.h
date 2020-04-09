#ifndef POSTCLEANING_H
#define POSTCLEANING_H

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

class PostCleaning : public QWidget
{
    Q_OBJECT
public:
    explicit PostCleaning(QWidget *parent = nullptr);
    QIcon getIcon(QString ico);

signals:
    void sendSignal(int a);

public slots:
private:
    DFloatingMessage *floatMessage;
    QVector<DFloatingMessage *> m_floatingMessage;
};

#endif // POSTCLEANING_H
