# LITL
The LITL library - Linked-list, Input, Timer, Library



- INPUT:
  - An input class for avr inputs
  - Supports: Rising Edge, Falling Edge, Filtering (requres castimer)
  - Initialization :  INPUT_t example("pin","port", bool invert state);  or  INPUT_t example = INPUT_t(pin,'port letter', bool invert state);
                                                    If invert state is set to 1, the input's value will be inverted from the PIN register value
  - Functions: 
    - bool value(); -> Returns value of the input
    - bool risen_edge();  -> Returns 1 if input went from 0 to 1 from the last function call, the risen edge bit is cleared if this function is called or if input is 0
    - bool fallen_edge(); -> Returns 1 if input went from 1 to 0 from the last function call, the fallen edge bit is cleared if this function is called or if input is 1
  
- TIMER:
  - An universal timer class, if on interrupt mode, then it will only work on avr.
  - Supports interrupt mode (every timer is incremented in an ISR) or system time mode (time difference)
  - Functions: 
    - uint32_t value(); -> Starts the timer and returns the value
    - void reset();     -> Resets the timer and disables it
    - void set_hook(function to call, calling period, pointer of parameter to send to function); [ ONLY AVAILABLE IN INTERRUPT MODE] -> attaches function to the timer which gets called every specified period, then the timer auto reloads. To reset back into normal mode, call this function again but with NULL, 0, NULL as parameters.
- LINKED LIST:
  - A high language like linked list
  - It uses a TEMPLATE PARAMETER meaning you can tell it what the variable type will be.

-------------------------------------------------------------------------------------------
LINKED LIST FUNCTIONS 
-------------------------------------------------------------------------------------------

     *  FUNCTION:    length()
     *  PARAMETERS:  void
     *  DESCRIPTION: Returns the number of elements in the list     
     *  RETURN:      uint32_t number of elements                                   
     
-------------------------------------------------------------------------------------------


    
     *  FUNCTION:    add_front()
     *  PARAMETERS:  custom_type value
     *  DESCRIPTION: adds element to the front of the list  
     *  RETURN:      void               
     

-------------------------------------------------------------------------------------------
    
     *  FUNCTION:    add_end()
     *  PARAMETERS:  custom_type value
     *  DESCRIPTION: adds element to the end of the list        
     *  RETURN:      void         
     

-------------------------------------------------------------------------------------------


    
     *  FUNCTION:    pop_end()
     *  PARAMETERS:  void
     *  DESCRIPTION: removes the last element and returns it
     *  RETURN:      Custom type element at the end of the list                     
     
-------------------------------------------------------------------------------------------


    
     *  FUNCTION:    sort()
     *  PARAMETERS:  int function_comparator_function (must return < 0 if element 1 is before element 2)
     *  DESCRIPTION: Sorts elements in the list                         
     *  RETURN:      void
     

-------------------------------------------------------------------------------------------

    
     *  FUNCTION:    print_console()
     *  PARAMETERS:  void
     *  DESCRIPTION: Prints the contents of the list to the console  ( elements must be a string or a number )                         
     *  RETURN:      void
     

-------------------------------------------------------------------------------------------


    
     *  FUNCTION:    remove_by_index ()
     *  PARAMETERS:  uint32_t index of element to remove
     *  DESCRIPTION: Removes the element by index,  moves the contents on the right to the left                        
     *  RETURN:      void
     

-------------------------------------------------------------------------------------------


    
     *  FUNCTION:    splice ()
     *  PARAMETERS:  uint32 start_index, uint32 number of elements to remove
     *  DESCRIPTION: Removes the specified number of elements, starting at start index  
     *  RETURN:    void
     

-------------------------------------------------------------------------------------------
    
     *  FUNCTION:    peek ()
     *  PARAMETERS:  void
     *  DESCRIPTION: returns a copy of the last element in the list
     *  RETURN:    custom_type
-------------------------------------------------------------------------------------------

     *  FUNCTION:    clone
     *  PARAMETERS:  List of same type
     *  DESCRIPTION: copies data from a different list to current list
     *  RETURN:      void
                                             
-------------------------------------------------------------------------------------------
LINKED LIST OPERATORS
-------------------------------------------------------------------------------------------
    
     *  OPERATOR:    [] 
     *  PARAMETERS:  unsigned long index
     *  DESCRIPTION: returns the element at specific index by reference                    
     *  RETURN:      Reference return of custom type data at specific index
     
-------------------------------------------------------------------------------------------
    
     *  OPERATOR:    +=
     *  PARAMETERS:  custom data
     *  DESCRIPTION: Adds data to the back of the list                   
     *  RETURN:      void
     
-------------------------------------------------------------------------------------------
     
     *  OPERATOR:    +
     *  PARAMETERS:  custom data
     *  DESCRIPTION: Adds data to the back/front of the list (data on left, object on right means it will be added to the front)                   
     *  RETURN:      reference to the original object
     
--------------------------------------------------------------------------------------------
     
     *  FUNCTION:    pop 
     *  PARAMETERS:  index of element to pop
     *  DESCRIPTION: Removes the element at index and returns it
     *  RETURN:      custom data type element at index

