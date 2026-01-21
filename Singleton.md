A [[Data Structures|data structure]] in which only a single instance of an object can exist - that instance cannot be copied nor can other instances of this object type be created.

Classes that are made singleton have only a single instance. You can gain a global access point to that instance by making a getter which returns a reference or pointer to that instance. 

The singleton object is initialized ***only when it's requested for the first time***.