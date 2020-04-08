#ifndef SELECTKERNEL_H
#define SELECTKERNEL_H

#include <DApplication>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DFontSizeManager>
#include <DLabel>
#include <DPushButton>
#include <dfilechooseredit.h>

#include <QWidget>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class SelectKernel : public QWidget
{
    Q_OBJECT
public:
    explicit SelectKernel(QWidget *parent = nullptr);

signals:
    void sendSignal(int a);

public slots:
};

#endif // SELECTKERNEL_H
