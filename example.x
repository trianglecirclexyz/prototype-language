// basic data types are:
// int, float, bool, string

// float function
fn func(bool i, int j): float {
    return i / j;
}

// variable declaration
float float_example = 100 / 2;

// void function
fn func_void() {
    stdout!("this is a formatted string ${float_example}"); // this is a formatted string 50.0
    stdout!("this is a formatted string \${float_example}"); // this is a formatted string ${float_example}
    stdout!("Hello world."); // Hello world.
}

// take input
float x;
stdin!(x); // gets first word of line

// mathematical operations
stdout!(10 * 10); // 100, multiplication
stdout!(10 / 10); // 1, division
stdout!(12 + 2); // 14, addition
stdout!(1 - 10); // -9, subtraction
stdout!(10 ^ 3); // 1000, exponent
stdout!(10 % 3); // 1, modulo

stderr!("This is an error!");

struct struct_example {
    string name;
    int age; 
}

struct_example john(name = "John", age = 73);

// access struct members
stdout!("My name is ${john.name} and i am ${john.age} years old!"); 
    // "My name is John and i am 73 years old!" 
