#pragma once

class IShape
{
public:
    virtual ~IShape()
    {
    }
    
    virtual float getArea() const = 0;
};

class Square : public IShape
{
public:
    Square()
    : a_(0.0f)
    {
    }

    Square(float const a)
    : a_(a)
    {
    }

    ~Square()
    {
    }

    float getArea() const override
    {
        return a_ * a_;
    }

private:
    float a_;
};

class Triangle : public IShape
{
public:
    Triangle()
    : h_(0.0f)
    , b_(0.0f)
    {
    }

    Triangle(float const h, float const b)
    : h_(h)
    , b_(b)
    {
    }

    ~Triangle()
    {
    }
    
    float getArea() const override
    {
        return 0.5f * h_ * b_;
    }

private:
    float h_;
    float b_;
};

class Circle : public IShape
{
public:
    Circle()
    : r_(0.0f)
    {
    }

    Circle(float const r)
    : r_(r)
    {
    }

    ~Circle()
    {
    }
    
    float getArea() const override
    {
        return 3.14159f * r_ * r_;
    }

private:
    float r_;
};

float getArea(IShape const& shape)
{
    return shape.getArea();
}

float getArea(IShape const* shape)
{
    return shape->getArea();
}