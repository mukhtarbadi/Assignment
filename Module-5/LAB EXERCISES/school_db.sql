CREATE DATABASE school_db;

USE school_db;

CREATE TABLE students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    age INT,
    class VARCHAR(20),
    address VARCHAR(100)
);


-- Insert 5 records into students table
INSERT INTO students VALUES (1, 'Amit', 18, '10th', 'Rajkot');
INSERT INTO students VALUES (2, 'Priya', 17, '9th', 'Surat');
INSERT INTO students VALUES (3, 'Rohit', 19, '11th', 'Ahmedabad');
INSERT INTO students VALUES (4, 'Neha', 16, '8th', 'Baroda');
INSERT INTO students VALUES (5, 'Karan', 18, '10th', 'Morbi');

-- Retrieve all records
SELECT * FROM students;

--show student_name and age 
SELECT student_name, age 
FROM students;


-- Show all students whose age is more than 10
SELECT * 
FROM students 
WHERE age > 10;


-- Create teachers table
CREATE TABLE teachers (
    teacher_id INT PRIMARY KEY,
    teacher_name VARCHAR(50) NOT NULL,
    subject VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE
);


-- Add teacher_id column in students table
ALTER TABLE students
ADD teacher_id INT;

-- Set teacher_id as FOREIGN KEY
ALTER TABLE students
ADD CONSTRAINT fk_teacher
FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id);


-- Create courses table
CREATE TABLE courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50),
    course_credits INT
);


-- Create database
CREATE DATABASE university_db;


-- Add new column in courses table
ALTER TABLE courses 
ADD course_duration INT;


-- Drop course_credits column
ALTER TABLE courses 
DROP COLUMN course_credits;


-- Drop foreign key from students table
ALTER TABLE students DROP FOREIGN KEY fk_teacher;

-- Ab teachers table drop karo
DROP TABLE teachers;


-- Step 2: Drop the students table
DROP TABLE students;

-- Step 3: Verify that the table has been removed
SHOW TABLES;


-- Insert 3 records into courses table

INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (1, 'Computer Basics', '3 Months');

INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (2, 'Database Fundamentals', '4 Months');

INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (3, 'Web Development', '6 Months');

-- Update course duration of a specific course

UPDATE courses 
SET course_duration = '5 Months' 
WHERE course_id = 2;

-- Delete a course with specific course_id

DELETE FROM courses 
WHERE course_id = 3;


-- Retrieve all courses from courses table

SELECT * FROM courses;

-- Show courses sorted by duration in descending order

SELECT * FROM courses 
ORDER BY course_duration DESC;

-- Show only top 2 courses from courses table

SELECT * FROM courses 
LIMIT 2;


-- Create two new users

CREATE USER 'user1'@'localhost' IDENTIFIED BY 'password1';
CREATE USER 'user2'@'localhost' IDENTIFIED BY 'password2';

-- Give user1 permission to select data from courses table

GRANT SELECT ON courses TO 'user1'@'localhost';

-- Remove INSERT permission from user1
REVOKE INSERT ON courses FROM 'user1'@'localhost';

-- Give INSERT permission to user2
GRANT INSERT ON courses TO 'user2'@'localhost';



-- Insert few rows in courses table
INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (4, 'Networking Basics', '2 Months');

INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (5, 'Python Programming', '5 Months');

-- Save the changes
COMMIT;

-- Insert additional rows in courses table
INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (10, 'Cloud Computing', '6 Months');

INSERT INTO courses (course_id, course_name, course_duration) 
VALUES (11, 'Cyber Security', '5 Months');

-- Undo last insert operation
ROLLBACK;

-- Start transaction
START TRANSACTION;

-- Make a savepoint
SAVEPOINT sp1;

-- Update (we will undo this)
UPDATE courses
SET course_duration = '7 Months'
WHERE course_id = 5;

-- Roll back only this change
ROLLBACK TO sp1;

-- Finish the transaction
COMMIT;


-- Create departments table
CREATE TABLE departments (
  dept_id INT PRIMARY KEY,
  dept_name VARCHAR(50)
);

-- Create employees table
CREATE TABLE employees (
  emp_id INT PRIMARY KEY,
  emp_name VARCHAR(50),
  dept_id INT
);

-- Insert sample data
INSERT INTO departments VALUES (1, 'IT'), (2, 'HR');
INSERT INTO employees VALUES (101, 'Mukhtar', 1), (102, 'Badi', 2);

-- Show employees with their departments using INNER JOIN
SELECT employees.emp_name, departments.dept_name
FROM employees
INNER JOIN departments
ON employees.dept_id = departments.dept_id;


-- Show all departments, even if no employees
SELECT departments.dept_name, employees.emp_name
FROM departments
LEFT JOIN employees
ON departments.dept_id = employees.dept_id;

-- Count employees in each department
SELECT dept_id, COUNT(emp_id) AS total_employees
FROM employees
GROUP BY dept_id;

-- Add salary column in employees table
ALTER TABLE employees ADD salary INT;

UPDATE employees SET salary = 30000 WHERE emp_id = 101;
UPDATE employees SET salary = 25000 WHERE emp_id = 102;

-- Find average salary of employees in each department
SELECT dept_id, AVG(salary) AS avg_salary
FROM employees
GROUP BY dept_id;


-- This procedure shows employees based on department

DELIMITER //

CREATE PROCEDURE GetEmployeesByDept(IN dept INT)
BEGIN
    SELECT * 
    FROM employees
    WHERE dept_id = dept;
END //

DELIMITER ;

-- How to use:
-- CALL GetEmployeesByDept(1);  -- replace 1 with the department id

-- This procedure shows all details of a course based on course_id

