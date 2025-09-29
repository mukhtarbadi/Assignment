-- Create Database
CREATE DATABASE library_db;


-- Create Table
CREATE TABLE books (
    book_id INT PRIMARY KEY,
    title VARCHAR(100),
    author VARCHAR(100),
    publisher VARCHAR(100),
    year_of_publication INT,
    price DECIMAL(10,2)
);

-- Insert Records
INSERT INTO books VALUES (1, 'C Programming', 'Dennis Ritchie', 'PHI', 1978, 450.00);
INSERT INTO books VALUES (2, 'C++ Basics', 'Bjarne Stroustrup', 'Pearson', 1985, 550.00);
INSERT INTO books VALUES (3, 'Java Intro', 'James Gosling', 'Sun', 1995, 600.00);
INSERT INTO books VALUES (4, 'Database System', 'Ramakrishnan', 'McGrawHill', 2000, 700.00);
INSERT INTO books VALUES (5, 'Python Guide', 'Guido van Rossum', 'OReilly', 1991, 500.00);



-- Create Table
CREATE TABLE members (
    member_id INT PRIMARY KEY,
    member_name VARCHAR(100),
    date_of_membership DATE,
    email VARCHAR(100)
);

-- Insert Records with today (2025-08-26) and tomorrow (2025-08-27)
INSERT INTO members VALUES (1, 'Rahul Sharma', '2025-08-26', 'rahul@gmail.com');
INSERT INTO members VALUES (2, 'Priya Patel', '2025-08-26', 'priya@gmail.com');
INSERT INTO members VALUES (3, 'Amit Singh', '2025-08-27', 'amit@gmail.com');
INSERT INTO members VALUES (4, 'Neha Joshi', '2025-08-27', 'neha@gmail.com');
INSERT INTO members VALUES (5, 'Ravi Kumar', '2025-08-27', 'ravi@gmail.com');



-- Retrieve members before 2022
SELECT *
FROM members
WHERE date_of_membership < '2022-01-01'
ORDER BY date_of_membership;


-- Display books of specific author 
SELECT title, year_of_publication
FROM books
WHERE author = 'James Gosling'
ORDER BY year_of_publication DESC;


-- Add CHECK constraint
ALTER TABLE books
ADD CONSTRAINT chk_price CHECK (price > 0);


-- Add UNIQUE constraint on email
ALTER TABLE members
ADD CONSTRAINT unique_email UNIQUE (email);


-- Create Table
CREATE TABLE authors (
    author_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    country VARCHAR(50)
);


-- Create Table
CREATE TABLE publishers (
    publisher_id INT PRIMARY KEY,
    publisher_name VARCHAR(100),
    contact_number VARCHAR(15) UNIQUE,
    address VARCHAR(200)
);


-- Add new column
ALTER TABLE books
ADD COLUMN genre VARCHAR(50);

-- Update all records (example values)
UPDATE books SET genre = 'Programming' WHERE book_id = 1;
UPDATE books SET genre = 'Programming' WHERE book_id = 2;
UPDATE books SET genre = 'Programming' WHERE book_id = 3;
UPDATE books SET genre = 'Database'    WHERE book_id = 4;
UPDATE books SET genre = 'Programming' WHERE book_id = 5;


-- Modify column size
ALTER TABLE members
MODIFY email VARCHAR(100);


-- Drop the table
DROP TABLE publishers;


-- Create backup table
CREATE TABLE members_backup AS
SELECT * FROM members;

-- Drop original table
DROP TABLE members;


-- Insert 3 new authors
INSERT INTO authors VALUES (1, 'James', 'Gosling', 'Canada');
INSERT INTO authors VALUES (2, 'Bjarne', 'Stroustrup', 'Denmark');
INSERT INTO authors VALUES (3, 'Dennis', 'Ritchie', 'USA');

-- Update last name of one author
UPDATE authors
SET last_name = 'Smith'
WHERE author_id = 3;


-- Delete books with price > 100
DELETE FROM books
WHERE price > 100;


-- Insert new records
INSERT INTO books VALUES (6, 'HTML Basics', 'John Doe', 'TechPress', 2021, 90.00, 'Web Development');
INSERT INTO books VALUES (7, 'CSS Design', 'Jane Smith', 'CodeHouse', 2022, 120.00, 'Web Development');
INSERT INTO books VALUES (8, 'JavaScript Guide', 'Mark Lee', 'WebBooks', 2020, 150.00, 'Programming');
INSERT INTO books VALUES (9, 'AI Concepts', 'Alan Turing', 'FutureTech', 2023, 200.00, 'Artificial Intelligence');
INSERT INTO books VALUES (10, 'Data Science', 'Andrew Ng', 'ML Press', 2024, 180.00, 'Data Science');
INSERT INTO books VALUES (11, 'Old DB Concepts', 'Michael Stone', 'TechWorld', 2010, 80.00, 'Database');
INSERT INTO books VALUES (12, 'Basic Networking', 'Sam Wilson', 'NetPress', 2012, 95.00, 'Networking');


