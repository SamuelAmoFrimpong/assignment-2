// Matrix Operations

const readlineSync = require('readline-sync');

function readMatrix(rows, cols, label) {
  const matrix = [];

  for (let i = 0; i < rows; i++) {
    const line = readlineSync.question("Enter row " + (i + 1) + ": ");
    const row = line.split(' ').map(Number);
    matrix.push(row);
  }

  return matrix;
}

function printMatrix(matrix) {
  for (let i = 0; i < matrix.length; i++) {
    let rowText = "";
    for (let j = 0; j < matrix[i].length; j++) {
      rowText = rowText + matrix[i][j] + "  ";
    }
    console.log(rowText);
  }
}

function transposeMatrix(matrix) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const result = [];

  for (let j = 0; j < cols; j++) {
    const newRow = [];
    for (let i = 0; i < rows; i++) {
      newRow.push(matrix[i][j]);
    }
    result.push(newRow);
  }

  return result;
}

function addMatrices(matrixA, matrixB) {
  const rows = matrixA.length;
  const cols = matrixA[0].length;
  const result = [];

  for (let i = 0; i < rows; i++) {
    const newRow = [];
    for (let j = 0; j < cols; j++) {
      newRow.push(matrixA[i][j] + matrixB[i][j]);
    }
    result.push(newRow);
  }

  return result;
}

function multiplyMatrices(matrixA, matrixB) {
  const rowsA = matrixA.length;
  const colsA = matrixA[0].length;
  const colsB = matrixB[0].length;
  const result = [];

  for (let i = 0; i < rowsA; i++) {
    const newRow = [];
    for (let j = 0; j < colsB; j++) {
      let sum = 0;
      for (let k = 0; k < colsA; k++) {
        sum = sum + matrixA[i][k] * matrixB[k][j];
      }
      newRow.push(sum);
    }
    result.push(newRow);
  }

  return result;
}

function main() {
  // ---------- PART A: Transpose ----------
  console.log("PART A - Transpose a Matrix");

  const rowsA = readlineSync.questionInt("Enter number of rows: ");
  const colsA = readlineSync.questionInt("Enter number of columns: ");

  console.log("Enter the matrix:");
  const matrixA = readMatrix(rowsA, colsA);

  console.log("");
  console.log("Original Matrix:");
  printMatrix(matrixA);

  const transposed = transposeMatrix(matrixA);

  console.log("");
  console.log("Transposed Matrix:");
  printMatrix(transposed);

  // ---------- PART B: Add Two Matrices ----------
  console.log("");
  console.log("PART B - Add Two Matrices");
  console.log("Enter two matrices of the same size (" + rowsA + " x " + colsA + ")");

  console.log("Matrix 1:");
  const matrixB1 = readMatrix(rowsA, colsA);

  console.log("Matrix 2:");
  const matrixB2 = readMatrix(rowsA, colsA);

  const sumMatrix = addMatrices(matrixB1, matrixB2);

  console.log("");
  console.log("Sum Matrix:");
  printMatrix(sumMatrix);

  // ---------- PART C: Multiply Two Matrices ----------
  console.log("");
  console.log("PART C - Multiply Two Matrices");

  const rowsC1 = readlineSync.questionInt("Enter rows for Matrix A: ");
  const colsC1 = readlineSync.questionInt("Enter columns for Matrix A: ");
  console.log("Matrix A:");
  const matrixC1 = readMatrix(rowsC1, colsC1);

  const rowsC2 = colsC1; // must match columns of A
  const colsC2 = readlineSync.questionInt("Enter columns for Matrix B: ");
  console.log("Matrix B (rows = " + rowsC2 + "):");
  const matrixC2 = readMatrix(rowsC2, colsC2);

  const productMatrix = multiplyMatrices(matrixC1, matrixC2);

  console.log("");
  console.log("Product Matrix (A x B):");
  printMatrix(productMatrix);
}

main();