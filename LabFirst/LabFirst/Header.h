class IsoscelesTriangle {
private:
    double side;  
    double angle;

public:
    // Конструктор по умолчанию
    IsoscelesTriangle();

    // Метод для установки боковой стороны и угла
    bool setProperties(double s, double a);

    // Метод для увеличения или уменьшения размера треугольника
    bool scale(double factor);

    // Метод для вычисления длины биссектрисы
    double calculateBisector(double& bis, double& bisSide) const;

    // Метод для вычисления длины высоты
    double calculateHeight(double& h, double& hs) const;

    // Метод для определения длин сторон
    void calculateSides(double& base, double& leftSide, double& rightSide) const;
};
