# OOPs Concepts in C++

This folder contains beginner-friendly C++ programs demonstrating core object-oriented programming concepts.

## Files included

- Abstraction.cpp - demonstrates abstraction using classes and interfaces-style design.
- Encapsulation.cpp - shows data hiding and controlled access through member functions.
- Encapsulation1.cpp - another example of encapsulation using a simple class.
- Inheritance.cpp - demonstrates class inheritance and code reuse.
- FunctionOverloadingPolymorphism.cpp - shows compile-time polymorphism through function overloading.
- OperatorOverloadingPolymorphism.cpp - demonstrates operator overloading.
- VirtualDestructor.cpp - explains the importance of virtual destructors in polymorphic hierarchies.
- CustomNewDeleteImpWithPrimitiveDataType.cpp - illustrates custom memory allocation and deallocation.
- CustomNewDeleteImpWithCustomDataType.cpp - same concept applied to custom data types.
- CopyConstructor.cpp - demonstrates how copy constructors initialize objects.
- CopyAssignmentOperator.cpp - shows how assignment operators behave for class objects.
- CopyConstructorDynamicMemory.cpp - explains copy semantics when objects manage dynamic memory.
- SharedPointer.cpp - demonstrates ownership semantics using `std::shared_ptr`.
- VirtualInheritance.cpp - explains the use of virtual inheritance in diamond hierarchies.
- customString.cpp - a simple custom string implementation to practice class design.
- CustomStringFunction.c - a C-style string helper example for comparison with C++ classes.

## How to compile

You can compile any file individually using g++:

```bash
g++ <file_name>.cpp -o <output_name>
```

Example:

```bash
g++ Abstraction.cpp -o Abstraction
```

If you are compiling a file with C++ standard library features such as `std::shared_ptr`, use:

```bash
g++ SharedPointer.cpp -o SharedPointer -std=c++11
```

## Purpose

These examples are intended for learning and practicing the fundamentals of OOPs in C++.
