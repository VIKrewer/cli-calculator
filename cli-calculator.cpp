#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;

void convertToFraction(double num, int &numerator, int &denominator) {
  const double tolerance = 1e-9;
  double intpart;

  if (modf(num, &intpart) == 0.0) {
    numerator = static_cast<int>(intpart);
    denominator = 1;
    return;
  }

  double fracpart = num - intpart;
  denominator = 1;

  while (fabs(fracpart * denominator - round(fracpart * denominator)) >
         tolerance) {
    denominator++;
  }

  numerator =
      static_cast<int>(round(fracpart * denominator) + intpart * denominator);
  int gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
}

int getTemperature() {
  double temp;
  cout << "Enter the Temperature: ";
  while (!(cin >> temp)) {
    cout << "Invalid input. Please enter a temperature: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return temp;
}

int main() {

  int x, y;
  double a, b, c;
  double percentage;
  double pi;
  double radius;
  double circumference;
  double temp;
  double x1, x2;
  double discriminant;
  int oneortwo;

  char userUnit;
  userUnit = tolower(userUnit);

  char selection[1];
  bool validSelection = false;

  char choose[1];

  cout << "******Choose an operation******\n" << std::endl;
  cout << "( s = +, l = -, m = *, d = /, p = %, c = Circumference, t = "
          "Temperature Conversion, q = Quadratic Equation )\n";
  cin >> choose;
  choose[0] = tolower(choose[0]);

  switch (choose[0]) {
  case 's':
    system("clear");
    cout << "********Addition selected********\n" << std::endl;
    cout << "Enter the first value\n";
    cin >> x;

    cout << "Enter the second value\n";
    cin >> y;

    cout << "The result is: " << x + y;
    break;

  case 'l':
    system("clear");
    cout << "********Subtraction selected********\n" << std::endl;
    cout << "Enter the first value\n";
    cin >> x;

    cout << "Enter the second value\n";
    cin >> y;

    cout << "The result is: " << x - y;
    break;

  case 'm':
    system("clear");
    cout << "********Multiplication selected********\n" << std::endl;
    cout << "Enter the first value\n";
    cin >> x;

    cout << "Enter the second value\n";
    cin >> y;

    cout << "The result is: " << x * y;
    break;

  case 'd':
    system("clear");
    cout << "********Division selected********\n" << std::endl;
    cout << "Enter the dividend\n";
    cin >> a;

    cout << "Enter the divisor\n";
    cin >> b;
    if (b == 0) {
      cout << "Error: Division by zero!\n";
    } else {
      double result = a / b;
      cout << "The result is: " << result;
    }
    break;

  case 'p':
    system("clear");
    cout << "********Percentage selected********\n" << std::endl;
    cout << "A % B\n\n";
    cout << "Enter the \"A\" value\n";
    cin >> a;

    cout << "Enter the \"B\" value\n";
    cin >> b;

    percentage = b / 100;
    cout << a * percentage;
    break;

  case 'c':
    system("clear");
    cout << "********Circumference selected********\n" << std::endl;

    while (!validSelection) {
      cout << "Select the value of PI\n"
           << "(1) 3 --- (2) 3.14 --- (3) 3.14159\n";
      cin >> selection;

      switch (selection[0]) {
      case '1': {
        pi = 3;
        validSelection = true;
      } break;

      case '2': {
        pi = 3.14;
        validSelection = true;
      } break;

      case '3': {
        pi = 3.14159;
        validSelection = true;
      } break;

      default:
        system("clear");
        cout << "Invalid, select (1), (2) or (3).\n\n";
      }
    }
    cout << "Set the value of Radius\n";
    cin >> radius;

    circumference = 2 * pi * radius;
    cout << "The result of the circumference is: " << circumference;
    break;

  case 't':
    cout << "********Temperature Conversion********" << std::endl;
    cout << "Enter unit (F°/C°): ";
    cin >> userUnit;

    switch (userUnit) {
    case 'f': {
      temp = getTemperature();
      cout << "The temperature in Celsius is: " << (temp - 32) * 5 / 9 << "C°";
    } break;

    case 'c': {
      temp = getTemperature();
      cout << "The temperature in Fahrenheit is: " << temp * 1.8 + 32 << "F°";
    } break;
    }
    break;

    case 'q':

      system("clear");
      cout << "********Quadratic equation********\n" << endl;
      cout << "ax² + bx + c = 0\n\n";
      cout << "Enter A value (A cannot be zero) >> ax²\n";
      cin >> a;

      if (abs(a) < numeric_limits<double>::epsilon()) {
        cout << "Error: A cannot be zero." << endl;
        return 1;
      }

      cout << "Enter B value >> bx\n";
      cin >> b;

      cout << "Enter C value >> c\n";
      cin >> c;
      system("clear");

      discriminant = pow(b, 2) - (4 * a * c);

      if (discriminant < 0) {
        cout << "The equation has complex number solutions." << endl;
        return 1;
      }

      x1 = (-b + sqrt(discriminant)) / (2 * a);
      x2 = (-b - sqrt(discriminant)) / (2 * a);

      int num1, den1, num2, den2;
      convertToFraction(x1, num1, den1);
      convertToFraction(x2, num2, den2);

      if (den1 == 1) {
        cout << "x1 = " << num1 << endl;
      } else {
        cout << "x1 = " << num1 << "/" << den1 << endl;
      }

      if (den2 == 1) {
        cout << "x2 = " << num2 << endl;
      } else {
        cout << "x2 = " << num2 << "/" << den2 << endl;
      }

      char div;
      cout << "Do you want to divide any of the results? (y) or (n)";
      cin >> div;

      switch (div) {
      case 'y':
        cout << "Which one of the result do you want to divide\n";
        cout << "(1) " << num1 << "/" << den1 << " or "
            << "(2) " << num2 << "/" << den2 << endl;

        cin >> oneortwo;
        switch (oneortwo) {
        case 1:
          cout << "The result is: " << (double)num1 / (double)den1;
          break;

        case 2:
          cout << "The result is: " << (double)num2 / (double)den2;
          break;

        default:
          cout << "Select (1) or (2)!";
      break;
    }
  }

    break;

  default:
    cout << "Invalid choice!\n";
    break;
  }
  return 0;
}
