# C Stack

A stack data structure implementation in C using dynamically allocated linked nodes.

## Features

- **Push:** Insert an element at the top of the stack.
- **Pop:** Remove and return the top element.
- **Peek:** Access the top element without removing it.
- **Is Empty:** Check whether the stack is empty.
- **Show:** Display all elements in the stack.
- **Clear:** Free all dynamically allocated memory.

## Implementation

The stack is implemented using a singly linked list, where each node stores an integer value and a pointer to the next node.

Memory is dynamically allocated using `malloc()` and released using `free()`.

## Concepts Practiced

- Pointers and pointer manipulation
- Dynamic memory allocation
- Structures (`struct`)
- Linked nodes
- Stack operations (LIFO)
- Memory management
