#include <QtWidgets>
#include <QtSql>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QVBarModelMapper>
#include <QtCharts/QBarCategoryAxis>

#include "maindialog.h"
#include "declarations.h"
#include "tablemodel.h"
#include "mapperdialog.h"

QT_CHARTS_USE_NAMESPACE

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

//    m_model->setHeaderData(statistics_date,      Qt::Horizontal,
//                           trUtf8("Дата\n(Месяц, Год)"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_internal,  Qt::Horizontal,
//                           trUtf8("Внутренние\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_external,  Qt::Horizontal,
//                           trUtf8("Международные\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_transit,   Qt::Horizontal,
//                           trUtf8("Транзитные\nрейсы"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_charter,   Qt::Horizontal,
//                           trUtf8("Рейсы вне расписания\n(чартерные)"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_maxday,    Qt::Horizontal,
//                           trUtf8("Максимальная суточная\nинтенсивность ВС\nсекторов РДЦ"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_foreigner, Qt::Horizontal,
//                           trUtf8("Рейсы иностранных\nавиакомпаний"), Qt::DisplayRole);
//    m_model->setHeaderData(statistics_note,      Qt::Horizontal,
//                           trUtf8("Примечание"), Qt::DisplayRole);
}


void MainDialog::setupView()
{
    m_view->setModel(m_model);
    m_view->resizeColumnsToContents();
//    m_view->horizontalHeader()->setStretchLastSection(true);
    m_view->verticalHeader()->show();
    m_view->setColumnHidden(month_pid, true);
    m_view->setColumnHidden(month_department_pid, true);
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

    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(4);
//    mapper->setLastBarSetColumn(m_model->columnCount() - 1);
    mapper->setLastBarSetColumn(4);
    mapper->setFirstRow(0);
    mapper->setRowCount(m_model->rowCount());
    mapper->setSeries(series);
    mapper->setModel(m_model);

    QStringList categories;
    categories << "Январь" << "Февраль" << "Март" << "Апрель" << "Май" << "Июнь";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

//    QString seriesColorHex = "#000000";

//    // get the color of the series and use it for showing the mapped area
//    QList<QBarSet *> barsets = series->barSets();
//    for (int i = 0; i < barsets.count(); i++) {
//        seriesColorHex = "#" + QString::number(barsets.at(i)->brush().color().rgb(), 16).right(6).toUpper();
//        m_model->addMapping(seriesColorHex, QRect(1 + i, first, 1, barsets.at(i)->count()));
//    }

//    QStringList categories;
//    categories << "April" << "May" << "June" << "July" << "August";
//    QBarCategoryAxis *axis = new QBarCategoryAxis();
//    axis->append(categories);
//    chart->createDefaultAxes();
//    chart->setAxisX(axis, series);



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640, 480);



    QHBoxLayout *dialogLayout = new QHBoxLayout;
    dialogLayout->addWidget(chartView);

    QDialog *chartDialog = new QDialog;
    chartDialog->setLayout(dialogLayout);
    chartDialog->show();
}
