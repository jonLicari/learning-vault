The term is used to describe the contract or agreement that a class's code maintains throughout the lifetime of its existence.

A class may need to maintain certain rules, for example, that: **`min` `<=` `max`**
To maintain this, member functions, constructors, etc. must ensure that when the object is at "steady state", this condition still holds. This means that when member function operations have concluded and we are about to "return" to an "idle state", **`min` is still `<=` `max`**.

Most developers design invariant-maintaining classes without ever needing to give a name to this activity. But when we give it a name, we can see more. For instance, we can form a criterion for when we need to define our own class.