# Philosophers 🍽️

**Philosophers (Philo)** is a C project from the 42 curriculum that simulates the classic **Dining Philosophers problem** using **processes or threads and synchronization primitives**.  
The goal is to manage multiple philosophers sitting at a table, alternating between **thinking, eating, and sleeping**, while avoiding **deadlocks and starvation**.  

---

## 📚 Table of Contents
- [Extended Description](#extended-description)  
- [Installation & Make](#installation--make)  
- [Usage](#usage)  
- [Features](#features)  
- [License](#license)  

---

## 📝 Extended Description

Philo teaches students:

- **Concurrency** – handling multiple processes or threads simultaneously.  
- **Synchronization** – using semaphores, mutexes, or other mechanisms to prevent deadlocks.  
- **Timing control** – managing sleeping and eating durations accurately.  
- **Resource management** – ensuring each philosopher can access forks (shared resources) without conflicts.  
- **Modular C programming** – separating logic for philosophers, forks, and main program flow.  

By completing this project, you gain experience in **multithreading/multiprocessing, synchronization, and real-time programming** in C.  

---

## 🛠 Installation & Make

Clone the repository and compile the project:

```bash
git clone https://github.com/algaboya/philo.git
cd philo
make
```


## ⚙️Usage
```bash
# Run the program with required arguments:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

# Example
./philo 5 800 200 200
# 5 philosophers, die after 800ms if they don't eat, eat for 200ms, sleep for 200ms

```
The program prints actions for each philosopher: taking forks 🍴, eating 🍝, sleeping 😴, thinking 💭.
It ensures no philosopher starves and no deadlocks occur.

## 🔧Features

```text
- Simulates Dining Philosophers problem
- Handles concurrency with threads or processes
- Synchronization to prevent deadlocks and race conditions
- Accurate timing for thinking, eating, and sleeping
- Optional stop condition after a number of meals
- Modular and clean C code

```
## 📄License

This project is for educational purposes and follows the 42 school guidelines.
