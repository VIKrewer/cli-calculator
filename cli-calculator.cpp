#include <iostream>
#include <cctype>

int main() {
  int x, y;
  float a;
  float b;

  char choose[1];

  std::cout << "******Choose an operation******\n" << std::endl;
  std::cout << "( s = +, l = -, m = *, d = /, p = % )\n";
  std::cin >> choose;
  choose[0] = tolower(choose[0]); 

  if (choose[0] == 's') {
    std::cout << "********Addition selected********\n" << std::endl;
    std::cout << "Enter the first value\n";
    std::cin >> x;

    std::cout << "Enter the second value\n";
    std::cin >> y;

    std::cout << "The result is: " << x + y;
  } else if (choose[0] == 'l') {
    std::cout << "********Subtraction selected********\n" << std::endl;
    std::cout << "Enter the first value\n";
    std::cin >> x;

    std::cout << "Enter the second value\n";
    std::cin >> y;

    std::cout << "The result is: " << x - y;
  } else if (choose[0] == 'm') {
    std::cout << "********Multiplication selected********\n" << std::endl;
    std::cout << "Enter the first value\n";
    std::cin >> x;

    std::cout << "Enter the second value\n";
    std::cin >> y;

    std::cout << "The result is: " << x * y;
  } else if (choose[0] == 'd') {
    std::cout << "********Division selected********\n" << std::endl;
    std::cout << "Enter the dividend\n";
    std::cin >> a;

    std::cout << "Enter the divisor\n";
    std::cin >> b;
    float result = (a) / b;
    std::cout << "The result is: " << result;
  } else if (choose[0] == 'p') {
    std::cout << "********Percentage selected********\n" << std::endl;
    std::cout << "A % B\n\n";
    std::cout << "Enter the \"A\" value\n";
    std::cin >> a;

    std::cout << "Enter the \"B\" value\n";
    std::cin >> b;

    float percentage = b / 100;
    std::cout << a * percentage;
  } else {
    return 0;
  }
}
