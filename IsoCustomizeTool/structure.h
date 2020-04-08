#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <QWidget>
#include <DApplication>
#include <DPushButton>
#include <DListView>

DWIDGET_USE_NAMESPACE

class Structure : public QWidget
{
    Q_OBJECT
public:
    explicit Structure(QWidget *parent = nullptr);

signals:
    void sendSignal(int a);

public slots:

private:

    DPushButton *nextButton;

    DListView *m_listView;
};

#endif // STRUCTURE_H
