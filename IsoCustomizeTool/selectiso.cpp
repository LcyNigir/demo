#include "selectiso.h"


SelectIso::SelectIso(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();

    DLabel *topLabel = new DLabel("选择ISO");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    topLabel->setFont(font);
    DFontSizeManager::instance()->bind(topLabel, DFontSizeManager::T3);

    DFileChooserEdit *fileChooser = new DFileChooserEdit();
    fileChooser->setNameFilters(QStringList("ISO(*.iso)"));

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    nextButton = new DPushButton("下一步");
    nextButton->setEnabled(false);

    buttonLayout->addSpacing(120);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addSpacing(120);

    pMainLayout->addWidget(topLabel);
    pMainLayout->addWidget(fileChooser);
    pMainLayout->addStretch();
    pMainLayout->addLayout(buttonLayout);

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


