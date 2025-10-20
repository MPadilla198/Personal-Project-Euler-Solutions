import sys 

file_path = "problem-8/sequence.txt"

try:
    with open(file_path, 'r') as file:
        file_content = file.read()
except FileNotFoundError:
    print(f"Error: The file '{file_path}' was not found.")
    sys.exit()
except Exception as e:
    print(f"An error occurred: {e}")
    sys.exit()

# Split on 0 because any segment with a 0 cannot be the largest
segments = file_content.split('0')

maxProduct = 0

for segment in segments:
    # Skip string segments with length less than 13
    if len(segment) < 13:
        continue

    product = 1
    baseIndex = 0
    index = 0
    for char in segment:
        # Convert character to numerical value
        digit = int(char)

        if index < 13:
            product *= digit
            if index != 12:
                index += 1
                # Do not check product against max product
                continue
        else:
            # Remove base from 
            product //= int(segment[baseIndex])

            product *= digit
            baseIndex += 1

        if maxProduct < product:
            maxProduct = product
        
        index += 1

print(maxProduct)