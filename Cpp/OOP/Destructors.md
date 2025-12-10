See also: [[Constructors]]

The purpose of destructors is to free resources (memory, files, resource locks). They are invoked mechanically just before the memory of the object is released.

They are declared as the same name as the class prefixed with a tilde operator. They do not have a return type nor take input parameters.

C++ does not have garbage collection so if an object was created with a new keyword (dynamically on the heap) then the destructor is called when the delete keyword is applied to the pointer of the object. Usually this operation occurs within another destructor of a smart pointer object.

### Virtual Destructors

In inheritance hierarchies, declaration of a virtual destructor in the base class ensures that the destructors of derived classes are invoked properly when an object is deleted through a pointer-to-base-class. Objects that may be deleted in this way need to inherit a virtual destructor.

Example of why we use **virtual destructors** [here](https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors). Every destructor down gets called no matter what. virtual makes sure it starts at the top instead of the middle.
