#include <iostream>
#include<math.h>
using namespace std;

class Polynomial {
public:
    int degree;
    double* coeff;
    Polynomial(int degree, double* coeff);
    Polynomial(const Polynomial& p);
    ~Polynomial();
    Polynomial operator+(const Polynomial& p);
    Polynomial operator-(const Polynomial& p);
    Polynomial operator*(const Polynomial& p);
    double evaluate(double x);
};

Polynomial::Polynomial(int degree, double* coeff) {
    this->degree = degree;
    this->coeff = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        this->coeff[i] = coeff[i];
    }
}

Polynomial::Polynomial(const Polynomial& p) {
    degree = p.degree;
    coeff = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coeff[i] = p.coeff[i];
    }
}

Polynomial::~Polynomial() {
    delete[] coeff;
}

Polynomial Polynomial::operator+(const Polynomial& p) {
    int maxDegree = max(degree, p.degree);
    double* resultCoeff = new double[maxDegree + 1];

    for (int i = 0; i <= maxDegree; i++) {
        double coeff1 = (i <= degree) ? coeff[i] : 0;
        double coeff2 = (i <= p.degree) ? p.coeff[i] : 0;
        resultCoeff[i] = coeff1 + coeff2;
    }

    Polynomial result(maxDegree, resultCoeff);
    delete[] resultCoeff;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& p) {
    int maxDegree = max(degree, p.degree);
    double* resultCoeff = new double[maxDegree + 1];

    for (int i = 0; i <= maxDegree; i++) {
        double coeff1 = (i <= degree) ? coeff[i] : 0;
        double coeff2 = (i <= p.degree) ? p.coeff[i] : 0;
        resultCoeff[i] = coeff1 - coeff2;
    }

    Polynomial result(maxDegree, resultCoeff);
    delete[] resultCoeff;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& p) {
    int resultDegree = degree + p.degree;
    double* resultCoeff = new double[resultDegree + 1];

    for (int i = 0; i <= resultDegree; i++) {
        resultCoeff[i] = 0;
        for (int j = 0; j <= degree; j++) {
            if (i - j >= 0 && i - j <= p.degree) {
                resultCoeff[i] += coeff[j] * p.coeff[i - j];
            }
        }
    }

    Polynomial result(resultDegree, resultCoeff);
    delete[] resultCoeff;
    return result;
}

double Polynomial::evaluate(double x) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coeff[i] * pow(x, i);
    }
    return result;
}

int main() {
    // Example usage
    double coeff1[] = {1, 2, 3}; // 1 + 2x + 3x^2
    double coeff2[] = {2, 3};    // 2 + 3x
    Polynomial poly1(2, coeff1);
    Polynomial poly2(1, coeff2);

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial product = poly1 * poly2;

    cout << "Sum: ";
    // Output sum
    for (int i = 0; i <= sum.degree; i++) {
        cout << sum.coeff[i] << "x^" << i;
        if (i != sum.degree) cout << " + ";
    }
    cout << endl;

    cout << "Difference: ";
    // Output difference
    for (int i = 0; i <= diff.degree; i++) {
        cout << diff.coeff[i] << "x^" << i;
        if (i != diff.degree) cout << " + ";
    }
    cout << endl;

    cout << "Product: ";
    // Output product
    for (int i = 0; i <= product.degree; i++) {
        cout << product.coeff[i] << "x^" << i;
        if (i != product.degree) cout << " + ";
    }
    cout << endl;

    // Evaluation example
    cout << "Evaluation of poly1 at x=2: " << poly2.evaluate(0) << endl;

    return 0;
}
