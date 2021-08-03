
class Vector_2d {
private:
    double x, y;
public:

    Vector_2d(double arg_x = 0, double arg_y = 0) {
        x = arg_x;
        y = arg_y;
    }

    const Vector_2d operator+(const Vector_2d &op);

    void print(const char *inhalt) const;

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    friend const Vector_2d operator*(double a, const Vector_2d &op);

    const Vector_2d operator*(double a) const;

    const Vector_2d &operator+=(const Vector_2d &op);

    const Vector_2d &operator=(const Vector_2d &op);

    const Vector_2d operator-(const Vector_2d &op) const {
        return Vector_2d(x - op.x, y - op.y);
    }

    const Vector_2d &operator++();

    const Vector_2d operator++(int);

    friend istream &operator>>(istream &is, Vector_2d &op);

    friend ostream &operator<<(ostream &os, const Vector_2d &op);

};

istream &operator>>(istream &is, Vector_2d &op) {
    is >> op.x >> op.y;
    return is;
}
const Vector_2d &Vector_2d::operator++() {
    x = x + 1.;
    y = y + 1.;
    return *this;
}

ostream &operator<<(ostream &os, const Vector_2d &op) {
    os << "(" << op.x << "," << op.y << ")";
    return os;
}

const Vector_2d Vector_2d::operator++(int) {
    Vector_2d tmp(x, y);
    x = x + 1.;
    y = y + 1.;
    return tmp;
}

const Vector_2d operator*(double a, const Vector_2d &op) {
    return Vector_2d(a * op.x, a * op.y);
}

const Vector_2d Vector_2d::operator*(double a) const {
    return Vector_2d(x * a, y * a);
}

const Vector_2d &Vector_2d::operator+=(const Vector_2d &op) {
    x = x + op.x;
    y = y + op.y;
    return *this;
}


const Vector_2d Vector_2d::operator+(const Vector_2d &op) {
    Vector_2d tmp;
    tmp.x = x + op.x;
    tmp.y = y + op.y;
    return tmp;
}
void Vector_2d::print(const char *inhalt = 0) const {
    if (inhalt){
        cout << inhalt<< " = ";
    }
    cout << "(" << x << "," << y << ")" << endl;
}

const Vector_2d &Vector_2d::operator=(const Vector_2d &op) {
    x = op.x;
    y = op.y;
    return *this;
}