DELIMITER //

CREATE PROCEDURE GetCourseDetails(IN input_course_id INT)
BEGIN
    SELECT * 
    FROM courses
    WHERE course_id = input_course_id;
END //

DELIMITER ;

-- How to use:
-- CALL GetCourseDetails(4);  -- replace 4 with the course id

-- This view shows all employees with their department names

CREATE VIEW EmployeeDeptView AS
SELECT e.emp_id, e.emp_name, e.salary, d.dept_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id;

-- How to use:
-- SELECT * FROM EmployeeDeptView;

-- This view shows employees with their department names, salary >= 50000

CREATE OR REPLACE VIEW EmployeeDeptView AS
SELECT e.emp_id, e.emp_name, e.salary, d.dept_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id
WHERE e.salary >= 50000;

-- How to use:
-- SELECT * FROM EmployeeDeptView;


-- This trigger logs when a new employee is added

CREATE TABLE IF NOT EXISTS employee_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_id INT,
    emp_name VARCHAR(50),
    action_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DELIMITER //

CREATE TRIGGER after_employee_insert
AFTER INSERT ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_log(emp_id, emp_name)
    VALUES (NEW.emp_id, NEW.emp_name);
END //

DELIMITER ;


-- Add a column to track last modified time
ALTER TABLE employees
ADD COLUMN last_modified TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;

-- Trigger is actually not needed because ON UPDATE handles it automatically
-- But if you want a trigger version:

DELIMITER //

CREATE TRIGGER before_employee_update
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
    SET NEW.last_modified = CURRENT_TIMESTAMP;
END //

DELIMITER ;



--Introduction to PL/SQL

-- PL/SQL block to print total number of employees

DECLARE
    total_emp NUMBER;
BEGIN
    SELECT COUNT(*) INTO total_emp
    FROM employees;
    
    DBMS_OUTPUT.PUT_LINE('Total Employees: ' || total_emp);
END;
/

-- PL/SQL block to calculate total sales from orders table

DECLARE
    total_sales NUMBER;
BEGIN
    SELECT SUM(order_amount) INTO total_sales
    FROM orders;
    
    DBMS_OUTPUT.PUT_LINE('Total Sales: ' || total_sales);
END;
/

-- Check employee department using IF-THEN

DECLARE
    emp_department NUMBER;
BEGIN
    SELECT dept_id INTO emp_department
    FROM employees
    WHERE emp_id = 101;

    IF emp_department = 1 THEN
        DBMS_OUTPUT.PUT_LINE('Employee belongs to IT Department');
    ELSIF emp_department = 2 THEN
        DBMS_OUTPUT.PUT_LINE('Employee belongs to HR Department');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Employee department unknown');
    END IF;
END;
/

-- Display all employee names using FOR LOOP

BEGIN
    FOR emp_rec IN (SELECT emp_name FROM employees) LOOP
        DBMS_OUTPUT.PUT_LINE('Employee Name: ' || emp_rec.emp_name);
    END LOOP;
END;
/


-- Retrieve and display employee details using explicit cursor

DECLARE
    -- Declare cursor to select all employees
    CURSOR emp_cursor IS
        SELECT emp_id, emp_name, dept_id FROM employees;

    -- Variable to hold each row
    emp_record emp_cursor%ROWTYPE;
BEGIN
    OPEN emp_cursor; -- open the cursor
    LOOP
        FETCH emp_cursor INTO emp_record; -- fetch each row
        EXIT WHEN emp_cursor%NOTFOUND;    -- exit when no more rows

        DBMS_OUTPUT.PUT_LINE('ID: ' || emp_record.emp_id || 
                             ', Name: ' || emp_record.emp_name || 
                             ', Dept: ' || emp_record.dept_id);
    END LOOP;
    CLOSE emp_cursor; -- close the cursor
END;
/

-- Retrieve and display all courses using cursor

DECLARE
    CURSOR course_cursor IS
        SELECT course_id, course_name, course_duration FROM courses;

    course_record course_cursor%ROWTYPE;
BEGIN
    OPEN course_cursor;
    LOOP
        FETCH course_cursor INTO course_record;
        EXIT WHEN course_cursor%NOTFOUND;

        DBMS_OUTPUT.PUT_LINE('ID: ' || course_record.course_id ||
                             ', Name: ' || course_record.course_name ||
                             ', Duration: ' || course_record.course_duration);
    END LOOP;
    CLOSE course_cursor;
END;
/


-- Transaction with savepoint, insert, and rollback (simple version)

-- Insert first employee with new emp_id
INSERT INTO employees (emp_id, emp_name, dept_id) VALUES (103, 'Ali', 1);

-- Create a savepoint
SAVEPOINT emp_savepoint;

-- Insert second employee
INSERT INTO employees (emp_id, emp_name, dept_id) VALUES (104, 'Sara', 2);

-- Rollback to savepoint (second insert undone)
ROLLBACK TO emp_savepoint;

-- Commit the first insert
COMMIT;


-- Transaction with savepoint, partial commit, and rollback

-- Insert first employee
INSERT INTO employees (emp_id, emp_name, dept_id) VALUES (105, 'Rahul', 1);

-- Create a savepoint
SAVEPOINT after_first_insert;

-- Insert second employee
INSERT INTO employees (emp_id, emp_name, dept_id) VALUES (106, 'Nina', 2);

-- Commit first insert (before savepoint)
COMMIT;

-- Insert third employee
INSERT INTO employees (emp_id, emp_name, dept_id) VALUES (107, 'Ayesha', 1);

-- Rollback remaining changes (undo third insert)
ROLLBACK;

-- Result: 
-- emp_id = 105 and 106 will stay (because committed), emp_id = 107 will be undone
