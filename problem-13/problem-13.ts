import { readFileSync } from 'fs'

const file = readFileSync('./problem-13/numbers.txt', 'utf-8')

const lines = file.split("\n")
const lineLength = lines.at(0)!.length

let carryOver = 0
let result = ""

for (let strIndex = lineLength - 1; strIndex >= 0; strIndex--) {
    let columnSum = carryOver
    for (const line of lines) {
        columnSum += +line[strIndex]!
    }

    // Split between digit and carry over
    const digit = (columnSum % 10).toString()
    carryOver = Math.floor(columnSum / 10)

    // Append to beginning of resulting string
    result = digit + result
}

// Append left over carry over to beginning of the result
result = carryOver.toString() + result

console.log(result.substring(0, 10))