-- Update year of a specific book (example book_id = 6)
UPDATE books
SET year_of_publication = 2020
WHERE book_id = 6;


-- Increase price by 10% for old books
UPDATE books
SET price = price * 1.10
WHERE year_of_publication < 2015;

--Restore members table from backup
CREATE TABLE members AS
SELECT * FROM members_backup;

-- Delete records (joined before 2020)
DELETE FROM members
WHERE date_of_membership < '2020-01-01';


-- Delete all books that have a NULL value in the author column
DELETE FROM books
WHERE author IS NULL;

-- Retrieve all books with price between $50 and $100
SELECT * FROM books
WHERE price BETWEEN 50 AND 100;

-- Retrieve top 3 books sorted by author in ascending order
SELECT *
FROM books
ORDER BY author ASC
LIMIT 3;

-- Grant SELECT permission on books table to user 'librarian'
GRANT SELECT ON books TO 'librarian'@'localhost';


-- Grant INSERT and UPDATE permissions on members table to user 'admin'
GRANT INSERT, UPDATE ON members TO 'admin'@'localhost';
FLUSH PRIVILEGES;


-- Revoke INSERT privilege on books table from user 'librarian'
REVOKE INSERT ON books FROM 'librarian'@'localhost';
FLUSH PRIVILEGES;


-- Remove all permissions of user 'admin' on members table
REVOKE ALL PRIVILEGES ON members FROM 'admin'@'localhost';
FLUSH PRIVILEGES;


-- Lab 3: Start transaction
START TRANSACTION;

-- Insert multiple records
INSERT INTO books (book_id, title, author, publisher, year_of_publication, price, genre)
VALUES 
(13, 'Python Basics', 'Alice', 'CodePress', 2021, 95.00, 'Programming'),
(14, 'Java Fundamentals', 'Bob', 'TechBooks', 2022, 120.00, 'Programming');

-- Commit these records
COMMIT;

-- Insert another record
INSERT INTO books (book_id, title, author, publisher, year_of_publication, price, genre)
VALUES (15, 'C# Guide', 'Charlie', 'CodeHouse', 2023, 110.00, 'Programming');

-- Rollback this last insertion
ROLLBACK;

-- Check final books table
SELECT * FROM books;


-- Start transaction
START TRANSACTION;

-- Set a savepoint before updates
SAVEPOINT before_update;

-- Make some updates
UPDATE members
SET member_name = 'Rahul Sharma Updated'
WHERE member_id = 1;

UPDATE members
SET email = 'priya_new@gmail.com'
WHERE member_id = 2;

-- Rollback to savepoint
ROLLBACK TO SAVEPOINT before_update;

-- Commit remaining changes
COMMIT;

-- Check final members table
SELECT * FROM members;

-- Show books with their authors using INNER JOIN
SELECT b.title, b.author
FROM books b
INNER JOIN authors a
ON b.author = CONCAT(a.first_name, ' ', a.last_name);


-- Show all books and authors using FULL OUTER JOIN
SELECT b.title, b.author, a.first_name, a.last_name
FROM books b
LEFT JOIN authors a
ON b.author = CONCAT(a.first_name, ' ', a.last_name)

UNION

SELECT b.title, b.author, a.first_name, a.last_name
FROM books b
RIGHT JOIN authors a
ON b.author = CONCAT(a.first_name, ' ', a.last_name);


-- Show total number of books in each genre
SELECT genre, COUNT(*) AS total_books
FROM books
GROUP BY genre;


-- Show number of members joined in each year
SELECT YEAR(date_of_membership) AS join_year, COUNT(*) AS total_members
FROM members
GROUP BY YEAR(date_of_membership);


-- Stored procedure to get books by a given author
DELIMITER $$

CREATE PROCEDURE GetBooksByAuthor(IN authorName VARCHAR(100))
BEGIN
    SELECT title, author, year_of_publication, price
    FROM books
    WHERE author = authorName;
END $$

DELIMITER ;


-- Stored procedure to get price of a book using book_id
DELIMITER $$

CREATE PROCEDURE GetBookPrice(IN bid INT)
BEGIN
    SELECT price 
    FROM books
    WHERE book_id = bid;
END $$

DELIMITER ;



-- Create a view to show only title, author and price of books
CREATE VIEW book_view AS
SELECT title, author, price
FROM books;

SELECT * FROM book_view;


-- Create a view to show members who joined before 2020
CREATE VIEW old_members AS
SELECT *
FROM members
WHERE date_of_membership < '2020-01-01';

SELECT * FROM old_members;

-- Add last_modified column to books table if not exists
ALTER TABLE books
ADD COLUMN last_modified TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;

-- Create trigger to update last_modified on update
DELIMITER $$

