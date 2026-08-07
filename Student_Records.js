// Student Record Management System

const readlineSync = require('readline-sync');

let students = [];

function addStudent() {
  const name = readlineSync.question("Student name: ");
  const id = readlineSync.questionInt("Student ID: ");

  const numScores = readlineSync.questionInt("How many scores? ");
  const scores = [];

  for (let i = 0; i < numScores; i++) {
    const score = readlineSync.questionInt("Enter score " + (i + 1) + ": ");
    scores.push(score);
  }

  const student = {
    name: name,
    id: id,
    scores: scores
  };

  students.push(student);
  console.log('Student "' + name + '" added successfully.');
}

function calculateAverage(scores) {
  let sum = 0;

  for (let i = 0; i < scores.length; i++) {
    sum = sum + scores[i];
  }

  return sum / scores.length;
}

function displayAllStudents() {
  if (students.length === 0) {
    console.log("No students have been added yet.");
    return;
  }

  console.log("");
  console.log("Name            ID          Scores              Average");
  console.log("---------------------------------------------------------");

  for (let i = 0; i < students.length; i++) {
    const student = students[i];
    const average = calculateAverage(student.scores);

    console.log(
      student.name + "  |  " +
      student.id + "  |  " +
      student.scores.join(", ") + "  |  " +
      average.toFixed(2)
    );
  }
}

function findStudentAverage() {
  const id = readlineSync.questionInt("Enter student ID: ");

  for (let i = 0; i < students.length; i++) {
    if (students[i].id === id) {
      const average = calculateAverage(students[i].scores);
      console.log(students[i].name + "'s average score: " + average.toFixed(2));
      return;
    }
  }

  console.log("Error: Student ID not found.");
}

function showMenu() {
  console.log("");
  console.log("================================");
  console.log("   STUDENT RECORD SYSTEM MENU");
  console.log("================================");
  console.log("1. Add student");
  console.log("2. Display all students");
  console.log("3. Calculate average score");
  console.log("4. Quit");
}

function main() {
  let running = true;

  while (running) {
    showMenu();
    const choice = readlineSync.questionInt("Enter your choice (1-4): ");

    if (choice === 1) {
      addStudent();
    } else if (choice === 2) {
      displayAllStudents();
    } else if (choice === 3) {
      findStudentAverage();
    } else if (choice === 4) {
      console.log("Goodbye!");
      running = false;
    } else {
      console.log("Error: Please enter a number between 1 and 4.");
    }
  }
}

main();