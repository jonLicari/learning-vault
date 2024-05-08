```cpp
events::EventQueue * mbed::mbed_event_queue()
```

Function returns a pointer to the [[MBED OS]] Event Queue. This queue is a [[Singleton | singleton ]] so all threads which call this function will be able to access the same event queue.

Both the Event Queue and its dispatch thread are created on the first call to this function. The dispatch thread runs at default priority (currently osPriorityNormal).


In the event of either case below:
1. an RTOS is not present or 
2. configuration option `events.shared-dispatch-from-application` is set to true in the config.json file, 
 
then calling `mbed_event_queue()` does **NOT** create a dedicated dispatch thread - the application is expected to run the EventQueue's dispatch explicitly, for example, from main. This is necessary for the event loop to work without an RTOS, or an RTOS system can save memory by reusing the main stack.

This can be achieved in the following example:

```cpp
int main(void) {
	...
	EventQueue* queue = mbed_event_queue();
    queue->dispatch_forever();
}
```

