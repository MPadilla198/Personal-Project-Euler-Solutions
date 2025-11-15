import sys

### LOAD 2D MATRIX ###
file_path = "problem-13/numbers.txt"

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
lineLength = len(lines[0])
numOfLines = len(lines)

carryOver = 0
result = ""

for strIndex in range(lineLength - 1, -1, -1):
    columnSum = carryOver
    for line in lines:
        columnSum += int(line[strIndex])

    # Split between digit and carry over
    digit = str(columnSum % 10)
    carryOver = columnSum // 10

    # Append to beginning of resulting string
    result = digit + result

# Append left over carry over to beginning of the result
result = str(carryOver) + result

print(result[:10])
