// Console-Based Simple Calculator

const readlineSync = require('readline-sync');

function add(a, b) {
  return a + b;
}

function subtract(a, b) {
  return a - b;
}

function multiply(a, b) {
  return a * b;
}

function divide(a, b) {
  if (b === 0) {
    return null;
  }
  return a / b;
}

function modulus(a, b) {
  return a % b;
}

function power(a, b) {
  return a ** b;
}

function showMenu() {
  console.log("");
  console.log("============================");
  console.log("     SIMPLE CALCULATOR");
  console.log("============================");
  console.log("1. Addition");
  console.log("2. Subtraction");
  console.log("3. Multiplication");
  console.log("4. Division");
  console.log("5. Modulus");
  console.log("6. Exponentiation");
  console.log("7. Quit");
}

function main() {
  let running = true;

  while (running) {
    showMenu();
    const choice = readlineSync.questionInt("Select an operation (1-7): ");

    if (choice === 7) {
      console.log("Goodbye!");
      running = false;
      continue;
    }

    if (choice < 1 || choice > 7) {
      console.log("Error: Please enter a number between 1 and 7.");
      continue;
    }

    const num1 = readlineSync.questionFloat("Enter first number : ");
    const num2 = readlineSync.questionFloat("Enter second number: ");

    if (choice === 1) {
      const result = add(num1, num2);
      console.log("Result: " + num1 + " + " + num2 + " = " + result.toFixed(2));
    } else if (choice === 2) {
      const result = subtract(num1, num2);
      console.log("Result: " + num1 + " - " + num2 + " = " + result.toFixed(2));
    } else if (choice === 3) {
      const result = multiply(num1, num2);
      console.log("Result: " + num1 + " * " + num2 + " = " + result.toFixed(2));
    } else if (choice === 4) {
      const result = divide(num1, num2);
      if (result === null) {
        console.log("Error: Cannot divide by zero.");
      } else {
        console.log("Result: " + num1 + " / " + num2 + " = " + result.toFixed(2));
      }
    } else if (choice === 5) {
      const result = modulus(num1, num2);
      console.log("Result: " + num1 + " % " + num2 + " = " + result.toFixed(2));
    } else if (choice === 6) {
      const result = power(num1, num2);
      console.log("Result: " + num1 + " ** " + num2 + " = " + result.toFixed(2));
    }
  }
}

main();