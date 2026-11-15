#include <iostream>

#include <algorithm>

int recursive_gcd(int a, int b);

int iterative_gcd(int a, int b);

int swap_gcd(int a, int b);

int main(){
    //recursive_gcd(48,18);
    //iterative_gcd(48,18);
    swap_gcd(48,18);
}

int recursive_gcd(int a, int b){
    while(true){
    if (b==0){
        std::cout << "greatest common divisor of a and b is " << a << std::endl;
        return a;
    }
    else{
        std::cout << a << " divided by " << b  << " give modulus " << a%b << std::endl;
        return recursive_gcd(b, a% b);
    }}
};


int iterative_gcd(int a, int b){
    int temp = 0;
    while(b != 0){
        std::cout << a << " divided by " << b  << " give modulus " << a%b << std::endl;
        temp = a;
        a = b;
        b = temp % b;
    }
    std::cout << "greatest common divisor of a and b is " << a << std::endl;
    return a;
};

int swap_gcd(int a, int b){
    while(b != 0){
        std::cout << a << " divided by " << b  << " give modulus " << a%b << std::endl;
        a = a%b;
        std::swap(a,b);
    }
    std::cout << "greatest common divisor of a and b is " << a << std::endl;
    return a;
};