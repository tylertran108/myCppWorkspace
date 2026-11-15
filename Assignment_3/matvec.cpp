#include <iostream>
#include <vector>

// Function to print a vector of integers
void print_vector(const std::vector <int> &vec);

// Function to print a matrix of integers
void print_matrix(const std::vector<std::vector<int>> &A);

// Overloaded function to print a vector of doubles
void print_vector(const std::vector <double> &vec);

// Overloaded function to print a matrix of doubles
void print_matrix(const std::vector<std::vector<double>> &A);

// Function to multiply a matrix of integers with a vector of integers
std::vector<int> multiply_matrix_vector(const std::vector<std::vector<int>> &A, const std::vector<int> &vec);

//  Function to multiply a matrix of doubles with a vector of doubles
std::vector<double> multiply_matrix_vector(const std::vector<std::vector<double>> &A, const std::vector<double> &vec);

// Operator function to multiply a matrix of doubles with a vector of doubles
std::vector<double> operator*(const std::vector<std::vector<double>> &A, const std::vector<double> &vec);

// Overloaded operator function to multiply a matrix of integers with a vector of integers
std::vector<int> operator*(const std::vector<std::vector<int>> &A, const std::vector<int> &vec);

// Function to test the matrix-vector product implementation
bool test_matrix_vector_product();

int main(){
        //declare a vector of doubles and read its elements from user input
        std::vector <double> vec;
        double element;    
        std::cout << "Give vector elements in a row then press x: " << std::endl;
        while(std::cin >> element){
          vec.push_back(element);
        }
        std::cin.clear(); // clear the error state caused by non-numeric input
        std::cin.ignore(); // ignore the rest of the line after the non-numeric input

        int N = vec.size(); // size of the vector is used to determine the size of the square matrix
        //declare a square matrix of doubles and read its elements from user input
        std::vector<std::vector<double>> A(N, std::vector<double>(N));
        std::cout << "Give a square " << N << " by " << N << " matrix elements - row first:" << std::endl;
        // Read the elements of the matrix from user input
        for (int i = 0; i < N; ++i){
          std::cout << "Row " << i << " of matrix A is: " << std::endl;
          for (int j = 0; j<N; ++j){
           std::cin >> element;
           A[i][j] = element;
          }
        }

        // Test the operator* function
        test_matrix_vector_product();

        // Perform matrix-vector multiplication
        const std::vector<double> result = A * vec;
        std::cout << "Result of matrix vector multiplication is: " << std::endl;
        print_vector(result);
        return 0;
}

void print_vector(const std::vector <int> &vec){
    std::cout << "[ ";
    for (const auto &element : vec){
        std::cout << element << " ";
        }
    std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<int>> &A){
  std::cout << "[ " << std::endl;
  for (const auto &row : A){
    for (const auto &element :row){
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "]" << std::endl;
}

void print_vector(const std::vector <double> &vec){
    std::cout << "[ ";
    for (const auto &element : vec){
        std::cout << element << " ";
        }
    std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<double>> &A){
  std::cout << "[ " << std::endl;
  for (const auto &row : A){
    for (const auto &element :row){
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "]" << std::endl;
}

std::vector<int> multiply_matrix_vector(const std::vector<std::vector<int>> &A, const std::vector<int> &vec){
  int N = vec.size();
  std::vector<int> result(N, 0);
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      result[i] = result[i] + A[i][j] * vec[j];
    }
  }

  return result;
}

std::vector<double> multiply_matrix_vector(const std::vector<std::vector<double>> &A, const std::vector<double> &vec){
  int N = vec.size();
  std::vector<double> result(N, 0);
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      result[i] = result[i] + A[i][j] * vec[j];
    }
  }

  return result;
}

std::vector<double> operator*(const std::vector<std::vector<double>> &A, const std::vector<double> &vec){
  return multiply_matrix_vector(A, vec);
}

std::vector<int> operator*(const std::vector<std::vector<int>> &A, const std::vector<int> &vec){
  return multiply_matrix_vector(A, vec);
}


bool test_matrix_vector_product(){
  std::vector<double> v_test = {1.0, 2.0, 3.0};
  std::vector<std::vector<double>> A_test = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  std::vector<double> result1 = operator*(A_test, v_test);
  std::vector<double> result2 = {14.00, 32.00, 50.00};
  if (result1 == result2){
    std::cout << "Matrix vector product test passed!" << std::endl;
    return true;
  }
  else{
    std::cout << "Matrix vector product test failed!" << std::endl;
    return false;
  }
};