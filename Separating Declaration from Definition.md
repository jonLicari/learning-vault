Header files expose the interface.
Source shows (hides) the implementation details.

Definition --> Header File (.h)
Implementation --> Source File (.cpp)

Why is this useful?

By exposing only the interface, clients can understand how to interact with an API or library without having access to the IP contained in the implementation details. By supplying the header files without the source files, you can protect your IP while supporting external usage of your code.

