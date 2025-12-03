
Where should I add `#include` - to source files, header files, or both?

Generally, it is recommended to only keep the minimum amount of inclusions necessary in the header file because this is the file that will be included in other files, in turn. 

Thus, if you bloat one header file with inclusions, then whatever other higher level header includes the lower level header, will take longer to compile since it has to include *all other files included in the attached header!*

