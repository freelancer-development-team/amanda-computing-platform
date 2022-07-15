/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object-system-test.cpp
 * Author: Javier Marrero
 *
 * Created on February 17, 2022, 4:10 PM
 */

#include <stdlib.h>
#include <iostream>

#include <AmandaSDK.h>

using namespace amanda::core;
using namespace amanda::io;

class ACommonObject : public Object
{

    AMANDA_OBJECT(ACommonObject, Object)
public:

    ACommonObject()
    {
        console().out.println("Creating object of type: %s", getClass().getName());
    }

    ~ACommonObject()
    {
        console().out.println("Deleting object of type: %s", getClass().getName());
    }
};

int main(int argc, char** argv)
{
    console().out.println("Initiating object system test.");
    StrongReference<ACommonObject> object1 = new ACommonObject();

    console().out.println("object1 pointer type: %s", object1.getClass().getName());
    console().out.println("object1 pointer super: %s", object1.getClass().getSuperClass()->getName());
    console().out.println("object1 pointer grandparent: %s", object1.getClass().getSuperClass()->getSuperClass()->getName());
    console().out.println("object1 pointer is considered Object? %d", object1.is<Object>());

    console().out.println("\nEntering new scope");
    {
        StrongReference<ACommonObject> object2 = new ACommonObject();

        /* Do some type checking. */
        console().out.println("Is object1 an object of type Object? %d", object1->is<Object>());
        console().out.println("Is object2 an object of type File? %d", object2->is<File>());

        if (object1.get() != object2.get())
        {
            console().out.println("Objects are not equals.");
        }
        else
        {
            console().out.println("Objects are equal.");
        }

        if (object1.equals(&object2))
        {
            console().out.println("Pointers are not equal (of course not)");
        }
        else
        {
            console().out.println("Pointer are equal? That's not true :(");
        }
    }
    console().out.println("\nExiting scope, object must have been deleted. ");

    if (object1)
    {
        console().out.println("Testing existence of object 1 returned true.");
    }

    console().out.println("Exiting program (destructor objects must be called now on)");
    return (EXIT_SUCCESS);
}

