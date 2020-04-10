#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <DApplication>
#include <DPushButton>
#include <DListView>
#include <DLabel>

#include <QStandardItem>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class Structure : public QWidget
{
    Q_OBJECT
public:
    explicit Structure(QWidget *parent = nullptr);

signals:
    void sendSignal(int a);
    void sendSelectedItemName(QString);

public slots:

private:
    QStandardItemModel *itemModel;
    DPushButton *nextButton;
    DListView *m_listView;
};

#endif // STRUCTURE_H
