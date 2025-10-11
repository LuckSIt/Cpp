#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

class Circle : public QWidget
{
    Q_OBJECT
public:
    explicit Circle(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void setRed();
    void setGreen();
    void setYellow();

private:
    QPixmap mCurrentCircle;
    QPixmap mRedCircle;
    QPixmap mYellowCircle;
    QPixmap mGreenCircle;
};

Circle::Circle(QWidget *parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mRedCircle   = QPixmap("C:/Users/Vladimir/QtProjects/red.png");
    mGreenCircle = QPixmap("C:/Users/Vladimir/QtProjects/green.png");
    mYellowCircle= QPixmap("C:/Users/Vladimir/QtProjects/yellow.png");

    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect());
}

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}

QSize Circle::sizeHint() const
{
    return mCurrentCircle.size();
}

QSize Circle::minimumSizeHint() const
{
    return QSize(100, 100);
}

void Circle::setRed()
{
    mCurrentCircle = mRedCircle;
    update();
}

void Circle::setGreen()
{
    mCurrentCircle = mGreenCircle;
    update();
}

void Circle::setYellow()
{
    mCurrentCircle = mYellowCircle;
    update();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);

    auto *circle = new Circle(&window);
    auto *slider = new QSlider(Qt::Horizontal, &window);

    slider->setRange(0, 100);

    auto *layout = new QVBoxLayout(&window);
    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged,
                     [circle](int newValue) {
                         if (newValue <= 33)      circle->setGreen();
                         else if (newValue <= 66) circle->setYellow();
                         else                     circle->setRed();
                     });

    window.show();
    return a.exec();
}

#include "main.moc"
