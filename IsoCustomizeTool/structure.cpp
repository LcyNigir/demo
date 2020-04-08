#include "structure.h"

#include <DLabel>
#include <QStandardItem>
#include <QVBoxLayout>

Structure::Structure(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("选择架构");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);

    QStandardItemModel *itemModel = new QStandardItemModel;
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
        itemModel->item(index.row(), 0)->setCheckState(Qt::Checked);
        nextButton->setEnabled(true);
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        nextButton->setEnabled(true);
        emit sendSignal(1);
    });
}


