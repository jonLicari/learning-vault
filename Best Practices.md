## DRY

Don't Repeat Yourself!

Factor out code that can be reused so you don't have duplicate code all over the place!

## Qualities of Professional Code

#### Reliable
Code works as expected under various conditions

#### Clear
Easy for developers to understand

#### Adaptable
Simple to modify and extend

#### Maintainable
Ensures seamless updates and fixes

## Modularity

Modularize code by separating functionality. This simplifies logic, test, and maintainability of functionality.

**Low Coupling** - modules are as independent as possible
**High Cohesion** - each modules parts should work closely together without outside interference 

### Modular Design Strategies

- Define clear class interfaces
	- expose a public interface that expresses **what** the class does instead of how it does it
- Encapsulate implementation details
	- Hide inner workings via private & protected members to protect the implementation details from the blueprint
- Inject Dependencies
	- Pass dependencies rather than creating them directly
	- This allows for more flexible, testable code
- Utilize header and implementation files effectively
	- Separate interface (**what it does**) from the implementation (**how it works**)

### Design Evaluation Checklist

- [ ] Does each class have a single, clear purpose?
- [ ] Can you describe what a class does without using "and"?
- [ ] Could you replace one class's implementation without changing others?
- [ ] Are your interfaces clean and minimal?

## SOLID Principles

- **S**ingle responsibility principle
- **O**pen-closed principle
- **L**iskov substitution principle
- **I**nterface segregation principle
- **D**ependency inversion principle

#### Single Responsibility Principle

Class should only have one reason to change.

#### Open-Closed Principle

Software entities should be open for extension but closed for modification (achieved by interfaces, inheritance).

#### Liskov Substitution Principle

Code that works with pointers or references to base classes should work just as well with any derived class (polymorphism).

#### Interface Segregation Principle

Clients shouldn't be forced to depend on interfaces they don't use.

#### Dependency Inversion Principle

Depend on abstractions rather than concrete implementations.
