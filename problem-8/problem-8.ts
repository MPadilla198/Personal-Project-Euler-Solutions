import { readFileSync } from 'fs'

const file = readFileSync('./problem-8/sequence.txt', 'utf-8')

// Split on 0 because any segment with a 0 cannot be the largest
const sequences = file.split("0")

let maxProduct = 0

for (const sequence of sequences) {
    // Skip string segments with length less than 13
    if (sequence.length < 13)
        continue

    let product = 1
    let baseIndex = 0
    let index = 0
    for (const char of sequence) {
        // Convert character to numerical value
        let digit = parseInt(char)

        if (index < 13) {
            product *= digit

            if (index != 12) {
                index++
                //Do not check product against max product
                continue
            }
        } else {
            const baseDigit = parseInt(sequence[baseIndex]!)
            // Remove base from product
            product /= baseDigit

            product *= digit
            baseIndex++
        }

        if (maxProduct < product)
            maxProduct = product

        index++
    }
}

console.log(maxProduct)