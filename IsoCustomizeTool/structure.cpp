#include "structure.h"
#include <QDebug>

Structure::Structure(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("选择架构");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);

    itemModel = new QStandardItemModel;
    QStandardItem *arm = new QStandardItem(tr("ARM"));
    QStandardItem *x86 = new QStandardItem(tr("X86"));
    QStandardItem *mips = new QStandardItem(tr("MIPS"));
    m_listView = new DListView(this);

    itemModel->appendRow(arm);
    itemModel->appendRow(x86);
    itemModel->appendRow(mips);
    m_listView->setModel(itemModel);

    nextButton = new DPushButton("下一步");
    nextButton->setEnabled(false);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    mainLayout->addWidget(label);
    mainLayout->addWidget(m_listView);
    mainLayout->addStretch();

    buttonLayout->addSpacing(120);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addSpacing(120);

    mainLayout->addLayout(buttonLayout);

    this->setLayout(mainLayout);

    connect(m_listView, &DListView::clicked, [ = ](const QModelIndex & index) {
        for (int i = 0; i < m_listView->count(); i++) {
            itemModel->item(i, 0)->setCheckState(Qt::Unchecked);
        }
//        QString str = arm->text();
//        qDebug() << str;
        itemModel->item(index.row(), 0)->setCheckState(Qt::Checked);
        nextButton->setEnabled(true);
        emit sendSelectedItemName(itemModel->item(index.row(), 0)->text());
        qDebug() << itemModel->item(index.row(), 0)->text();
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        emit sendSignal(1);
    });
}


