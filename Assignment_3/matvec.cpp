#include <iostream>
#include <vector>


void print_vector(const std::vector <int> &vec);

void print_matrix(const std::vector<std::vector<int>> &A);

void print_vector(const std::vector <double> &vec);

void print_matrix(const std::vector<std::vector<double>> &A);

std::vector<int> multiply_matrix_vector(const std::vector<std::vector<int>> &A, const std::vector<int> &vec);

std::vector<double> multiply_matrix_vector(const std::vector<std::vector<double>> &A, const std::vector<double> &vec);

std::vector<double> operator*(const std::vector<std::vector<double>> &A, const std::vector<double> &vec);

std::vector<int> operator*(const std::vector<std::vector<int>> &A, const std::vector<int> &vec);

bool test_matrix_vector_product();

int main(){
        std::vector <double> vec;
        double element;    
        std::cout << "Give vector elements in a row then press x: " << std::endl;
        while(std::cin >> element){
          vec.push_back(element);
        }
        std::cin.clear();
        std::cin.ignore();

        int N = vec.size();
        std::vector<std::vector<double>> A(N, std::vector<double>(N));
        std::cout << "Give a square " << N << " by " << N << " matrix elements - row first:" << std::endl;
        for (int i = 0; i < N; ++i){
          std::cout << "Row " << i << " of matrix A is: " << std::endl;
          for (int j = 0; j<N; ++j){
           std::cin >> element;
           A[i][j] = element;
          }
        }

        test_matrix_vector_product();
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