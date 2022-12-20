from numpy import array, diag, diagflat, dot, append, zeros
import sys

def seidel(a, b, x):
    for j in range(0, len(a)):
        d = b[j]
        for i in range(0, len(a)):
            if j != i:
                d -= a[j][i] * x[i]
        x[j] = d / a[j][j]

    return x

def cholesky(matrix_a, matrix_b, solution_array, n=4):
    matrix_a = append(matrix_a, matrix_b, axis=1)
    for i in range(n):
        if matrix_a[i][i] == 0.0:
            sys.exit('Eroare! Divizare cu 0')
        for j in range(i + 1, n):
            ratio = matrix_a[j][i] / matrix_a[i][i]
            for k in range(n + 1):
                matrix_a[j][k] = matrix_a[j][k] - ratio * matrix_a[i][k]

    solution_array[n - 1] = matrix_a[n - 1][n] / matrix_a[n - 1][n - 1]

    for i in range(n - 2, -1, -1):
        solution_array[i] = matrix_a[i][n]
        for j in range(i + 1, n):
            solution_array[i] = solution_array[i] - matrix_a[i][j] * solution_array[j]
        solution_array[i] = solution_array[i] / matrix_a[i][i]

    return solution_array

def jacobi(a, b, x, n=3):
    d = diag(a)
    r = a - diagflat(d)

    for i in range(n):
        x = (b - dot(r, x)) / d

    return x

def menu(array_a, array_b, solution):
    print("********* Alegeti metoda *********")
    print('matricea A \n', array_a)
    print('matricea B \n', array_b)
    while True:
        print('\n1.Gauss-Seidel\n'
              '2.Jacobi\n'
              '3.Cholesky\n')
        method = int(input('Numarul metodei: '))
        match method:
            case 1:
                for i in range(0, 5):
                    solution = seidel(array_a, array_b, solution)
                print('metoda Gauss-Seidel')
                print(solution, '\n')
            case 2:
                sol = jacobi(array_a, array_b, solution)
                print('Metoda Jacobi')
                print(sol, '\n')
            case 3:
                cahnged_matrix_b = array([[9.2], [8.7], [-10.6], [9.7]])
                sol = cholesky(array_a, cahnged_matrix_b, initial_solutions)
                print('Metoda Cholesky')
                print(sol, '\n')
            case __:
                break

initial_solutions = [0, 0, 0, 0]

matrix_A = array([[15.1, -0.9, 1.2, 0.4],[-0.9, 14.6, 0.8, 0.7],[1.2, 0.8, 17.6, -0.6],[0.4, 0.7, -0.6, 21.3]])

matrix_B= array([9.2, 8.7, -10.6, 9.7])
      

menu(matrix_A, matrix_B, initial_solutions)
