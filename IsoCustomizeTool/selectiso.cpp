#include "selectiso.h"


SelectIso::SelectIso(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();

    DLabel *label = new DLabel("选择ISO");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);

    DFileChooserEdit *fileChooser = new DFileChooserEdit();
    fileChooser->setNameFilters(QStringList("ISO(*.iso)"));

    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    nextButton = new DPushButton("下一步");
    nextButton->setEnabled(false);

    pButtonLayout->addSpacing(120);
    pButtonLayout->addWidget(nextButton);
    pButtonLayout->addSpacing(120);

    pMainLayout->addWidget(label);
    pMainLayout->addWidget(fileChooser);
    pMainLayout->addStretch();
    pMainLayout->addLayout(pButtonLayout);

    this->setLayout(pMainLayout);

    connect(fileChooser, &DFileChooserEdit::fileChoosed, [ = ](const QString & fileName) {
        if (!fileName.isEmpty()) {
            nextButton->setEnabled(true);
        }
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        emit sendSignal(0);
    });
}


