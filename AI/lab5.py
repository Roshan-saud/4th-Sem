'''
Title: Implementation of N queen problem as CSP (Domain, Variables and constraints)
Objective: To implement N queen problem using backtracking
'''

#function for printing the solution
def print_solution(board):
    n= len(board)
    for row in range(n):
        for col in range(n):
            print("Q" if board[row]== col else ".", end= "")
        print("\n "+ "=" * (3*n) + "\n") #==============
#check if queen attack each other
def is_safe(board, row, col):
    #check for row, column and diagonal conflict
    for r in range(row):
        if board[r]== col or abs(board[r]-col)==abs(r-row):
            return False
    return True
#Place the queens backtracking
def solve_n_queen(board, row,n,solution):
    #place queen row by row backtrack if the position is not safe
    if row == n:
        solution.append(board[:])  #[:]= array slicing to save the solution
        return 
    for col in range(n):
        if is_safe(board,row,col):
            board[row] = col
            solve_n_queen(board,row+1,n,solution)
            board[row]= -1 #barcktrack
#main function
def n_queens(n):
    board =[-1]*n #-1 represents there is no queen
    solution= []
    solve_n_queen(board,0,n,solution)
    return solution
if __name__ == "__main__":
    N = 4
    print(f"\n Solving {N} Queen problem \n")
    result = n_queens(N)
    print(f"Total soltuion found: {len(result)}\n")
    for i, sol in enumerate(result, 1):
        print(f"Solution{i}:")
        print_solution(sol)

