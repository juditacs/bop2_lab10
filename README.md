# Task 1

Implement the missing functions in `String.cpp` and test your code execution with the debugger.

# Task 2

Implement quicksort as a template function that works on arbitrary types.
Test it on different arrays.
Use at least one built-in type such as int or double and at least one custom type such as Complex, Rational or Vector.
Demonstrate your results via printing (i.e. overload operator<< if necessary).

Example usage:

~~~
int* t[4];
t[0] = new int(1);
t[1] = new int(-1);
t[2] = new int(10);
t[2] = new int(22);
quicksort(t, 4);

for (int i=0; i<4; i++) std::cout << t[i] << " ";

Complex* c[3];
c[0] = new Complex(0, 0);
c[1] = new Complex(1, -4);
c[2] = new Complext(3, 3);
quicksort(c, 3);

for (int i=0; i<3; i++) std::cout << c[i] << " ";
~~~

# How do I use my old quicksort that worked with start and end?

You can wrap it in a new quicksort:

~~~
void quicksort(int** array, int size) {
    old_qsort(array, size, 0, size-1);
}
~~~
