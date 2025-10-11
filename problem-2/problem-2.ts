let a = 1
let b = 2
let sum = 0

while (b < 4000000) {
    // If even, then add fibonacci term to sum
    if (b % 2 == 0) {
        sum += b
    }

    // Update fibonacci terms
    let c = a + b
    a = b
    b = c
}

console.log(sum)