class rectangleType
{
    public:
        void setDimension(double, double);
        double getLength();
        double getWidth();
        double area();
        double perimeter();
        void print();
        rectangleType(double l = 0, double w = 0);

    protected:
        double length;
        double width;
};
