class IsoscelesTriangle {
private:
    double side;  
    double angle;

public:
    // ����������� �� ���������
    IsoscelesTriangle();

    // ����� ��� ��������� ������� ������� � ����
    bool setProperties(double s, double a);

    // ����� ��� ���������� ��� ���������� ������� ������������
    bool scale(double factor);

    // ����� ��� ���������� ����� �����������
    double calculateBisector(double& bis, double& bisSide) const;

    // ����� ��� ���������� ����� ������
    double calculateHeight(double& h, double& hs) const;

    // ����� ��� ����������� ���� ������
    void calculateSides(double& base, double& leftSide, double& rightSide) const;
};
