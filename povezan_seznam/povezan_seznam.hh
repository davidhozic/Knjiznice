#ifndef SEZNAM_INC
#define SEZNAM_INC

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#include <stdint.h>


/************************************************************************/
/*							  SETTINGS                                  */
/************************************************************************/
#define  USE_FREERTOS_MALLOC   1
/************************************************************************/

#define add_end     dodaj_konec
#define add_front   dodaj_zacetek
#define clear       cisti_seznam

#if (USE_FREERTOS_MALLOC == 1)
	#include "FreeRTOS.h"
#endif



template <typename tip>
class Vozlisce_t
{
private:

    class vozlisce_data_obj_t
    {
    public:
        friend class Vozlisce_t<tip>;

    private:
        vozlisce_data_obj_t *naslednji;
        vozlisce_data_obj_t *prejsnji;
        tip podatek;
    };

    vozlisce_data_obj_t *glava = nullptr;
    unsigned short count = 0;
    unsigned short glava_index = 0;

    inline void pojdi_zacetek()
    {
        while (glava != nullptr && glava->prejsnji != nullptr)
        {
            glava = glava->prejsnji;
        }
    }

    inline void pojdi_konec()
    {
        while (glava != nullptr && glava->naslednji != nullptr)
        {
            glava = glava->naslednji;
        }
	}

public:
    inline unsigned short length()
    {
        return count;
    }

    void cisti_seznam()
    {
        pojdi_zacetek();
        while (glava != nullptr)
        {
            vozlisce_data_obj_t *temp = glava->naslednji;
            free(glava);
            glava = temp;
        }
        count = 0;
    }

    void dodaj_zacetek(tip vrednost)
    {
	#if (USE_FREERTOS_MALLOC == 1)
        vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) pvPortMalloc(sizeof(vozlisce_data_obj_t));
    #else
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) malloc(sizeof(vozlisce_data_obj_t));
	#endif
		pojdi_zacetek();

        if (glava != nullptr)
        {
            glava->prejsnji = nov;
        }
        nov->prejsnji = nullptr;
        nov->naslednji = glava;
        nov->podatek = vrednost;
        glava = nov;
        count++;
        glava_index = 0;
    }

    void dodaj_konec(tip vrednost)
    {

	#if (USE_FREERTOS_MALLOC == 1)
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) pvPortMalloc(sizeof(vozlisce_data_obj_t));
	#else
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) malloc(sizeof(vozlisce_data_obj_t));
	#endif

        pojdi_konec();
        if (glava != nullptr)
        {
            glava->naslednji = nov;
        }
        nov->prejsnji = glava;
        nov->naslednji = nullptr;
        nov->podatek = vrednost;
		glava = nov;
        count++;
        glava_index = count - 1;
    }

    tip &operator[](unsigned short index)
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
};


#endif
