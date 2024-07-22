#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

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
  char selection;
  bool validSelection = false;
  char choose;
  char userUnit;

using std::cin;
using std::cout;
using std::numeric_limits;

void initializeSelection();

void sumCalculus(); // (S)

void subtractionCalculus(); //(L)

void multiplicationCalculus(); // (M)

void divisionCalculus(); // (D)

void percentageCalculus(); // (P)

void circumferenceCalculus(); // (C)

int getTemperature();

void temperatureConversion(); // (T)

void convertToFraction(double num, int &numerator, int &denominator);

void quadraticEquation();


int main() {
  while (true) {
    initializeSelection();

    switch (choose) {
      case 's':
        sumCalculus();
        break; // Break out of the switch, then the while loop

      case 'l':
        subtractionCalculus();
        break; // Break out of the switch, then the while loop

      case 'm':
        multiplicationCalculus();
        break; // Break out of the switch, then the while loop

      case 'd':
        divisionCalculus();
        break; // Break out of the switch, then the while loop

      case 'p':
        percentageCalculus();
        break; // Break out of the switch, then the while loop

      case 'c':
        circumferenceCalculus();
        break; // Break out of the switch, then the while loop

      case 't':
        temperatureConversion();
        break; // Break out of the switch, then the while loop

      case 'q':
        quadraticEquation();
        break; // Break out of the switch, then the while loop

      default:
        system("clear");
        cout << "Invalid choice!\n";
        break; // Break out of the switch, then the while loop
    }

    // Ask the user if they want to continue
    char continueChoice;
    std::cout << "\nDo you want to perform another operation? (y/n): ";
    std::cin >> continueChoice;

    if (tolower(continueChoice) == 'y') {
      system("clear");
    } else {
      break;
    }
  }

  return 0;
}

void initializeSelection(){

  userUnit = tolower(userUnit);

  cout << "******Choose an operation******\n\n";
  cout << "( s = +, l = -, m = *, d = /, p = %, c = Circumference, t = "
          "Temperature Conversion, q = Quadratic Equation )\n";
  cin >> choose;
  choose = tolower(choose);
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void sumCalculus(){
  system("clear");
        cout << "********Addition selected********\n\n";
        cout << "Enter the first value\n";
        cin >> x;

        cout << "Enter the second value\n";
        cin >> y;

        cout << "The result is: " << x + y;
}

void subtractionCalculus(){
  system("clear");
        cout << "********Subtraction selected********\n\n";
        cout << "Enter the first value\n";
        cin >> x;

        cout << "Enter the second value\n";
        cin >> y;

        cout << "The result is: " << x - y;
}

void multiplicationCalculus(){
  system("clear");
        cout << "********Multiplication selected********\n\n";
        cout << "Enter the first value\n";
        cin >> x;

        cout << "Enter the second value\n";
        cin >> y;

        cout << "The result is: " << x * y;
}

void divisionCalculus(){
  system("clear");
        cout << "********Division selected********\n\n";
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
}

void percentageCalculus(){
  system("clear");
        cout << "********Percentage selected********\n\n";
        cout << "A % B\n\n";
        cout << "Enter the \"A\" value\n";
        cin >> a;

        cout << "Enter the \"B\" value\n";
        cin >> b;

        percentage = b / 100;
        cout << a * percentage;
}

void circumferenceCalculus(){
  system("clear");
        cout << "********Circumference selected********\n\n";

        while (!validSelection) {
          cout << "Select the value of PI\n"
               << "(1) 3 --- (2) 3.14 --- (3) 3.14159\n";
          cin >> selection;

          switch (selection) {
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
}

void temperatureConversion(){
  cout << "********Temperature Conversion********\n";
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
}

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

void quadraticEquation() {
    system("clear");
    cout << "********Quadratic equation********\n\n";
    cout << "ax² + bx + c = 0\n\n";

    // Input Validation for A
    while (true) {
        cout << "Enter A value (A cannot be zero) >> ax²\n";
        cin >> a;

        if (std::abs(a) < numeric_limits<double>::epsilon()) {
            cout << "Error: A cannot be zero. Please try again.\n";
        } else {
            break;
        }
    }

    // Input for B and C
    cout << "Enter B value >> bx\n";
    cin >> b;
    cout << "Enter C value >> c\n";
    cin >> c;

    system("clear");

    discriminant = pow(b, 2) - (4 * a * c);

    // Handle Complex Solutions
    if (discriminant < 0) {
        cout << "The equation has complex number solutions.\n";
        return; // Exit the function
    }

    // Calculate Roots
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    // Convert to Fractions
    int num1, den1, num2, den2;
    convertToFraction(x1, num1, den1);
    convertToFraction(x2, num2, den2);

    // Display Results
    cout << "x1 = ";
    if (den1 == 1) {
        cout << num1 << '\n';
    } else {
        cout << num1 << "/" << den1 << '\n';
    }

    cout << "x2 = ";
    if (den2 == 1) {
        cout << num2 << '\n';
    } else {
        cout << num2 << "/" << den2 << '\n';
    }

    while (true) {
        char div;
        cout << "Do you want to divide any of the results? (y/n): ";
        cin >> div;

        switch (tolower(div)) {
            case 'y':
                cout << "Which one of the result do you want to divide?\n";
                cout << "(1) " << num1 << "/" << den1 << " or "
                     << "(2) " << num2 << "/" << den2 << '\n';

                while (true) {
                    cin >> oneortwo;
                    if (oneortwo == 1 || oneortwo == 2) {
                        if (oneortwo == 1) {
                            cout << "The result is: " << (double)num1 / (double)den1 << '\n';
                        } else {
                            cout << "The result is: " << (double)num2 / (double)den2 << '\n';
                        }
                        break;
                    } else {
                        cout << "Invalid selection. Please enter 1 or 2: ";
                    }
                }
                break;

            case 'n':
                cout << "No division will be performed.\n";
                break;

            default:
                cout << "Invalid input. Please enter y or n: ";
        }
        break; // Exit the outer while loop if valid input is given
    }
}