CREATE TRIGGER update_books_last_modified
BEFORE UPDATE ON books
FOR EACH ROW
BEGIN
    SET NEW.last_modified = CURRENT_TIMESTAMP;
END $$

DELIMITER ;


-- Create log table to store deleted records
CREATE TABLE log_changes (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    book_id INT,
    title VARCHAR(100),
    deleted_at TIMESTAMP
);

-- Create trigger for DELETE operation on books table
CREATE TRIGGER after_book_delete
AFTER DELETE ON books
FOR EACH ROW
INSERT INTO log_changes (book_id, title, deleted_at)
VALUES (OLD.book_id, OLD.title, NOW());


-- Create a stored procedure to insert a book and return a message
DELIMITER $$
CREATE PROCEDURE insert_book()
BEGIN
  -- Insert new record
  INSERT INTO books (book_id, title, author, publisher, year_of_publication, price, genre)
  VALUES (21, 'Cloud Computing Advanced', 'Badi Mukhtar', 'TechWorld', 2025, 350.00, 'Technology');

  -- Return confirmation (shows as result set)
  SELECT 'Book inserted successfully!' AS message;
END $$
DELIMITER ;

-- Call the procedure to run it
CALL insert_book();


-- Show total number of books in books table
SELECT COUNT(*) AS total_books
FROM books;


-- Declare variables, assign values, and display results (MySQL style)
SET @book_id = 101;
SET @price = 500.00;

-- Show the values of the variables
SELECT @book_id AS Book_ID, @price AS Price;


-- Use variables to perform arithmetic on book prices

-- Declare variables (like constants)
SET @price1 = 200.00;
SET @price2 = 300.00;

-- Perform arithmetic operations
SELECT 
    @price1 + @price2 AS total_price,
    @price2 - @price1 AS price_difference,
    @price1 * 2 AS double_price,
    @price2 / 2 AS half_price;


-- Check if a book's price is above $100 and show message (MySQL style)

-- Declare variable for price
SET @price = 120.00;

-- Use IF function in SELECT to show message
SELECT 
    IF(@price > 100, 'Price is above $100', 'Price is $100 or below') AS price_check;


-- Display details of all books one by one (MySQL style)

-- Using a simple SELECT statement
SELECT * 
FROM books;



-- Oracle PL/SQL explicit cursor example (for exam reference)
DECLARE
    CURSOR member_cursor IS
        SELECT * FROM members;
    member_rec member_cursor%ROWTYPE;
BEGIN
    OPEN member_cursor;
    LOOP
        FETCH member_cursor INTO member_rec;
        EXIT WHEN member_cursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Member ID: ' || member_rec.member_id || ', Name: ' || member_rec.member_name);
    END LOOP;
    CLOSE member_cursor;
END;
/


-- Oracle PL/SQL explicit cursor example (for exam reference)
DECLARE
    CURSOR book_cursor IS
        SELECT title FROM books WHERE author = 'James Gosling';
    book_rec book_cursor%ROWTYPE;
BEGIN
    OPEN book_cursor;
    LOOP
        FETCH book_cursor INTO book_rec;
        EXIT WHEN book_cursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Book Title: ' || book_rec.title);
    END LOOP;
    CLOSE book_cursor;
END;
/


-- Start a transaction
START TRANSACTION;

-- Insert a new member
INSERT INTO members (member_id, member_name, date_of_membership, email)
VALUES (10, 'Mukhtar badi', '2025-09-29', 'mukhtar@gmail.com');

-- Set a savepoint
SAVEPOINT before_update;

-- Make some updates
UPDATE members
SET member_name = 'Mukhtar UPDATED'
WHERE member_id = 10;

UPDATE members
SET email = 'mukhtar_new@gmail.com'
WHERE member_id = 10;

-- Rollback to the savepoint
ROLLBACK TO SAVEPOINT before_update;

-- Commit the remaining transaction
COMMIT;

-- Check final table
SELECT * FROM members;


-- Start a transaction
START TRANSACTION;

-- Insert multiple books
INSERT INTO books (book_id, title, author, publisher, year_of_publication, price, genre)
VALUES 
(30, 'AI Basics', 'Alan Turing', 'FutureTech', 2025, 200.00, 'Artificial Intelligence'),
(31, 'Data Mining', 'Andrew Ng', 'ML Press', 2024, 180.00, 'Data Science');

-- Commit the insertion (save permanently)
COMMIT;

-- Start another transaction
START TRANSACTION;

-- Set a savepoint before making changes
SAVEPOINT before_update;

-- Make some updates
UPDATE books
SET price = price + 50
WHERE book_id = 30;

UPDATE books
SET price = price + 30
WHERE book_id = 31;

-- Rollback to the savepoint (undo the above updates)
ROLLBACK TO SAVEPOINT before_update;

-- Commit any remaining changes (if any)
COMMIT;

-- Check final books table
SELECT * FROM books;
