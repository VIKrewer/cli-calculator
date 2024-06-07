#include <iostream>
#include <cctype>

int main() {
  int x, y;
  float a;
  float b;
  float percentage;
  float pi;
  double radius;
  double circumference;

  char choose[1];

  std::cout << "******Choose an operation******\n" << std::endl;
  std::cout << "( s = +, l = -, m = *, d = /, p = %, c = Circumference )\n";
  std::cin >> choose;
  choose[0] = tolower(choose[0]); 

  switch(choose[0]){
    case 's':
      std::cout << "********Addition selected********\n" << std::endl;
      std::cout << "Enter the first value\n";
      std::cin >> x;

      std::cout << "Enter the second value\n";
      std::cin >> y;

      std::cout << "The result is: " << x + y;
    break;

    case 'l':
      std::cout << "********Subtraction selected********\n" << std::endl;
      std::cout << "Enter the first value\n";
      std::cin >> x;

      std::cout << "Enter the second value\n";
      std::cin >> y;

      std::cout << "The result is: " << x - y;
    break;
    
    case 'm':
      std::cout << "********Multiplication selected********\n" << std::endl;
      std::cout << "Enter the first value\n";
      std::cin >> x;

      std::cout << "Enter the second value\n";
      std::cin >> y;

      std::cout << "The result is: " << x * y;
    break;

    case 'd':
    std::cout << "********Division selected********\n" << std::endl;
    std::cout << "Enter the dividend\n";
    std::cin >> a;

    std::cout << "Enter the divisor\n";
    std::cin >> b;
       if (b == 0) {
        std::cout << "Error: Division by zero!\n";
    } else {
        float result = a / b;
        std::cout << "The result is: " << result;
    }
    break;

    case 'p':
    
    std::cout << "********Percentage selected********\n" << std::endl;
    std::cout << "A % B\n\n";
    std::cout << "Enter the \"A\" value\n";
    std::cin >> a;

    std::cout << "Enter the \"B\" value\n";
    std::cin >> b;

    percentage = b / 100;
    std::cout << a * percentage;
    break;

    case 'c':
    std::cout << "********Circumference selected********\n" << std::endl;
    char selection[1];

    std::cout << "Select the value of PI\n" << "(1) 3 --- (2) 3.14 --- (3) 3.14159\n";
    std::cin >> selection;

    switch(selection[0]){
        case '1':
            pi = 3;
            break;

        case '2':
            pi = 3.14;
            break;

        case '3':
            pi = 3.14159;
            break;
        default:
            std::cout << "Invalid, select (1), (2) or (3).\n";
    }

    std::cout << "Set the value of Radius\n";
    std::cin >> radius;

    circumference = 2 * pi * radius;
    std::cout << "The result of the circumference is: " << circumference;
    break;
  }
  return 0;
}
