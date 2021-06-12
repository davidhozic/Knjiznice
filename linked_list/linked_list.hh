#ifndef SEZNAM_INC
#define SEZNAM_INC
#include <stdlib.h>
#include <stdint.h>
#include "list_settings.hh"
#include <type_traits>

#if (USE_FREERTOS == 1)
	#include "FreeRTOS.h"
#endif

#if (INCLUDE_IOSTREAM == 1)
    #include <iostream>
#endif




template <typename tip>
class class_LIST
{
private:

    struct vpdt
    {
        friend class class_LIST<tip>;
    private:
        vpdt *naslednji;
        vpdt *prejsnji;
        tip podatek;
        
    };

    vpdt *glava = NULL;
    unsigned long count = 0;
    unsigned long glava_index = 0;
    
    
    inline void pojdi_zacetek()
    {
        while (glava != NULL && glava->prejsnji != NULL)
        {
            glava = glava->prejsnji;
        }
        glava_index = 0;
    }

    inline void pojdi_konec()
    {
        while (glava != NULL && glava->naslednji != NULL)
        {
            glava = glava->naslednji;
        }
        if (count > 0)
            glava_index = count-1;
	}

public:
    inline unsigned short length()
    {
        return count;
    }


	void add_front(tip vrednost)
    {
	#if (USE_FREERTOS == 1)
        vpdt *nov = (vpdt *) pvPortMalloc(sizeof(vpdt));
    #else
		vpdt *nov = (vpdt *) malloc(sizeof(vpdt));
	#endif
		pojdi_zacetek();

        if (glava != NULL)
        {
            glava->prejsnji = nov;
        }
        nov->prejsnji = NULL;
        nov->naslednji = glava;
        nov->podatek = vrednost;
        glava = nov;
        count++;
        glava_index = 0;
    }

    void add_end(tip vrednost)
    {

	#if (USE_FREERTOS == 1)
		vpdt *nov = (vpdt *) pvPortMalloc(sizeof(vpdt));
	#else
		vpdt *nov = (vpdt *) malloc(sizeof(vpdt));
	#endif

        pojdi_konec();
        if (glava != NULL)
        {
            glava->naslednji = nov;
        }
        nov->prejsnji = glava;
        nov->naslednji = NULL;
        nov->podatek = vrednost;
		glava = nov;
        count++;
        glava_index = count - 1;
    }

    tip pop_end()
    {
        tip return_data;
        if (std::is_scalar<tip>::value == false)
        {
            throw (-1);
        }
        if (glava != NULL)
        {
            pojdi_konec();
            return_data = glava->podatek;
            vpdt *prev = glava->prejsnji;
            if (prev != NULL)
                prev->naslednji = NULL;
        
        #if (USE_FREERTOS == 1)
            vPortFree(glava);
        #else    
            free(glava);
        #endif

            glava = prev;
            count--;
            glava_index--;
        }
        return return_data;
    }

#if (INCLUDE_SORT == 1)
    void sort(tip(*comparator_fnct)(tip , tip))
    {
        tip temp;
        for(uint32_t i = 0; i < count-1;)
        {
            if (comparator_fnct((*this)[i], (*this)[i+1]) > 0)
            {
                temp = (*this)[i];
                (*this)[i] = (*this)[i+1];
                (*this)[i+1] = temp;
                if (i > 0)
                    i--;
            }
            else    
                i++; 
        }
    }
#endif
#if (INCLUDE_IOSTREAM == 1)
    void print_console()
    {
        for (uint32_t i = 0; i < count; i++)
        {
            std::cout << std::to_string((*this)[i]) << std::endl;
        }
    }

#endif

    /*************************************************/
#if (USE_OPERATORS == 1)
    tip &operator[](unsigned long index)
    {
		while (glava_index < index)
        {
            glava = glava->naslednji;
            glava_index++;
        }
		
        while (glava_index > index)
        {
            glava = glava->prejsnji;
            glava_index--;
        }

        return (glava->podatek);
    }


    class_LIST<tip> operator+(tip pod)
    {
        this->add_end(pod);
        return *this;
    }

    void operator+=(tip pod)
    {
        this->add_end(pod);
    }
#endif
};
    
#if (USE_OPERATORS == 1)
template <class cl, typename tip>
class_LIST<tip> operator+(tip pod, cl obj)
{
    obj.add_front(pod);
    return obj;
}
#endif

#endif
