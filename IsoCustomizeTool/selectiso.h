#ifndef SELECTISO_H
#define SELECTISO_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DLabel>
#include <dfilechooseredit.h>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>


DWIDGET_USE_NAMESPACE

class Structure;
class MainWindow;
class SelectIso : public QWidget
{
    Q_OBJECT
public:
    explicit SelectIso(QWidget *parent = nullptr);
    void activationButton();

signals:
    void sendSignal(int a);

public slots:
private:
    DPushButton *nextButton;
};

#endif // SELECTISO_H
