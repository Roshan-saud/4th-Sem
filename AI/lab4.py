'''
lab 4:
Game Search usinh MiniMax Algorithm

Objective:

- To implement minimax algorithm for  two player game in Tic - Tac -Toe
- To implement the concept of adversible search and decision making


Algorithm:

1) define reversible function
         minimax(board,depth,isMaximizing)

2) If game is over then we need to return score(wn,lose, draw)

3) if Maximizera turn:
         Initialize best score to - infinity
         For each possible move:
         call the minimax recursively with ismaximizing = False
         Undo the move 
         update the best score with maximum value
4) If minimizer turn:
        Initalize best score  to - infinity
        for each possible move:
        call the minimax recursively with isMaximizing = True
        Undo the move
        update the best score with minimum value
5) Return the best score
6) The best score is returned on the basis of highest minimax score


'''

import math

# initalaize the board
board = [" " for _ in range(9)]

# print the board
def print_board():
    for i in range(3):
        row = board[i*3:(i+1)*3]
        print("| " + " | ".join(row) + " |")


print_board()


# Check Winner
def check_winner(brd):
    # set condition for win
    win_combinations = [
        # row
        [0,1,2],
        [3,4,5],
        [6,7,8],
        # column
        [0,3,6],
        [1,4,7],
        [2,5,8],
        # diagonal
        [0,4,8],
        [2,4,6],
    ]
    
    # For win
    for combo in win_combinations:
        if brd[combo[0]] == brd[combo[1]] == brd[combo[2]] and brd[combo[0]] != " ":
            return brd[combo[0]]
    return None


# for draw
def isDraw(brd):
    return " " not in brd

# Implement the minimizer and maximizer
def minimax(brd, depth, isMaximizing):
    winner = check_winner(brd)
    
    if winner == "0":  # AI wins
        return 1
    elif winner == "x":  # Human Wins
        return -1
    elif isDraw(brd):
        return 0
    
    if isMaximizing:
        bestScore = -math.inf
        for i in range(9):
            if brd[i] == " ":
                brd[i] = "0"
                score = minimax(brd, depth + 1, False)
                brd[i] = " "
                bestScore = max(score, bestScore)
        return bestScore
    
    else:
        bestScore = math.inf
        for i in range(9):
            if brd[i] == " ":
                brd[i] = "x"
                score = minimax(brd, depth + 1, True)
                brd[i] = " "
                bestScore = min(score, bestScore)
        return bestScore


# AI choose the best move
def best_move(brd):
    bestScore = -math.inf
    move = None
    for i in range(9):
        if brd[i] == " ":
            brd[i] = "0"
            score = minimax(brd, 0, False)
            brd[i] = " "
            if score > bestScore:
                bestScore = score
                move = i
    board[move] = "0"


# main game play
def play_game():
    print("TIC TAC TOE ( you are 'x', AI is '0')\n")
    print_board()

    while True:

        # --- Human turn ---
        while True:
            try:
                pos = int(input("\nEnter position (0-8): "))
                if pos < 0 or pos > 8 or board[pos] != " ":
                    print("Invalid move. Try again.")
                else:
                    break
            except:
                print("Enter a number 1-9 only.")

        board[pos] = "x"
        print_board()

        # Check human win
        if check_winner(board) == "x":
            print("You win!")
            break
        if isDraw(board):
            print("It's a draw!")
            break

        # --- AI turn ---
        best_move(board)
        print("\nAI move:")
        print_board()

        # Check AI win
        if check_winner(board) == "0":
            print("AI wins!")
            break
        if isDraw(board):
            print("It's a draw!")
            break


# Run the game
play_game()
