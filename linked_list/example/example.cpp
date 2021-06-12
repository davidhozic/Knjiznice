#include "../linked_list.hh"





class_LIST<int> test;





int main()
{

    /* Add elements via operator += to the back of the list */
    for (char i = 0; i < 3; i++)
        test += i;

    /* Add elements via operator + to the front of the list NOTE: When using this operator make sure you push the same data type as declared in the list creation (or recast it) otherwise it will not find the operator */
    for (char i = 0; i < 3; i++)
        test = (int)i + test;
        
    /* Removes 3 elements from the list starting at index 0 */
    test.splice(0, 2);

 
}