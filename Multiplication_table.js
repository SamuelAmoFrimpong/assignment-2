// Multiplication Table Generator

const readlineSync = require('readline-sync');

function printSingleTable(num) {
  console.log("Multiplication Table for " + num + ":");

  for (let i = 1; i <= 12; i++) {
    console.log(num + "  x  " + i + "  =  " + (num * i));
  }
}

function printTablesUpToN(n) {
  for (let num = 1; num <= n; num++) {
    printSingleTable(num);
    console.log("---------------------------");
  }
}

function main() {
  // ---------- PART A: Single Table ----------
  const num = readlineSync.questionInt("Enter a number: ");

  console.log("");
  printSingleTable(num);

  // ---------- PART B: Tables from 1 to N ----------
  const n = readlineSync.questionInt("\nEnter N to print tables from 1 to N: ");

  if (n <= 0) {
    console.log("Error: Please enter a positive number.");
    return;
  }

  console.log("");
  printTablesUpToN(n);
}

main();