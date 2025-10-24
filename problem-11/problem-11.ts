import { readFileSync } from 'fs'

const file = readFileSync('./problem-11/numbers.txt', 'utf-8')

const lines = file.split("\n")

const matrix = []

// Fill matrix with values
for (const line of lines) {
    const numbers = line.split(" ");
    const row = []
    for (const number of numbers) {
        row.push(parseInt(number))
    }

    matrix.push(row)
}

const SIZE = 20;
const DISPLACE_SIZE = 3;
const TRAVERSE_SIZE = SIZE - DISPLACE_SIZE;

let maxProduct = 0;

for (let r = 0; r < SIZE; r++) {
    for (let c = 0; c < SIZE; c++) {
        if (c < TRAVERSE_SIZE) {
            const horizontalProduct = matrix[r]![c]! * matrix[r]![c+1]! * matrix[r]![c+2]! * matrix[r]![c+3]!
            if (horizontalProduct > maxProduct) {
                maxProduct = horizontalProduct
            }
        }

        if (r < TRAVERSE_SIZE) {
            const verticalProduct = matrix[r]![c]! * matrix[r+1]![c]! * matrix[r+2]![c]! * matrix[r+3]![c]!
            if (verticalProduct > maxProduct) {
                maxProduct = verticalProduct
            }
        }

        if (c < TRAVERSE_SIZE && r < TRAVERSE_SIZE) {
            const diagonalProduct = matrix[r]![c]! * matrix[r+1]![c+1]! * matrix[r+2]![c+2]! * matrix[r+3]![c+3]!
            if (diagonalProduct > maxProduct) {
                maxProduct = diagonalProduct
            }
        }

        if (c >= DISPLACE_SIZE && r < TRAVERSE_SIZE) {
            const diagonalProduct = matrix[r]![c]! * matrix[r+1]![c-1]! * matrix[r+2]![c-2]! * matrix[r+3]![c-3]!
            if (diagonalProduct > maxProduct) {
                maxProduct = diagonalProduct
            }
        }
    }
}

console.log(maxProduct)