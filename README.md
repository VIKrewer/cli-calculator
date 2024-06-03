# Simple Calculator

This is a simple command-line calculator program written in C++. It allows users to perform basic arithmetic operations (addition, subtraction, multiplication, division) and calculate percentages.

# Features

- Performs basic arithmetic operations.

- Calculates percentages.

- User-friendly interface with clear instructions.

- Handles case-insensitive input for operation selection (s/S for sum, etc.).

- Includes error checking for division by zero.

**Getting Started**

_Clone && run the program:_
```
git clone https://github.com/VIKrewer/cli-calculator.git
cd cli-calculator
g++ -o3 -o cli-calculator cli-calculator.cpp
./cli-calculator
```

The program will prompt you to choose an operation from the following options:

- ```s (S)```: Addition

- ```l (L)```: Subtraction

- ```m (M)```: Multiplication
  
- ```d (D)```: Division
  
- ```p (P)```: Percentage
After selecting an operation, follow the on-screen instructions to enter the necessary values.

# Example Usage

```

******Choose an operation******

( s = +, l = -, m = *, d = /, p = % )
s

********Addition selected********

Enter the first value
5
Enter the second value
3
The result is: 8
```

Feel free to fork this repository and submit pull requests with improvements or additional features. (Also i would love some advices :D)
