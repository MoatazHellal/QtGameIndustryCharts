#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);

    QVBoxLayout* barLayout = new QVBoxLayout(ui->BarsTab);
    QChartView* barView = new QChartView(createBarChart());
    barView->setRenderHint(QPainter::Antialiasing);
    barLayout->addWidget(barView);

    QVBoxLayout* HbarLayout = new QVBoxLayout(ui->HorizontalStackedBarsTab);
    QChartView* HbarView = new QChartView(createHBarChart());
    HbarView->setRenderHint(QPainter::Antialiasing);
    HbarLayout->addWidget(HbarView);

    QVBoxLayout* LineLayout = new QVBoxLayout(ui->LineTab);
    QChartView* LineView = new QChartView(createLineChart());
    LineView->setRenderHint(QPainter::Antialiasing);
    LineLayout->addWidget(LineView);

    QVBoxLayout* PieLayout = new QVBoxLayout(ui->PieTab);
    QChartView* PieView = new QChartView(createPieChart());
    PieView->setRenderHint(QPainter::Antialiasing);
    PieLayout->addWidget(PieView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<QBarSet*> MainWindow::createBarSets()
{
    QVector<QBarSet*> sets;

    QBarSet* set0 = new QBarSet("Tencent");
    QBarSet* set1 = new QBarSet("Sony");
    QBarSet* set2 = new QBarSet("Microsoft");
    QBarSet* set3 = new QBarSet("Activision Blizzard");

    *set0 << 29.6 << 33.1 << 35.4 << 36.8;
    *set1 << 21.0 << 23.5 << 26.2 << 27.5;
    *set2 << 11.3 << 13.7 << 15.1 << 16.0;
    *set3 << 6.1 << 7.4 << 	8.1 << 8.5;

    sets.append(set0);
    sets.append(set1);
    sets.append(set2);
    sets.append(set3);

    return sets;
}

QChart * MainWindow::createBarChart()
{
    auto sets = createBarSets();

    QBarSeries* series = new QBarSeries();
    for (auto set : sets)
        series->append(set);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Game Companies Revenue By Year");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "2020" << "2021" << "2022" << "2023";

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Revenue (Billion USD)");
    axisY->setLabelFormat("%.1f");
    axisY->setRange(0, 40);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    return chart;

}

QChart* MainWindow::createHBarChart()
{
    auto sets = createBarSets();

    QHorizontalStackedBarSeries* series = new QHorizontalStackedBarSeries();
    for(auto set : sets)
        series->append(set);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Game Companies Revenue By Year");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "2020" << "2021" << "2022" << "2023";

    QBarCategoryAxis* axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Revenue (Billion USD)");
    axisX->setLabelFormat("%.1f");
    axisX->setRange(0, 100);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    return chart;
}

QChart* MainWindow::createLineChart()
{
    QLineSeries* tencent = new QLineSeries();
    tencent->setName("Tencent");
    tencent->append(2020, 29.6);
    tencent->append(2021, 33.1);
    tencent->append(2022, 35.4);
    tencent->append(2023, 36.8);

    QLineSeries* sony = new QLineSeries();
    sony->setName("Sony");
    sony->append(2020, 21.0);
    sony->append(2021, 23.5);
    sony->append(2022, 26.2);
    sony->append(2023, 27.5);

    QLineSeries* microsoft = new QLineSeries();
    microsoft->setName("Microsoft");
    microsoft->append(2020, 11.3);
    microsoft->append(2021, 13.7);
    microsoft->append(2022, 15.1);
    microsoft->append(2023, 16.0);

    QLineSeries* activision = new QLineSeries();
    activision->setName("Activision Blizzard");
    activision->append(2020, 6.1);
    activision->append(2021, 7.4);
    activision->append(2022, 8.1);
    activision->append(2023, 8.5);

    QChart* chart = new QChart();
    chart->addSeries(tencent);
    chart->addSeries(sony);
    chart->addSeries(microsoft);
    chart->addSeries(activision);
    chart->setTitle("Game Companies Revenue Over Years");
    chart->setAnimationOptions(QChart::AllAnimations);

    QValueAxis* axisX = new QValueAxis();
    axisX->setRange(2020, 2023);
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Year");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, 40);
    axisY->setTitleText("Revenue (Billion USD)");
    axisY->setLabelFormat("%.1f");
    chart->addAxis(axisY, Qt::AlignLeft);

    for (QLineSeries* series : {tencent, sony, microsoft, activision})
    {
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    return chart;
}

QChart* MainWindow::createPieChart()
{
    QPieSeries* series = new QPieSeries();

    series->append("Tencent", 36.8);
    series->append("Sony", 27.5);
    series->append("Microsoft", 16.0);
    series->append("Activision Blizzard", 8.5);

    QPieSlice* slice = series->slices().at(0);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Game Companies Revenue Share 2023");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    return chart;
}
