import sys

### LOAD 2D MATRIX ###
file_path = "problem-11/numbers.txt"

try:
    with open(file_path, "r") as file:
        file_content = file.read()
except FileNotFoundError:
    print(f"Error: The file '{file_path}' was not found.")
    sys.exit()
except Exception as e:
    print(f"An error occurred: {e}")
    sys.exit()

lines = file_content.splitlines()

matrix = []
for line in lines:
    matrix.append([int(digit) for digit in line.split(" ")])

### CONSTANTS ###
SIZE = 20
DISPLACE_SIZE = 3  # We are calculating the 4 adjacent numbers, so TRAVERSE_SIZE reflects the bounds of this traversal
TRAVERSE_SIZE = SIZE - DISPLACE_SIZE

### CALCULATE MAX PRODUCT ###
maxProduct = 0

for row in range(SIZE):
    for col in range(SIZE):
        if col < TRAVERSE_SIZE:
            horizontalProduct = matrix[row][col] * matrix[row][col+1] * matrix[row][col+2] * matrix[row][col+3]
            if horizontalProduct > maxProduct:
                maxProduct = horizontalProduct
        
        if row < TRAVERSE_SIZE:
            verticalProduct = matrix[row][col] * matrix[row+1][col] * matrix[row+2][col] * matrix[row+3][col]
            if verticalProduct > maxProduct:
                maxProduct = verticalProduct

        if col < TRAVERSE_SIZE and row < TRAVERSE_SIZE:
            diagonalProduct = matrix[row][col] * matrix[row+1][col+1] * matrix[row+2][col+2] * matrix[row+3][col+3]
            if diagonalProduct > maxProduct:
                maxProduct = diagonalProduct

        if col >= DISPLACE_SIZE and row < TRAVERSE_SIZE:
            diagonalProduct = matrix[row][col] * matrix[row+1][col-1] * matrix[row+2][col-2] * matrix[row+3][col-3]
            if diagonalProduct > maxProduct:
                maxProduct = diagonalProduct

print(maxProduct)
