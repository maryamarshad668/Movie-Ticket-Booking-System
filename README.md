# Movie Ticket Booking System

## Overview

The **Movie Ticket Booking System** is a console-based application developed in **C++** using **Object-Oriented Programming (OOP)** principles. The system simulates a real-world cinema booking platform where administrators manage movies and shows while customers can register, log in, browse movies, and book tickets.

The project demonstrates the practical use of **classes, inheritance, polymorphism, vectors, file handling, and object relationships** to build an organized and modular application.

---

# Objectives

* Apply Object-Oriented Programming concepts in C++.
* Simulate a real-world movie ticket booking system.
* Manage movies, shows, users, and tickets efficiently.
* Implement user authentication and role-based access.
* Store application data using file handling.

---

# Features

## User Authentication

The system supports two types of users:

### Administrator

* Login as administrator
* Add new movies
* Schedule movie shows
* View all issued tickets
* Manage the cinema database

### Customer

* Register a new account
* Login securely
* View available movies
* Book movie tickets
* View personal bookings
* Cancel booked tickets

---

# Movie Management

Administrators can:

* Add new movies
* Specify movie title
* Set movie genre
* Set movie duration
* Maintain a list of available movies

---

# Show Management

For each movie, administrators can create multiple shows.

Each show contains:

* Show ID
* Movie information
* Show timing
* Seat availability

---

# Seat Booking System

Customers can:

* View available shows
* Select a show
* Choose an available seat
* Confirm booking

The system automatically:

* Checks seat availability
* Prevents duplicate bookings
* Generates a unique ticket
* Updates seat status

---

# Ticket Management

Each booking generates a ticket containing:

* Ticket ID
* Customer Name
* Movie Name
* Show Time
* Seat Number

Tickets are linked with:

* Customer
* Movie Show
* Booking System

Customers can also cancel tickets, making the seat available for future bookings.

---

# File Handling

The application stores data using text files.

Information such as:

* Users
* Movies
* Shows
* Tickets

can be saved and loaded when the program starts, ensuring data persistence between sessions.

---

# System Workflow

### Administrator

1. Login
2. Add movies
3. Create movie shows
4. View all bookings

---

### Customer

1. Register/Login
2. View available movies
3. Select a movie show
4. Choose an available seat
5. Confirm booking
6. Receive ticket
7. View or cancel bookings

---

# Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL Vectors
* File Handling
* Console-Based User Interface

---

# OOP Concepts Implemented

This project demonstrates several fundamental OOP concepts:

### Classes & Objects

The system is built around multiple interacting classes such as `Movie`, `Show`, `Ticket`, and `User`.

### Inheritance

The `Admin` and `Customer` classes inherit from the base `User` class.

### Polymorphism

Different user types provide their own menu implementations through overridden functions.

### Encapsulation

Data members are kept private and accessed through public member functions.

### Composition

The `CinemaSystem` class manages collections of movies, users, shows, and tickets.

---

# Learning Outcomes

This project demonstrates:

* Object-Oriented Programming
* Class relationships
* Inheritance and Polymorphism
* Encapsulation
* Composition
* Dynamic memory management
* STL vectors
* File handling
* Menu-driven application development
* Real-world system design

---

# Author

**Maryam Arshad**

---
