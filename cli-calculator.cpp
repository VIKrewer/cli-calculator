#include <iostream>
#include <cctype>
#include <limits>
#include <cmath>

using std::cout;
using std::cin;

int getTemperature() {
    double temp;
    while (!(cin >> temp)) {
        cout << "Invalid input. Please enter a temperature: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return temp;
}

int main(){

    int x, y;
    float a;
    float b;
    float percentage;
    float pi;
    double radius;
    double circumference;
    double temp;

    char userUnit;
    userUnit = tolower(userUnit);

    char selection[1];
    bool validSelection = false;

    char choose[1];

    cout << "******Choose an operation******\n" << std::endl;
    cout << "( s = +, l = -, m = *, d = /, p = %, c = Circumference, t = Temperature Conversion )\n";
    cin >> choose;
    choose[0] = tolower(choose[0]);

    switch(choose[0]){
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
                float result = a / b;
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
            
            while(!validSelection){
                cout << "Select the value of PI\n" << "(1) 3 --- (2) 3.14 --- (3) 3.14159\n";
                cin >> selection;

                switch(selection[0]){
                    case '1':{
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
            cout << "Enter unit (F/C): ";
            cin >> userUnit;

            switch(userUnit) {
                case 'f': {
                    temp = getTemperature();
                    cout << "The temperature in Celsius is: " << (temp - 32) * 5 / 9;
                } break;

                case 'c': {
                    temp = getTemperature();
                    cout << "The temperature in Fahrenheit is: " << temp * 1.8 + 32;
                } break;
            }
            break;
            
        default:
            cout << "Invalid choice!\n";
            break;
    }
    return 0;
}
