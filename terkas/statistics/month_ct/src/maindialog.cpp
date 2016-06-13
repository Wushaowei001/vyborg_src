#include <QtWidgets>
#include <QtSql>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QVBarModelMapper>
#include <QtCharts/QHBarModelMapper>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLegendMarker>

QT_CHARTS_USE_NAMESPACE

#include "maindialog.h"
#include "declarations.h"
#include "tablemodel.h"
#include "mapperdialog.h"

MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupView();
    setupMapperDialog();
    setupFilterDialog();
    setupSortDialog();

    QPushButton *chartsButton = addButton(trUtf8("Charts"));
    connect(chartsButton, SIGNAL(clicked(bool)),
            this, SLOT(chartsButtonClicked()));
}

void MainDialog::setupModel()
{
    m_model = new TableModel;
    m_model->setTable(PGSQL_TABLENAME);

    bool ret = m_model->select();
    if (ret == false) {
        QString msgText("SELECT returned FALSE: " + m_model->lastError().text());
        QMessageBox::warning(this,
                             "ERROR",
                             msgText,
                             QMessageBox::Close);
        qApp->quit();
    }

//  m_model->setHeaderData(statistics_date, Qt::Horizontal, trUtf8("Дата\n(Месяц, Год)"), Qt::DisplayRole);
}


void MainDialog::setupView()
{
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();
//    m_view->horizontalHeader()->setStretchLastSection(true);
    m_view->verticalHeader()->hide();
//    m_view->setColumnHidden(month_pid, true);
//    m_view->setColumnHidden(month_department_pid, true);
    m_view->selectRow(0);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
//    filterDialog_->addColumn(trUtf8("Дата"), trUtf8("date"));
//    filterDialog_->addColumn(trUtf8("Внутренние рейсы"), trUtf8("internal"));
//    filterDialog_->addColumn(trUtf8("Международные рейсы"), trUtf8("external"));
//    filterDialog_->addColumn(trUtf8("Транзитные рейсы"), trUtf8("transit"));
//    filterDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), trUtf8("charter"));
//    filterDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), trUtf8("maxday"));
//    filterDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), trUtf8("foreigner"));
}

void MainDialog::setupSortDialog()
{
//    sortDialog_->addColumn(trUtf8("Дата"), statistics_date);
//    sortDialog_->addColumn(trUtf8("Внутренние рейсы"), statistics_internal);
//    sortDialog_->addColumn(trUtf8("Международные рейсы"), statistics_external);
//    sortDialog_->addColumn(trUtf8("Транзитные рейсы"), statistics_transit);
//    sortDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), statistics_charter);
//    sortDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), statistics_maxday);
//    sortDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), statistics_foreigner);
}

void MainDialog::chartsButtonClicked()
{
    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);

    QBarSeries *series = new QBarSeries;

    QHBarModelMapper *mapper = new QHBarModelMapper(this);
    mapper->setFirstBarSetRow(0);
    mapper->setLastBarSetRow(m_model->rowCount());
    mapper->setFirstColumn(1);
    mapper->setColumnCount(m_model->columnCount());
    mapper->setSeries(series);
    mapper->setModel(m_model);

    chart->addSeries(series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QList<QLegendMarker *> markers = chart->legend()->markers();
    for (int i = 0; i < markers.count(); i++)
        markers.at(i)->setLabel(QString::number(i + 2013));

    QStringList categories;
    categories << "Январь"
               << "Февраль"
               << "Март"
               << "Апрель"
               << "Май"
               << "Июнь"
               << "Июль"
               << "Август"
               << "Сентябрь"
               << "Октябрь"
               << "Ноябрь"
               << "Декабрь";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1200, 640);


    QHBoxLayout *dialogLayout = new QHBoxLayout;
    dialogLayout->addWidget(chartView);

    QDialog *chartDialog = new QDialog;
    chartDialog->setLayout(dialogLayout);
    chartDialog->show();
}
