// Fibonacci Sequence Generator

const readlineSync = require('readline-sync');

function printFibonacciTerms(n) {
  const sequence = [];
  let first = 0;
  let second = 1;

  for (let i = 0; i < n; i++) {
    sequence.push(first);
    const next = first + second;
    first = second;
    second = next;
  }

  console.log("Fibonacci sequence: " + sequence.join(" "));
}

function isFibonacciNumber(num) {
  let first = 0;
  let second = 1;

  if (num === 0 || num === 1) {
    return true;
  }

  while (first <= num) {
    if (first === num) {
      return true;
    }
    const next = first + second;
    first = second;
    second = next;
  }

  return false;
}

function main() {
  // ---------- PART A: Print the First N Terms ----------
  const n = readlineSync.questionInt("How many terms? ");

  if (n <= 0) {
    console.log("Error: Please enter a positive number.");
    return;
  }

  printFibonacciTerms(n);

  // ---------- PART B: Check if a Number Belongs to the Sequence ----------
  const num = readlineSync.questionInt("Enter a number to check: ");

  if (isFibonacciNumber(num)) {
    console.log(num + " is a Fibonacci number.");
  } else {
    console.log(num + " is NOT a Fibonacci number.");
  }
}

main();